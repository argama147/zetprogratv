#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{
    fullName.setBinding([&](){
        return firstName.value() + " " + lastName.value();
    });
}
