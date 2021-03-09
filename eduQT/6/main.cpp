#include <QtWidgets>

int main(int argc, char** argw)
{
    QApplication app(argc, argw);
    QWidget wgt;
    QPixmap pix(":/clock.png");
    QCursor cur(pix);

    wgt.setCursor(cur);
    wgt.resize(180, 180);
    wgt.show();
    return app.exec();
}