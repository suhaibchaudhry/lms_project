#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student_dashboard.h"
#include "faculty_dashboard.h"
#include "admin_dashboard.h"
#include "edit_information.h"
#include "admin_add_course.h"
#include "admineditinfo.h"
#include "admin_add_student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow:public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;

    //declares new instances of various windows to be used
    student_dashboard *stud_dboard;
    faculty_dashboard *fac_dboard;
    admin_dashboard *adm_dboard;
    edit_information *edit_info;
    admin_add_course *admin_add;
    admineditinfo *admin_edit_student;
    admin_add_student *add_student;
};
#endif // MAINWINDOW_H
