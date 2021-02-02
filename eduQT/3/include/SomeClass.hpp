#pragma once

#include <QObject>
#include <QtWidgets>

class SomeClass : public QObject
{
Q_OBJECT
private:
    QLabel *lbl;

public:
    SomeClass();
public slots:
    void slotShowAction(const QString&);
};

