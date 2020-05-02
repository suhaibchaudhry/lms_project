#include "faculty_course_information.h"
#include "ui_faculty_course_information.h"
#include "faculty_dashboard.h"
#include "mainwindow.h"
#include "variables.h"
#include <QMessageBox>

faculty_course_information::faculty_course_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::faculty_course_information)
{
    QString student = "0848065";
    ui->setupUi(this);
    ui->comboBox->addItem(student);
    ui->courseAssignment->setText(selected_course);
    QString filename = curr_path + student + "_info.dat";
    QFile myFile(filename);
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QTextStream stream(&myFile);
        QString noPurpose;
        QString line = stream.readLine();
        ui->firstName->setText(line);
        line = stream.readLine();
        ui->lastName->setText(line);
        noPurpose = stream.readLine();
        noPurpose = stream.readLine();
        noPurpose = stream.readLine();
        noPurpose = stream.readLine();
        noPurpose = stream.readLine();
        line = stream.readLine();
        ui->phone->setText(line);
    }
    myFile.close();

    /*ui->tableWidget->item(0,0)->setText("exam1");
    QString filename2 = curr_path + student + "_grades.dat";
    QFile myFile2(filename2);
    if(!myFile2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QString grades;
        QTextStream stream2(&myFile2);
        while(!myFile2.atEnd())
        {
            grades = stream2.readLine();
        }
    }*/
    int num_assignments = 0;
    

    
    //this->setFixedSize(QSize(240, 425));
    
     
    
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    
     QString grades_filename = curr_path + student + "_grades.dat";
     QString assignments_filename = curr_path + "assignments.dat";
     QFile grades(grades_filename);
     QFile assignments(assignments_filename);
     QStringList myGrades;
     QStringList myAssignments;
     if(!grades.open(QIODevice::ReadOnly | QIODevice::Text)) {
             QMessageBox::critical(this, "Error", "No grades found");
         } else {
             QString line;

             while(!grades.atEnd()) {
                 line = grades.readLine().trimmed();
                 myGrades << line;
                 qDebug() << line;
             }
         }

     if(!assignments.open(QIODevice::ReadOnly | QIODevice::Text)) {
             QMessageBox::critical(this, "Error", "No assignments found");
         } else {
             QString line;

             while(!assignments.atEnd()) {
                 line = assignments.readLine().trimmed();
                 myAssignments << line;
                 num_assignments++;
             }
         }
     ui->tableWidget->setRowCount(num_assignments);
     ui->tableWidget->setVerticalHeaderLabels(myAssignments);

     QString grade_element;
     for(int i = -1; i < num_assignments; i++) {
         for (int i = 0; i < myGrades.size(); ++i) {
              grade_element = myGrades.at(i);

      QTableWidgetItem* element = new QTableWidgetItem(grade_element);
      element->setTextAlignment(Qt::AlignHCenter);

      ui->tableWidget->setItem(i-1, 1, element);
             }
         }
     int curr_grade = 0;
         int total_assignments;
         for (int i = 0; i < myGrades.size(); ++i) {
             total_assignments = i+1;

             curr_grade = curr_grade + myGrades.at(i).toInt();
         }

         curr_grade = curr_grade/total_assignments;

         QString grade = QString::number(curr_grade);

         ui->curr_grade->setText(grade);

         grades.close();
         assignments.close();
}

faculty_course_information::~faculty_course_information()
{
    delete ui;
}

void faculty_course_information::on_pushButton_clicked()
{
}

void faculty_course_information::on_pushButton_2_clicked()
{
    hide();
    faculty_dashboard *fac_dboard = new faculty_dashboard(this);
    fac_dboard->show();
}
