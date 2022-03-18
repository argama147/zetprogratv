#ifndef ATTENDANCEACCESSOR_H
#define ATTENDANCEACCESSOR_H

#include "AttendanceAccessor_global.h"

class ATTENDANCEACCESSOR_EXPORT AttendanceAccessor
{
public:
    AttendanceAccessor();
    bool readCells(const QString &filePath, const QString &sheetName, QList<QList<QString>> &list);
};

#endif // ATTENDANCEACCESSOR_H
