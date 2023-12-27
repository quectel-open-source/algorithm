#include "projectClass.h"
#include "QtToolTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtToolTest w;
    w.show();
    return a.exec();
}
