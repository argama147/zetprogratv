#include "widget.h"
#include "ui_widget.h"
#include "excelaccessor.h"

#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonFileOpen_clicked()
{
    auto dialog = new QFileDialog(nullptr,
                                  tr("Please Select Excel File"),
                                  QDir::currentPath(),
                                  tr("Excel File (*.xls *.xlsx)"));
    connect(dialog, &QFileDialog::fileSelected,
            this,
            [=](const QString& filePath){
        auto accessor = new ExcelAccessor;
        if (accessor->open(filePath, 1)) {
            qInfo() << "read cell=" << accessor->readCell(1, 1);
        } else {
            qWarning() << "Excel File Open Failed.";
        }
        accessor->deleteLater();
    });
    connect(dialog, &QFileDialog::finished,
            this,
            [=](int result){
        qDebug() << "finished";
        Q_UNUSED(result)
        dialog->deleteLater();
    });
    dialog->exec();
}

