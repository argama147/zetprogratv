#include "attendancedata.h"

AttendanceData::AttendanceData()
{

}

QString AttendanceData::toString()
{
    return QString("%1,%2,%3,%4,%5,%6")
            .arg(date.toString("M/d"),
                 dayOfWeek,
                 startTime.toString(),
                 endTime.toString(),
                 breakTime.toString(),
                 contents);
}

const QDate &AttendanceData::getDate() const
{
    return date;
}

void AttendanceData::setDate(const QDate &newDate)
{
    date = newDate;
}

const QString &AttendanceData::getDayOfWeek() const
{
    return dayOfWeek;
}

void AttendanceData::setDayOfWeek(const QString &newDayOfWeek)
{
    dayOfWeek = newDayOfWeek;
}

const QTime &AttendanceData::getStartTime() const
{
    return startTime;
}

void AttendanceData::setStartTime(const QTime &newStartTime)
{
    startTime = newStartTime;
}

const QTime &AttendanceData::getEndTime() const
{
    return endTime;
}

void AttendanceData::setEndTime(const QTime &newEndTime)
{
    endTime = newEndTime;
}

const QTime &AttendanceData::getBreakTime() const
{
    return breakTime;
}

void AttendanceData::setBreakTime(const QTime &newBreakTime)
{
    breakTime = newBreakTime;
}

const QString &AttendanceData::getContents() const
{
    return contents;
}

void AttendanceData::setContents(const QString &newContents)
{
    contents = newContents;
}
