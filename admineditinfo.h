#ifndef ADMINEDITINFO_H
#define ADMINEDITINFO_H

#include <QDialog>

namespace Ui {
class admineditinfo;
}

class admineditinfo : public QDialog
{
    Q_OBJECT

public:
    explicit admineditinfo(QWidget *parent = nullptr);
    ~admineditinfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::admineditinfo *ui;
};

#endif // ADMINEDITINFO_H
