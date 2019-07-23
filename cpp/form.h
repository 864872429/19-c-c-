#ifndef FORM_H
#define FORM_H

#include "tesk.h"
#include "fileoperation.h"
#include "ui_form.h"
#include "password.h"
#include "phone.h"

namespace Ui {
class Form;
}

class Form : public QDialog
{
     Q_OBJECT
public:
    Form(QWidget *parent = nullptr);
    void set(const QString&);
    ~Form();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    Fileoperation file = Fileoperation::getFile();
    QVector<User> student_data;
    QString id;

};

#endif // FORM_H
