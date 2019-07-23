/*
机械1804 第7组
组长：
卢漫可
组员：
卢漫可
*/

#include "mainwindow.h"
#include "tesk.h"

void opendatabase();

int main(int argc, char *argv[])
{
    opendatabase();
    cout<<QDir::currentPath();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void opendatabase()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:\\Users\\manke\\Desktop\\management\\mydatabase.db");//平时debug正常用
    //mydb.setDatabaseName(".\\mydatabase.db");//生成exe用
    if(mydb.open())
    {
        cout<<"open success";
    }
    else
    {
        cout<<"open failed";
    }
}
