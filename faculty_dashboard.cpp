#include "faculty_dashboard.h"
#include "ui_faculty_dashboard.h"

faculty_dashboard::faculty_dashboard(QWidget *parent):QDialog(parent), ui(new Ui::faculty_dashboard) {
    ui->setupUi(this);
}

faculty_dashboard::~faculty_dashboard() {
    delete ui;
}
