#include "Question.h"


Question::Question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question)
{
    ui->setupUi(this);
    this->model = new QStandardItemModel;
    // 设置tableview的header的内容
    this->model->setHorizontalHeaderItem(0, new QStandardItem("题号"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("内容"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("最大人数"));
    this->model->setHorizontalHeaderItem(3, new QStandardItem("当前人数"));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setColumnWidth(0,180);
    this->ui->tableView->setColumnWidth(1,190);
    this->ui->tableView->setColumnWidth(2,200);
    this->ui->tableView->setColumnWidth(3,200);
    this->ui->new_con->hide();
    this->ui->new_num->hide();
    this->ui->new_label->hide();
    this->ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); 
    displayall();
}

void Question::on_pushButton_2_clicked()
{
    this->close();
}

void Question::on_btn_query_clicked()
{
    clearall();
    setGetData();
    QString content = this->ui->le_content->text();
    int index = this->ui->comboBox->currentIndex();
    int row = 0;
    for(int i=0;i<problem_data.size();i++)
    {
        if(problem_data[i].status=="1")
        {
            switch(index)
            {
            case 0:
                if(content==problem_data[i].problem_num)
                    display(row++,problem_data[i]);
                break;
            case 1:
                if(content==problem_data[i].instruction)
                    display(row++,problem_data[i]);
                break;
            case 2:
                if(content==problem_data[i].max_num)
                    display(row++,problem_data[i]);
                break;
            case 3:
                if(content==problem_data[i].current_num)
                    display(row++,problem_data[i]);
                break;
            }
        }
    }
    if (row == 0)
    {
        QMessageBox::information(this,"错误","查询不到符合要求的题目","确认");
        displayall();
        return;
    }
}

void Question::setGetData(const int x)//0-read,1-write
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

void Question::displayall()
{
   setGetData();
   int m=0;
   for(int i=0;i<problem_data.size();i++)
   {
       if(problem_data[i].status=="1")
       {
            display(m,problem_data[i]);
            m++;
       }
   }
   this->ui->tableView->setColumnWidth(0,180);
   this->ui->tableView->setColumnWidth(1,190);
   this->ui->tableView->setColumnWidth(2,200);
   this->ui->tableView->setColumnWidth(3,200);
}

void Question::display(const int row, const Problem &temp) const
{
    this->model->setItem(row, 0,new QStandardItem(temp.problem_num));
    this->model->item(row,0)->setTextAlignment(Qt::AlignCenter);
    this->model->setItem(row, 1,new QStandardItem(temp.instruction));
    this->model->item(row,1)->setTextAlignment(Qt::AlignCenter);
    this->model->setItem(row, 2,new QStandardItem(temp.max_num));
    this->model->item(row,2)->setTextAlignment(Qt::AlignCenter);
    this->model->setItem(row, 3,new QStandardItem(temp.current_num));
    this->model->item(row,3)->setTextAlignment(Qt::AlignCenter);
}

//清除tableview 当中的所有的数据
void Question::clearall() const
{
    for(int i = 0;i<problem_data.size();i++)
    {
        this->model->removeRow(i);
    }
}


void Question::on_pushButton_clicked()
{
    add_problem.show();
    add_problem.exec();
    displayall();
}

void Question::on_CHANGE_clicked()
{
    for(int i=0;i<problem_data.size();i++)
        if(problem_data[i].problem_num==problem_id&&problem_data[i].status=="1")
        {
            this->ui->new_num->setPlaceholderText("请输入新人数");
            this->ui->new_con->show();
            this->ui->new_num->show();
            this->ui->new_label->show();
            this->ui->DELET->hide();
            this->ui->CHANGE->hide();
            flag=1;
            return;
        }
    QMessageBox::information(this, "失败","没找到@_@","确认");
    displayall();
}

void Question::on_DELET_clicked()
{
    for(int i=0;i<problem_data.size();i++)
        if(problem_data[i].problem_num==problem_id&&problem_data[i].status=="1")
        {
            if(problem_data[i].current_num=="0")
            {
                problem_data[i].status="0";
                QMessageBox::information(this, "成功","成功^_^","确认");
                setGetData(1);
                clearall();
                displayall();
                return;
            }
            else
            {
                this->ui->new_num->setPlaceholderText("请输入删除理由");
                this->ui->new_con->show();
                this->ui->new_num->show();
                this->ui->DELET->hide();
                this->ui->CHANGE->hide();
                flag=2;
                displayall();
                return;
            }
        }
    QMessageBox::information(this, "失败","没找到@_@","确认");
    displayall();
}

void Question::on_new_con_clicked()
{
    QString str2=this->ui->new_num->text();
    if(flag==1)
    {
        for(int i=0;i<str2.length();i++)
            if(str2[i]>'9'||str2[i]<'0')
            {
                QMessageBox::information(this, "失败","请输入正确的数字","确认");
                this->ui->new_con->hide();
                this->ui->new_num->hide();
                this->ui->DELET->show();
                this->ui->CHANGE->show();
                this->ui->new_num->clear();
                this->ui->new_label->hide();
                return;
            }
        for(int i=0;i<problem_data.size();i++)
            if(problem_data[i].problem_num==problem_id&&problem_data[i].status=="1")
            {
                if (problem_data[i].current_num.toInt()>str2.toInt()-1)
                {
                     QMessageBox::information(this, "失败","请输入无法设置为这个人数","确认");
                     this->ui->new_con->hide();
                     this->ui->new_num->hide();
                     this->ui->DELET->show();
                     this->ui->CHANGE->show();
                     this->ui->new_num->clear();
                     this->ui->new_label->hide();
                     return;
                }
                problem_data[i].max_num=str2;
                this->ui->new_con->hide();
                this->ui->new_num->hide();
                this->ui->DELET->show();
                this->ui->CHANGE->show();
                this->ui->new_num->clear();
                this->ui->new_label->hide();
                setGetData(1);
                displayall();
                return;
            }
    }
    else
    {
        for(int i=0;i<problem_data.size();i++)
            if(problem_data[i].problem_num==problem_id&&problem_data[i].status=="1")
            {
                if(str2.isEmpty())
                {
                    QMessageBox::information(this, "失败","请输入删除理由","确认");
                    this->ui->new_con->hide();
                    this->ui->new_num->hide();
                    this->ui->new_label->hide();
                    this->ui->DELET->show();
                    this->ui->CHANGE->show();
                    this->ui->new_num->clear();
                    return;
                }
                problem_data[i].delete_reason=str2;
                problem_data[i].status="-1";
                this->ui->new_con->hide();
                this->ui->new_num->hide();
                this->ui->DELET->show();
                this->ui->CHANGE->show();
                this->ui->new_num->clear();
                this->ui->new_label->hide();
                setGetData(1);
                displayall();
                return;
            }
    }

}

void Question::on_tableView_clicked(const QModelIndex &index)
{
    QAbstractItemModel *modessl = ui->tableView->model();
    int curRow  = index.row();
    problem_id=modessl->data( modessl->index(curRow,0)).toString();
}
