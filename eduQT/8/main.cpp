#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton* pcmd1 = new QPushButton("A");
    QPushButton* pcmd2 = new QPushButton("B");
    QPushButton* pcmd3 = new QPushButton("C");

    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addWidget(pcmd1, 1);
    pbxLayout->addWidget(pcmd2, 2);
    pbxLayout->addWidget(pcmd3, 3);
    wgt.setLayout(pbxLayout);
    wgt.resize(450, 40);
    wgt.show();
    
    return app.exec();
}