#include "course_information.h"
#include "ui_course_information.h"

course_information::course_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course_information)
{
    ui->setupUi(this);
}

course_information::~course_information()
{
    delete ui;
}
