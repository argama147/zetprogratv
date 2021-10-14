#include "mycolor.h"

#include <QRandomGenerator>
#include <QDebug>

MyColor::MyColor(QObject *parent) : QObject(parent)
{

}

void MyColor::changeColor()
{
    int r = QRandomGenerator::global()->bounded(0, 255);
    int g = QRandomGenerator::global()->bounded(0, 255);
    int b = QRandomGenerator::global()->bounded(0, 255);
    qInfo() << "RGB : " << r << g << b;
    m_color = QColor(r, g, b);
    emit colorChanged(m_color);
}
