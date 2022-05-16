#ifndef EXCELACCESSORODBC_H
#define EXCELACCESSORODBC_H

#include "excelaccessor.h"

struct ExcelAccessorOdbcParam {
    ExcelAccessorOdbcParam(
            const QString &filePath,
            const QString &sheetName,
            int rowStartNo,
            int columnNum)
        : filePath{filePath},
          sheetName{sheetName},
          rowStartNo{rowStartNo},
          columnNum{columnNum}{}

    QString filePath;
    QString sheetName;
    int rowStartNo = 0;
    int columnNum = 0;
};

class ExcelAccessorOdbc : public ExcelAccessor
{
    Q_OBJECT
public:
    explicit ExcelAccessorOdbc(const ExcelAccessorOdbcParam &param, QObject *parent = nullptr);
    void readCells() override;
private:
    QString filePath;
    QString sheetName;
    int rowStartNo = 0;
    int columnNum = 0;
};

#endif // EXCELACCESSORODBC_H
