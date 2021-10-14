#ifndef MYCOLOR_H
#define MYCOLOR_H

#include <QObject>
#include <QColor>

class MyColor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)
public:
    explicit MyColor(QObject *parent = nullptr);
public slots:
    void changeColor();

signals:
    void colorChanged(QColor color);

private:
    QColor m_color;
};

#endif // MYCOLOR_H
