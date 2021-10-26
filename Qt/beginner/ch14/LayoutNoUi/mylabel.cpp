#include "mylabel.h"

#include <QDebug>

MyLabel::MyLabel(const QString &text, QWidget *parent, Qt::WindowFlags f)
    : QLabel(text, parent, f)
{
    qInfo() << __FUNCTION__;
}

MyLabel::~MyLabel()
{
    qInfo() << __FUNCTION__;
}
