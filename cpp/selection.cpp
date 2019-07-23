#include "selection.h"

Selection::Selection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selection)
{   
    ui->setupUi(this);
    this->model = new QStandardItemModel;
    // 设置tableview的header的内容
    this->model->setHorizontalHeaderItem(0, new QStandardItem("题号"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("内容"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("当前人数"));
    this->model->setHorizontalHeaderItem(3, new QStandardItem("最大人数"));
    displayall();
}

void Selection::setGetData(const int x)//0-read,1-write
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

void Selection::displayall()
{

    this->ui->tableView->setModel(model);
    setGetData();
    int m=0;
    for(int i=0;i<problem_data.size();i++)
    {
        if(problem_data[i].status=="1"&&
           problem_data[i].current_num!=problem_data[i].max_num)
        {
             display(m,problem_data[i]);
             m++;
        }
    }
    this->ui->tableView->setColumnWidth(0,120);
    this->ui->tableView->setColumnWidth(1,200);
    this->ui->tableView->setColumnWidth(2,120);
    this->ui->tableView->setColumnWidth(3,120);
}

void Selection::display(const int row,const Problem &temp)
{

    this->model->setItem(row, 0,new QStandardItem(temp.problem_num));
    this->model->item(row,0)->setTextAlignment(Qt::AlignCenter);
    this->model->setItem(row, 1,new QStandardItem(temp.instruction));
    this->model->item(row,1)->setTextAlignment(Qt::AlignCenter);
    this->model->setItem(row, 2,new QStandardItem(temp.current_num));
    this->model->item(row,2)->setTextAlignment(Qt::AlignCenter);
    this->model->setItem(row, 3,new QStandardItem(temp.max_num));
    this->model->item(row,2)->setTextAlignment(Qt::AlignCenter);
}

void Selection::set(const QString& x)
{
    student_id=x;
}

int Selection::search_problem(QString x) const
{
    for (int i = 0; i < problem_data.size(); i++)
        if (problem_data[i].problem_num== x&& problem_data[i].status=="1")
            return i;
    return -1;
}

int Selection::search_studen(QString x) const
{
    for (int i = 0; i < student_data.size(); i++)
        if (student_data[i].student_num==x&& student_data[i].n!="0")
            return i;
    return -1;
}

void Selection::on_pushButton_3_clicked()
{
    int i=search_problem(problem_id);
    if(i==-1)
    {
        QMessageBox::information(this, "失败","没找到@_@","确认");
        return;
    }
    //选题人数+1
    problem_data[i].current_num
    =QString::number(problem_data[i].current_num.toInt()+1);
    //学生选题=problem_id
    student_data[search_studen(student_id)].topic=problem_id;
    //创建报告
    Report newone;
    newone.status="-1";
    newone.problem_mun=problem_data[i].problem_num;
    newone.student_num=student_data[search_studen(student_id)].student_num;
    newone.content="";
    report_data.push_back(newone);
    //写文件
    setGetData(1);
    QMessageBox::information(this, "成功","等待老师审核","确认");
    this->close();
}

void Selection::on_pushButton_2_clicked()
{
    this->close();
}

void Selection::on_tableView_clicked(const QModelIndex &index)
{
    QAbstractItemModel *modessl = ui->tableView->model();
    int curRow  = index.row();
    problem_id=modessl->data( modessl->index(curRow,0)).toString();
}
