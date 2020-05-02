#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student_dashboard.h"
#include "faculty_dashboard.h"
#include "edit_information.h"
#include "faculty_course_information.h"


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
    edit_information *edit_info;
    faculty_course_information *course_info;
};
#endif // MAINWINDOW_H
