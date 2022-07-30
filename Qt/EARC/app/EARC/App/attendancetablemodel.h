#ifndef ATTENDANCETABLEMODEL_H
#define ATTENDANCETABLEMODEL_H

#include "attendancedata.h"
#include <QAbstractTableModel>

class AttendanceTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit AttendanceTableModel(const QList<AttendanceData> &attendanceDataList, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    const QList<AttendanceData> attendanceDataList;
};

#endif // ATTENDANCETABLEMODEL_H
