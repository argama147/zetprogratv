#include "javacaller.h"
#include <QQuickItem>
#include <QAndroidJniObject>

JavaCaller::JavaCaller(QObject *root, QObject *parent) : QObject(parent)
{
    QQuickItem *button = root->findChild<QQuickItem *>("callJavaButton");
    connect(button, SIGNAL(clicked()),
            this, SLOT(callJava()));
}

void JavaCaller::callJava()
{
    QAndroidJniObject::callStaticMethod<void>("com.eugo.example.helloworld/MyClass",
                                       "helloWorld",
                                       "()V");
}
