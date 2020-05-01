#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include <QDialog>
#include <QApplication>
#include <QSqlTableModel>
#include <QTableView>

namespace Ui {
class student_course;
}

class student_course : public QDialog
{
    Q_OBJECT

public:
    explicit student_course(QWidget *parent = nullptr);
    ~student_course();

private:
    Ui::student_course *ui;
    QSqlTableModel *model;
};

#endif // STUDENT_COURSE_H
