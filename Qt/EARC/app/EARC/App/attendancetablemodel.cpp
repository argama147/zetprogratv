#include "attendancetablemodel.h"
#include <QColor>

AttendanceTableModel::AttendanceTableModel(const QList<AttendanceData> &attendanceDataList, QObject *parent)
    : QAbstractTableModel{parent},
      attendanceDataList{attendanceDataList}
{

}


int AttendanceTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 31;
}

int AttendanceTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant AttendanceTableModel::data(const QModelIndex &index, int role) const
{
    switch(role) {
    case Qt::DisplayRole:
        switch(index.column()) {
        case 0:
            return attendanceDataList.at(index.row()).getDate().toString("M/d");
        case 1:
            return attendanceDataList.at(index.row()).getDayOfWeek();
        case 2:
            return attendanceDataList.at(index.row()).getStartTime().toString("HH:mm");
        case 3:
            return attendanceDataList.at(index.row()).getEndTime().toString("HH:mm");
        case 4:
            return attendanceDataList.at(index.row()).getBreakTime().toString("HH:mm");
        case 5:
            return attendanceDataList.at(index.row()).getContents();
        }
    case Qt::TextAlignmentRole:
        if (index.column() != 5) {
            return Qt::AlignCenter;
        } else {
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        }
    case Qt::BackgroundRole:
    {
        auto dayOfWeek = attendanceDataList.at(index.row()).getDayOfWeek();
        if (dayOfWeek == "土" || dayOfWeek == "日") {
            return QColor(Qt::darkGray);
        } else {
            return QColor(Qt::white);
        }
    }
    case Qt::ForegroundRole:
    {
        auto dayOfWeek = attendanceDataList.at(index.row()).getDayOfWeek();
        if (dayOfWeek == "土" || dayOfWeek == "日") {
            return QColor(Qt::white);
        } else {
            return QColor(Qt::black);
        }
    }
    }
    return QVariant();
}

QVariant AttendanceTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch(section) {
        case 0:
            return tr("Date");
        case 1:
            return tr("DayOfWeek");
        case 2:
            return tr("StartTime");
        case 3:
            return tr("EndTime");
        case 4:
            return tr("BreakTime");
        case 5:
            return tr("Contents");
        }
    }
    return QVariant();
}
