QT -= gui
QT += axcontainer

TEMPLATE = lib
DEFINES += ATTENDANCEACCESSOR_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attendanceaccessor.cpp \
    excelaccessoractiveqt.cpp

HEADERS += \
    AttendanceAccessor_global.h \
    attendanceaccessor.h \
    excelaccessoractiveqt.h

DESTDIR = ../bin

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

include(./AttendanceAccessor.pri)
