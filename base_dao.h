#ifndef BASEDAO_H
#define BASEDAO_H

#include "HQuick_global.h"
#include "base_object.h"

namespace ld
{
    class HQUICK_EXPORT BaseDao : public BaseObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(BaseDao)

    public:
        explicit BaseDao(QObject *data, const QString &objname = "BaseDao", QObject *parent = nullptr);
        virtual ~BaseDao();
    };
}



#endif // BASEDAO_H
