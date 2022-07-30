#include "attendancedataconverter.h"

AttendanceDataConverter::AttendanceDataConverter()
{

}

QDate AttendanceDataConverter::toDate(const QString &strData)
{
    QDate date;
    if (!strData.isEmpty()) {
        date = QDate::fromString(strData, "M/d");
    }
    return date;
}

QTime AttendanceDataConverter::toTime(const QString &strData)
{
    QTime time;
    if (!strData.isEmpty()) {
        time = QTime::fromString(strData, "H:m");
    }
    return time;
}
