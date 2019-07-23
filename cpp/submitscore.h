#ifndef SUBMITSCORE_H
#define SUBMITSCORE_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_submitscore.h"

namespace Ui {
class submitScore;
}

class Submitscore :public QDialog
{
    Q_OBJECT
public:
    Submitscore(QWidget *parent = nullptr);
    void set(const int,const int);
    void display();
    ~Submitscore();
private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:

    Ui::submitScore *ui;
    int s_num;
    int r_num;
    Fileoperation file = Fileoperation::getFile();
    QVector<Report> report_data;
    QVector<User> student_data;
    QStandardItemModel *model;
};

#endif // SUBMITSCORE_H
