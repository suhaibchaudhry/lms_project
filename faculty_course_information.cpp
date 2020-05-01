#include "faculty_course_information.h"
#include "ui_faculty_course_information.h"

faculty_course_information::faculty_course_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::faculty_course_information)
{
    ui->setupUi(this);
}

faculty_course_information::~faculty_course_information()
{
    delete ui;
}
