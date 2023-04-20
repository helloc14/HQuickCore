#ifndef HQUICK_GLOBAL_H
#define HQUICK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HQUICK_LIBRARY)
#  define HQUICK_EXPORT Q_DECL_EXPORT
#else
#  define HQUICK_EXPORT Q_DECL_IMPORT
#endif

#endif // HQUICK_GLOBAL_H
