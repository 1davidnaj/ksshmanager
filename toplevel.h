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
#ifndef TOPLEVEL_H
#define TOPLEVEL_H

#include "ssh_session.h"

#include <QSystemTrayIcon>
#include <QPointer>
#include <QMenu>


class QAction;

class QActionGroup;

class KAboutData;

class KActionCollection;

class KHelpMenu;

class TopLevel : public QSystemTrayIcon {
public:
    explicit TopLevel(const KAboutData *aboutData, const QString &icon = QLatin1String("kteatime"),
                      QWidget *parent = nullptr);

    ~TopLevel();
//        void setTeaList(const QList<Tea> &tealist);

    void reloadTrayMenu();

private:
    void showSettingsDialog();

    void showCreateSessionDialog();

    void sshToHost();

    void setTrayMenu();

    QList<SshSession> m_sshSessionsList;
    QAction *action = nullptr;
    KActionCollection *m_actionCollection = nullptr;

    QMenu *m_sshSessionsMenu = new QMenu;
    KHelpMenu *m_helpMenu = nullptr;
    QString m_iconName;

};

#endif

// kate: word-wrap off; encoding utf-8; indent-width 4; tab-width 4; line-numbers on; mixed-indent off; remove-trailing-space-save on; replace-tabs-save on; replace-tabs on; space-indent on;
// vim:set spell et sw=4 ts=4 nowrap cino=l1,cs,U1:
