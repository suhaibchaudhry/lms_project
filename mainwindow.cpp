#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "variables.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(QSize(325, 140));
    QDir::setCurrent(QStringLiteral("../lms_project/resources/"));
    curr_path = QDir::currentPath() + "/";
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

    QString filename = curr_path + username + "_auth.dat";
    QFile myFile(filename);

    QString user_check = ui->comboBox->currentText();

    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Authentication File Not Found");
    } else {
        while(!myFile.atEnd()) {
            user_auth = myFile.readLine();
            user_auth = user_auth.trimmed();
            pass_auth = myFile.readLine();
            pass_auth = pass_auth.trimmed();
        }
    }

    if(username == user_auth && password == pass_auth) {
        user_id = username;
        hide();
        if(user_check == "Student") {
            stud_dboard = new student_dashboard(this);
            stud_dboard->show();
        } else if(user_check == "Teacher") {
            fac_dboard = new faculty_dashboard(this);
            fac_dboard->show();
        }
    } else {
        QMessageBox::information(this, "Login", "Username and password are wrong!");
    }
}
