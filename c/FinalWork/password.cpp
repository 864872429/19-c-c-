#include "password.h"

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

void Password::on_pushButton_2_clicked()
{
    this->close();
}

void Password::set(const QString& x,const bool b)
{
    id = x;
    level = b;
}

void Password::on_pushButton_clicked()
{
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
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    if(level)
    {
        sql="select password from staff where staff_id =\'"+id+"\'";
        model->setQuery(sql);
    }
    else
    {
        sql="select password from admin where admin_id =\'"+id+"\'";
        model->setQuery(sql);
    }
    if(old!=model->index(0,0).data(0).toString())
    {
        QMessageBox::information(this, "失败","密码输入错误","确认");
        return;
    }
    if(level)
    {
        sql="update staff set password ='"+new_1+"' where staff_id='"+id+"'";
        model->setQuery(sql);
    }
    else
    {
        sql="update admin set password ='"+new_1+"' where admin_id='"+id+"'";
        model->setQuery(sql);
    }
    QMessageBox::information(this, "成功","密码修改成功","确认");
}
