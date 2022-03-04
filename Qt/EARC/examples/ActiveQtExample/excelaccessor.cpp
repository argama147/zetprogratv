#include "excelaccessor.h"

#include <ActiveQt/QAxObject>
#include <QDebug>

ExcelAccessor::ExcelAccessor(QObject *parent)
    : QObject{parent},
      excel{new QAxObject("Excel.Application")}
{

}

ExcelAccessor::~ExcelAccessor()
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

bool ExcelAccessor::open(const QString &filePath, int sheetNo)
{
    workBooks = excel->querySubObject("Workbooks()");
    if (!workBooks) {
        qWarning() << "workBooks is null.";
        return false;
    }

    workBook = workBooks->querySubObject("Open(const QString&)", filePath);
    if (!workBook) {
        qWarning() << "workBook is null.";
        return false;
    }

    QString querySheet = "Worksheets(" + QString::number(sheetNo) + ")";
    sheet = workBook->querySubObject(querySheet.toStdString().c_str());
    return sheet != nullptr;
}

QString ExcelAccessor::readCell(int row, int column)
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
