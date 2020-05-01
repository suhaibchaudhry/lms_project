#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include <QDialog>
#include <QApplication>

namespace Ui {
class student_course;
}

class student_course : public QDialog
{
    Q_OBJECT

public:
    explicit student_course(QWidget *parent = nullptr);
    ~student_course();

private slots:
    void on_pushButton_clicked();

private:
    Ui::student_course *ui;
};

#endif // STUDENT_COURSE_H
