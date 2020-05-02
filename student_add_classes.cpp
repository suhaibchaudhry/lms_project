#include "student_add_classes.h"
#include "ui_student_add_classes.h"
#include "variables.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>

student_add_classes::student_add_classes(QWidget *parent):QDialog(parent), ui(new Ui::student_add_classes) {
    ui->setupUi(this);

    //setWindowModality(Qt::ApplicationModal);

    courseList = new QStringListModel(this);
    QStringList full_courseList;

    QString courses_file = curr_path + "courseList.dat";
    QFile fullCourses(courses_file);

    if(!fullCourses.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QString line;

        while(!fullCourses.atEnd()) {
            line = fullCourses.readLine().trimmed();
            full_courseList << line;
        }
    }

    courseList->setStringList(full_courseList);
    ui->comboBox->setModel(courseList);
}

student_add_classes::~student_add_classes() {
    delete ui;
}

void student_add_classes::on_pushButton_clicked() {
    QString cb_text = ui->comboBox->currentText();
    QString filename = curr_path + user_id + "_courses.dat";
    QFile myFile(filename);

    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QByteArray fileData = myFile.readAll();
        QString text(fileData);

        if(!text.contains(cb_text)) {
            myFile.close();
            myFile.open(QIODevice::WriteOnly | QIODevice::Append);
            QTextStream text(&myFile);
            cb_text = "\n" + cb_text;
            text << cb_text;
            myFile.close();
        }
    }
}
