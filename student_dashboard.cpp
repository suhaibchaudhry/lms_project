#include "student_dashboard.h"
#include "ui_student_dashboard.h"
#include "mainwindow.h"
#include "variables.h"
#include <QMessageBox>
#include <QDebug>

student_dashboard::student_dashboard(QWidget *parent):QDialog(parent), ui(new Ui::student_dashboard) {
    ui->setupUi(this);

    //sets a fixed size for the window
    this->setFixedSize(QSize(860, 460));

    //creates a new model

    model = new QStringListModel(this);
    model->setStringList(studentList);


    //for (int i = 0; i < studentList.size(); ++i)
    //         qDebug() << studentList.at(i).toLocal8Bit().constData() << Qt::endl;


    //sets the ui listview to the model
    ui->listView->setModel(model);

    //prevents triggers on the model
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //opens student info file
    QString filename = curr_path + user_id + "_info.dat";
    QFile myFile(filename);

    //opens file in read-only mode
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        //assigns the first line of the text file to the variable line
        QTextStream stream(&myFile);
        QString line = stream.readLine();
        ui->firstName->setText(line);

        //assigns the next line to the variable line
        line = stream.readLine();
        ui->lastName->setText(line);

        line = stream.readLine();
        ui->address->setText(line);

        line = stream.readLine();
        ui->city->setText(line);

        line = stream.readLine();
        ui->state->setText(line);

        line = stream.readLine();
        ui->zip->setText(line);

        line = stream.readLine();
        ui->dob->setText(line);

        line = stream.readLine();
        ui->phone->setText(line);
    }

    myFile.close();
}

student_dashboard::~student_dashboard() {
    delete ui;
}

void student_dashboard::on_pushButton_3_clicked() {
    //add new course
    int row = model->rowCount();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);

    ui->listView->setCurrentIndex(index);

    ui->listView->edit(index);
}

void student_dashboard::on_pushButton_2_clicked() {
    //delete selected course
    model->removeRows(ui->listView->currentIndex().row(), 1);

}

void student_dashboard::on_pushButton_4_clicked() {
     //opens new instance of edit_information window
     hide();
     edit_info = new edit_information(this);
     edit_info->show();
}
