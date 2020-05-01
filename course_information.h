#ifndef COURSE_INFORMATION_H
#define COURSE_INFORMATION_H

#include <QDialog>

namespace Ui {
class course_information;
}

class course_information : public QDialog
{
    Q_OBJECT

public:
    explicit course_information(QWidget *parent = nullptr);
    ~course_information();

private:
    Ui::course_information *ui;
};

#endif // COURSE_INFORMATION_H
