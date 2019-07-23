#ifndef SELECTION_H
#define SELECTION_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_selection.h"

namespace Ui {
class selection;
}

class Selection:  public QDialog
{
     Q_OBJECT
public:
    Selection(QWidget *parent = nullptr);
    void set(const QString&);
    void display(const int row,const Problem&);
    void displayall();
    void setGetData(const int = 0);
    int search_problem(QString) const;
    int search_studen(QString) const;
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::selection *ui;
    Fileoperation file = Fileoperation::getFile();
    QVector<Problem> problem_data;
    QVector<Report> report_data;
    QVector<User> student_data;
    QStandardItemModel *model;
    QString student_id;
    QString problem_id;
};

#endif // SELECTION_H
