#include "student_dashboard.h"
#include "ui_student_dashboard.h"

student_dashboard::student_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_dashboard)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(860, 460));

    model = new QStringListModel(this);

    QStringList studentList;
    //studentList << "CS1436" << "CS1437" << "CS2425" << "CS2436" << "CS1408" <<
    //        "CS2301" << "CS2302" << "CS3306" << "CS3310" << "CS3321" <<
    //        "CS4300" << "CS4315" << "CS4318";

    model->setStringList(studentList);

    ui->listView->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

student_dashboard::~student_dashboard()
{
    delete ui;
}

void student_dashboard::on_pushButton_3_clicked()
{
    //add
    int row = model->rowCount();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void student_dashboard::on_pushButton_2_clicked()
{
    //delete
    model->removeRows(ui->listView->currentIndex().row(), 1);
}
