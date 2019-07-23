#include "login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_cancel_clicked()
{
    this->close();
}

void Login::on_btn_ok_clicked()
{
    student_data=file.get_student_data();
    teacher_data=file.get_teacher_data();
    //QStringList list = cnt.split(" ");

    QString acc = this->ui->le_account->text();
    QString pwd = this->ui->le_pwd->text();
    bool flag = false;
    for(int i = 0;i<teacher_data.size();i++)
    {
        qDebug()<<"teacher_data[i].teacher_num.toLatin1()+teacher_data[i].password.toLatin1()";
        if (acc ==teacher_data[i].teacher_num && pwd == teacher_data[i].password &&teacher_data[i].n!="-1")
        {
            if(pwd=="123")
            {
                QMessageBox::information(this, "成功","登陆成功\n您当前密码为初始密码，建议修改","确认");
                this->ui->le_account->clear();
                this->ui->le_pwd->clear();
                this->admin.show();
                this->hide();
                flag = true;
                admin.exec();
                this->close();
            }
            else
            {
                QMessageBox::information(this, "成功","恭喜你，登陆成功","确认");
                this->ui->le_account->clear();
                this->ui->le_pwd->clear();
                this->admin.show();
                this->hide();
                flag = true;
                admin.exec();
                this->close();
            }
        }
    }
    for(int i = 0;i<student_data.size();i++)
        if (acc ==student_data[i].student_num && pwd == student_data[i].password)
        {
            if(pwd=="123")
            {
                QMessageBox::information(this, "成功","登陆成功\n您当前密码为初始密码，建议修改","确认");
                this->ui->le_account->clear();
                this->ui->le_pwd->clear();
                flag = true;
                emit send_login(acc,student_data[i].name);
                this->close();
            }
            else
            {
                QMessageBox::information(this, "成功","恭喜你，登陆成功","确认");
                this->ui->le_account->clear();
                this->ui->le_pwd->clear();
                flag = true;
                emit send_login(acc,student_data[i].name);
                this->close();
            }
        }
    if (!flag) QMessageBox::information(this,"错误","账户或者密码错误","确认");

}
