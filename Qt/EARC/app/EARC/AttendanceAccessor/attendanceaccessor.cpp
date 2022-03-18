#include "attendanceaccessor.h"

#include <QDebug>

AttendanceAccessor::AttendanceAccessor()
{
}

bool AttendanceAccessor::readCells(const QString &filePath, const QString &sheetName, QList<QList<QString> > &list)
{
    qDebug() << "readCells";
    return true;
}
