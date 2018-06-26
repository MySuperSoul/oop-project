#ifndef INTERVIEWER_OPERATIONS_H
#define INTERVIEWER_OPERATIONS_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QDebug>
#include <string>
#include <QMessageBox>
#include <QTableWidget>
#include "interviewer.h"
#include "interviewee.h"
namespace Ui {
class interviewer_operations;
}

class interviewer_operations : public QDialog
{
    Q_OBJECT

public:
    explicit interviewer_operations(QWidget *parent = 0);
    ~interviewer_operations();

    QString thisname; //记录下登录上来的管理员名
    int this_id; //记录下登录上来的管理员编号
private slots:
    void on_search_button_clicked();

    void on_confirm_score_clicked();

    void show_groups(QTableWidget* tableWidget,QVector<QString> &result);
private:
    Ui::interviewer_operations *ui;
};

#endif // INTERVIEWER_OPERATIONS_H
