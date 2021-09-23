#ifndef CHILD_H
#define CHILD_H

#include <QObject>

class Child : public QObject
{
    Q_OBJECT
public:
    explicit Child(QObject *parent = nullptr);
    virtual ~Child();

signals:

};

#endif // CHILD_H
