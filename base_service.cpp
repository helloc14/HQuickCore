#include "base_service.h"

namespace ld
{
    BaseService::BaseService(const QString &objname, QObject *parent)
        : BaseObject(objname, parent)
        , __m_dao(nullptr)
        , __m_data(nullptr)
    {
    }

    BaseService::~BaseService()
    {
        __m_dao = nullptr;
        __m_data = nullptr;
    }

    void BaseService::exec(const QString &action_type, const QVariant &data)
    {
        qInfo() << "BaseService: function "  <<  __FUNCTION__ << "() action_type: " << action_type;
    }

    void BaseService::setData(QObject *data)
    {
        if (__m_data != data)
            __m_data = data;
    }

    void BaseService::setDAO(QObject *dao)
    {
        if (__m_dao != dao)
            __m_dao = dao;
    }
}


