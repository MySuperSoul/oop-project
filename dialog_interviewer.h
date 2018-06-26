#ifndef DIALOG_INTERVIEWER_H
#define DIALOG_INTERVIEWER_H

#include <QDialog>
#include <QString>
#include <string>
#include <QDebug>
#include <QMessageBox>

#include "interviewer_operations.h"
#include "interviewer.h"
namespace Ui {
class dialog_interviewer;
}

class dialog_interviewer : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_interviewer(QWidget *parent = 0);
    ~dialog_interviewer();

private slots:
    void on_interviewer_login_clicked();

    void on_register_button_clicked();

private:
    Ui::dialog_interviewer *ui;
    interviewer_operations * inter_ope = new interviewer_operations;
};

#endif // DIALOG_INTERVIEWER_H
