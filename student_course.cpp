#include "student_course.h"
#include "ui_student_course.h"

student_course::student_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_course)
{
    ui->setupUi(this);
}

student_course::~student_course()
{
    delete ui;
}
