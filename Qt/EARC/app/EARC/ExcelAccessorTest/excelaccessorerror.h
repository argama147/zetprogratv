#ifndef EXCELACCESSORERROR_H
#define EXCELACCESSORERROR_H

#include <excelaccessor.h>
#include <QObject>

class ExcelAccessorError : public ExcelAccessor
{
    Q_OBJECT
public:
    explicit ExcelAccessorError(QObject *parent = nullptr);
    void readCells() override;
};

#endif // EXCELACCESSORERROR_H
