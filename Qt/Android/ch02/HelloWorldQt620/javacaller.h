#ifndef JAVACALLER_H
#define JAVACALLER_H

#include <QObject>

class JavaCaller : public QObject
{
    Q_OBJECT
public:
    explicit JavaCaller(QObject *root, QObject *parent = nullptr);

public slots:
    void callJava();
};

#endif // JAVACALLER_H
