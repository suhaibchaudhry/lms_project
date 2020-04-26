#ifndef STUDENT_DASHBOARD_H
#define STUDENT_DASHBOARD_H

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

private:
    Ui::student_dashboard *ui;
};

#endif // STUDENT_DASHBOARD_H
