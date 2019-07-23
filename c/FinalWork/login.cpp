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
       bool flag = 1;
       QString sql;
       QModelIndex index;
       QString acc = this->ui->le_account->text();
       QString pwd = this->ui->le_pwd->text();
       QSqlQueryModel *model=new QSqlQueryModel;
       sql="select count (*) from admin where admin_id =\'"+acc+"\'";
       model->setQuery(sql);
       index=model->index(0,0);
       sql="select password from admin where admin_id =\'"+acc+"\'";
       model->setQuery(sql);
       {
           if(index.data()!=0&&pwd==model->index(0,0).data())
           {
               flag  = 0;
               if(pwd=="123")
                   QMessageBox::information(this, "成功","管理员登陆成功\n您当前密码为初始密码，建议修改","确认");
               else
                   QMessageBox::information(this, "成功","管理员登陆成功\n","确认");
               this->ui->le_account->clear();
               this->ui->le_pwd->clear();
               admin.set(acc);//将登陆的学生信息读取出来
               admin.show();
               this->close();
           }
       }
       sql="select count (*) from staff where staff_id=\'"+acc+"\'";
       model->setQuery(sql);
       index=model->index(0,0);
       sql="select password from staff where staff_id =\'"+acc+"\'";
       model->setQuery(sql);
       if(index.data()!=0&&pwd==model->index(0,0).data())
       {
           flag  = 0;
           if(pwd=="123")
               QMessageBox::information(this, "成功","员工登陆成功\n您当前密码为初始密码，建议修改","确认");
           else
               QMessageBox::information(this, "成功","员工登陆成功\n","确认");
           this->ui->le_account->clear();
           this->ui->le_pwd->clear();
           staff.set(acc);//将登陆的学生信息读取出来
           staff.show();
           this->close();
       }
       if(flag)
            QMessageBox::information(this,"错误","账户或者密码错误","确认");
}
