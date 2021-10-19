#include <QCoreApplication>
#include <QDebug>
#include <QLocale>
#include <QTranslator>

#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    qInfo() << "uiLanguages=" << uiLanguages;
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TranslateConsole_" + QLocale(locale).name();
        qInfo() << "locale=" << locale;
        qInfo() << "baseName=" << baseName;
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            qInfo() << "installTranslator : " << baseName;
            break;
        }
    }

    MyObject obj;
    obj.hello();

    return a.exec();
}
