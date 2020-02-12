#include <QGuiApplication>
#include <QTextEdit>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QDebug>

#include "store.h"

static QObject* store_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Store *store = new Store();
    return static_cast<QObject*>(store);
}


int main(int argv, char ** argc){

    QGuiApplication app(argv, argc);
    QQmlEngine engine;
    QQmlComponent component(&engine);
    QQuickWindow::setDefaultAlphaBuffer(true);
    Store store;
    qmlRegisterSingletonType<Store>("com.devtato.store", 1, 0, "Store", store_provider);
    component.loadUrl(QUrl("qrc:///todo.qml"));

    if ( component.isReady() )
        component.create();
    else
        qWarning() << component.errorString();
    return app.exec();

}
