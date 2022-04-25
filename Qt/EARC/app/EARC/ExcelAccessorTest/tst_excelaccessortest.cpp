#include <QtTest>
#include <QSignalSpy>

#include "excelaccessorimpl.h"

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

ExcelAccessorTest::ExcelAccessorTest()
{

}

ExcelAccessorTest::~ExcelAccessorTest()
{

}

void ExcelAccessorTest::initTestCase()
{
    accessor = new ExcelAccessorImpl;
}

void ExcelAccessorTest::cleanupTestCase()
{
    delete accessor;
}

void ExcelAccessorTest::signalCount()
{
    QSignalSpy spy(accessor, &ExcelAccessor::sendExcelData);
    accessor->readCells();
    QTest::qWait(3000);
    QCOMPARE(spy.count(), 1);
}

void ExcelAccessorTest::test_case1_data()
{
    QSignalSpy spy(accessor, &ExcelAccessor::sendExcelData);
    accessor->readCells();
    QTest::qWait(3000);

    QTest::addColumn<QString>("date");
    QTest::addColumn<QString>("day_of_week");
    QTest::addColumn<QString>("startTime");
    QTest::addColumn<QString>("endTime");
    QTest::addColumn<QString>("breakTime");
    QTest::addColumn<QString>("sum");
    QTest::addColumn<QString>("contents");
    QTest::addColumn<QString>("date_result");
    QTest::addColumn<QString>("day_of_week_result");
    QTest::addColumn<QString>("startTime_result");
    QTest::addColumn<QString>("endTime_result");
    QTest::addColumn<QString>("breakTime_result");
    QTest::addColumn<QString>("sum_result");
    QTest::addColumn<QString>("contents_result");

    QList<QString> dateList
            = {"1/1", "1/2", "1/3", "1/4", "1/5", "1/6", "1/7", "1/8", "1/9", "1/10",
              "1/11", "1/12", "1/13", "1/14", "1/15", "1/16", "1/17", "1/18", "1/19", "1/20",
              "1/21", "1/22", "1/23", "1/24", "1/25", "1/26", "1/27", "1/28", "1/29", "1/30",
              "1/31"};
    QList<QString> dateOfWeekList
            = {"土","日","月","火","水","木","金",
               "土","日","月","火","水","木","金",
               "土","日","月","火","水","木","金",
               "土","日","月","火","水","木","金",
               "土", "日","月"};
    QList<QString> startTimeList
            = {"", "", "","9:00","9:00","9:00","9:00",
              "", "", "9:00","9:00","9:00","9:00","9:00",
              "", "", "9:00","9:00","9:00","9:00","9:00",
              "", "", "9:00","9:00","9:00","9:00","9:00",
              "", "", "9:00"};
    QList<QString> endTimeList
            = {"","","","18:00","18:00","18:00","18:00",
              "","","18:00","18:00","18:00","18:00","18:00",
              "","","18:00","18:00","18:00","18:00","18:00",
              "","","18:00","18:00","18:00","18:00","18:00",
              "","","18:00"};
    QList<QString> breakTimeList
            = {"","","","1:00","1:00","1:00","1:00",
              "","","1:00","1:00","1:00","1:00","1:00",
              "","","1:00","1:00","1:00","1:00","1:00",
              "","","1:00","1:00","1:00","1:00","1:00",
              "","","1:00","1:00"};
    QList<QString> sumList
            = {"","","","8:00","8:00","8:00","8:00",
              "","","8:00","8:00","8:00","8:00","8:00",
              "","","8:00","8:00","8:00","8:00","8:00",
              "","","8:00","8:00","8:00","8:00","8:00",
              "","","8:00"};
    QList<QString> contentsList
            = {"", "", "","1/4の作業","1/5の作業","","1/7の作業",
              "", "", "1/10の作業","1/11の作業","","1/13の作業","1/14の作業",
              "", "", "1/17の作業","1/18の作業","1/19の作業","","1/21の作業",
              "", "", "","1/25の作業","1/26の作業","1/27の作業","1/28の作業",
              "", "", "1/31の作業"};

    auto result = spy.takeFirst();
    for (int i = 0; i < 31; i++) {
        QString str = QString("Row:%1").arg(QString::number(i + 1));
        QTest::newRow(str.toStdString().c_str())
               << dateList[i] << dateOfWeekList[i] << startTimeList[i] << endTimeList[i]
               << breakTimeList[i] << sumList[i] << contentsList[i]
               << result.at(0).toList().at(i).toList().at(0).toString()
               << result.at(0).toList().at(i).toList().at(1).toString()
               << result.at(0).toList().at(i).toList().at(2).toString()
               << result.at(0).toList().at(i).toList().at(3).toString()
               << result.at(0).toList().at(i).toList().at(4).toString()
               << result.at(0).toList().at(i).toList().at(5).toString()
               << result.at(0).toList().at(i).toList().at(6).toString();
    }

}

void ExcelAccessorTest::test_case1()
{
    QFETCH(QString, date);
    QFETCH(QString, day_of_week);
    QFETCH(QString, startTime);
    QFETCH(QString, endTime);
    QFETCH(QString, breakTime);
    QFETCH(QString, sum);
    QFETCH(QString, contents);
    QFETCH(QString, date_result);
    QFETCH(QString, day_of_week_result);
    QFETCH(QString, startTime_result);
    QFETCH(QString, endTime_result);
    QFETCH(QString, breakTime_result);
    QFETCH(QString, sum_result);
    QFETCH(QString, contents_result);

    QCOMPARE(date_result, date);
    QCOMPARE(day_of_week, day_of_week_result);
    QCOMPARE(startTime, startTime_result);
    QCOMPARE(endTime, endTime_result);
    QCOMPARE(breakTime, breakTime_result);
    QCOMPARE(sum, sum_result);
    QCOMPARE(contents, contents_result);
}

QTEST_MAIN(ExcelAccessorTest)

#include "tst_excelaccessortest.moc"
