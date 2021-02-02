#include "include/SomeClass.hpp"
#include <iostream>
SomeClass::SomeClass()
    :
    QObject()
{
    lbl = new QLabel("clickIngo");
    lbl->show();

    QSignalMapper *psigMapper = new QSignalMapper();
    connect(psigMapper, SIGNAL(mapped(const QString&)), 
            this, SLOT(slotShowAction(const QString&)));

    QPushButton* btn1 = new QPushButton("Button 1");
    connect(btn1, SIGNAL(clicked()), psigMapper, SLOT(map()));
    psigMapper->setMapping(btn1, "Button 1 was clicked");
    btn1->show();

    QPushButton* btn2 = new QPushButton("Button 2");
    connect(btn2, SIGNAL(clicked()), psigMapper, SLOT(map()));
    psigMapper->setMapping(btn2, "Button 2 was clicked");
    btn2->show();
}
void SomeClass::slotShowAction(const QString& clickIngo)
{
    lbl->setText(clickIngo);
}