#include "draganddroplabel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->labelGetFilePath, &DragAndDropLabel::sendFilePathList,
            this, [=](const QStringList &pathList){
        qDebug() << "pathList=" << pathList;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFileOpen_clicked()
{
    auto dialog = new QFileDialog(nullptr,
                                  tr("Please Select Excel Files"),
                                  QDir::currentPath(),
                                  tr("Excel File (*.xls *.xlsx)"));
    dialog->setFileMode(QFileDialog::ExistingFiles);
    connect(dialog, &QFileDialog::filesSelected,
            this,
            [=](const QStringList &files){
        qDebug() << "files=" << files;
        ui->labelGetFilePath->setText(files.join("\n"));
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

