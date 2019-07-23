#include "password.h"

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
    student_data=file.get_student_data();
}

void Password::on_pushButton_2_clicked()
{
    this->close();
}

void Password::set(const QString& x)
{
    id=x;    
}

int Password::search_studen(const QString &x) const
{
    for (int i = 0; i < student_data.size(); i++)
        if (student_data[i].student_num==x&& student_data[i].n!="0")
            return i;
    return -1;
}

void Password::on_pushButton_clicked()
{
    int i=search_studen(id);
    QString old=this->ui->lineEdit->text();
    QString new_1=this->ui->lineEdit_2->text();
    QString new_2=this->ui->lineEdit_3->text();
    if(new_2!=new_1)
    {
        QMessageBox::information(this, "失败","两次密码不一样","确认");
        return;
    }
    if(new_1.isEmpty())
    {
        QMessageBox::information(this, "失败","请输入密码","确认");
        return;
    }

    if(old!=student_data[i].password)
    {
        QMessageBox::information(this, "失败","密码输入错误","确认");
        return;
    }
    student_data[i].password=new_1;
    file.set_student_data(student_data);
    QMessageBox::information(this, "成功","密码修改成功","确认");
}
