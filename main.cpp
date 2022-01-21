#include "mainwindow.h"
#include "loginwindow.h"
#include "database.h"
#include <QApplication>
#include<QObject>
#include "database.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Database registerUser;
    w.showNormal();
    registerUser.create_database("users");
    return a.exec();
}
