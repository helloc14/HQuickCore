#ifndef ACTION_H
#define ACTION_H

#include "HQuick_global.h"

#include <QObject>
#include <QVariant>

namespace ld
{
    class HQUICK_EXPORT Action : public QObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(Action)

    public:
        explicit Action(QObject *parent = nullptr);

    public slots:
        void req(const QString &type, const QVariant &data);

    signals:
        void sigReq(const QString &type, QVariant data);
    };
}

#endif // ACTION_H
