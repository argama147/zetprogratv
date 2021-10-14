#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

const QString &MyObject::message() const
{
    return m_message;
}

void MyObject::setMessage(const QString &newMessage)
{
    if (m_message == newMessage)
        return;
    m_message = newMessage;
    emit messageChanged(m_message);
}
