#include <QObject>

class Store : public QObject {
    Q_OBJECT
public:

    Q_PROPERTY(QString test_state READ testState NOTIFY testStateChanged)
    QString testState();

signals:
    void testStateChanged();
};
