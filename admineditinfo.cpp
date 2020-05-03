#include "admineditinfo.h"
#include "ui_admineditinfo.h"

admineditinfo::admineditinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admineditinfo)
{
    ui->setupUi(this);
}

admineditinfo::~admineditinfo()
{
    delete ui;
}
