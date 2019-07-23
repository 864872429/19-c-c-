#include "form.h"

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

void Form::on_pushButton_3_clicked()
{
    this->close();
}

void Form::set(const QString& x,const bool b)
{
    id = x;
    level = b;
}

void Form::on_pushButton_2_clicked()
{
    Password password;
    password.set(id,level);
    password.show();
    password.exec();
    ;
}

void Form::on_pushButton_clicked()
{
    Phone phone;
    phone.set(id,level);
    phone.show();
    phone.exec();
}

Form::~Form()
{
    delete ui;
}
