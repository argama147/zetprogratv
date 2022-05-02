#ifndef EXCELACCESSORTEST_H
#define EXCELACCESSORTEST_H

#include <QObject>

class ExcelAccessor;

class ExcelAccessorTest : public QObject
{
    Q_OBJECT

public:
    ExcelAccessorTest();
    ~ExcelAccessorTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void signalCount();
    void test_case1_data();
    void test_case1();
private:
    ExcelAccessor *accessor;
};

#endif // EXCELACCESSORTEST_H
