TEMPLATE = subdirs

SUBDIRS += \
    App \
    AttendanceAccessor \
    AttendanceAccessorTest

App.depends = AttendanceAccessor
AttendanceAccessorTest.depends = AttendanceAccessor
