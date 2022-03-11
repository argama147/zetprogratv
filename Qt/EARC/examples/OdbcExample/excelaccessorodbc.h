#ifndef EXCELACCESSORODBC_H
#define EXCELACCESSORODBC_H

#include <QObject>

class ExcelAccessorODBC : public QObject
{
    Q_OBJECT
public:
    explicit ExcelAccessorODBC(QObject *parent = nullptr);
    bool read(const QString filePath, const QString sheetName, QList<QList<QString>> &list);
};

#endif // EXCELACCESSORODBC_H
