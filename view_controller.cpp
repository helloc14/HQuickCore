
#include "view_controller.h"

namespace ld
{

ViewController::ViewController(QObject *engine, QObject *serviceMan, QObject *parent)
    : QObject(parent)
    , __m_engine(engine)
    , __m_service_man(serviceMan)
{

}

ViewController::~ViewController()
{

}

QObject *ViewController::findView(int childView)
{
    if (!__m_view_objs.contains(childView))
        return nullptr;
    return __m_view_objs[childView];
}

}


