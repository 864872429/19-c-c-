#ifndef PASSWORD_H
#define PASSWORD_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_password.h"

namespace Ui {
class password;
}

class Password :  public QDialog
{
     Q_OBJECT

public:
    Password(QWidget *parent = nullptr);

    void set(const QString&);

    int search_studen(const QString&) const;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::password *ui;
    Fileoperation file = Fileoperation::getFile();
    QVector<User> student_data;
    QString id;
};

#endif // PASSWORD_H
