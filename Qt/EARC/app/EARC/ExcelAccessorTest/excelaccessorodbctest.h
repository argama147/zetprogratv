#ifndef EXCELACCESSORODBCTEST_H
#define EXCELACCESSORODBCTEST_H

#include <QObject>
#include <QSignalSpy>
#include <QScopedPointer>

#include "excelaccessor.h"

class ExcelAccessorOdbcTest : public QObject
{
    Q_OBJECT
public:
    explicit ExcelAccessorOdbcTest(QObject *parent = nullptr);
private slots:
    void signalCountXls();
    void readXls_data();
    void readXls();
    void signalCountXlsx();
    void readXlsx_data();
    void readXlsx();
    void readError();
private:
    QScopedPointer<ExcelAccessor> accessor;

    void setTestData(QSignalSpy& spy);
    void check();

};

#endif // EXCELACCESSORODBCTEST_H
