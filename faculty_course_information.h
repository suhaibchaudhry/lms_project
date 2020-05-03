#ifndef FACULTY_COURSE_INFORMATION_H
#define FACULTY_COURSE_INFORMATION_H

#include <QDialog>

namespace Ui {
class faculty_course_information;
}

class faculty_course_information : public QDialog
{
    Q_OBJECT

public:
    explicit faculty_course_information(QWidget *parent = nullptr);
    ~faculty_course_information();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::faculty_course_information *ui;
};

#endif // FACULTY_COURSE_INFORMATION_H
