#ifndef STUDENT_DASHBOARD_H
#define STUDENT_DASHBOARD_H

#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "edit_information.h"

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

private:
    Ui::student_dashboard *ui;

    //declared a new model for use in the student dashboard
    QStringListModel *model;

    //declared a new instance of the edit_information window
    edit_information *edit_info;
};

#endif // STUDENT_DASHBOARD_H
