#include "charts.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    charts c;
    c.show();
    return a.exec();
}

