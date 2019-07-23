#include "add_person.h"

Add_person::Add_person(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_person)
{
    ui->setupUi(this);
}

Add_person::~Add_person()
{
    delete ui;
}

void Add_person::on_btn_cancel_clicked()
{
    this->close();
}

void Add_person::on_btn_ok_clicked()
{
    QString staff_id,name,sql;
    int salary,allowance,insurance;
    QSqlQueryModel model;
    staff_id = this->ui->id_acc->text();
    if(staff_id.length()==0)
    {
        QMessageBox::information(this,"提示","请输入员工ID呀老铁","确认");
        return;
    }
    else if(staff_id[0]!='S'||staff_id.length()!=5)
    {
        QMessageBox::information(this,"提示","学号请以S开头并连接四位数字\n","确认");
        return;
    }
    else
    {
        QSqlQueryModel model2;
        model.setQuery("select count (*) from staff");
        for(int i=0;i<model.index(0,0).data().toInt();i++)
        {
           model2.setQuery("select staff_id from staff");
            if(model2.index(i,0).data().toString()==staff_id)
            {
                QMessageBox::information(this,"提示","改员工已存在\n","确认");
                return;
            }

        }
    }
    name= this->ui->name_acc->text();
    if(name.length()==0)
    {
        QMessageBox::information(this,"提示","请输入员工姓名呀老铁","确认");
        return;
    }
    bool ok;
    salary = this->ui->salary->text().toInt(&ok);
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
    allowance = this->ui->allowance->text().toInt(&ok);
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
    insurance = this->ui->lineEdit_2->text().toInt(&ok);
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
    sql="insert into staff values ('"+staff_id+"','123','"+name+"',null,"+QString::number(salary)+","+QString::number(allowance)+","+QString::number(insurance)+");";
    model.setQuery(sql);
    if (model.lastError().isValid())
          cout<< model.lastError();
    QMessageBox::information(this,"提示","添加成功","确认");
}































