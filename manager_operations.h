#ifndef MANAGER_OPERATIONS_H
#define MANAGER_OPERATIONS_H

#include <QDialog>
#include <QMessageBox>
#include <string>
#include <QString>
#include <QVector>
#include <QTableWidget>
#include "admin.h"
using namespace std;

namespace Ui {
class manager_operations;
}

class manager_operations : public QDialog
{
    Q_OBJECT

public:
    explicit manager_operations(QWidget *parent = 0);
    ~manager_operations();

private slots:
    void on_divide_group_button_clicked();

    void on_exec_button_clicked();

    void on_search_viewer_button_clicked();

    void on_confirm_button_clicked();

    void show_interviewer(QTableWidget* tableWidget,QVector<QString> &result);

    void show_groups(QTableWidget* tableWidget,QVector<QString> &result);
private:
    Ui::manager_operations *ui;
};

#endif // MANAGER_OPERATIONS_H
