#ifndef REPORT_H
#define REPORT_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_report.h"

namespace Ui {
class report;
}

class REport:  public QDialog//由于Report已作为结构体名，所以前两位大写
{
    Q_OBJECT
public:
    REport(QWidget *parent = nullptr);
    void set(const QString&);
    int search_report(const QString&) const;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:

    Ui::report *ui;
    QString id;
    Fileoperation file = Fileoperation::getFile();
    QVector<Report> report_data;
    QVector<User> student_data;
    QStandardItemModel *model;
};

#endif // REPORT_H
