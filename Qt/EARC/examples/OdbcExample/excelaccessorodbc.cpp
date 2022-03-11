#include "excelaccessorodbc.h"

#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>

ExcelAccessorODBC::ExcelAccessorODBC(QObject *parent)
    : QObject{parent}
{

}

bool ExcelAccessorODBC::read(const QString filePath,
                             const QString sheetName,
                             QList<QList<QString> > &list)
{
    bool ret = false;
    QFile file(filePath);
    if (file.exists()) {
        {
            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "earc_xlsx_connection");
            db.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ="
                               + filePath);
            if(db.open()) {
                QSqlQuery query("select * from [" + sheetName + "$B10:H41]",db);
                while (query.next()) {
                    QList<QString> row;
                    for (int i = 0; i < 7; i++) {
                        row << query.value(i).toString();
                    }
                    list << row;
                }
                db.close();
                ret = true;
            } else {
                qWarning() << "file cannot open.";
            }
        }
        QSqlDatabase::removeDatabase("earc_xlsx_connection");
    } else {
        qWarning() << "file is not exist.";
    }
    return ret;
}
