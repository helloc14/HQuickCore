#ifndef SIGNLE_APP_HELPER_H
#define SIGNLE_APP_HELPER_H

#include "HQuick_global.h"

#include <QString>
#include <QObject>

class QLocalServer;

namespace ld
{
    class HQUICK_EXPORT SingleAppHelper : public QObject
    {
    public:
        explicit SingleAppHelper(const QString &appName = "SingleAppHelper");
        virtual ~SingleAppHelper();

        virtual bool alreadyRunning();

    protected Q_SLOTS:
        void newLocalService();

    protected:
        void init();
        void createLocalService();

    protected:
        QString __m_appname;
        bool __m_running;
        QLocalServer *__m_local_server;
    };
}

#endif // SIGNLE_APP_HELPER_H
