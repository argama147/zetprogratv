#include <QCoreApplication>

#include "parent.h"
#include "child.h"

bool isParent(QObject &obj) {
    qInfo() << &obj;
    qInfo() << obj.objectName();
    return obj.objectName() == "parent";
}

//Error
//bool isParent(QObject obj) {
//    qInfo() << &obj;
//    qInfo() << obj.objectName();
//    return obj.objectName() == "parent";
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parent *parent = new Parent(&a);
    parent->setObjectName("parent");
    Child *child = new Child(parent);
    child->setObjectName("child");

    qInfo() << "isParent(*parent):" << isParent(*parent);
    qInfo() << "isParent(*child):" << isParent(*child);

    QObject obj1;
    QObject obj2;
    //Error
    //obj2 = obj1;

    return a.exec();
}
