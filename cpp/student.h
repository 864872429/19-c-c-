#ifndef STUDENT_H
#define STUDENT_H

#include "tesk.h"
#include "fileoperation.h"
#include "add_person.h"
#include "ui_Student.h"
#include "submitscore.h"

namespace Ui {
class Student;
}

class Student : public QDialog
{
    Q_OBJECT
public:
    explicit Student(QWidget *parent = nullptr);
    void display(const int, const User&) const;
    void clearall() const;
    void displayall();
    void setGetData(const int = 0);
    int search_report(const QString&) const; //根据学生用户名返回选题在二维数组的位置
    int search_studen(const QString&) const;
    int search_problem(const QString&) const;

signals:

public slots:

private slots:

    void on_pushButton_clicked();

    void on_btn_query_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:

    Ui::Student *ui;
    QStandardItemModel *model;
    QVector<User> student_data;
    QVector<Report> report_data;
    QVector<Problem> problem_data;
    Fileoperation file = Fileoperation::getFile();
    QString student_id;
};

#endif // STUDENT_H
