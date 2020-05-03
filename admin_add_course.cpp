#include "admin_add_course.h"
#include "ui_admin_add_course.h"

admin_add_course::admin_add_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_add_course)
{
    ui->setupUi(this);
}

admin_add_course::~admin_add_course()
{
    delete ui;
}
