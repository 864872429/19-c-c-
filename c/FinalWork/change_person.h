#ifndef CHANGE_PERSON_H
#define CHANGE_PERSON_H

#include "tesk.h"
#include "ui_change_person.h"

#include <QMainWindow>

namespace Ui {
class Change_person;
}

class Change_person : public QDialog
{
    Q_OBJECT
public:
    explicit Change_person(QWidget *parent = nullptr);

    ~Change_person();

    void set(const QString &);

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_enter_clicked();

private:
    Ui::Change_person *ui;

    QString this_staff_id;
};

#endif // CHANGE_PERSON_H
