#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 各个窗口之间的交流
    connect(&this->login,SIGNAL(send_login(QString,QString)),this,SLOT(loginit(QString,QString)));
    //connect(&this->question,SIGNAL(send_score(QString)),this,SLOT(receive_score(QString)));
    this->ui->pushButton_2->setVisible(false);
    this->ui->pushButton_5->setVisible(false);
    student_data=file.get_student_data();
    report_data=file.get_report_data();
    problem_data=file.get_problem_data();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_login_clicked()
{
    this->login.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    Form form;
    form.set(id);
    form.show();
    form.exec();
}

int MainWindow::search_studen(const QString& x) const
{
    for (int i = 0; i < student_data.size(); i++)
        if (student_data[i].student_num==x&& student_data[i].n!="0")
            return i;
    return -1;
}

void MainWindow::setGetData(const int x)//0-read,1-write
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

void MainWindow::on_pushButton_2_clicked()
{
    setGetData();
    if(student_data[search_studen(id)].topic.isEmpty())
    {
        QMessageBox::information(this, "选题","您当前没有选题，请先选题","确认");
        Selection selection;
        selection.set(id);
        selection.show();
        selection.exec();
        return;
    }
    if(report_data[search_report(id)].status=="-2")
    {
        QMessageBox::information(this, "选题",
        "您当前选题申请失败，请重新选题","确认");
        Selection selection;
        selection.set(id);
        selection.show();
        selection.exec();
        return;
    }
    if(report_data[search_report(id)].status=="-1")
    {
        QMessageBox::information(this, "选题",
        "您当前选题已提交\n等待老师审核\n请耐心等待","确认");
        return;
    }
    if(report_data[search_report(id)].status=="0")
    {
        QMessageBox::information(this, "选题",
        "您当前选题已通过\n提交报告吧","确认");
        REport report;
        report.set(id);
        report.show();
        report.exec();
        return;
    }
    if(report_data[search_report(id)].status=="1")
    {
        QMessageBox::information(this, "选题",
        "您当前报告已提交\n等待老师审核\n请耐心等待","确认");
        return;
    }
    if(report_data[search_report(id)].status=="2")
    {
        QString temp = "您的编程水平测试已完成\n得分"+student_data[search_studen(id)].score+"\n辛苦了";
        QMessageBox::information(this, "选题",
        temp,"确认");
        return;
    }

}

int MainWindow::search_report(const QString& x) const
{
    for (int i = 0; i < report_data.size(); i++)
        if (report_data[i].student_num== x&& report_data[i].status!="5")
            return i;
    return -1;
}

void MainWindow::loginit(QString id, QString name)
{
    QString x=name+"同学您好";
    this->ui->label->setText(x);
    this->ui->pushButton_2->setVisible(true);
    this->ui->pushButton_5->setVisible(true);
    this->ui->btn_login->setVisible(false);
    this->id = id;
    this->name = name;
}


void MainWindow::on_actionAbout_this_triggered()
{
    QMessageBox::information(this,"关于本系统","作者：\n王希成"" 张珍珍\n""胡洁琴"" 卢漫可","666");
}
void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}
