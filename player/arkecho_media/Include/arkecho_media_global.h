#ifndef ARKECHO_MEDIA_GLOBAL_H
#define ARKECHO_MEDIA_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef ARKECHO_MEDIA_LIB
# define ARKECHO_MEDIA_EXPORT Q_DECL_EXPORT
#else
# define ARKECHO_MEDIA_EXPORT Q_DECL_IMPORT
#endif

#endif // ARKECHO_MEDIA_GLOBAL_H