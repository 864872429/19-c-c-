#include "admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_btn_quit_clicked()
{
    this->close();
}

void Admin::set(const QString &x)
{
    this_admin=x;
    QString sql;
    QSqlQueryModel *model=new QSqlQueryModel;
    sql="select name from admin where admin_id =\'"+this_admin+"\'";
    model->setQuery(sql);
    sql = model->index(0,0).data().toString() + "管理员您好";
    this->ui->admintext->setText(sql);
}

void Admin::on_btn_add_clicked()
{
   Managemen managemen;
   managemen.show();
   managemen.exec();
}

void Admin::on_btn_cancel_donate_clicked()
{
    QMessageBox::information(this,"提示","攻城狮正茬努力开发中，敬请期待！","确认");
}


void Admin::on_btn_donate_detail_clicked()
{
    Form form;
    form.set(this_admin,0);
    form.show();
    form.exec();
}
