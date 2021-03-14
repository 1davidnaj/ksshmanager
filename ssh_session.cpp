#include "ssh_session.h"

#include <KLocalizedString>

SshSession::SshSession(const QString &name, const QString &user, const QString &ip)
{
    setName( name );
    setIp( ip );
    setUser( user );
}


QString SshSession::name() const
{
    return m_name;
}


void SshSession::setName(const QString &name)
{
    if( name.isEmpty() ) {
        m_name = i18n( "Unnamed" );
    }
    else {
        m_name = name;
    }
}


QString SshSession::ip() const
{
    return m_ip;
}


void SshSession::setIp(const QString &ip)
{
    m_ip = ip;
}


QString SshSession::user() const
{
    return m_user;
}


void SshSession::setUser(const QString &user)
{
    m_user = user;
}

QString SshSession::getCommand() const {
    std::string stdRet;

    stdRet = "ssh " + m_user.toStdString() + "@" + m_ip.toStdString();

    return QString::fromLocal8Bit(stdRet.c_str());
}
