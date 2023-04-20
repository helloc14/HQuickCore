#include "base_dao.h"

namespace ld
{
    BaseDao::BaseDao(QObject *data, const QString &objname, QObject *parent)
        : BaseObject(objname, parent)
    {

    }
    BaseDao::~BaseDao()
    {

    }
}
