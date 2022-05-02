#ifndef EXCELACCESSORERRORTEST_H
#define EXCELACCESSORERRORTEST_H

#include <QObject>

class ExcelAccessor;

class ExcelAccessorErrorTest : public QObject
{
    Q_OBJECT
public:
    explicit ExcelAccessorErrorTest(QObject *parent = nullptr);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void errorCase();
private:
    ExcelAccessor *accessor;
};

#endif // EXCELACCESSORERRORTEST_H
