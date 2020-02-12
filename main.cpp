#include <QGuiApplication>
#include <QTextEdit>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QDebug>

int main(int argv, char ** argc){

    QGuiApplication app(argv, argc);
    QQmlEngine engine;
    QQmlComponent component(&engine);
    QQuickWindow::setDefaultAlphaBuffer(true);
    component.loadUrl(QUrl("qrc:///todo.qml"));
    if ( component.isReady() )
        component.create();
    else
        qWarning() << component.errorString();
    return app.exec();

}
