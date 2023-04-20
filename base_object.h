#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "HQuick_global.h"
#include <QObject>
#include <QDebug>

namespace ld
{
    class HQUICK_EXPORT BaseObject : public QObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(BaseObject)

    public:
        explicit BaseObject(const QString &objname = "BaseObject", QObject *parent = nullptr);
        virtual ~BaseObject();
    };
}

#endif // BASEOBJECT_H
