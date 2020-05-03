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

    void on_addCourse_clicked();

    void on_deleteCourse_clicked();

    void on_activeCourses_clicked(const QModelIndex &index);

    void on_activeStudents_clicked(const QModelIndex &index);

    void on_editStudent_clicked();

    void on_addStudent_clicked();

    void on_deleteStudent_clicked();

private:
    Ui::admin_dashboard *ui;
    QStringListModel *enrolledStudents;
    QStringListModel *activeCourses;

};

#endif // ADMIN_DASHBOARD_H
