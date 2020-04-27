#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QFile>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(QSize(325, 125));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loginButton_clicked() {
    QString username = ui->username_text->text();
    QString password = ui->password_text->text();

    QString user_auth;
    QString pass_auth;
    QString fac_auth;
    QString facpass_auth;

    QFile myFile(":/auth/resources/student_auth.dat");
    QFile Fac(":/auth/resources/teacher_auth.txt");

    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Authentication File Not Found");
    } else {
        while(!myFile.atEnd()) {
            user_auth = myFile.readLine();
            user_auth = user_auth.trimmed();
            qDebug() << username;
            qDebug() << user_auth;
            pass_auth = myFile.readLine();
            pass_auth = pass_auth.trimmed();
            qDebug() << password;
            qDebug() << pass_auth;
        }
        while(!Fac.atEnd()) {
            fac_auth = Fac.readLine();
            fac_auth = fac_auth.trimmed();
            qDebug() << username;
            qDebug() << fac_auth;
            pass_auth = Fac.readLine();
            pass_auth = facpass_auth.trimmed();
            qDebug() << password;
            qDebug() << facpass_auth;
        }
    }

    if(username == user_auth && password == pass_auth) {
        hide();
        stud_dboard = new student_dashboard(this);
        stud_dboard->show();
    }
    else if(username == fac_auth && password == facpass_auth)
    {
        hide();
        fac_dboard = new faculty_dashboard(this);
        fac_dboard->show();;
    }
    else {
        QMessageBox::information(this, "Login", "Username and password are wrong!");
    }
}
