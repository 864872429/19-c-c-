#ifndef STUDENT_H
#define STUDENT_H

#include "tesk.h"
#include "add_person.h"
#include "ui_managemen.h"
#include "change_person.h"

namespace Ui {
class managemen;
}

class Managemen : public QDialog
{
    Q_OBJECT
public:
    explicit Managemen(QWidget *parent = nullptr);
    void displayall();
    void setGetData(const int = 0);
    int search_report(QString) const; //根据学生用户名返回选题在二维数组的位置
    int search_studen(QString) const;

signals:

public slots:

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void find();
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_comboBox_activated();

    void on_btn_query_clicked();

    void on_pushButton_4_clicked();

private:

    QString this_staff_id;
    Ui::managemen *ui;
    QStandardItemModel *model;
    QString this_staff_name;
    Change_person change_person;
};

#endif // STUDENT_H
