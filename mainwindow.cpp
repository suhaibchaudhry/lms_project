#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "variables.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //sets a fixed size for the window
    this->setFixedSize(QSize(325, 140));

    //sets the global variable of curr_path to the relative resources path
    QDir::setCurrent(QStringLiteral("../lms_project/resources/"));
    curr_path = QDir::currentPath() + "/";
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loginButton_clicked() {
    //set the username and password entered by the user
    QString username = ui->username_text->text();
    QString password = ui->password_text->text();

    //create variables for user authentication
    QString user_auth;
    QString pass_auth;

    //open authentication file
    QString filename = curr_path + username + "_auth.dat";
    QFile myFile(filename);

    //set variable user_check to match category of user
    QString user_check = ui->comboBox->currentText();

    //open the file as readonly
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Authentication File Not Found");
    } else {
        //read the file line by line
        while(!myFile.atEnd()) {
            //set authentication variables line by line
            user_auth = myFile.readLine();
            //trim the trailing new line character
            user_auth = user_auth.trimmed();
            pass_auth = myFile.readLine();
            pass_auth = pass_auth.trimmed();
        }
    }

    //check whether the username entered by the user matches the username and password set
    if(username == user_auth && password == pass_auth) {
        //set global variable to use in other windows
        user_id = username;
        hide();

        //start new window based on category of user
        if(user_check == "Student") {
            stud_dboard = new student_dashboard(this);
            stud_dboard->show();
        } else if(user_check == "Teacher") {
            fac_dboard = new faculty_dashboard(this);
            fac_dboard->show();
        }else if(user_check == "Admin") {
            adm_dboard = new admin_dashboard(this);
            adm_dboard->show();
        }
    } else {
        QMessageBox::information(this, "Login", "Username and password are wrong!");
    }
}
