TEMPLATE = subdirs

SUBDIRS += \
    App \
    AttendanceAccessor \
    AttendanceAccessorTest \
    ExcelAccessorTest

App.depends = AttendanceAccessor
AttendanceAccessorTest.depends = AttendanceAccessor
