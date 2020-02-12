#include <QObject>

class Store : public QObject {

public:

    Q_PROPERTY(QString test_state READ testState NOTIFY testStateChanged)

    QString test_state();
signals:
    void testStateChanged();
};
