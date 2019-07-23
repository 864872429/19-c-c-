#include "managemen.h"

Managemen::Managemen(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::managemen)
{
    ui->setupUi(this);
    this->model = new QStandardItemModel;
    displayall();
    connect(ui->le_content,SIGNAL(textChanged(QString)),this,SLOT(find()));//将字符变化的事件，与某函数连接
}

void Managemen::displayall()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff");
    ui->tableView->setModel(model);
}

void Managemen::find()//需要connect函数进行连接，每当输入框文本发生变化，就执行一边这个函数，而不需要手动点击什么按钮了
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    find=ui->le_content->text();
    switch(this->ui->comboBox->currentIndex())
    {
    case 0:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where staff_id LIKE '%"+find+"%'");break;
    case 1:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where name LIKE '%"+find+"%'"); break;
    case 2:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where phone LIKE '%"+find+"%'"); break;
    case 3:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where salary LIKE '%"+find+"%'"); break;
    case 4:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where allowance LIKE '%"+find+"%'"); break;
    }
    ui->tableView->setModel(modell);
}

void Managemen::on_pushButton_clicked()
{
    Add_person add_person;
    add_person.show();
    add_person.exec();
    this->ui->le_content->clear();
    displayall();
}

void Managemen::on_pushButton_2_clicked()
{
    this->close();
}

void Managemen::on_pushButton_5_clicked()
{
    this->ui->le_content->clear();
    displayall();
}

void Managemen::on_tableView_clicked(const QModelIndex &index)
{
    QAbstractItemModel *modessl = ui->tableView->model();
    int curRow  = index.row();
    this_staff_id=modessl->data( modessl->index(curRow,0)).toString();
    this_staff_name=modessl->data(modessl->index(curRow,1)).toString();
}

void Managemen::on_pushButton_3_clicked()
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString name="您确定删除员工"+this_staff_name+"吗？\n一旦删除，无法修改";
    int rb=QMessageBox::question(nullptr, "确定", name, QMessageBox::Yes| QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        QString sql="DELETE FROM staff WHERE staff_id ='"+ this_staff_id+"'";
        modell->setQuery(sql);
        QMessageBox::question(nullptr, "成功", "删除改员成功","确定");
        displayall();
    }
}



void Managemen::on_comboBox_activated()
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    find=ui->le_content->text();
    switch(this->ui->comboBox->currentIndex())
    {
    case 0:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where staff_id LIKE '%"+find+"%'");break;
    case 1:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where name LIKE '%"+find+"%'"); break;
    case 2:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where phone LIKE '%"+find+"%'"); break;
    case 3:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where salary LIKE '%"+find+"%'"); break;
    case 4:modell->setQuery("select staff_id as 工号,name as 姓名,phone as 电话,salary as 基本工资,allowance as 岗位津贴 from staff where allowance LIKE '%"+find+"%'"); break;
    }
    ui->tableView->setModel(modell);
}

void Managemen::on_btn_query_clicked()
{
    QString sql;
    QSqlQueryModel *modell=new QSqlQueryModel;
    sql="select * from staff where staff_id =\'"+this_staff_id+"\'";
    modell->setQuery(sql);
    sql = "下面是选中员工的信息\n工号："+modell->index(0,0).data(0).toString()+"\n密码："+modell->index(0,1).data(0).toString()
            +"\n姓名："+modell->index(0,2).data(0).toString()+"\n电话："+modell->index(0,3).data(0).toString()+"\n基本工资："+modell->index(0,4).data(0).toString()
            +"\n岗位津贴："+modell->index(0,5).data(0).toString()+"\n医疗保险："+modell->index(0,6).data(0).toString();
    QMessageBox::information(this, "信息查询",sql,"确认");
}

void Managemen::on_pushButton_4_clicked()
{
    if(this_staff_id.isEmpty())
    {
        QMessageBox::question(nullptr, "错误", "请选择员工", "确认");
        return;
    }
    change_person.set(this_staff_id);
    change_person.show();
    change_person.exec();
    displayall();
}
