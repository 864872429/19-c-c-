#include "add_problem.h"

Add_problem::Add_problem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_problem)
{
    ui->setupUi(this);
}

Add_problem::~Add_problem()
{
    delete ui;
}

void Add_problem::on_btn_cancel_clicked()
{
    this->close();
}

void Add_problem::on_btn_ok_clicked()
{
    Problem temp;
    temp.problem_num=this->ui->number->text();
    temp.instruction=this->ui->content->text();
    temp.max_num=this->ui->max_num->text();
    switch(judge(temp))
    {
        case 0:QMessageBox::information(this, "成功","添加题目成功","确认");break;
        case 1:QMessageBox::information(this, "失败","添加题目失败：\n""题号请以Q开头并连接四位数字","确认");break;
        case 2:QMessageBox::information(this, "失败","添加题目失败，请检查：\n""输入题目内容呀老铁","确认");break;
        case 3:QMessageBox::information(this, "失败","添加题目失败，请检查：\n""题号请以Q开头并连接四位数字\n""输入题目内容呀老铁","确认");break;
        case 4:QMessageBox::information(this, "失败","添加题目失败，请检查：\n""最大选题是数字","确认");break;
        case 5:QMessageBox::information(this, "失败","添加题目失败，请检查：\n""题号请以Q开头并连接四位数字\n""最大选题是数字","确认");break;
        case 6:QMessageBox::information(this, "失败","添加题目失败，请检查：\n""输入题目内容呀老铁\n""最大选题是数字\n","确认");break;
        case 7:QMessageBox::information(this, "失败","添加题目失败，请检查：\n""题号请以Q开头并连接四位数字\n""输入题目内容呀老铁\n""最大选题是数字","确认");break;
        case 10:QMessageBox::information(this, "失败","题号已存在(被删除题目的题号也不能使用)","确认");break;
   }
}

int Add_problem::judge(Problem &temp)
{
    problem_data=file.get_problem_data();
    int retur=0;
    for(int i=0;i<problem_data.size();i++)
        if(temp.problem_num==problem_data[i].problem_num)
            return 10;
    if(temp.problem_num[0]!='Q'||temp.problem_num.length()!=5)
        retur += 1;
    if(temp.instruction.isEmpty())
        retur += 2;
    if(temp.max_num.isEmpty())
        retur += 4;
    else
        for(int i=0;i<temp.max_num.length();i++)
            if(temp.max_num[i]>'9'||temp.max_num[i]<'0')
            {
                retur += 4;
                break;
            }
    if(!retur)
    {
        temp.status="1";
        temp.current_num="0";
        temp.delete_reason="";
        problem_data.push_back(temp);
        file.set_problem_data(problem_data);
        file.set_problem_data(problem_data);
        this->close();
    }
    return retur;
}
