/*
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
#ifndef SSHSESSION_H
#define SSHSESSION_H

#include <QString>


/**
 * @short this class represent a tea.
 *
 * @author Stefan Böhmann <kde@hilefoks.org>
 */
class SshSession {
public:

    explicit SshSession(const QString &name, const QString &user, const QString &ip);

    QString name() const;
    void setName(const QString &name);

    QString ip() const;
    void setIp(const QString &name);

    QString user() const;
    void setUser(const QString &user);

    QString getCommand() const;
private:
    QString m_name;
    QString m_ip;
    QString m_user;
};

#endif

// kate: word-wrap off; encoding utf-8; indent-width 4; tab-width 4; line-numbers on; mixed-indent off; remove-trailing-space-save on; replace-tabs-save on; replace-tabs on; space-indent on;
// vim:set spell et sw=4 ts=4 nowrap cino=l1,cs,U1:

