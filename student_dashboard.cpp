#include "student_dashboard.h"
#include "ui_student_dashboard.h"

student_dashboard::student_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_dashboard)
{
    ui->setupUi(this);
}

student_dashboard::~student_dashboard()
{
    delete ui;
}
