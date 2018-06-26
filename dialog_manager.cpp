#include "dialog_manager.h"
#include "ui_dialog_manager.h"

extern string Admin_name;
extern string Admin_password;

dialog_manager::dialog_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_manager)
{
    ui->setupUi(this);
    ui->manager_password->setEchoMode(QLineEdit::Password);
}

dialog_manager::~dialog_manager()
{
    delete ui;
}

/*管理员登录之后的操作*/
void dialog_manager::on_pushButton_clicked()
{
    if(ui->manager_name->text().isEmpty() || ui->manager_password->text().isEmpty())
    {
        QMessageBox::about(0,QObject::tr("fail"),"用户名或密码未填写");
        ui->manager_name->clear(); ui->manager_password->clear();
        return;
    }

    /*判断密码和用户名是否正确*/
    string cur_name = ui->manager_name->text().toStdString();  string cur_pas = ui->manager_password->text().toStdString();
    if(cur_name != Admin_name || cur_pas != Admin_password)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"用户名或密码有误");
        ui->manager_name->clear(); ui->manager_password->clear();
        return;
    }

    //登录成功 内容清空
    ui->manager_name->clear();
    ui->manager_password->clear();

    /*隐藏主窗口，显示子窗口*/
    this->hide();
    manager_ope->show();
}
