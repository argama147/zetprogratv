#ifndef OBJECT2_H
#define OBJECT2_H

#include <QObject>

class Object2 : public QObject
{
    Q_OBJECT
public:
    explicit Object2(QObject *parent = nullptr);
public slots:
    void receiveData(int data);

};

#endif // OBJECT2_H
