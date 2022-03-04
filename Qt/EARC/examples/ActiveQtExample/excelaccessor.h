#ifndef EXCELACCESSOR_H
#define EXCELACCESSOR_H

#include <QObject>

class QAxObject;

class ExcelAccessor : public QObject
{
    Q_OBJECT
public:
    explicit ExcelAccessor(QObject *parent = nullptr);
    ~ExcelAccessor();
    bool open(const QString& filePath, int sheetNo);
    QString readCell(int row, int column);

private:
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *sheet;
};

#endif // EXCELACCESSOR_H
