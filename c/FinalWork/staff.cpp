#include "staff.h"

Staff::Staff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staff)
{
    ui->setupUi(this);
}

Staff::~Staff()
{
    delete ui;
}

void Staff::on_btn_add_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select * from staff where staff_id =\'"+this_staff+"\'";
    model->setQuery(sql);
    sql = "下面是您的信息\n工号："+model->index(0,0).data(0).toString()+"\n密码："+model->index(0,1).data(0).toString()
            +"\n姓名："+model->index(0,2).data(0).toString()+"\n电话："+model->index(0,3).data(0).toString()+"\n基本工资："+model->index(0,4).data(0).toString()
            +"\n岗位津贴："+model->index(0,5).data(0).toString()+"\n医疗保险："+model->index(0,6).data(0).toString();
    QMessageBox::information(this, "个人信息查询",sql,"确认");
}

 void Staff::set(const QString& x)
 {
     this_staff=x;
     QString sql;
     QSqlQueryModel *model=new QSqlQueryModel;
     sql="select name from staff where staff_id =\'"+this_staff+"\'";
     model->setQuery(sql);
     sql = model->index(0,0).data().toString()+"员工您好";
     this->ui->stafftext->setText(sql);
 }

void Staff::on_btn_quit_clicked()
{
    this->close();
}

void Staff::on_btn_donate_detail_clicked()
{
     Form form;
     form.set(this_staff,1);
     form.show();
     form.exec();
}
