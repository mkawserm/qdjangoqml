TEMPLATE = lib
TARGET = QDjangoQML
QT += qml quick
QT += sql

CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = QDjangoQML

include(qdjango.pri)
# Input
SOURCES += \
        qdjangoqml_plugin.cpp \
        qdjangoorm.cpp

HEADERS += \
        qdjangoqml_plugin.h \
        qdjangoorm.h

DISTFILES = qmldir QDjangoQML.qmltypes

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmltypes.commands = qmlplugindump -nonrelocatable QDjangoQML 1.0 > $$PWD/QDjangoQML.qmltypes
QMAKE_EXTRA_TARGETS += qmltypes

qmldir.files = qmldir QDjangoQML.qmltypes
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
