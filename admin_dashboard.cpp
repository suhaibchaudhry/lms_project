#include "admin_dashboard.h"
#include "ui_admin_dashboard.h"

admin_dashboard::admin_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_dashboard)
{
    ui->setupUi(this);
}

admin_dashboard::~admin_dashboard()
{
    delete ui;
}
