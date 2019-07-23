#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include "tesk.h"

bool opendatabase();

int main(int argc, char *argv[])
{
    opendatabase();
    cout<<QDir::currentPath();
    QApplication a(argc, argv);
    //Login w;
    MainWindow w;
    //Shop w;
    //Donate w;
    w.show();

    return a.exec();
}

bool opendatabase()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:\\mydatabase.db");//平时debug正常用
    //mydb.setDatabaseName("./mydatabase.db");//生成exe用
    if(mydb.open())
    {
        cout<<"open success";
        return true;
    }
    else
    {
        cout<<"open failed";
        return false;
    }
}
