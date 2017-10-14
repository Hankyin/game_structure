#include "mainwindow.h"
#include <QApplication>
#include "QDebug"
#include "unistd.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int pid = getpid();
    qDebug()<<pid<<endl;
    w.show();

    return a.exec();
}
