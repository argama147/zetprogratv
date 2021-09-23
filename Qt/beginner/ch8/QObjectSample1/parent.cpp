#include "parent.h"
#include <QDebug>

Parent::Parent(QObject *parent) : QObject(parent)
{
    qInfo() << __FUNCTION__;
}

Parent::~Parent()
{
    qInfo() << __FUNCTION__;
}
