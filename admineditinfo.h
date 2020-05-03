#ifndef ADMINEDITINFO_H
#define ADMINEDITINFO_H

#include <QDialog>

namespace Ui {
class admineditinfo;
}

class admineditinfo : public QDialog
{
    Q_OBJECT

public:
    explicit admineditinfo(QWidget *parent = nullptr);
    ~admineditinfo();

private:
    Ui::admineditinfo *ui;
};

#endif // ADMINEDITINFO_H
