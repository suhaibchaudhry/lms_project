#include "student_dashboard.h"
#include "ui_student_dashboard.h"
#include "mainwindow.h"
#include "variables.h"
#include <QMessageBox>

student_dashboard::student_dashboard(QWidget *parent):QDialog(parent), ui(new Ui::student_dashboard) {
    ui->setupUi(this);
    this->setFixedSize(QSize(860, 460));

    model = new QStringListModel(this);

    QStringList studentList;

    model->setStringList(studentList);

    ui->listView->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QString filename = curr_path + user_id + "_info.dat";
    QFile myFile(filename);

    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    } else {
        QTextStream stream(&myFile);
        QString line = stream.readLine();
        ui->firstName->setText(line);

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
    //add
    int row = model->rowCount();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void student_dashboard::on_pushButton_2_clicked() {
    //delete
    model->removeRows(ui->listView->currentIndex().row(), 1);
}

void student_dashboard::on_pushButton_4_clicked() {
     hide();
     edit_info = new edit_information(this);
     edit_info->show();
}
