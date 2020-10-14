#include <QGuiApplication>
#include <QTextEdit>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QDebug>

#include <thread>
#include <string>
#include <vector>
#include <iostream>

#include "store.h"
#include "dispatcher.h"
#include "messageTypes.h"

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

    Dispatcher dispatcher;
    std::vector<std::thread> workers;

    for (int i = 0; i < 5; i++) {
    workers.push_back(std::thread([i, &dispatcher]() 
    {
      for(int j = 0; j < 1000; j++){
        dispatcher.dispatch<messageTypes::TEST_MESSAGE>(std::string("test " + std::to_string(i) + " " + std::to_string(j)));
        dispatcher.dispatch<messageTypes::SILENT_MESSAGE>();
      }
      }));
    }

    if ( component.isReady() )
        component.create();
    else
        qWarning() << component.errorString();
    return app.exec();

}
