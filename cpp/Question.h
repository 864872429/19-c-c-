#ifndef QUESTION_H
#define QUESTION_H

#include "tesk.h"
#include "ui_Question.h"
#include "Fileoperation.h"
#include "add_problem.h"

namespace Ui {
class Question;
}

class Question : public QDialog
{
    Q_OBJECT

public:
    explicit Question(QWidget *parent = nullptr);
    void display(const int row,const Problem&) const;
    void clearall() const;
    void displayall();
    void setGetData(const int = 0);
private slots:
    void on_pushButton_2_clicked();

    void on_btn_query_clicked();

    void on_pushButton_clicked();

    void on_DELET_clicked();

    void on_CHANGE_clicked();

    void on_new_con_clicked();    

    void on_tableView_clicked(const QModelIndex &index);

signals:

private:
    int flag;
    Add_problem add_problem;
    Ui::Question *ui;
    QStandardItemModel *model;
    QVector<User> student_data;
    QVector<Report> report_data;
    QVector<Problem> problem_data;
    Fileoperation file = Fileoperation::getFile();
    QString problem_id;
};

#endif // SHOP_H
