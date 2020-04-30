#include "mainwindow.h"
#include "variables.h"
#include <QMessageBox>
#include <QDebug>
#include "faculty_dashboard.h"
#include "ui_faculty_dashboard.h"

faculty_dashboard::faculty_dashboard(QWidget *parent):QDialog(parent), ui(new Ui::faculty_dashboard) {
    ui->setupUi(this);
    model2 = new QStringListModel(this);


    ui->listView->setModel(model2);

    QString courseList = curr_path + "courseList" + ".dat";
    QFile courses(courseList);
    if(!courses.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "User Not Found");
    }
    else
    {

        while(!courses.atEnd())
        {

            QString line = courses.readLine().trimmed();
            studentList << line;
        }
    }
    model2->setStringList(studentList);
}

faculty_dashboard::~faculty_dashboard() {
    delete ui;
}

void faculty_dashboard::on_pushButton_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    qDebug() << itemText;
    //QString current = ui->listView->selectionModel()->selectedIndexes();
    //details
}
