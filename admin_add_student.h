#ifndef ADMIN_ADD_STUDENT_H
#define ADMIN_ADD_STUDENT_H

#include <QDialog>

namespace Ui {
class admin_add_student;
}

class admin_add_student : public QDialog
{
    Q_OBJECT

public:
    explicit admin_add_student(QWidget *parent = nullptr);
    ~admin_add_student();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::admin_add_student *ui;
};

#endif // ADMIN_ADD_STUDENT_H
