QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    excelaccessorerror.cpp \
    excelaccessorerrortest.cpp \
    excelaccessorimpl.cpp \
    excelaccessorodbctest.cpp \
    excelaccessortest.cpp \
    main.cpp

DESTDIR = ../bin
INCLUDEPATH += $$PWD/../AttendanceAccessor/

include($$PWD/../AttendanceAccessor/AttendanceAccessor.pri)

HEADERS += \
    excelaccessorerror.h \
    excelaccessorerrortest.h \
    excelaccessorimpl.h \
    excelaccessorodbctest.h \
    excelaccessortest.h
