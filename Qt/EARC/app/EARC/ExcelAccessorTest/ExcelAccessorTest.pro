QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_excelaccessortest.cpp \
    excelaccessorimpl.cpp

DESTDIR = ../bin
INCLUDEPATH += $$PWD/../AttendanceAccessor/

include($$PWD/../AttendanceAccessor/AttendanceAccessor.pri)

HEADERS += \
    excelaccessorimpl.h
