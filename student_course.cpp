#include "student_course.h"
#include "ui_student_course.h"
#include "variables.h"
#include "mainwindow.h"
#include <QAbstractTableModel>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QByteArray>

student_course::student_course(QWidget *parent):QDialog(parent), ui(new Ui::student_course) {
    int num_assignments = 0;

    ui->setupUi(this);

    this->setFixedSize(QSize(240, 425));

    ui->courseName->setText(student_selectedCourse);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    QString grades_filename = curr_path + user_id + "_grades.dat";
    QString assignments_filename = curr_path + student_selectedCourse + "_assignments.dat";
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

student_course::~student_course() {
    delete ui;
}

void student_course::on_pushButton_clicked() {
    hide();

    //starts new instance of student dashboard without information change
    student_dashboard *stud_dboard = new student_dashboard(this);
    stud_dboard->show();
}
