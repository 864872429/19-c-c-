#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>

namespace Ui {
class Change;
}

class Change : public QDialog
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = nullptr);
    ~Change();

private:
    Ui::Change *ui;
};

#endif // CHANGE_H
