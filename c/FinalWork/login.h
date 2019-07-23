#ifndef LOGIN_H
#define LOGIN_H

#include "tesk.h"
#include "admin.h"
#include "staff.h"
#include "ui_login.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_ok_clicked();

private:
    Ui::Login *ui;
    QString id;
    QString name;
    Admin admin;
    Staff staff;
};

#endif // LOGIN_H
