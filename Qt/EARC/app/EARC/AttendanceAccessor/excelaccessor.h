#ifndef EXCELACCESSOR_H
#define EXCELACCESSOR_H

#include <QObject>

class ExcelAccessor : public QObject
{
    Q_OBJECT
public:
    explicit ExcelAccessor(QObject *parent = nullptr);
    virtual void readCells() = 0;

signals:
    void sendExcelData(const QList<QList<QString>> &excelData);
    void readError(const QString &reason);
};

#endif // EXCELACCESSOR_H
