#ifndef DIALOG_MANAGER_H
#define DIALOG_MANAGER_H

#include <QDialog>
#include "manager_operations.h"
namespace Ui {
class dialog_manager;
}

class dialog_manager : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_manager(QWidget *parent = 0);
    ~dialog_manager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialog_manager *ui;
    manager_operations * manager_ope = new manager_operations;
};

#endif // DIALOG_MANAGER_H
