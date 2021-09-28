#ifndef OBJECT1_H
#define OBJECT1_H

#include <QObject>

class Object1 : public QObject
{
    Q_OBJECT
public:
    explicit Object1(QObject *parent = nullptr);
    void act();

signals:
    void sendData(int data);

};

#endif // OBJECT1_H
