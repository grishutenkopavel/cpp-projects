#include <QApplication>
#include "Progress.hpp"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Progress progress;

    progress.show();
    return app.exec();
}