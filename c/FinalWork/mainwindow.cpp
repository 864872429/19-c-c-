#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_login_clicked()
{
    this->login.exec();
}

void MainWindow::on_actionAbout_this_triggered()
{
    QMessageBox::information(this,"关于本系统","作者：\n 卢漫可","666");
}
void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
