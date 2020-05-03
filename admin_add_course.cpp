#include "admin_add_course.h"
#include "ui_admin_add_course.h"
#include "variables.h"
//#include "mainwindow.h"
#include "admin_dashboard.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>

admin_add_course::admin_add_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_add_course)
{
    ui->setupUi(this);
}

admin_add_course::~admin_add_course()
{
    delete ui;
}

void admin_add_course::on_addCourseButton_clicked()
{
    QString course_text = ui->addCourseText->text();
    QString filename = curr_path + "courseList.dat";
    QFile myFile(filename);

    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QByteArray fileData = myFile.readAll();
        qDebug() << fileData;
        QString text(fileData);

        if(!text.contains(course_text)) {
            myFile.close();
            myFile.open(QIODevice::WriteOnly | QIODevice::Append);
            qDebug() << "course text" << course_text;
            qDebug() << "text" << text;

            QTextStream text(&myFile);
            course_text = "\n" + course_text;
            text << course_text;
            myFile.close();
        }
    }

    hide();
    admin_dashboard *admin_dboard = new admin_dashboard(this);
    admin_dboard->show();
}

void admin_add_course::on_pushButton_2_clicked()
{
    hide();
    admin_dashboard *admin_dboard = new admin_dashboard(this);
    admin_dboard->show();
}
