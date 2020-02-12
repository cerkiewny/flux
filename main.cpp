#include <QGuiApplication>
#include <QTextEdit>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QDebug>
#include <QQmlContext>

#include "store.h"

int main(int argv, char ** argc){

    QGuiApplication app(argv, argc);
    QQmlEngine engine;
    QQmlComponent component(&engine);
    QQuickWindow::setDefaultAlphaBuffer(true);

    Store store;
    engine.rootContext()->setContextProperty("Store", &store);

    component.loadUrl(QUrl("qrc:///todo.qml"));
    if ( component.isReady() )
        component.create();
    else
        qWarning() << component.errorString();
    return app.exec();

}
