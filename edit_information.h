#ifndef EDIT_INFORMATION_H
#define EDIT_INFORMATION_H

#include <QDialog>

namespace Ui {
class edit_information;
}

class edit_information : public QDialog
{
    Q_OBJECT

public:
    explicit edit_information(QWidget *parent = nullptr);
    ~edit_information();

private:
    Ui::edit_information *ui;
};

#endif // EDIT_INFORMATION_H
