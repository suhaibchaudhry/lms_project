#ifndef FACULTY_DASHBOARD_H
#define FACULTY_DASHBOARD_H
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "faculty_course_information.h"



namespace Ui {
class faculty_dashboard;
}

class faculty_dashboard:public QDialog {
    Q_OBJECT

public:
    explicit faculty_dashboard(QWidget *parent = nullptr);
    ~faculty_dashboard();

private slots:
    void on_pushButton_clicked();


private:
    Ui::faculty_dashboard *ui;
    QStringListModel *model2;
    QStringList studentList;
    QString selected_course;

    faculty_course_information *faculty_course_info;
};

#endif // FACULTY_DASHBOARD_H
