#ifndef ATTENDANCEACCESSOR_H
#define ATTENDANCEACCESSOR_H

#include "AttendanceAccessor_global.h"
#include "attendancedata.h"
#include "excelaccessor.h"
#include <cstdlib>
#include <QObject>

class ATTENDANCEACCESSOR_EXPORT AttendanceAccessor : public QObject
{
    Q_OBJECT
public:
    enum class BuilderType : int {
        ActiveQt,
        Odbc
    };
    class ATTENDANCEACCESSOR_EXPORT Builder {
    public:
        AttendanceAccessor* create();
        Builder* setBuilderType(BuilderType newBuilderType);
        Builder* setFilePath(const QString &newFilePath);
        Builder* setSheetName(const QString &newSheetName);
        Builder* setSheetNo(int newSheetNo);
        Builder* setRowStartNo(int newRowStartNo);
        Builder* setRowNum(int newRowNum);
        Builder* setColumnNum(int newColumnNum);
        Builder* setColumnStartNo(int newColumnStartNo);
    private:
        BuilderType builderType = BuilderType::Odbc;
        QString filePath;
        QString sheetName;
        int sheetNo = 0;
        int rowStartNo = 0;
        int rowNum = 0;
        int columnNum = 0;
        int columnStartNo = 0;
    };

public:
    AttendanceAccessor(QObject *parent = nullptr);
    virtual ~AttendanceAccessor();
    void readCells();
    void setExcelAccessor(ExcelAccessor *accessor);
signals:
    void sendAttendanceData(const QList<AttendanceData> &attendanceDataList);
    void readError(const QString &reason);
private:
    std::unique_ptr<ExcelAccessor> excelAccessor;
};

#endif // ATTENDANCEACCESSOR_H
