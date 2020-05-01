#include "student_add_classes.h"
#include "ui_student_add_classes.h"

student_add_classes::student_add_classes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_add_classes)
{
    ui->setupUi(this);
}

student_add_classes::~student_add_classes()
{
    delete ui;
}
