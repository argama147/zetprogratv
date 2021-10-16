#include <QCoreApplication>

#include "object1.h"
#include "object2.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Object1 obj1;
    Object2 obj2;

    //Qt4
//    QObject::connect(&obj1, SIGNAL(sendData(int)),
//                     &obj2, SLOT(receiveData(int)));


    //Qt5
//    QObject::connect(&obj1, &Object1::sendData,
//                     &obj2, &Object2::receiveData);

    //Qt5 - Lambdaスタイル1
    QObject::connect(&obj1, &Object1::sendData,
                     [](int data){
        qInfo() << "Lambda1:" << data;
    });

    //Qt5 - Lambdaスタイル2
    QObject::connect(&obj1, &Object1::sendData,
                     &a, [](int data){
        qInfo() << "Lambda2:" << data;
    });

    obj1.act();

    return a.exec();
}
