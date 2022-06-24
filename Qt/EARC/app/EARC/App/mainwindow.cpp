#include "attendanceaccessor.h"
#include "draganddroplabel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QtConcurrent>

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
    QFutureWatcher<void> futureWatcher;
    QProgressDialog dialog;
    dialog.setWindowTitle(tr("Attendance File Loading"));
    dialog.setLabelText(tr("Loading..."));
    dialog.setRange(0, 0);
    dialog.setCancelButton(nullptr);

    auto builder = new AttendanceAccessor::Builder;
#ifdef USE_ACTIVE_QT
    auto accessor = builder
            ->setBuilderType(AttendanceAccessor::BuilderType::ActiveQt)
            ->setFilePath(filePath)
            ->setSheetNo(1)
            ->setRowStartNo(11)
            ->setRowNum(31)
            ->setColumnStartNo(2)
            ->setColumnNum(7)
            ->create();
#else
    auto accessor = builder
            ->setBuilderType(AttendanceAccessor::BuilderType::Odbc)
            ->setFilePath(filePath)
            ->setSheetName("シート")
            ->setRowStartNo(11)
            ->setColumnNum(7)
            ->create();
#endif //USE_ACTIVE_QT
    delete builder;
    connect(accessor, &AttendanceAccessor::sendAttendanceData,
            this,
            [=](const QList<AttendanceData> &attendanceDataList){
        for (auto data : attendanceDataList) {
            qDebug() << data.toString();
        }
        ui->tabWidget->setCurrentIndex(1);
    });
    connect(accessor, &AttendanceAccessor::readError,
            this,
            [=](const QString &reason){
        qDebug() << "readError:" << reason;
        QMessageBox::warning(this, "EARC", reason);
    });

    connect(&futureWatcher,
            &QFutureWatcher<void>::finished,
            &dialog,
            &QProgressDialog::reset);
    connect(&futureWatcher,
            &QFutureWatcher<void>::finished,
            accessor,
            &AttendanceAccessor::deleteLater);
    connect(&dialog,
            &QProgressDialog::canceled,
            &futureWatcher,
            &QFutureWatcher<void>::canceled);
    connect(&futureWatcher,
            &QFutureWatcher<void>::canceled,
            accessor,
            &AttendanceAccessor::deleteLater);

    std::function<void()> func = [=]() {
        accessor->readCells();
    };
    futureWatcher.setFuture(QtConcurrent::run(func));
    dialog.exec();
    futureWatcher.waitForFinished();
}

