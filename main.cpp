

#include <QtGui>
#include <QtCore>


#include "mainwindow.h"

#include <iostream>
#include <random>
#include <ctime>


#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*double mas[1000];
    memset((void*)mas,0.0,1000 * sizeof(double));
    srand(time(0));
    for(int i = 0; i < 1000; i++) {
        double a1 = (rand() % 10057) / 10057.0;
        double a2 = (rand() % 10057) / 10057.0;
        double V1 = 2 * a1 - 1;
        double V2 = 2 * a2 - 1;
        double S = V1 * V1 + V2 * V2;
        if(S >= 1) {
            i--;
            continue;
        }
        else {
            mas[i] = V1 * sqrt((-2 * log(S)) / S);
            mas[i + 1] = V2 * sqrt((-2 * log(S)) / S);
            i++;
        }
    }
    double b = 0.0;
    b = cos(45);*/
    return a.exec();
}
