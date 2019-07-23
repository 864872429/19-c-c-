#include "change_person.h"

Change_person::Change_person(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change_person)
{
    ui->setupUi(this);
}

Change_person::~Change_person()
{
    delete ui;
}

void Change_person::on_pushButton_exit_clicked()
{
    close();
}

void Change_person::on_pushButton_enter_clicked()
{
    QString sql,phone,password;
    int salary,allowance,insurance;
    bool ok;
    phone=ui->lineEdit_phone->text();
    if(phone.length()!=11)
    {
        QMessageBox::information(this, "失败","请输入正确的11位电话号码","确认");
        return;
    }
    if(phone[0]!='1')
    {
        QMessageBox::information(this, "失败","电话号码应该以1开头\n","确认");
        return;
    }
    password = ui->lineEdit_password->text();
    salary = ui->lineEdit_salary->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::information(this,"提示","基本工资只能是数字","确认");
        return;
    }
    if(!salary)
    {
        QMessageBox::information(this,"提示","请输入基本工资呀老铁","确认");
        return;
    }
    allowance=ui->lineEdit_allowance->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::information(this,"提示","岗位津贴只能是数字","确认");
        return;
    }
    if(!allowance)
    {
        QMessageBox::information(this,"提示","请输入岗位津贴呀老铁","确认");
        return;
    }
    insurance=ui->lineEdit_insurance->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::information(this,"提示","医疗保险只能是数字","确认");
        return;
    }
    if(!insurance)
    {
        QMessageBox::information(this,"提示","请输入医疗保险呀老铁","确认");
        return;
    }
    QSqlQueryModel *model=new QSqlQueryModel;
    sql="update staff set password ='"+password+"',phone='"+phone+"',salary="+QString::number(salary)+",allowance="+ QString::number(allowance)+",insurance="+QString::number(insurance)+" where staff_id='"+this_staff_id+"'";
    model->setQuery(sql);
    cout<<sql;
    if (model->lastError().isValid())
          cout<< model->lastError();
    QMessageBox::about(nullptr,"提示","系统信息修改成功");


}

void Change_person::set(const QString &x)
{
    QString sql;
    this_staff_id = x;
    QSqlQueryModel *model=new QSqlQueryModel;
    sql ="select *from staff where staff_id = '"+this_staff_id+"'";
    model->setQuery(sql);
    this->ui->label_name->setText(model->index(0,2).data(0).toString());
    this->ui->lineEdit_phone->setText(model->index(0,3).data(0).toString());
    this->ui->label_id->setText(this_staff_id);
    this->ui->lineEdit_salary->setText(model->index(0,4).data(0).toString());
    this->ui->lineEdit_allowance->setText(model->index(0,5).data(0).toString());
    this->ui->lineEdit_insurance->setText(model->index(0,6).data(0).toString());
    this->ui->lineEdit_password->setText(model->index(0,1).data(0).toString());
}
