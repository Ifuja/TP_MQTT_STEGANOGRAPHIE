#include "mainwindow.h"

#include <QApplication>
#include <limits>
#include <qmqttclient.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
