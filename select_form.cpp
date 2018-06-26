#include "select_form.h"
#include "ui_select_form.h"

extern void rewrite();
select_form::select_form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::select_form)
{
    ui->setupUi(this);
}

select_form::~select_form()
{
    delete ui;
    rewrite();
}

void select_form::on_pushButton_clicked()
{
    //this->hide();
    temp->show();
}

void select_form::on_pushButton_2_clicked()
{
    inter_viewer->show();
}

void select_form::on_pushButton_3_clicked()
{
    manager->show();
}
