/*
 * Copyright 1998-1999 by Matthias Hölzer-Klüpfel <matthias@hoelzer-kluepfel.de>
 * Copyright 2002-2003 by Martin Willers <willers@xm-arts.de>
 * Copyright 2007-2009 by Stefan Böhmann <kde@hilefoks.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "toplevel.h"
#include "dialogs/add_ssh_session_dialog.h"

#include <fstream>
#include <thread>

#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QBrush>
#include <QMenu>
#include <QString>
#include <QTimer>
#include <QPainter>
#include <QIcon>

#include <KAboutData>
#include <KActionCollection>
#include <KConfigGroup>
#include <KHelpMenu>
#include <KIconLoader>
#include <KNotifyConfigWidget>
#include <KSharedConfig>
#include <KLocalizedString>
#include <dialogs/settings_dialog.h>


TopLevel::TopLevel(const KAboutData *aboutData, const QString &icon, QWidget *parent)
        : QSystemTrayIcon(parent),
          m_iconName(icon) {
    setTrayMenu();

    m_actionCollection = new KActionCollection(this);

    // configure button
    action = m_actionCollection->addAction(QStringLiteral("configure"));
    action->setIcon(QIcon::fromTheme(QStringLiteral("configure")));
    action->setText(i18n("&Configure..."));
    connect(action, &QAction::triggered, this, &TopLevel::showSettingsDialog);

    // quit button
    action = KStandardAction::quit(qApp, &QCoreApplication::quit, m_actionCollection);
    action->setShortcut(0);

    // set context menu
    setContextMenu(new QMenu);

    // draw tray menu
    reloadTrayMenu();

    // show in tray
    show();
}


TopLevel::~TopLevel() {
}


void TopLevel::reloadTrayMenu() {

    KSharedConfigPtr config = KSharedConfig::openConfig();
    KConfigGroup sshHosts(config, "ssh_hosts");

    /*sshHosts.deleteGroup();
    sshHosts.config()->sync();*/

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

                m_sshSessionsList.append(SshSession(name, user, ip));
            } else {
                break;
            }
        }
    }
    for (QAction *sessionMenuAction: m_sshSessionsMenu->actions()) {
        delete sessionMenuAction;
    }
    m_sshSessionsMenu->setTitle(QStringLiteral("Sessions"));
    m_sshSessionsMenu->clear();

    // connect ssh session button signals
    int i = 0;
    for (const SshSession &sshSession : qAsConst(m_sshSessionsList)) {
        QAction *a = m_sshSessionsMenu->addAction(
                i18nc("%1 - Name, %2 - Ip address "
                      "ssh session", "%1 (%2)", sshSession.name(), sshSession.ip())
        );
        a->setData(sshSession.getCommand());
        connect(a, &QAction::triggered, this, &TopLevel::sshToHost);

    }

    // add plus button
    QAction *plusButton = m_sshSessionsMenu->addAction(
            i18nc("Add SSH Session"
                  "add ssh session", "ADD NEW"
            )
    );
    connect(plusButton, &QAction::triggered, this, &TopLevel::showCreateSessionDialog);
    m_sshSessionsMenu->addAction(plusButton);

    // draw context menu
    contextMenu()->clear();
    contextMenu()->addMenu(m_sshSessionsMenu);
    contextMenu()->addSeparator();
    contextMenu()->addSeparator();
    contextMenu()->addAction(m_actionCollection->action(QStringLiteral("configure")));
    contextMenu()->addSeparator();
    contextMenu()->addAction(m_actionCollection->action(QLatin1String(KStandardAction::name(KStandardAction::Quit))));
}

void TopLevel::showSettingsDialog() {
    SettingsDialog( this ).exec();
}


void TopLevel::setTrayMenu() {
    QIcon ic = QIcon::fromTheme(QStringLiteral("utilities-terminal"));

    setIcon(ic);
}

void TopLevel::showCreateSessionDialog() {
    AddSshSessionDialog(this).exec();
}

void TopLevel::sshToHost() {
    QObject *obj = sender();
    auto *a = qobject_cast<QAction *>(obj);
    QString command = a->data().toString();

    std::string terminalCommand = "konsole --separate -e \"" + command.toStdString() + "\" &";
    system(terminalCommand.c_str());
}

