#ifndef DONATE_H
#define DONATE_H

#include <QDialog>

namespace Ui {
class Donate;
}

class Donate : public QDialog
{
    Q_OBJECT

public:
    explicit Donate(QWidget *parent = nullptr);
    ~Donate();
   // void read_file();
    void setid(QString a);
    void setname(QString a);
    void setscore(QString a);
    void write_file();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void send_score(QString);

private:
    Ui::Donate *ui;
    QString id;
    QString name;
    QString score;
    QString datail;
};

#endif // DONATE_H
