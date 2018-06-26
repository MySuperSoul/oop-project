#include "interviewer_operations.h"
#include "ui_interviewer_operations.h"

extern vector<class interviewee> interviewee_collection; //保存面试者的信息
extern vector<vector<class interviewee>> Group;
extern std::vector<std::string> Department;
extern vector<string> interview_time;

interviewer_operations::interviewer_operations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interviewer_operations)
{
    ui->setupUi(this);
}

interviewer_operations::~interviewer_operations()
{
    delete ui;
}

/*查询该对应场次的面试者的信息*/
void interviewer_operations::on_search_button_clicked()
{
    QVector<QString> result; //用来最后输出信息用的
    QString infor = "管理员:"+thisname+" 您好~";
    ui->information->setText(infor); //输出对应的登录信息

    int session_id = (this_id - 1) % 8; //分配当前的面试官场次

    for(int i = 0; i < Group[session_id].size(); i++)
    {
        qDebug() << "here" + QString::number(i);
        int id = Group[session_id][i].get_id(); result.push_back(QString::number(id));
        string name = Group[session_id][i].get_name(); result.push_back(QString::fromStdString(name));
        string stu_id = Group[session_id][i].get_stu_id(); result.push_back(QString::fromStdString(stu_id));
        string class_num = Group[session_id][i].get_class_num(); result.push_back(QString::fromStdString(class_num));
        int first = Group[session_id][i].get_first_aspiration(); result.push_back(QString::fromStdString(Department[first]));
        int second = Group[session_id][i].get_second_aspiration(); result.push_back(QString::fromStdString(Department[second]));
        bool flag = Group[session_id][i].get_is_subject(); result.push_back((flag == true) ? "是" : "否");
    }

    if(Group[session_id].size() != 0)
        show_groups(ui->interviewee_info_table, result);
}

void interviewer_operations::show_groups(QTableWidget* tableWidget,QVector<QString> &result)
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

/*确认打分的机制*/
void interviewer_operations::on_confirm_score_clicked()
{
    if(ui->score_id_line->text().isEmpty() || ui->score_line->text().isEmpty())
    {
        QMessageBox::about(0,QObject::tr("Fail"),"编号或者分数未填写");
        ui->score_id_line->clear(); ui->score_line->clear();
        return;
    }

    /*获取到当前的编号以及对应的打分*/
    std::string score_id = ui->score_id_line->text().toStdString(); std::string cur_score = ui->score_line->text().toStdString();

    /*判断当前的编号是否符合规则*/
    int i_d = stoi(score_id);
    if(i_d <= 0 || i_d > (interviewee_collection.size()))
    {
        QMessageBox::about(0,QObject::tr("Fail"),"编号不符合规则");
        ui->score_id_line->clear(); ui->score_line->clear();
        return;
    }

    /*判断所打分数是否规范*/
    int c_score = stoi(cur_score);
    if(c_score < 0 || c_score > 100)
    {
        QMessageBox::about(0,QObject::tr("Fail"),"分数范围（0~100）有误");
        ui->score_id_line->clear(); ui->score_line->clear();
        return;
    }

    /*面试者编号与分数都符合规则*/
    score temp(i_d, this_id, c_score); //创建score对象
    Score_vector.push_back(temp); //放到分数容器当中，每个对应的面试者编号可以重复打分

    QMessageBox::about(0,QObject::tr("Success"),"打分成功！");
    ui->score_id_line->clear(); ui->score_line->clear();
}
