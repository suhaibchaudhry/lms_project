#ifndef STUDENT_DASHBOARD_H
#define STUDENT_DASHBOARD_H

#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "edit_information.h"
#include "student_course.h"
#include "student_add_classes.h"

namespace Ui {
class student_dashboard;
}

class student_dashboard:public QDialog {
    Q_OBJECT

public:
    explicit student_dashboard(QWidget *parent = nullptr);
    ~student_dashboard();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::student_dashboard *ui;

    //declared a new model for use in the student dashboard
    QStringListModel *studCourses;

    //declared a new instance of the edit_information window
    edit_information *edit_info;
    student_course *stud_course;
    student_add_classes *stud_add_course;
    student_dashboard *stud_dboard;
};

#endif // STUDENT_DASHBOARD_H
