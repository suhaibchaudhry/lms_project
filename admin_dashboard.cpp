#include "admin_dashboard.h"
#include "ui_admin_dashboard.h"
#include "variables.h"
#include "QMessageBox"
#include "QStyle"


admin_dashboard::admin_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_dashboard)
{
    ui->setupUi(this);

    //creates a new model
       enrolledStudents = new QStringListModel(this);

       QStringList studentList;


       //sets the current course list for the student
       QString courseList = curr_path + "courseList.dat";
       QFile courses(courseList);

       if(!courses.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QMessageBox::critical(this, "Error", "User Not Found");
       } else {
           QString line;

           while(!courses.atEnd()) {
               line = courses.readLine().trimmed();
               studentList << line;
           }
       }
    ui->activeCourses->setModel(enrolledStudents);
}

admin_dashboard::~admin_dashboard()
{
    delete ui;
}

