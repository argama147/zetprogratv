#include "object1.h"
#include <QDebug>

Object1::Object1(QObject *parent) : QObject(parent)
{

}

void Object1::act()
{
    qInfo() << __FUNCTION__;
    emit sendData(100);
}
