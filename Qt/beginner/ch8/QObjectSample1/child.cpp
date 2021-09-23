#include "child.h"
#include <QDebug>

Child::Child(QObject *parent) : QObject(parent)
{
    qInfo() << __FUNCTION__;
}

Child::~Child()
{
    qInfo() << __FUNCTION__;
}
