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
    User temp;
    QString inf = "";
    temp.student_num = this->ui->le_acc->text();
    temp.name = this->ui->le_pwd->text();
    temp.CLASS = this->ui->le_name->text();
    switch (judge(temp))
    {
    case 0:QMessageBox::information(this, "成功","添加账户成功","确认");break;
    case 1:QMessageBox::information(this, "失败","添加账户失败，请检查：：\n""学号请以S开头并连接四位数字","确认");break;
    case 2:QMessageBox::information(this, "失败","添加账户失败，请检查：\n""输入名字呀老铁","确认");break;
    case 3:QMessageBox::information(this, "失败","添加账户失败，请检查：\n""学号请以S开头并连接四位数字\n""输入名字呀老铁","确认");break;
    case 4:QMessageBox::information(this, "失败","添加账户失败，请检查：\n""班级是四位数字","确认");break;
    case 5:QMessageBox::information(this, "失败","添加账户失败，请检查：\n""学号请以S开头并连接四位数字\n""班级是四位数字","确认");break;
    case 6:QMessageBox::information(this, "失败","添加账户失败，请检查：\n""输入名字呀老铁\n""班级是四位数字\n","确认");break;
    case 7:QMessageBox::information(this, "失败","添加账户失败，请检查：\n""学号请以S开头并连接四位数字\n""输入名字呀老铁\n""班级是四位数字","确认");break;
    case 10:QMessageBox::information(this, "失败","账号已存在(被删除学生的学号也不能使用)","确认");break;
    }
}

int Add_person::judge(User &temp)
{
    student_data=file.get_student_data();
    int retur=0;
    if(temp.student_num[0]!='S'||temp.student_num.length()!=5)
        retur += 1;
    if(temp.name.isEmpty())
        retur += 2;
    if(temp.CLASS.length()!=4||               //验证电话是四位数字
       temp.CLASS[0]>'9'||temp.CLASS[0]<'0'||temp.CLASS[1]>'9'||temp.CLASS[1]<'0'||
       temp.CLASS[2]>'9'||temp.CLASS[2]<'0'||temp.CLASS[3]>'9'||temp.CLASS[3]<'0')
        retur += 4;
    for(int i=0;i<student_data.size();i++)
        if(temp.student_num==student_data[i].student_num)
            return 10;
    if(!retur)
    {
        temp.n="1";
        temp.phone="";
        temp.password="123";
        temp.score="";
        student_data.push_back(temp);
        file.set_student_data(student_data);
    }
    return retur;
}
