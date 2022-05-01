#include <QCoreApplication>
#include <QDebug>

#include "excelaccessorodbc.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ExcelAccessorODBC accessor;
    QList<QList<QString>> list;
    if (accessor.read("C:/Users/argam/Desktop/勤怠表.xls", "シート", list)) {
        qInfo() << list;
    } else {
        qWarning() << "read failed.";
    }

    return a.exec();
}
