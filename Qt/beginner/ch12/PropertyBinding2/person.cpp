#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{
    b_fullName.setBinding([&](){
        return firstName.value() + " " + lastName.value();
    });
}

const QString &Person::fullName() const
{
    return b_fullName;
}

void Person::setFullName(const QString &newFullName)
{
    b_fullName = newFullName;
}

QBindable<QString> Person::bindableFullName()
{
    return &b_fullName;
}
