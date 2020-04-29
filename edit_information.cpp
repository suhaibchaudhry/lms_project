#include "edit_information.h"
#include "ui_edit_information.h"
#include "variables.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

edit_information::edit_information(QWidget *parent):QDialog(parent), ui(new Ui::edit_information) {
    ui->setupUi(this);

    //set file for student info
    QString filename = curr_path + user_id + "_info.dat";
    QFile myFile(filename);

    //open student info as file as read only
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        //start reading line by line and set the variable line to next line from file
        QTextStream stream(&myFile);
        QString line = stream.readLine();

        //set the element placeholdertext to the line variable
        ui->firstName->setPlaceholderText(line);

        line = stream.readLine();
        ui->lastName->setPlaceholderText(line);

        line = stream.readLine();
        ui->address->setPlaceholderText(line);

        line = stream.readLine();
        ui->city->setPlaceholderText(line);

        line = stream.readLine();
        ui->state->setPlaceholderText(line);

        line = stream.readLine();
        ui->zip->setPlaceholderText(line);

        line = stream.readLine();
        ui->dob->setPlaceholderText(line);

        line = stream.readLine();
        ui->phone->setPlaceholderText(line);
    }

    myFile.close();
}

void edit_information::on_pushButton_clicked() {
    QString filename = curr_path + user_id + "_info.dat";
    QFile myFile(filename);

    //open file as readable and writable
    myFile.open(QIODevice::ReadWrite | QIODevice::Text);

    //create new qbytearray to store filedata and store it as a qstring called text
    QByteArray fileData = myFile.readAll();
    QString text(fileData);

    //declare user inputted variables
    QString user_fname;
    QString user_lname;
    QString user_address;
    QString user_city;
    QString user_state;
    QString user_zip;
    QString user_dob;
    QString user_phone;

    //set read pointer to beginning of file
    myFile.seek(0);
    QTextStream stream(&myFile);

    QString line = stream.readLine();
    user_fname = line;

    line = stream.readLine();
    user_lname = line;

    line = stream.readLine();
    user_address = line;

    line = stream.readLine();
    user_city = line;

    line = stream.readLine();
    user_state = line;

    line = stream.readLine();
    user_zip = line;

    line = stream.readLine();
    user_dob = line;

    line = stream.readLine();
    user_phone = line;

    //checks if the label is empty
    //if label is not empty, sets variable to the user inputted text
    //and writes it to file
    if(ui->firstName->text() != "") {
        QString fname = ui->firstName->text();

        //replaces user_fname with fname
        text.replace(QRegularExpression(user_fname), QString(fname));

        myFile.seek(0);

        //writes to file as a qbytearray (.toUtf8() converts to qbytearray)
        myFile.write(text.toUtf8());
    }

    if(ui->lastName->text() != "") {
        QString lname = ui->lastName->text();
        text.replace(QRegularExpression(user_lname), QString(lname));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    if(ui->address->text() != "") {
        QString address = ui->address->text();
        text.replace(QRegularExpression(user_address), QString(address));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    if(ui->city->text() != "") {
        QString city = ui->city->text();
        text.replace(QRegularExpression(user_city), QString(city));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    if(ui->state->text() != "") {
        QString state = ui->state->text();
        text.replace(QRegularExpression(user_state), QString(state));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    if(ui->zip->text() != "") {
        QString zip = ui->zip->text();
        text.replace(QRegularExpression(user_zip), QString(zip));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    if(ui->dob->text() != "") {
        QString dob = ui->dob->text();
        text.replace(QRegularExpression(user_dob), QString(dob));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    if(ui->phone->text() != "") {
        QString phone = ui->phone->text();
        text.replace(QRegularExpression(user_phone), QString(phone));

        myFile.seek(0);
        myFile.write(text.toUtf8());
    }

    myFile.close();

    hide();

    //starts new instance of student dashboard with updated information
    student_dashboard *stud_dboard = new student_dashboard(this);
    stud_dboard->show();
}

edit_information::~edit_information() {
    delete ui;
}

void edit_information::on_pushButton_2_clicked() {
    hide();

    //starts new instance of student dashboard without information change
    student_dashboard *stud_dboard = new student_dashboard(this);
    stud_dboard->show();
}
