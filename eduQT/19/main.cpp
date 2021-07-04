#include <QtWidgets>
#include "OGLPyramid.hpp"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    OGLPyramid oglPyramid;

    oglPyramid.resize(200, 200);
    oglPyramid.show();

    return app.exec();
}