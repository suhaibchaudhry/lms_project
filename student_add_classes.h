#ifndef STUDENT_ADD_CLASSES_H
#define STUDENT_ADD_CLASSES_H

#include <QDialog>

namespace Ui {
class student_add_classes;
}

class student_add_classes : public QDialog
{
    Q_OBJECT

public:
    explicit student_add_classes(QWidget *parent = nullptr);
    ~student_add_classes();

private:
    Ui::student_add_classes *ui;
};

#endif // STUDENT_ADD_CLASSES_H
