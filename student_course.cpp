#include "student_course.h"
#include "ui_student_course.h"
#include "variables.h"

student_course::student_course(QWidget *parent):QDialog(parent), ui(new Ui::student_course) {
    ui->setupUi(this);

    ui->courseName->setText(student_selectedCourse);
}

student_course::~student_course() {
    delete ui;
}
