#include "change.h"
#include "ui_change.h"

Change::Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
}

Change::~Change()
{
    delete ui;
}
