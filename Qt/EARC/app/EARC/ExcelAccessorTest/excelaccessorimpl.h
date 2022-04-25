#ifndef EXCELACCESSORIMPL_H
#define EXCELACCESSORIMPL_H

#include <excelaccessor.h>
#include <QObject>

class ExcelAccessorImpl : public ExcelAccessor
{
    Q_OBJECT
public:
    explicit ExcelAccessorImpl(QObject *parent = nullptr);
    void readCells() override;
};

#endif // EXCELACCESSORIMPL_H
