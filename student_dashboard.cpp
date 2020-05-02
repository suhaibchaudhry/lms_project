#include "student_dashboard.h"
#include "ui_student_dashboard.h"
#include "mainwindow.h"
#include "variables.h"
#include <QMessageBox>
#include <QModelIndex>

student_dashboard::student_dashboard(QWidget *parent):QDialog(parent), ui(new Ui::student_dashboard) {
    ui->setupUi(this);

    //sets a fixed size for the window
    this->setFixedSize(QSize(860, 490));

    //creates a new model
    studCourses = new QStringListModel(this);

    QStringList studentList;


    //sets the current course list for the student
    QString courseList = curr_path + user_id + "_courses.dat";
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



    studCourses->setStringList(studentList);
    courses.close();

    //sets the ui listview to the model
    ui->listView->setModel(studCourses);

    //prevents triggers on the model
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //opens student info file
    QString filename = curr_path + user_id + "_info.dat";
    QFile myFile(filename);

    //opens file in readonly mode
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        //assigns the first line of the text file to the variable line
        QTextStream stream(&myFile);
        QString line = stream.readLine();
        ui->firstName->setText(line);

        //assigns the next line to the variable line
        line = stream.readLine();
        ui->lastName->setText(line);

        line = stream.readLine();
        ui->address->setText(line);

        line = stream.readLine();
        ui->city->setText(line);

        line = stream.readLine();
        ui->state->setText(line);

        line = stream.readLine();
        ui->zip->setText(line);

        line = stream.readLine();
        ui->dob->setText(line);

        line = stream.readLine();
        ui->phone->setText(line);
    }

    myFile.close();
}

student_dashboard::~student_dashboard() {
    delete ui;
}

void student_dashboard::on_pushButton_3_clicked() {
    //add new course

    hide();
    stud_add_course = new student_add_classes(this);
    stud_add_course->show();
}

void student_dashboard::on_pushButton_2_clicked() {
    //delete selected course
    studCourses->removeRows(ui->listView->currentIndex().row(), 1);
}

void student_dashboard::on_pushButton_4_clicked() {
     //opens new instance of edit_information window
     hide();
     edit_info = new edit_information(this);
     edit_info->show();
}

void student_dashboard::on_listView_clicked(const QModelIndex &index) {
    QModelIndex listIndex = ui->listView->currentIndex();
    student_selectedCourse = listIndex.data(Qt::DisplayRole).toString();
}

void student_dashboard::on_pushButton_clicked()
{
    if(student_selectedCourse == "") {
        QMessageBox::critical(this, "Error", "Please select a course.");
        return;
    } else {
        hide();
        stud_course = new student_course(this);
        stud_course->show();
    }
}
