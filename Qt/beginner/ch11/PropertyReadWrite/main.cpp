#include <QCoreApplication>
#include <QDebug>

#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyObject obj;
    QObject::connect(&obj, &MyObject::messageChanged,
                     [=](QString message){
        qInfo() << "message Changed:" << message;
    });
//    obj.setMessage("new Message");
    obj.setProperty("message", "new Property");
    qInfo() << "message property:" << obj.property("message");

    return a.exec();
}
