//
// Created by davidnaj on 14.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_settings_dialog.h" resolved

#include "settings_dialog.h"
#include "ui_settings_dialog.h"


#include <KActionCollection>
#include <KConfigGroup>
#include <KIconLoader>
#include <KSharedConfig>
#include <KLocalizedString>

SettingsDialog::SettingsDialog(TopLevel *parent) :
        QDialog(), m_topLevel(parent), ui(new Ui::SettingsDialog) {
    ui->setupUi(this);

    KSharedConfigPtr config = KSharedConfig::openConfig();
    KConfigGroup sshHosts(config, "ssh_hosts");

    m_sshSessionsList.clear();
    if (sshHosts.exists()) {
        for (unsigned index = 0;; ++index) {
            const QString ipKey = QString::asprintf("%d ip", index);
            const QString nameKey = QString::asprintf("%d name", index);
            const QString userKey = QString::asprintf("%d user", index);
            if (sshHosts.hasKey(ipKey) && sshHosts.hasKey(nameKey) && sshHosts.hasKey(userKey)) {

                QString ip = sshHosts.readEntry(ipKey, QString());
                QString name = sshHosts.readEntry(nameKey, QString());
                QString user = sshHosts.readEntry(userKey, QString());

                m_sshSessionsList.insert(index,SshSession(name, user, ip));

                ui->sshSessionsList->addItem(name);
            } else {
                break;
            }
        }
    }
    ui->sshSessionsList->setCurrentRow(0);

    connect(ui->sshSessionsList, &QListWidget::currentItemChanged, this, &SettingsDialog::selectedSessionIndexChanged);
    connect(ui->deleteSshSession, &QPushButton::clicked, this, &SettingsDialog::deleteSshSession);
    connect(ui->save, &QPushButton::clicked, this, &SettingsDialog::saveAndClose);

}

SettingsDialog::~SettingsDialog() {
    delete ui;
}

void SettingsDialog::selectedSessionIndexChanged() {
    QListWidgetItem* selected = ui->sshSessionsList->currentItem();
}


void SettingsDialog::deleteSshSession() {
    int selected = ui->sshSessionsList->currentRow();

    m_sshSessionsList.remove(selected);

    qDeleteAll(ui->sshSessionsList->selectedItems());

}



void SettingsDialog::saveAndClose() {
    KSharedConfigPtr config = KSharedConfig::openConfig();
    KConfigGroup sshHosts( config, "ssh_hosts" );

    sshHosts.deleteGroup();

    int index = 0;
    for (auto it = m_sshSessionsList.begin(); it != m_sshSessionsList.end(); ++it) {
        sshHosts.writeEntry(QStringLiteral( "%1 ip" ).arg( index ), it->ip() );
        sshHosts.writeEntry(QStringLiteral( "%1 name" ).arg( index ), it->name() );
        sshHosts.writeEntry(QStringLiteral( "%1 user" ).arg( index ), it->user() );

        index++;
    }
    sshHosts.config()->sync();

    m_topLevel->reloadTrayMenu();
    close();
}
