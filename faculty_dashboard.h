#ifndef FACULTY_DASHBOARD_H
#define FACULTY_DASHBOARD_H
#include <QDialog>

namespace Ui {
class faculty_dashboard;
}

class faculty_dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit faculty_dashboard(QWidget *parent = nullptr);
    ~faculty_dashboard();

private:
    Ui::faculty_dashboard *ui;
};

#endif // FACULTY_DASHBOARD_H
