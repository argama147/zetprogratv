#include "myobject.h"

#include <QDebug>

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::hello()
{
    QString str = QString(tr("Hello World"));
    qInfo() << str;
}
