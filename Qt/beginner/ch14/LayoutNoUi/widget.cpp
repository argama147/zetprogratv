#include "widget.h"
#include "mylabel.h"

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(new MyLabel("label1"));
    hlayout->addWidget(new QLineEdit);

    QHBoxLayout *hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(new QLabel("label2"));
    hlayout2->addWidget(new QLineEdit);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayout);
    vlayout->addLayout(hlayout2);

    setLayout(vlayout);
}

Widget::~Widget()
{
}

