#include "draganddroplabel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "attendanceaccessor.h"

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
        readData(pathList[0]);
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
        readData(files[0]);
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

void MainWindow::readData(const QString &filePath)
{
    auto builder = new AttendanceAccessor::Builder;
    //TODO:ActiveQt用のデファインを追加して切り替えられるようにする
//    auto accessor = builder
//            ->setBuilderType(AttendanceAccessor::BuilderType::ActiveQt)
//            ->setFilePath(filePath)
//            ->setSheetNo(1)
//            ->setRowStartNo(11)
//            ->setRowNum(31)
//            ->setColumnStartNo(2)
//            ->setColumnNum(7)
//            ->create();
    auto accessor = builder
            ->setBuilderType(AttendanceAccessor::BuilderType::Odbc)
            ->setFilePath(filePath)
            ->setSheetName("シート")
            ->setRowStartNo(11)
            ->setColumnNum(7)
            ->create();
    delete builder;
    connect(accessor, &AttendanceAccessor::sendAttendanceData,
            this,
            [=](const QList<AttendanceData> &attendanceDataList){
        for (auto data : attendanceDataList) {
            qDebug() << data.toString();
        }
        delete accessor;
    });
    connect(accessor, &AttendanceAccessor::readError,
            this,
            [=](const QString &reason){
        qDebug() << "readError:" << reason;
        delete accessor;
    });
    accessor->readCells();
}

