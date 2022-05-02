#include <QCoreApplication>
#include <QTest>

#include "excelaccessortest.h"
#include "excelaccessorerrortest.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int status = 0;
    {
        ExcelAccessorTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        ExcelAccessorErrorTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}
