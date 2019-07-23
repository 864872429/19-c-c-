#include "phone.h"

Phone::Phone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::phone)
{
    ui->setupUi(this);
    student_data=file.get_student_data();
}

void Phone::set(const QString& x)
{
    id=x;
    this->ui->label_4->setText(student_data[search_studen(id)].phone);
}

int Phone::search_studen(const QString &x) const
{
    for (int i = 0; i < student_data.size(); i++)
        if (student_data[i].student_num==x&& student_data[i].n!="0")
            return i;
    return -1;
}

void Phone::on_pushButton_2_clicked()
{
    this->ui->label_4->setText("");
    this->close();
}

void Phone::on_pushButton_3_clicked()
{
    QString temp=this->ui->lineEdit->text();
    if(temp.isEmpty())
    {
        QMessageBox::information(this, "失败","请输入新电话","确认");
        return;
    }
    if(temp.length()!=11)
    {
        QMessageBox::information(this, "失败","请输入正确的11位电话号码","确认");
        return;
    }
    if(temp[0]!='1')
    {
        QMessageBox::information(this, "失败","电话号码应该以1开头\n国外用户请联系辅导员","确认");
        return;
    }
    for(int i=0;i<11;i++)
        if(temp[i]<'0'||temp[i]>'9')
        {
            QMessageBox::information(this, "失败","请输入11位数字","确认");
            return;
        }
    student_data[search_studen(id)].phone=temp;
    file.set_student_data(student_data);
    QMessageBox::information(this, "成功","修改电话成功","确认");
    this->ui->label_4->setText(student_data[search_studen(id)].phone);
    this->ui->lineEdit->clear();
}
