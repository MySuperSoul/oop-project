#include "manager_operations.h"
#include "ui_manager_operations.h"

extern vector<class InterViewer> InterViewer_vector; //保存当前的面试官的vector
extern std::vector<std::string> Majority;

manager_operations::manager_operations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager_operations)
{
    ui->setupUi(this);
}

manager_operations::~manager_operations()
{
    delete ui;
}

/*分组按钮点击,Todo*/
void manager_operations::on_divide_group_button_clicked()
{
    QVector<QString> result;//放显示内容
    /*调用当前的分组函数*/
    Admin::judgeGroup();

    for(int i = 0; i < 8; i++) //遍历当前的Group
    {
        for(int j = 0; j < Group[i].size(); j++) //遍历第i个Group的vector
        {
            /*获取当前的信息，插到result数组里面去*/
            QString divide_group = QString::number(i + 1); string name = Group[i][j].get_name(); string stu_id = Group[i][j].get_stu_id();
            string major = Majority[Group[i][j].get_major()]; string class_num = Group[i][j].get_class_num();
            /*cout<<name<<endl;
            cout<<stu_id<<endl;
            cout<<major<<endl;
            cout<<class_num<<endl;*/
            result.push_back(divide_group); result.push_back(QString::fromStdString(name));
            result.push_back(QString::fromStdString(stu_id)); result.push_back(QString::fromStdString(major)); result.push_back(QString::fromStdString(class_num));
        }
    }

    /*更新当前的表单*/
    show_groups(ui->interviewee_divide, result);
}

/*更新分组*/
void manager_operations::show_groups(QTableWidget* tableWidget,QVector<QString> &result)
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

/*执行当前设置，待做选项，可不做*/
void manager_operations::on_exec_button_clicked()
{
    QMessageBox::about(0,QObject::tr("Success"),"设置成功执行");
}

/*管理员查询面试官的信息*/
void manager_operations::on_search_viewer_button_clicked()
{
    QVector<QString> result; //用来保存面试官的信息

    /*保存所有的面试者信息*/
    for(int i = 0; i < InterViewer_vector.size(); i++)
    {
        QString id = QString::number(InterViewer_vector[i].id); result.push_back(id);
        QString name = QString::fromStdString(InterViewer_vector[i].name); result.push_back(name);
        QString is_valid = (InterViewer_vector[i].is_valid == true) ? "True" : "False"; result.push_back(is_valid);
        QString password = QString::fromStdString(InterViewer_vector[i].password); result.push_back(password);
    }

    show_interviewer(ui->interviewer_table, result);
}

/*更新表单*/
void manager_operations::show_interviewer(QTableWidget* tableWidget,QVector<QString> &result)
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

/*确认修改权限的选项*/
void manager_operations::on_confirm_button_clicked()
{
    if(ui->interviewer_id->text().isEmpty())
    {
        QMessageBox::about(0,QObject::tr("Fail"),"编号未输入");
        return;
    }

    string interviewer_id = ui->interviewer_id->text().toStdString(); //面试官的编号
    /*判断面试官编号是否有效*/
    int read_id = stoi(interviewer_id);
    if(read_id <= 0 || read_id > InterViewer_vector.size())
    {
        QMessageBox::about(0,QObject::tr("Fail"),"编号范围有误");
        return;
    }

    /*编号无误*/
    Admin::judgeInterviewer(read_id); //权限设为true
    QMessageBox::about(0,QObject::tr("Success"),"修改权限成功");
    ui->interviewer_id->clear();//改了一个的权限后清空显示
    on_search_viewer_button_clicked(); //动态更新
}
