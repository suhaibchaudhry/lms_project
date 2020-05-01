#ifndef ADMIN_DASHBOARD_H
#define ADMIN_DASHBOARD_H

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

private:
    Ui::admin_dashboard *ui;
};

#endif // ADMIN_DASHBOARD_H
