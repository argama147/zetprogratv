#ifndef EXCELACCESSORACTIVEQT_H
#define EXCELACCESSORACTIVEQT_H

#include "excelaccessor.h"

struct ExcelAccessorActiveQtReadParam {
    ExcelAccessorActiveQtReadParam(
            const QString &filePath,
            int sheetNo,
            int rowStartNo,
            int rowNum,
            int columnStartNo,
            int columnNum) :
        filePath{filePath},
        sheetNo{sheetNo},
        rowStartNo{rowStartNo},
        rowNum{rowNum},
        columnStartNo{columnStartNo},
        columnNum{columnNum} {}

    QString filePath;
    int sheetNo;
    int rowStartNo;
    int rowNum;
    int columnStartNo;
    int columnNum;
};

class QAxObject;

class ExcelAccessorActiveQt : public ExcelAccessor
{
    Q_OBJECT
public:
    explicit ExcelAccessorActiveQt(const ExcelAccessorActiveQtReadParam &param, QObject *parent = nullptr);
    ~ExcelAccessorActiveQt();
    void readCells() override;
private:
    QString filePath;
    int sheetNo;
    int rowStartNo;
    int rowNum;
    int columnStartNo;
    int columnNum;

    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *sheet;

    bool open(const QString& filePath, int sheetNo);
    QString readCell(int row, int column);

};

#endif // EXCELACCESSORACTIVEQT_H
