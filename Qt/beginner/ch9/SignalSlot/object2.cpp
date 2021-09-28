#include "object2.h"
#include <QDebug>

Object2::Object2(QObject *parent) : QObject(parent)
{

}

void Object2::receiveData(int data)
{
    qInfo() << __FUNCTION__ << data;
}
