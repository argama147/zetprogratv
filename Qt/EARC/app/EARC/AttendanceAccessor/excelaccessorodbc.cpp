#include "excelaccessorodbc.h"

#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>

ExcelAccessorOdbc::ExcelAccessorOdbc(const ExcelAccessorOdbcParam &param, QObject *parent)
    : ExcelAccessor{parent},
      filePath{param.filePath},
      sheetName{param.sheetName},
      rowStartNo{param.rowStartNo},
      columnNum{param.columnNum}
{
}

void ExcelAccessorOdbc::readCells()
{
    if (rowStartNo < 2) {
        QString reason = QString("rowStartNo=%1 but rowStartNo is 2 or more").arg(rowStartNo);
        emit readError(reason);
        return;
    }
    QFile file(filePath);
    if (file.exists()) {
        {
            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "earc_xlsx_connection");
            db.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ="
                               + filePath);
            if(db.open()) {
                QSqlQuery query("select * from [" + sheetName + "$]",db);
                QList<QList<QString>> excelData;
                int rowNo = 1;
                while (query.next()) {
                    QList<QString> row;
                    if (rowNo >= (rowStartNo - 2)) {
                        for (int i = 0; i < columnNum; i++) {
                            row << query.value(i).toString();
                        }
                        excelData << row;
                    } else {
                        rowNo++;
                        continue;
                    }
                }
                db.close();
                emit sendExcelData(excelData);
            } else {
                emit readError("file cannot open.");
            }
        }
        QSqlDatabase::removeDatabase("earc_xlsx_connection");
    } else {
        emit readError("file is not exist.");
    }
}
