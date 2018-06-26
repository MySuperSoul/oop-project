#ifndef DIALOG_INTERVIEWEE_H
#define DIALOG_INTERVIEWEE_H

#include <QDialog>
#include <QString>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidget>
#include "interviewee.h"
using namespace std;

namespace Ui {
class Dialog_interviewee;
}

class Dialog_interviewee : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_interviewee(QWidget *parent = 0);
    ~Dialog_interviewee();

private slots:


    void on_register_button_clicked();

    void on_search_information_button_clicked();

    void show_groups(QTableWidget* tableWidget,QVector<QString> &result);
private:
    Ui::Dialog_interviewee *ui;
};

#endif // DIALOG_INTERVIEWEE_H
