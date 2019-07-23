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

void Admin::on_btn_add_clicked()
{
    Student student;
    student.show();
    student.exec();
}

void Admin::on_btn_cancel_donate_clicked()
{
    QMessageBox::information(this,"提示","攻城狮正茬努力开发中，敬请期待！","确认");
}

void Admin::on_btn_look_clicked()
{
    Question question;
    question.show();
    question.exec();
}

void Admin::on_btn_donate_detail_clicked()
{
    QMessageBox::information(this,"提示","攻城狮正茬努力开发中，敬请期待！","确认");
}
