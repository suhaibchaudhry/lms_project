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

    QFile myFile(":/auth/resources/student_auth.dat");

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
    }

    if(username == user_auth && password == pass_auth) {
        hide();
        stud_dboard = new student_dashboard(this);
        stud_dboard->show();
    } else {
        QMessageBox::information(this, "Login", "Username and password are wrong!");
    }
}
