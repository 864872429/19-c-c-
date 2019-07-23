#ifndef STAFF_H
#define STAFF_H

#include "tesk.h"

#include "form.h"
#include "ui_staff.h"

namespace Ui {
class staff;
}

class Staff : public QDialog
{
    Q_OBJECT

public:
    explicit Staff(QWidget *parent = nullptr);
    ~Staff();
    void set(const QString&);

private slots:
    void on_btn_add_clicked();

    void on_btn_quit_clicked();

    void on_btn_donate_detail_clicked();

private:
    QString this_staff;
    Ui::staff *ui;
};

#endif // STAFF_H
