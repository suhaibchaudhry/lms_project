#ifndef STUDENT_DASHBOARD_H
#define STUDENT_DASHBOARD_H

#include <QtCore>
#include <QtGui>
#include <QDialog>

namespace Ui {
class student_dashboard;
}

class student_dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit student_dashboard(QWidget *parent = nullptr);
    ~student_dashboard();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::student_dashboard *ui;
    QStringListModel *model;
};

#endif // STUDENT_DASHBOARD_H
