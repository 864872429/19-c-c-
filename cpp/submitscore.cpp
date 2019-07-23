#include "submitscore.h"

Submitscore::Submitscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::submitScore)
{
    ui->setupUi(this);
    report_data=file.get_report_data();
    student_data=file.get_student_data();
}

void Submitscore::on_pushButton_2_clicked()
{
    this->close();
}

void Submitscore::set(const int num1,const int num2)
{
    s_num=num1;
    r_num=num2;
}

void Submitscore::display()
{
    this->ui->textBrowser->setText(report_data[r_num].content);
    this->ui->textBrowser_2->setText(student_data[s_num].name);
    this->ui->spinBox->setMaximum(100);
    this->ui->spinBox->setMinimum(0);
    this->ui->spinBox->setValue(90);
}

Submitscore::~Submitscore()
{
    delete ui;
}

void Submitscore::on_comboBox_activated(int index)
{
    switch (index)
    {
    case 0:this->ui->spinBox->setValue(90);break;
    case 1:this->ui->spinBox->setValue(80);break;
    case 2:this->ui->spinBox->setValue(70);break;
    case 3:this->ui->spinBox->setValue(60);break;
    case 4:this->ui->spinBox->setValue(59);break;
    }
}

void Submitscore::on_pushButton_clicked()
{
    int rb=QMessageBox::question(NULL, "确定", "您确定提交成绩吗？\n一旦提交，无法修改", QMessageBox::Yes| QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
        {
        student_data[s_num].score=QString::number(this->ui->spinBox->value());
        report_data[r_num].status="2";
        file.set_report_data(report_data);
        file.set_student_data(student_data);
        QMessageBox::information(this, "成功","成功^_^","确认");
        this->close();
        }

}
