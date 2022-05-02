#include "excelaccessorerrortest.h"
#include "excelaccessorerror.h"

#include <QtTest>
#include <QSignalSpy>

ExcelAccessorErrorTest::ExcelAccessorErrorTest(QObject *parent)
    : QObject{parent}
{

}

void ExcelAccessorErrorTest::initTestCase()
{
    accessor = new ExcelAccessorError;
}

void ExcelAccessorErrorTest::cleanupTestCase()
{
    delete accessor;
}

void ExcelAccessorErrorTest::errorCase()
{
    QSignalSpy spy(accessor, &ExcelAccessor::readError);
    accessor->readCells();
    QTest::qWait(3000);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.takeFirst().at(0).toString(), "Error Test");
;}
