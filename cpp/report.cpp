#include "report.h"

REport::REport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);

}

void REport::set(const QString& x)
{
    id=x;
}

void REport::on_pushButton_2_clicked()
{
    this->close(); 
}

void REport::on_pushButton_clicked()
{
    report_data=file.get_report_data();
    QString temp;
    temp=this->ui->textEdit->toPlainText();
    if(temp.isEmpty())
    {
        QMessageBox::information(this, "失败","请输入报告","确认");
        return;
    }
    report_data[search_report(id)].status="1";
    report_data[search_report(id)].content=temp;
    file.set_report_data(report_data);
    QMessageBox::information(this, "成功","报告提交成功","确认");
    this->close();
}

int REport::search_report(const QString &x) const
{
    for (int i = 0; i < report_data.size(); i++)
        if (report_data[i].student_num== x&& report_data[i].status!="5")
            return i;
    return -1;
}
