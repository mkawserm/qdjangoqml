#include "qdjangoqml_plugin.h"
#include "qdjangoorm.h"

#include <qqml.h>

void QDjangoQMLPlugin::registerTypes(const char *uri)
{
    // @uri QDjangoQML
    qmlRegisterType<QDjangoORM>(uri, 1, 0, "QDjangoORM");
}

