#include "excelaccessoractiveqt.h"

#include <ActiveQt/QAxObject>

ExcelAccessorActiveQt::ExcelAccessorActiveQt(const ExcelAccessorActiveQtReadParam &param, QObject *parent)
    : ExcelAccessor{parent},
      filePath{param.filePath},
      sheetNo{param.sheetNo},
      rowStartNo{param.rowStartNo},
      rowNum{param.rowNum},
      columnStartNo{param.columnStartNo},
      columnNum{param.columnNum},
      excel{new QAxObject("Excel.Application")}
{
}

ExcelAccessorActiveQt::~ExcelAccessorActiveQt()
{
    if (sheet) {
        sheet->deleteLater();
    }
    if (workBook) {
        workBook->dynamicCall("Close(Boolean)", false);
        workBook->deleteLater();
    }
    if (workBooks) {
        workBooks->deleteLater();
    }
    if (excel) {
        excel->dynamicCall("Quit(void)");
        excel->deleteLater();
    }
}


void ExcelAccessorActiveQt::readCells()
{
    if (open(filePath, sheetNo)) {
        QList<QList<QString>> excelData;
        qDebug() << "readCells" << rowStartNo << rowNum << columnStartNo << columnNum;
        for (int i = rowStartNo; i < (rowStartNo + rowNum); i++) {
            QList<QString> rowData;
            for (int j = columnStartNo; j < (columnStartNo + columnNum); j++) {
                rowData << readCell(i, j);
            }
            excelData << rowData;
        }
        emit sendExcelData(excelData);
    } else {
        emit readError("cannot open:" + filePath);
    }
}

bool ExcelAccessorActiveQt::open(const QString &filePath, int sheetNo)
{
    qDebug() << Q_FUNC_INFO << filePath << sheetNo;
    workBooks = excel->querySubObject("Workbooks()");
    if (!workBooks) {
        emit readError("Unable to access workbooks.");
        return false;
    }

    workBook = workBooks->querySubObject("Open(const QString&)", filePath);
    if (!workBook) {
        emit readError("Unable to access workbook.");
        return false;
    }

    QString querySheet = "Worksheets(" + QString::number(sheetNo) + ")";
    sheet = workBook->querySubObject(querySheet.toStdString().c_str());
    auto result = (sheet != nullptr);
    if (!result) {
        emit readError("Unable to access Worksheets.");
    }
    qDebug() << Q_FUNC_INFO << result;
    return result;
}

QString ExcelAccessorActiveQt::readCell(int row, int column)
{
    if (!sheet) {
        qWarning() << "sheet is null.";
        return "";
    }

    auto cell = sheet->querySubObject("Cells(QVariant&, QVariant&)",
                                      row,
                                      column);
    QString ret;
    if (cell) {
        ret = cell->property("Value").toString();
        cell->deleteLater();
    }
    return ret;
}
