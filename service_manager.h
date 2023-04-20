#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "base_dao.h"
#include "base_service.h"
#include "HQuick_global.h"

#include <QMap>

namespace ld
{
    class HQUICK_EXPORT ServiceManager : public BaseObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(ServiceManager)

    public:
        explicit ServiceManager(QObject *dao, QObject *data, const QString &objname = "ServiceManager", QObject *parent = nullptr);
        virtual ~ServiceManager();

        bool add(const QString &name, BaseService *service);
        bool remove(const QString &name);
        BaseService *get(const QString &name);

    private:
        QMap<QString, BaseService*> __m_services;
        QObject *__m_dao;
        QObject *__m_data;
    };
}


#endif // SERVICEMANAGER_H
