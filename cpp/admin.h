#ifndef ADMIN_H
#define ADMIN_H

#include "tesk.h"
#include "student.h"
#include "Question.h"
#include "ui_admin.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

signals:

private slots:
    void on_btn_quit_clicked();

    void on_btn_add_clicked();

    void on_btn_cancel_donate_clicked();

    void on_btn_look_clicked();

    void on_btn_donate_detail_clicked();

private:
    Ui::Admin *ui;

};

#endif // ADMIN_H
