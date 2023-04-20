#include "service_manager.h"

namespace ld
{
    ServiceManager::ServiceManager(QObject *dao, QObject *data, const QString &objname, QObject *parent)
        : BaseObject(objname, parent)
        , __m_dao(dao)
        , __m_data(data)
    {

    }

    ServiceManager::~ServiceManager()
    {
        QStringList keys = __m_services.keys();
        for (auto &key : keys)
        {
            delete __m_services[key];
            __m_services[key] = nullptr;
        }
        __m_services.clear();
    }

    bool ServiceManager::add(const QString &name, BaseService *service)
    {
        if (__m_services.find(name) != __m_services.end())
        {
            qInfo() << "add " << name << " failed!!! exist same service";
            return false;
        }
        service->setDAO(__m_dao);
        service->setData(__m_data);
        __m_services[name] = service;

        return true;
    }

    bool ServiceManager::remove(const QString &name)
    {
        if (__m_services.find(name) != __m_services.end())
        {
            delete __m_services[name];
            __m_services[name] = nullptr;
            __m_services.remove(name);
            return true;
        }
        qInfo() << "remove " << name << " failed!!! no exist service";
        return false;
    }

    BaseService *ServiceManager::get(const QString &name)
    {
        if (__m_services.find(name) == __m_services.end())
            return nullptr;
        else
            return __m_services[name];
    }

}

