/**
 * @file main.cpp
 * @date Oct 17, 2018
 * @author <b>Ing. Luis Alejandro Reyes Morales.</b>
 *
 * @brief
 *
 * This class implements the main class that show the MainWindow class
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
