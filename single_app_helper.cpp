#include "single_app_helper.h"

#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include <QFile>

namespace ld
{
    SingleAppHelper::SingleAppHelper(const QString &appName)
        : __m_appname(appName)
        , __m_running(false)
        , __m_local_server(nullptr)
    {
        init();
    }

    SingleAppHelper::~SingleAppHelper()
    {
        #if !defined (Q_OS_ANDROID)

        if (__m_local_server != nullptr)
        {
            delete __m_local_server;
            __m_local_server = nullptr;
        }

        #endif
    }

    bool SingleAppHelper::alreadyRunning()
    {
        return __m_running;
    }

    void SingleAppHelper::newLocalService()
    {
        #if !defined (Q_OS_ANDROID)

        QLocalSocket *l_pSocket = __m_local_server->nextPendingConnection();
        if (!l_pSocket)
        {
            return;
        }

        l_pSocket->waitForReadyRead(1000);
        delete l_pSocket;
        l_pSocket = nullptr;

        #endif
    }

    void SingleAppHelper::createLocalService()
    {
        #if !defined (Q_OS_ANDROID)

        __m_local_server = new QLocalServer(this);
        connect(__m_local_server, &QLocalServer::newConnection, this, &SingleAppHelper::newLocalService);

        if (!__m_local_server->listen(__m_appname))
        {
            if ((__m_local_server->serverError() == QAbstractSocket::AddressInUseError)
                && (QFile::exists(__m_local_server->serverName())))
            {
                QFile::remove(__m_local_server->serverName());
                __m_local_server->listen(__m_appname);
            }
        }

        #endif
    }

    void SingleAppHelper::init()
    {
        #if !defined (Q_OS_ANDROID)
        QLocalSocket l_socket;
        l_socket.connectToServer(__m_appname);

        if (l_socket.waitForConnected(500))
        {
            __m_running = true;
            return;
        }
        else
        {
            createLocalService();
        }
        #endif
    }
}


