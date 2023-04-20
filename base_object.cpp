#include "base_object.h"

namespace ld
{
    BaseObject::BaseObject(const QString &objname, QObject *parent)
        : QObject{parent}
    {
        setObjectName(objname);
    }

    BaseObject::~BaseObject()
    {

    }
}
