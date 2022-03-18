#include <QtTest>

#include "attendanceaccessor.h"

class AttendanceAccessorTest : public QObject
{
    Q_OBJECT

public:
    AttendanceAccessorTest();
    ~AttendanceAccessorTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
private:
    AttendanceAccessor *accessor;
};

AttendanceAccessorTest::AttendanceAccessorTest()
{

}

AttendanceAccessorTest::~AttendanceAccessorTest()
{

}

void AttendanceAccessorTest::initTestCase()
{
    accessor = new AttendanceAccessor;
}

void AttendanceAccessorTest::cleanupTestCase()
{
    delete accessor;
}

void AttendanceAccessorTest::test_case1()
{
    QList<QList<QString>> list;
    auto ret = accessor->readCells("", "", list);
    QVERIFY(ret);
}

QTEST_APPLESS_MAIN(AttendanceAccessorTest)

#include "tst_attendanceaccessortest.moc"
