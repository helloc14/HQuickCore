#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "action.h"
#include "HQuick_global.h"

#include <QObject>
#include <QMap>

namespace ld
{
    class HQUICK_EXPORT Dispatcher : public QObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(Dispatcher)

    public:
        explicit Dispatcher(Action *action, QObject *parent = nullptr);
        virtual ~Dispatcher();

        bool addConnection(const QString &action_type, QObject *obj, const QString &funcname);
        bool removeConnection(const QString &action_type, QObject *obj, const QString &funcname);

    private:
        bool existConnection(const QString &action_type, QObject *obj, const QString &funcname);

    private:
        Action *__m_action;
        QMap<QString, QMap<QObject*, QList<QString>>> __m_connections;
    };
}



#endif // DISPATCHER_H
