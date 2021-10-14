#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit MyObject(QObject *parent = nullptr);
    const QString &message() const;
    void setMessage(const QString &newMessage);

signals:
    void messageChanged(QString message);

private:
    QString m_message;
};

#endif // MYOBJECT_H
