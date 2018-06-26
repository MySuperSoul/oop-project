#include "dialog_interviewer.h"
#include "ui_dialog_interviewer.h"

extern string real_key; //注册时的校验码

dialog_interviewer::dialog_interviewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_interviewer)
{
    ui->setupUi(this);
    ui->password_line->setEchoMode(QLineEdit::Password);
    ui->password_again->setEchoMode(QLineEdit::Password);
    ui->password_login->setEchoMode(QLineEdit::Password);
}

dialog_interviewer::~dialog_interviewer()
{
    delete ui;
}

/*面试官登录之后的页面跳转*/
void dialog_interviewer::on_interviewer_login_clicked()
{
    int temp_id; //记住当前的面试者id
    if(ui->name_login->text().isEmpty() || ui->password_login->text().isEmpty())
    {
        QMessageBox::about(0,QObject::tr("fail"),"信息未填写完全");
        ui->name_login->clear();  ui->password_login->clear(); //清空当前的输入栏
        return;
    }

    bool flag = false; string real_password;
    string name = ui->name_login->text().toStdString();  string password = ui->password_login->text().toStdString();

    for(int i = 0; i < InterViewer_vector.size(); i++)
    {
        if(name == InterViewer_vector[i].name && InterViewer_vector[i].is_valid == true)
        {
            flag = true;
            real_password = InterViewer_vector[i].password;
            password = InterViewer_vector[i].confirmation(password);
            temp_id = i + 1; //保存id
        }
    }

    /*判断name是否存在*/
    if(flag == false)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"当前用户名不存在或者并没有权限");
        ui->name_login->clear();  ui->password_login->clear(); //清空当前的输入栏
        return;
    }

    if(password != real_password)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"密码错误");
        ui->name_login->clear();  ui->password_login->clear(); //清空当前的输入栏
        return;
    }

    /*成功之后，隐藏当前窗口，打开新的子窗口*/
    inter_ope->thisname = ui->name_login->text();
    inter_ope->this_id = temp_id;
    ui->name_login->clear();
    ui->password_login->clear();//登录成功 内容清空
    this->hide();
    inter_ope->show();
}

/*点击面试官的注册*/
void dialog_interviewer::on_register_button_clicked()
{
    if(ui->name_line->text().isEmpty() || ui->password_line->text().isEmpty() || ui->password_again->text().isEmpty()
    || ui->key->text().isEmpty()) //有信息未填写的机制
    {
        QMessageBox::about(0,QObject::tr("fail"),"信息未填写完全");
        return;
    }

    //将所有信息转成string类型
    string name = ui->name_line->text().toStdString(); string password = ui->password_line->text().toStdString();
    string password_again = ui->password_again->text().toStdString(); string key = ui->key->text().toStdString();

    /*两次输入的密码不同*/
    if(password != password_again)
    {
        QMessageBox::about(0,QObject::tr("fail"),"两次密码填写不相同，请再次输入");
        ui->password_again->clear();  ui->password_line->clear();
        ui->name_line->clear();  ui->key->clear(); //将填写的信息全部清空
        return;
    }

    /*校验码不同*/
    if(key != real_key)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"校验码不同");
        return;
    }

    /*创建对象，并且对密码进行加密*/
    int cur_id = InterViewer_vector.size() + 1;
    InterViewer temp(cur_id, name, password, false);
    temp.password = temp.confirmation(password);

    /*处理完之后，插到vector里面去*/
    InterViewer_vector.push_back(temp);

    QMessageBox::about(0,QObject::tr("Success"),"恭喜您注册成功");
    //一旦面试官注册成功，显示内容清空
    ui->name_line->clear();
    ui->password_line->clear();
    ui->password_again->clear();
    ui->key->clear();

}
