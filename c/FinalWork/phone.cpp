#include "phone.h"

Phone::Phone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::phone)
{
    ui->setupUi(this);
}

void Phone::set(const QString& x,const bool b)
{
    id = x;
    level = b;
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    if(level)
    {
        sql="select phone from staff where staff_id =\'"+id+"\'";
        model->setQuery(sql);
    }
    else
    {
        sql="select phone from admin where admin_id =\'"+id+"\'";
        model->setQuery(sql);
    }
    this->ui->label_4->setText(model->index(0,0).data(0).toString());
}



void Phone::on_pushButton_2_clicked()
{
    this->ui->lineEdit->clear();
    this->close();
}

void Phone::on_pushButton_3_clicked()
{
    QString temp=this->ui->lineEdit->text();
    if(temp.length()!=11)
    {
        QMessageBox::information(this, "失败","请输入正确的11位电话号码","确认");
        return;
    }
    if(temp[0]!='1')
    {
        QMessageBox::information(this, "失败","电话号码应该以1开头\n国外用户请管理员","确认");
        return;
    }
    for(int i=0;i<11;i++)
        if(temp[i]<'0'||temp[i]>'9')
        {
            QMessageBox::information(this, "失败","请输入11位数字","确认");
            return;
        }
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    if(level)
    {
        sql="update staff set phone ='"+temp+"' where staff_id='"+id+"'";
        model->setQuery(sql);
    }
    else
    {
        sql="update admin set phone ='"+temp+"' where admin_id='"+id+"'";
        model->setQuery(sql);
    }
    QMessageBox::information(this, "成功","修改电话成功","确认");
    this->ui->label_4->setText(temp);
    this->ui->lineEdit->clear();
}
