#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ボタンが押されたら色を変更
    connect(ui->pushButton, &QPushButton::clicked,
            &color, &MyColor::changeColor);

    // 色が変更されたら背景色を変更
    connect(&color, &MyColor::colorChanged,
            [=](QColor color){
        QPalette pal(palette());
        pal.setColor(QPalette::Window, color);
        setAutoFillBackground(true);
        setPalette(pal);
    });
}

Widget::~Widget()
{
    delete ui;
}

