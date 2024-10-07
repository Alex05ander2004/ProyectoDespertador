#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "despertador.h"
#include <QQmlComponent>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Registrar el tipo Despertador para QML
    qmlRegisterType<Despertador>("Despertador", 1, 0, "Despertador");

    QQmlApplicationEngine engine;

    // Cargar el archivo QML
    engine.load(QUrl(QStringLiteral("qrc:/Screen01.ui.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
