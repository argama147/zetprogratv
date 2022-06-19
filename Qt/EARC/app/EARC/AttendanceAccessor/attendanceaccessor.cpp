#include "attendanceaccessor.h"
#include "attendancedataconverter.h"
#include "excelaccessoractiveqt.h"
#include "excelaccessorodbc.h"

#include <QDebug>

AttendanceAccessor::AttendanceAccessor(QObject *parent)
    : QObject(parent),
      excelAccessor(nullptr)
{
}

AttendanceAccessor::~AttendanceAccessor()
{
    qDebug() << Q_FUNC_INFO;
}

void AttendanceAccessor::readCells()
{
    connect(excelAccessor.get(), &ExcelAccessor::sendExcelData,
            this,
            [=](const QList<QList<QString>> &excelData){
        qDebug() << "excelData=" << excelData;
        QList<AttendanceData> attendanceList;
        AttendanceDataConverter converter;
        for (auto &row : excelData) {
            AttendanceData data;
            data.setDate(converter.toDate(row[0]));
            data.setDayOfWeek(row[1]);
            data.setStartTime(converter.toTime(row[2]));
            data.setEndTime(converter.toTime(row[3]));
            data.setBreakTime(converter.toTime(row[4]));
            data.setContents(row[6]);
            attendanceList << data;
        }
        emit sendAttendanceData(attendanceList);
    });
    connect(excelAccessor.get(), &ExcelAccessor::readError,
            this,
            &AttendanceAccessor::readError);
    excelAccessor->readCells();
}

void AttendanceAccessor::setExcelAccessor(ExcelAccessor *accessor)
{
    excelAccessor.reset(accessor);
}

AttendanceAccessor *AttendanceAccessor::Builder::create()
{
    AttendanceAccessor *attendanceAccessor = new AttendanceAccessor;
    switch(builderType) {
    case BuilderType::ActiveQt:
    {
        ExcelAccessorActiveQtReadParam param(
                    filePath,
                    sheetNo,
                    rowStartNo,
                    rowNum,
                    columnStartNo,
                    columnNum);
        attendanceAccessor->setExcelAccessor(new ExcelAccessorActiveQt(param));
    }
        break;
    case BuilderType::Odbc:
    {
        ExcelAccessorOdbcParam param(
                    filePath,
                    sheetName,
                    rowStartNo,
                    columnNum);
        attendanceAccessor->setExcelAccessor(new ExcelAccessorOdbc(param));
    }
        break;
    }
    return attendanceAccessor;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setBuilderType(BuilderType newBuilderType)
{
    builderType = newBuilderType;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setFilePath(const QString &newFilePath)
{
    filePath = newFilePath;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setSheetName(const QString &newSheetName)
{
    sheetName = newSheetName;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setSheetNo(int newSheetNo)
{
    sheetNo = newSheetNo;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setRowStartNo(int newRowStartNo)
{
    rowStartNo = newRowStartNo;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setRowNum(int newRowNum)
{
    rowNum = newRowNum;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setColumnNum(int newColumnNum)
{
    columnNum = newColumnNum;
    return this;
}

AttendanceAccessor::Builder* AttendanceAccessor::Builder::setColumnStartNo(int newColumnStartNo)
{
    columnStartNo = newColumnStartNo;
    return this;
}


