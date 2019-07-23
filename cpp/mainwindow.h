#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tesk.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "login.h"
#include "Question.h"
#include "form.h"
#include "selection.h"
#include "report.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int search_studen(const QString&) const;
    int search_report(const QString&) const;
    void setGetData(const int = 0);
private slots:
    void on_btn_login_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();   

    void loginit(QString,QString);

    void on_actionAbout_this_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Fileoperation file = Fileoperation::getFile();
    QVector<User> student_data;
    QVector<Report> report_data;
    QVector<Problem> problem_data;
    Ui::MainWindow *ui;
    Login login;
    QString name;
    QString id;

};

#endif // MAINWINDOW_H
