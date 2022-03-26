#ifndef DRAGANDDROPLABEL_H
#define DRAGANDDROPLABEL_H

#include <QLabel>

class DragAndDropLabel : public QLabel
{
    Q_OBJECT
public:
    DragAndDropLabel(QWidget *parent = nullptr);
signals:
    void sendFilePathList(const QStringList &pathList);
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // DRAGANDDROPLABEL_H
