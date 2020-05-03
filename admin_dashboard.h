#ifndef ADMIN_DASHBOARD_H
#define ADMIN_DASHBOARD_H
#include "QtCore"
#include "QtGui"
#include <QDialog>

namespace Ui {
class admin_dashboard;
}

class admin_dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit admin_dashboard(QWidget *parent = nullptr);
    ~admin_dashboard();

private slots:
    void on_pushButton_clicked();

private:
    Ui::admin_dashboard *ui;
    QStringListModel *enrolledStudents;
    QStringListModel *activeCourses;

};

#endif // ADMIN_DASHBOARD_H
