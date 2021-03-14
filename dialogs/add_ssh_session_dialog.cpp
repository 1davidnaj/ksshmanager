//
// Created by davidnaj on 14.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_add_ssh_session_dialog.h" resolved

#include "add_ssh_session_dialog.h"
#include "ui_add_ssh_session_dialog.h"

#include <QDialogButtonBox>
#include <QScreen>
#include <QHashIterator>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

#include <KConfigGroup>
#include <KHelpClient>
#include <KLocalizedString>
#include <KSharedConfig>

AddSshSessionDialog::AddSshSessionDialog(TopLevel *parent) :
        QDialog(), m_topLevel(parent), ui(new Ui::AddSshSessionDialog) {
    ui->setupUi(this);

    connect(ui->add, &QPushButton::clicked, this, &AddSshSessionDialog::addSshSession);
}

AddSshSessionDialog::~AddSshSessionDialog() {
    delete ui;
}

void AddSshSessionDialog::addSshSession() {
    KSharedConfigPtr config = KSharedConfig::openConfig();
    KConfigGroup sshHosts( config, "ssh_hosts" );

    QList<SshSession> sshSessionsList;
    unsigned index = 0;
    if( sshHosts.exists() ) {
        for(index=0;; ++index) {
            const QString ipKey = QString::asprintf("%d ip", index);
            const QString nameKey = QString::asprintf("%d name", index);
            const QString userKey = QString::asprintf("%d user", index);
            if (sshHosts.hasKey(ipKey) && sshHosts.hasKey(nameKey) && sshHosts.hasKey(userKey)) {

                QString ip = sshHosts.readEntry(ipKey, QString());
                QString name = sshHosts.readEntry(nameKey, QString());
                QString user = sshHosts.readEntry(userKey, QString());

                sshSessionsList.append(SshSession(name, user, ip));
            } else {
                break;
            }
        }
    }
    sshHosts.writeEntry(QStringLiteral( "%1 ip" ).arg( index ), ui->ip->text() );
    sshHosts.writeEntry(QStringLiteral( "%1 name" ).arg( index ), ui->name->text() );
    sshHosts.writeEntry(QStringLiteral( "%1 user" ).arg( index ), ui->user->text() );

    sshHosts.config()->sync();

    m_topLevel->reloadTrayMenu();
    close();

}
