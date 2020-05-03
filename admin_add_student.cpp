#include "admin_add_student.h"
#include "ui_admin_add_student.h"
#include "variables.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "QStyle"
#include <QtDebug>
#include <QModelIndex>

admin_add_student::admin_add_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_add_student)
{
    ui->setupUi(this);
}

admin_add_student::~admin_add_student()
{
    delete ui;
}

void admin_add_student::on_pushButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString fname = ui->fname->text() + "\n";
    QString lname = ui->lname->text() + "\n";
    QString address = ui->address->text() + "\n";
    QString city = ui->city->text() + "\n";
    QString state = ui->state->text() + "\n";
    QString zip = ui->zip->text() + "\n";
    QString dob = ui->dob->text() + "\n";
    QString number = ui->number->text() + "\n";

    QString student_auth = curr_path + username + "_auth.dat";
    QFile authFile(student_auth);

    QString studAuth;
    studAuth = username + "\n" + password;

    authFile.open((QIODevice::WriteOnly | QIODevice::Append));
    QTextStream auth_text(&authFile);
    auth_text << studAuth;
    authFile.close();

    QString student_info = curr_path + username + "_info.dat";
    qDebug() << "path" << student_info;
    QFile file(student_info);

    QString studInfo;
    studInfo = fname + lname + address + city + state + zip + dob + number;

    file.open((QIODevice::WriteOnly | QIODevice::Append));
    QTextStream text(&file);
    text << studInfo;
    file.close();

    QString students_enrolled = curr_path + "studentsEnrolled.dat";
    QFile students(students_enrolled);



   students.open((QIODevice::WriteOnly | QIODevice::Append));
   QTextStream curr_students(&students);
   curr_students << username + "\n";
   students.close();

   hide();
   admin_dashboard *admin_dboard = new admin_dashboard(this);
   admin_dboard->show();
}

void admin_add_student::on_pushButton_2_clicked()
{
    hide();
    admin_dashboard *admin_dboard = new admin_dashboard(this);
    admin_dboard->show();
}
