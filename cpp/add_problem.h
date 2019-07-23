#ifndef ADD_PROBLEM_H
#define ADD_PROBLEM_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_add_problem.h"

namespace Ui {
class Add_problem;
}

class Add_problem : public QDialog
{
    Q_OBJECT

public:
    explicit Add_problem(QWidget *parent = nullptr);
    int judge(Problem&);
    ~Add_problem();

public slots:

private slots:
    void on_btn_cancel_clicked();

    void on_btn_ok_clicked();

private:
    Ui::Add_problem *ui;
    Fileoperation file = Fileoperation::getFile();
    QVector<Problem> problem_data;
};

#endif // ADD_PROBLEM_H
