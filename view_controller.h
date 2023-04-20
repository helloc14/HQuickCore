#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "HQuick_global.h"

#include <QObject>
#include <QMap>

namespace ld
{
    class ServiceManager;
    class HQUICK_EXPORT ViewController : public QObject
    {
        Q_OBJECT

    public:
        explicit ViewController(QObject *engine, QObject *serviceMan, QObject *parent = nullptr);
        virtual ~ViewController();

        typedef QMap<int, QObject*> ModuleViews;
        virtual void init() = 0;
        virtual void uninit() = 0;

    protected:
        virtual void controlView() = 0;
        virtual void disControlView() = 0;

        virtual void initViewObjs() = 0;

        QObject *findView(int childView);

    protected:
        QObject *__m_engine = nullptr;
        QObject *__m_service_man = nullptr;
        ModuleViews __m_view_objs;
    };
}

#endif // VIEWCONTROLLER_H
