#include "student_dashboard.h"
#include "ui_student_dashboard.h"
#include "variables.h"

student_dashboard::student_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_dashboard)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(860, 460));

    model = new QStringListModel(this);

    QStringList studentList;

    model->setStringList(studentList);

    ui->listView->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->firstName->setText(user_id);
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
