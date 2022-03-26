#include "draganddroplabel.h"

#include <QDropEvent>
#include <QMimeData>

DragAndDropLabel::DragAndDropLabel(QWidget *parent)
    : QLabel(parent)
{
    setAcceptDrops(true);
}


void DragAndDropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    Q_ASSERT(event);
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void DragAndDropLabel::dropEvent(QDropEvent *event)
{
    Q_ASSERT(event);
    QStringList pathList;
    for (auto &url : event->mimeData()->urls()) {
        pathList << url.toLocalFile();
    }
    emit sendFilePathList(pathList);
    setText(pathList.join("\n"));
}
