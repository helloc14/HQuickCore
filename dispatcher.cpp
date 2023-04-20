#include "dispatcher.h"

namespace ld
{
    Dispatcher::Dispatcher(Action *action, QObject *parent)
        : QObject{parent}
        , __m_action(action)
    {
        connect(__m_action, &Action::sigReq, this, [&](const QString &action_type, const QVariant &data)
        {
            if (__m_connections.find(action_type) == __m_connections.end())
            {
                qInfo() << "action_type: " << action_type << " data:" << data << " has not bind service member function";
                return;
            }
            QList<QObject*> service_list = __m_connections[action_type].keys();
            for (QObject *obj : service_list)
            {
                QList<QString> func_list = __m_connections[action_type][obj];
                for (auto &funcname : func_list)
                {
                    qInfo() << "start invokeMethod " << obj << " func:" << funcname << " action type:" << action_type << "data:" << data;
                    QMetaObject::invokeMethod(obj, funcname.toUtf8().data(), Q_ARG(const QString&, action_type), Q_ARG(const QVariant&, data));
                    qInfo() << "end invokeMethod " << obj << " func:" << funcname << " action type:" << action_type << "data:" << data;
                }
            }
        });
    }

    Dispatcher::~Dispatcher()
    {
        __m_connections.clear();
    }

    bool Dispatcher::addConnection(const QString &action_type, QObject *obj, const QString &funcname)
    {
        if (!existConnection(action_type, obj, funcname))
        {
            __m_connections[action_type][obj].append(funcname);
            return true;
        }
        qInfo() << "add connection failed!!! action_type:" << action_type << " funcname:" << funcname;
        return false;
    }

    bool Dispatcher::removeConnection(const QString &action_type, QObject *obj, const QString &funcname)
    {
        if (existConnection(action_type, obj, funcname))
        {
            if (__m_connections[action_type][obj].removeOne(funcname))
            {
                if (__m_connections[action_type][obj].isEmpty())
                {
                    __m_connections[action_type].remove(obj);
                    if (__m_connections[action_type].isEmpty())
                    {
                        __m_connections.remove(action_type);
                    }
                }
                return true;
            }
            return false;
        }
        qInfo() << "remove connection failed!!! action_type:" << action_type << " funcname:" << funcname;
        return false;
    }

    bool Dispatcher::existConnection(const QString &action_type, QObject *obj, const QString &funcname)
    {
        if (__m_connections.find(action_type) != __m_connections.end())
        {
            auto &connected_objs_list = __m_connections[action_type];
            if (connected_objs_list.find(obj) != connected_objs_list.end())
            {
                auto &connected_func_list = connected_objs_list[obj];
                return connected_func_list.contains(funcname);
            }
        }
        return false;
    }
}
