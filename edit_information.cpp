#include "edit_information.h"
#include "ui_edit_information.h"

edit_information::edit_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_information)
{
    ui->setupUi(this);
}

edit_information::~edit_information()
{
    delete ui;
}
