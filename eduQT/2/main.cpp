#include <QtWidgets>
#include "include/Counter.hpp"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton btn1("Add");
    QLabel lbl("0");
    Counter counter;
    lbl.show();
    btn1.show();

    QObject::connect(&btn1, SIGNAL(clicked()), &counter, SLOT(slotInc()));
    QObject::connect(&counter, SIGNAL(counterChanged(int)), &lbl, SLOT(setNum(int)));
    QObject::connect(&counter, SIGNAL(goodbye()), &app, SLOT(quit()));
    return app.exec();
}