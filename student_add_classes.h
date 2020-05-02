#ifndef STUDENT_ADD_CLASSES_H
#define STUDENT_ADD_CLASSES_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class student_add_classes;
}

class student_add_classes : public QDialog
{
    Q_OBJECT

public:
    explicit student_add_classes(QWidget *parent = nullptr);
    ~student_add_classes();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::student_add_classes *ui;
    QStringListModel *courseList;
};

#endif // STUDENT_ADD_CLASSES_H
