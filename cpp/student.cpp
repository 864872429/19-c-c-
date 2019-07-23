#include "student.h"

Student::Student(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::Student)
{
    ui->setupUi(this);
    this->model = new QStandardItemModel;
    this->model->setHorizontalHeaderItem(0, new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("状态"));
    this->model->setHorizontalHeaderItem(3, new QStandardItem("选题"));
    this->model->setHorizontalHeaderItem(4, new QStandardItem("得分"));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setColumnWidth(0,140);
    this->ui->tableView->setColumnWidth(1,140);
    this->ui->tableView->setColumnWidth(2,180);
    this->ui->tableView->setColumnWidth(3,140);
    this->ui->tableView->setColumnWidth(4,140);
    displayall();
}

void Student::displayall()
{
    clearall();
    clearall();
    clearall();
    setGetData(0);
    int m = 0;
    for(int i=0;i<student_data.size();i++)
    {
        if(student_data[i].n=="1")
                display(m++,student_data[i]);
    }
    cout<<m;
    this->ui->tableView->setColumnWidth(0,140);
    this->ui->tableView->setColumnWidth(1,140);
    this->ui->tableView->setColumnWidth(2,180);
    this->ui->tableView->setColumnWidth(3,140);
    this->ui->tableView->setColumnWidth(4,140);
}

void Student::display(const int row, const User& x)const
{
        QString a=x.student_num;
        QString b=x.name;
        QString c;
        QString e=x.score;
        QString d;
        int n =search_report(x.student_num);
        if(n!=-1)
            c=report_data[n].status;
         n =search_report(x.student_num);
        if(n!=-1)
            if(report_data[n].status!="-4"&&report_data[n].status!="-5")
                d=x.topic;
        this->model->setItem(row, 0,new QStandardItem(a));
        this->model->item(row,0)->setTextAlignment(Qt::AlignCenter);
        this->model->setItem(row, 1,new QStandardItem(b));
        this->model->item(row,1)->setTextAlignment(Qt::AlignCenter);
        if(c == "-2")   this->model->setItem(row, 2,new QStandardItem("选题未通过"));
        else if(c == "-1")  this->model->setItem(row, 2,new QStandardItem("选题待审核"));
        else if(c == "0")   this->model->setItem(row, 2,new QStandardItem("待提交报告"));
        else if(c == "1")   this->model->setItem(row, 2,new QStandardItem("报告已提交，待录入成绩"));
        else if(c == "2")   this->model->setItem(row, 2,new QStandardItem("测试已结束"));
        else this->model->setItem(row, 2,new QStandardItem("未选题或选题被删除"));
        this->model->item(row,2)->setTextAlignment(Qt::AlignCenter);
        this->model->setItem(row, 3,new QStandardItem(d));
        this->model->item(row,3)->setTextAlignment(Qt::AlignCenter);
        this->model->setItem(row, 4,new QStandardItem(e));
        this->model->item(row,4)->setTextAlignment(Qt::AlignCenter);
}

void Student::setGetData(const int x)//0-read,1-write
{
    if(x)
    {
        file.set_student_data(student_data);
        file.set_report_data(report_data);
        file.set_problem_data(problem_data);
    }
    else
    {
        student_data=file.get_student_data();
        report_data=file.get_report_data();
        problem_data=file.get_problem_data();
    }
}

void Student::on_pushButton_clicked()
{
    Add_person add_person;
    add_person.show();
    add_person.exec();
    displayall();
}

int Student::search_report(const QString& x) const
{
    for (int i = 0; i < report_data.size(); i++)
        if (report_data[i].student_num== x&& report_data[i].status!="5")
            return i;
    return -1;
}

int Student::search_studen(const QString& x) const
{
    for (int i = 0; i < student_data.size(); i++)
        if (student_data[i].student_num==x&& student_data[i].n!="0")
            return i;
    return -1;
}

void Student::clearall() const
{
    for(int i = 0;i<student_data.size();i++)
        this->model->removeRow(i);

}

void Student::on_btn_query_clicked()
{
    clearall();

    setGetData();
    QString content = this->ui->le_content->text();
    int index = this->ui->comboBox->currentIndex();
    int row = 0;
    for(int i=0;i<student_data.size();i++)
    {
        if(student_data[i].n=="1")
        {
            switch(index)
            {
            case 0:
                if(student_data[i].student_num == content)
                    display(row++,student_data[i]);
                break;
            case 1:
                if(student_data[i].name == content)
                {
                    display(row++,student_data[i]);
                }
                break;
            case 2:
            {
                if(search_report(student_data[i].student_num)==-1)
                {
                           if(content=="未选题或选题被删除")
                               display(row++,student_data[i]);
                    }
                    else
                    {
                        if(content=="选题未通过")
                        {
                            if(report_data[search_report(student_data[i].student_num)].status=="-2")
                                display(row++,student_data[i]);
                    }
                    else if(content=="选题待审核")
                    {
                        if(report_data[search_report(student_data[i].student_num)].status=="-1")
                            display(row++,student_data[i]);
                    }
                    else if(content=="待提交报告")
                    {
                        if(report_data[search_report(student_data[i].student_num)].status=="0")
                            display(row++,student_data[i]);
                    }
                    else if(content=="报告已提交，待录入成绩")
                    {
                        if(report_data[search_report(student_data[i].student_num)].status=="1")
                            display(row++,student_data[i]);
                    }
                    else if(content=="未选题或选题被删除")
                        if(report_data[search_report(student_data[i].student_num)].status!="-2"&&
                           report_data[search_report(student_data[i].student_num)].status!="-1"&&
                           report_data[search_report(student_data[i].student_num)].status!="0"&&
                           report_data[search_report(student_data[i].student_num)].status!="1")
                                display(row++,student_data[i]);
                }
            }
                break;
            case 3:
                if(student_data[i].score == content)
                {
                    display(row++,student_data[i]);
                }
            break;
            case 4:
                if(student_data[i].topic == content)
                {
                   display(row++,student_data[i]);
                 }
            }
        }
    }
    if (row == 0)
    {
        QMessageBox::information(this,"错误","查询不到符合要求的学生","确认");
        displayall();
        return;
    }
}

void Student::on_pushButton_2_clicked()
{
    this->close();
}

void Student::on_pushButton_3_clicked()
{
    int i=search_studen(student_id);
    if(i==-1)
    {
        QMessageBox::information(this, "失败","没找到@_@","确认");
        displayall();
        return;
    }
    student_data[i].n="0";
    setGetData(1);
    QMessageBox::information(this, "成功","成功^_^","确认");
    displayall();
}

int Student::search_problem(const QString& x) const
{
    for (int i = 0; i < problem_data.size(); i++)
        if (problem_data[i].problem_num==x&& (problem_data[i].status!="0"||problem_data[i].status!="-1"))
            return i;
    return -1;
}

void Student::on_pushButton_5_clicked()
{
    for (int i = 0; i < student_data.size(); i++)
        if (student_data[i].student_num==student_id)
        {

            setGetData(1);
            QString temp;
            temp+="学号："+student_data[i].student_num+"\n姓名："+student_data[i].name+
            "\n密码："+student_data[i].password+"\n班级："+student_data[i].CLASS+
            "\n电话："+student_data[i].phone+"\n选题题号："+student_data[i].topic;
            if(student_data[i].n=="0")
            {
                temp+="\n该学生已被删除";
                QMessageBox::information(this, "该学生已被删除",temp,"确认");
            }
            else
                QMessageBox::information(this, "成功",temp,"确认");
            displayall();
            return;
        }
    QMessageBox::information(this, "失败","没找到@_@","确认");
    displayall();
}

void Student::on_pushButton_4_clicked()
{
    int i=search_studen(student_id);
    if(i==-1)
    {
        QMessageBox::information(this, "失败","没找到@_@","确认");
        displayall();
        return;
    }
    int j=search_report(student_data[i].student_num);
    if(j==-1)
    {
        QMessageBox::information(this, "无需操作","该学生目前处于未选题或选题被删除状态\n无需操作","确认");

        displayall();
        return;
    }
    if(student_data[i].topic.isEmpty()||report_data[j].status=="5"||
       report_data[j].status=="4")
    {
        QMessageBox::information(this, "无需操作","该学生目前处于未选题或选题被删除状态\n无需操作","确认");
        displayall();
        return;
    }
    if(report_data[j].status=="0")
    {
        QMessageBox::information(this, "无需操作","该学生目前处于未选题或选题被删除状态\n无需操作","确认");
        displayall();
        return;
    }
    if(report_data[j].status=="-2")
    {
        QMessageBox::information(this, "无需操作","已通过审核，待学生提交\n无需操作","确认");
        displayall();
        return;
    }
    else if(report_data[j].status=="-1")
    {
        QMessageBox::StandardButton rb =
        QMessageBox::question(nullptr, "审核选题", "您同意该学生选题吗？", QMessageBox::Yes| QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
                cout<<"yes";
                report_data[j].status="0";
                setGetData(1);
                QMessageBox::information(this, "成功","成功^_^","确认");
                displayall();
        }
        else
        {
            int k=search_problem(report_data[j].problem_mun);
            report_data[j].status="-2";
            problem_data[k].current_num=QString(problem_data[k].current_num.toInt()-1);
            setGetData(1);
            displayall();
        }
    }
    else if(report_data[j].status=="1")
    {
        Submitscore submitscore;
        submitscore.show();
        submitscore.set(i,j);
        submitscore.display();
        submitscore.exec();
        setGetData();
        displayall();
    }
    else if(report_data[j].status=="2")
    {
        QString temp="该学生编程水平测试已完成\n"
                     "得分为："+student_data[i].score+"\n无需操作";
        QMessageBox::information(this, "无需操作",temp,"确认");
    }
}

void Student::on_tableView_clicked(const QModelIndex &index)
{
    QAbstractItemModel *modessl = ui->tableView->model();
    int curRow  = index.row();
    student_id=modessl->data( modessl->index(curRow,0)).toString();
}
