#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Распознавание математических формул");
//    w.resize(500, 900);
    QIcon winIcon("карандаш.png");
    w.setWindowIcon(winIcon);
    w.show();

    return a.exec();
}
