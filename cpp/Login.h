#ifndef LOGIN_H
#define LOGIN_H

#include "tesk.h"
#include "admin.h"
#include "fileoperation.h"
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

signals:
    void send_login(QString,QString );
    void send_login_admin(QString,QString );
private:
    Ui::Login *ui;
    QString id;
    QString name;
    Admin admin;
    QVector<User> student_data;
    QVector<ADMIN> teacher_data;
    Fileoperation file = Fileoperation::getFile();
};

#endif // LOGIN_H
