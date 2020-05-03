#include "admin_dashboard.h"
#include "ui_admin_dashboard.h"
#include "variables.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "QStyle"
#include <QtDebug>
#include <QModelIndex>

admin_dashboard::admin_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_dashboard)
{
    ui->setupUi(this);

    //creates a new model
    activeCourses = new QStringListModel(this);

    QStringList currentCourses;


    //sets the current course list for the student
    QString courseList = curr_path + "courseList.dat";
    QFile courses(courseList);

    if(!courses.open(QIODevice::ReadOnly | QIODevice::Text)) {
       QMessageBox::critical(this, "Error", "User Not Found");
    } else {
       QString line;

       while(!courses.atEnd()) {
           line = courses.readLine().trimmed();
           currentCourses << line;
       }
    }

    activeCourses->setStringList(currentCourses);
    ui->activeCourses->setModel(activeCourses);

    //creates a new model
    enrolledStudents = new QStringListModel(this);

    QStringList studentList;


    //sets the current course list for the student
    QString studentsEnrolled = curr_path + "studentsEnrolled.dat";
    QFile students(studentsEnrolled);

    if(!students.open(QIODevice::ReadOnly | QIODevice::Text)) {
       QMessageBox::critical(this, "Error", "User Not Found");
    } else {
       QString line;

       while(!students.atEnd()) {
           line = students.readLine().trimmed();
           studentList << line;
       }
    }

    enrolledStudents->setStringList(studentList);
    ui->activeStudents->setModel(enrolledStudents);


}

admin_dashboard::~admin_dashboard()
{
    delete ui;
}


void admin_dashboard::on_addCourse_clicked()
{
    hide();
    admin_add_course *admin_add = new admin_add_course(this);
    admin_add->show();

}

void admin_dashboard::on_deleteCourse_clicked()
{
    QString filename = curr_path + "courseList.dat";
    QFile myFile(filename);

    //open file as readable and writable
    myFile.open(QIODevice::ReadWrite | QIODevice::Text);

    //create new qbytearray to store filedata and store it as a qstring called text
    QByteArray fileData = myFile.readAll();
    QString text(fileData);



    admin_selectedCourse = admin_selectedCourse + "\n";

    qDebug() << "current text" << text;
    qDebug() << "selected course name" << admin_selectedCourse;

    text.replace(QString(admin_selectedCourse), QString(""));

    qDebug() << "new text" << text.toUtf8();

    myFile.resize(0);

    QTextStream output(&myFile);
    output << text;

    myFile.close();

    QStringList coursesList;

    QString courseList = curr_path + "courseList.dat";
    QFile courses(courseList);

    if(!courses.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QString line;

        while(!courses.atEnd()) {
            line = courses.readLine().trimmed();
            coursesList << line;
        }
    }

    activeCourses->setStringList(coursesList);
    courses.close();
}

void admin_dashboard::on_activeCourses_clicked(const QModelIndex &index)
{
    QModelIndex listIndex = ui->activeCourses->currentIndex();
    admin_selectedCourse = listIndex.data(Qt::DisplayRole).toString();

}

void admin_dashboard::on_activeStudents_clicked(const QModelIndex &index)
{
    QModelIndex listIndex = ui->activeStudents->currentIndex();
    user_id = listIndex.data(Qt::DisplayRole).toString();
}

void admin_dashboard::on_editStudent_clicked()
{
    hide();
    admineditinfo *admin_edit_student = new admineditinfo(this);
    admin_edit_student->show();
}

void admin_dashboard::on_addStudent_clicked()
{
    hide();
    admin_add_student *add_student = new admin_add_student(this);
    add_student->show();
}

void admin_dashboard::on_deleteStudent_clicked()
{
    QString filename = curr_path + "studentsEnrolled.dat";
    QFile myFile(filename);

    //open file as readable and writable
    myFile.open(QIODevice::ReadWrite | QIODevice::Text);

    //create new qbytearray to store filedata and store it as a qstring called text
    QByteArray fileData = myFile.readAll();
    QString text(fileData);



    user_id = user_id + "\n";

    qDebug() << "current text" << text;
    qDebug() << "selected course name" << user_id;

    text.replace(QString(user_id), QString(""));

    qDebug() << "new text" << text.toUtf8();

    myFile.resize(0);

    QTextStream output(&myFile);
    output << text;

    myFile.close();

    QStringList studentsList;

    QString studentList = curr_path + "studentsEnrolled.dat";
    QFile students(studentList);

    if(!students.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QString line;

        while(!students.atEnd()) {
            line = students.readLine().trimmed();
            studentsList << line;
        }
    }

    enrolledStudents->setStringList(studentsList);
    students.close();
}
