#include "dialog_interviewee.h"
#include "ui_dialog_interviewee.h"
#include "interviewer.h"
extern vector<class interviewee> interviewee_collection; //保存面试者的信息
extern vector<string> interview_time;
extern vector<class score> Score_vector;

Dialog_interviewee::Dialog_interviewee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_interviewee)
{
    ui->setupUi(this);
}

Dialog_interviewee::~Dialog_interviewee()
{
    delete ui;
}

/*注册按钮被点击的事件*/
void Dialog_interviewee::on_register_button_clicked()
{
    if(ui->name->text().isEmpty() || ui->student_id->text().isEmpty() || ui->class_num->text().isEmpty() || ui->phone->text().isEmpty() || ui->birthday->text().isEmpty() || ui->birth_place->text().isEmpty() || ui->habit->text().isEmpty() || ui->introduction->text().isEmpty())
    {
        QMessageBox::about(0,QObject::tr("fail"),"信息未填写完整");
        return;
    }
    string name = ui->name->text().toStdString(); string stu_id = ui->student_id->text().toStdString();
    string major = ui->major->currentText().toStdString(); string class_id = ui->class_num->text().toStdString();
    string phone = ui->phone->text().toStdString(); string birth_place = ui->birth_place->text().toStdString();
    string birthday = ui->birthday->text().toStdString(); string habit = ui->habit->text().toStdString();
    string introduction = ui->introduction->text().toStdString(); string first = ui->first->currentText().toStdString();
    string second = ui->second->currentText().toStdString(); bool is_subjective = (ui->is_subjective->currentText().toStdString() == "是") ? true : false;
    /*判断基本信息是否合法*/
    bool flag;
    flag = check_format_phone(phone);
    if(flag == false)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"手机号不符合格式");
        return;
    }//判断手机号

    flag = check_format_stuid(stu_id);
    if(flag == false)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"学号不符合ZJU学号格式");
        return;
    }//判断学号是否合法

    /*全部合法，创建对象*/
    int cur_id = interviewee_collection.size() + 1;
    interviewee temp(cur_id, name, stu_id, major, class_id, phone, birth_place, birthday, habit, introduction,
    first, second, is_subjective); //创建一个temp的面试者的对象

    /*判断是否已经注册*/
    flag = check_duplicate(temp);
    if(flag == false)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"学号已注册");
        return;
    }//判断是否重复注册

    /*都符合条件*/
    interviewee_collection.push_back(temp);
    QMessageBox::about(0,QObject::tr("Success"),"注册成功!");
    //注册成功之后需要清除显示内容
    ui->name->clear();
    ui->student_id->clear();
    ui->class_num->clear();
    ui->phone->clear();
    ui->birthday->clear();
    ui->birth_place->clear();
    ui->habit->clear();
    ui->introduction->clear();
}

/*面试者信息查询*/
void Dialog_interviewee::on_search_information_button_clicked()
{
    //一旦开始点击查询按钮，之前显示的信息需要先清空
    ui->session_table->clearContents();

    bool flag = false;
    interviewee temp; //用来保存下来刚刚找到的面试者信息
    QVector<QString> result; //保存信息用于输出

    if(ui->stu_id_line->text().isEmpty())
    {
        QMessageBox::about(0,QObject::tr("Fail"),"学号未填写");
        return;
    }

    string stu_id = ui->stu_id_line->text().toStdString(); //获取到输入的学号信息

    /*判断学号是否存在*/
    for(int i = 0; i < interviewee_collection.size(); i++)
    {
        if(stu_id == interviewee_collection[i].get_stu_id())
        {
            flag = true;
            temp = interviewee_collection[i];
            break;
        }
    }

    int count = 0; //用来判断在score vector里面是否已经打分
    int cur_score = 0; //平均分

    /*根据flag的状态来判断*/
    if(flag == false)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"学号不存在");
        return;
    }
    else
    {
        /*遍历interviewee_collection vector得到对应的编号,用对应的temp进行判断*/
        QString c_id = QString::number(temp.get_session_id()); result.push_back(c_id);
        QString time = QString::fromStdString(interview_time[temp.get_session_id() - 1]); result.push_back(time);
        result.push_back("小剧场311");

        for(int i = 0; i < Score_vector.size(); i++)
        {
            if(Score_vector[i].interviewee_id == temp.id)
            {
                count++;
                cur_score += Score_vector[i].current_score;
            }
        }

        if(count == 0)
        {
            result.push_back("未面试");
            result.push_back("");
        }
        else
        {
            result.push_back("已面试");
            double avg = cur_score * 1.0 / count;
            result.push_back(QString::number(avg, 10, 2));
        }

    }

    show_groups(ui->session_table, result);
}

/*更新分组*/
void Dialog_interviewee::show_groups(QTableWidget* tableWidget,QVector<QString> &result)
{
    int col = tableWidget->columnCount();
    int row = tableWidget->rowCount();

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i * col + j + 1 <= result.size()) //利用总个数进行比较
                tableWidget->setItem(i,j,new QTableWidgetItem(result[i * col + j])); //更新表单
            else
                tableWidget->setItem(i,j,new QTableWidgetItem(""));
        }
    }
}
