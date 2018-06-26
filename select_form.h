#ifndef SELECT_FORM_H
#define SELECT_FORM_H

#include <QMainWindow>
#include "dialog_interviewee.h"
#include "dialog_interviewer.h"
#include "dialog_manager.h"

namespace Ui {
class select_form;
}

class select_form : public QMainWindow
{
    Q_OBJECT

public:
    explicit select_form(QWidget *parent = 0);
    ~select_form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::select_form *ui;
    Dialog_interviewee * temp = new Dialog_interviewee;
    dialog_interviewer * inter_viewer = new dialog_interviewer;
    dialog_manager * manager = new dialog_manager;
};

#endif // SELECT_FORM_H
