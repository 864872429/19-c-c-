#ifndef PHONE_H
#define PHONE_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_phone.h"

namespace Ui {
class phone;
}

class Phone:  public QDialog
{
         Q_OBJECT
public:
    Phone(QWidget *parent = nullptr);

    void set(const QString&);

    int search_studen(const QString&) const;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::phone *ui;
    Fileoperation file = Fileoperation::getFile();
    QVector<User> student_data;
    QString id;
};

#endif // PHONE_H
