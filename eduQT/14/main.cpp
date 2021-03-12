#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QSplitter spl(Qt::Vertical);
    QTextEdit *ptxt1 = new QTextEdit;
    QTextEdit *ptxt2 = new QTextEdit;
    spl.addWidget(ptxt1);
    spl.addWidget(ptxt2);

    ptxt1->setPlainText("Line 1\n"
                        "Line 2\n"
                        "Line 3\n"
                        "Line 4\n"
                        "Line 5\n"
                        "Line 6\n"
                        "Line 7\n");
    ptxt2->setPlainText(ptxt1->toPlainText());
    spl.resize(200, 220);
    spl.show();
    return app.exec();
}