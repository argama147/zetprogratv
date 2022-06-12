#ifndef ATTENDANCEDATACONVERTER_H
#define ATTENDANCEDATACONVERTER_H

#include <QTime>

class AttendanceDataConverter
{
public:
    AttendanceDataConverter();
    QDate toDate(const QString &strData);
    QTime toTime(const QString &strData);
};

#endif // ATTENDANCEDATACONVERTER_H
