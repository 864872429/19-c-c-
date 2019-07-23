#ifndef FORM_H
#define FORM_H

#include "tesk.h"

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
    void set(const QString& , const bool);
    ~Form();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    QString id;
    bool level; //0->admin 1->staff

};

#endif // FORM_H
