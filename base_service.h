#ifndef SERVICE_H
#define SERVICE_H

#include "HQuick_global.h"
#include "base_object.h"

namespace ld
{
    class HQUICK_EXPORT BaseService : public BaseObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(BaseService)

    public:
        explicit BaseService(const QString &objname = "BaseService", QObject *parent = nullptr);
        virtual ~BaseService();

        void setData(QObject *data);
        void setDAO(QObject *dao);

        inline QObject *data() { return __m_data; }
        inline QObject *dao() { return __m_dao; }

        Q_INVOKABLE virtual void exec(const QString &action_type, const QVariant &data);

    private:
        QObject *__m_dao;
        QObject *__m_data;
    };
}

#endif // SERVICE_H
