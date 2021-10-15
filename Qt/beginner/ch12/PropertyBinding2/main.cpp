#include <QCoreApplication>

#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person person;
    qInfo() << "before fullName: " << person.fullName();

    QObject::connect(&person, &Person::fullNameChanged,
                     [&](){
        qInfo() << "slot fullName:" << person.fullName();
    });

//    // もしQ_OBJECT_BINDABLE_PROPERTYをpublicにした場合は
//    // 次のような記述できる
//    auto handler = person.b_fullName.onValueChanged([&](){
//        qInfo() << "handler: " << person.b_fullName;
//    });
//    // さらに、std::functionを使用した使い方
//    std::function<void()> fn = [&](){
//        qInfo() << "handler: " << person.b_fullName;
//    };
//    auto handler2 = person.b_fullName.onValueChanged(fn);

    person.firstName = "Hathaway";
    qInfo() << "after1 fullName: " << person.fullName();
    person.lastName = "Noa";
    qInfo() << "after2 fullName: " << person.fullName();

    return a.exec();
}
