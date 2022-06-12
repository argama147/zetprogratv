#ifndef ATTENDANCEDATA_H
#define ATTENDANCEDATA_H

#include "AttendanceAccessor_global.h"
#include <QDate>

class ATTENDANCEACCESSOR_EXPORT AttendanceData
{
public:
    AttendanceData();
    QString toString();
    const QDate &getDate() const;
    void setDate(const QDate &newDate);
    const QString &getDayOfWeek() const;
    void setDayOfWeek(const QString &newDayOfWeek);
    const QTime &getStartTime() const;
    void setStartTime(const QTime &newStartTime);
    const QTime &getEndTime() const;
    void setEndTime(const QTime &newEndTime);
    const QTime &getBreakTime() const;
    void setBreakTime(const QTime &newBreakTime);
    const QString &getContents() const;
    void setContents(const QString &newContents);

private:
    QDate date;
    QString dayOfWeek;
    QTime startTime;
    QTime endTime;
    QTime breakTime;
    QString contents;
};

#endif // ATTENDANCEDATA_H
