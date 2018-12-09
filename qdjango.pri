DEFINES += QDJANGO_DB_BUILD

HEADERS += \
    $$PWD/qdjango/src/db/QDjango.h \
    $$PWD/qdjango/src/db/QDjango_p.h \
    $$PWD/qdjango/src/db/QDjangoMetaModel.h \
    $$PWD/qdjango/src/db/QDjangoModel.h \
    $$PWD/qdjango/src/db/QDjangoQuerySet.h \
    $$PWD/qdjango/src/db/QDjangoQuerySet_p.h \
    $$PWD/qdjango/src/db/QDjangoWhere.h \
    $$PWD/qdjango/src/db/QDjangoWhere_p.h

SOURCES += \
    $$PWD/qdjango/src/db/QDjango.cpp \
    $$PWD/qdjango/src/db/QDjangoMetaModel.cpp \
    $$PWD/qdjango/src/db/QDjangoModel.cpp \
    $$PWD/qdjango/src/db/QDjangoQuerySet.cpp \
    $$PWD/qdjango/src/db/QDjangoWhere.cpp
