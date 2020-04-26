#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(QSize(325, 125));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loginButton_clicked() {
    ifstream myFile("/Users/chaud/Google Drive/School/CS3321/team_project/lms_project/auth.dat");
    QString username = ui->username_text->text();
    QString password = ui->password_text->text();
    string user_auth;
    string pass_auth;

    if(myFile) {
        getline(myFile, user_auth);
        getline(myFile, pass_auth);
    } else {
        QMessageBox::critical(this, "Error", "Authentication File Not Found");
    }

    QString user = QString::fromStdString(user_auth);
    QString pass = QString::fromStdString(pass_auth);

    if(username == user && password == pass) {
        //QMessageBox::information(this, "Login", "Username and password are correct!");
        hide();
        stud_dboard = new student_dashboard(this);
        stud_dboard->show();
    } else {
        QMessageBox::information(this, "Login", "Username and password are wrong!");
    }
}
