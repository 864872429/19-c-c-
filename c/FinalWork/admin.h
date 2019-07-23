#ifndef ADMIN_H
#define ADMIN_H

#include "tesk.h"

#include "managemen.h"
#include "form.h"

#include "ui_admin.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    void set(const QString &);

signals:

private slots:
    void on_btn_quit_clicked();

    void on_btn_add_clicked();

    void on_btn_cancel_donate_clicked();

    void on_btn_donate_detail_clicked();

private:
    Ui::Admin *ui;
    QString this_admin;
};

#endif // ADMIN_H
