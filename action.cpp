#include "action.h"
#include <QDebug>

namespace ld
{
    Action::Action(QObject *parent) : QObject(parent)
    {

    }

    void Action::req(const QString &type, const QVariant &data)
    {
        emit sigReq(type, data);
    }
}


