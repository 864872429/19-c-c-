#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tesk.h"
#include "ui_mainwindow.h"
#include "login.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btn_login_clicked();

    void on_actionAbout_this_triggered();

    void on_actionAbout_Qt_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Login login;

};

#endif // MAINWINDOW_H
