#include "select_form.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <string>
#include <QString>
#include <fstream>

#include "admin.h"
using namespace std;
vector<class InterViewer> InterViewer_vector; //保存当前的面试官的vector
vector<class score> Score_vector; //保存当前打分的vector
vector<class interviewee> interviewee_collection; //保存面试者的信息

vector<class interviewee> Session1_vector;
vector<class interviewee> Session2_vector;
vector<class interviewee> Session3_vector;
vector<class interviewee> Session4_vector;
vector<class interviewee> Session5_vector;
vector<class interviewee> Session6_vector;
vector<class interviewee> Session7_vector;
vector<class interviewee> Session8_vector;//根据一志愿以及是否服从调剂分为8个组，里面存放相应被面试者信息
vector<vector<class interviewee>> Group; //二维的数组,push进上面的8个vector

std::vector<std::string> Department = { "办公室", "人资部门", "组织部", "宣传部" };
std::vector<std::string> Majority = { "计算机科学与技术", "软件工程", "信息安全", "数字媒体技术", "工业设计", "产业设计" };
vector<string> interview_time = {"2:30", "2:40", "2:50", "3:00", "3:10", "3:20", "3:30", "3:40"};
string Admin_name = "oop_manager";
string Admin_password = "oop_class";
string real_key = "oop_class"; //面试官注册校验码
QString Interviewer_name;

void rewrite(); //重写回当前文件
void reload(); //从文件中重新读回来

class CommonHelper
{
public:
    static void setStyle(const QString &style) {
        qDebug()<<"hello";
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //reload();
    select_form w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));//solve the encoding problem
    CommonHelper::setStyle(":/ui.qss");
    w.show();

    return a.exec();
}

/*写回到对应的文件里面去*/
void rewrite()
{
    ofstream file("interviewee.txt"); //打开interviewee.txt
    for(int i = 0; i < interviewee_collection.size(); i++)
    {
        interviewee temp = interviewee_collection[i];
        file << temp.id << endl; file << temp.name << endl; file << temp.stu_id << endl; file << temp.class_num << endl;
        file << temp.aspiration[0] << endl; file << temp.aspiration[1] << endl; file << temp.major << endl;
        file << temp.is_subject << endl;
    }
    file.close();

    ofstream file_1("interviewer.txt"); //打开interviewer.txt
    if(file_1.is_open())
    {
        qDebug() << "here";
        file_1 << 1;
    }

    for(int i = 0; i < InterViewer_vector.size(); i++)
    {
        qDebug() << "here";
        //file << InterViewer_vector[i].id << endl; file << InterViewer_vector[i].name << endl;
        //file << InterViewer_vector[i].password << endl; file << InterViewer_vector[i].is_valid << endl;
    }

    file_1.close();

    file.open("score.txt"); //打开score.txt
    if(file.is_open())
        qDebug() << 1;
    for(int i = 0; i < Score_vector.size(); i++)
    {
        score temp = Score_vector[i];
        file << temp.interviewee_id << endl; file << temp.interviewer_id << endl; file << temp.current_score << endl;
    }
    file.close();
}

/*程序启动时自动读取文件插回容器中*/
void reload()
{
    ifstream file("interviewee.txt");
    while(!file.eof())
    {
        interviewee temp; //创建临时对象
        int id, as_0, as_1, major;
        string name, stu_id, class_num;
        bool is_subject;

        /*重新取回当前的信息*/
        file >> id >> name >> stu_id >> class_num >> as_0 >> as_1 >> major >> is_subject;
        temp.id = id; temp.name = name; temp.stu_id = stu_id; temp.class_num = class_num;
        temp.aspiration[0] = as_0; temp.aspiration[1] = as_1; temp.major = major; temp.is_subject = is_subject;

        interviewee_collection.push_back(temp);
    }
    file.close();

    file.open("interviewer.txt");
    while(!file.eof())
    {
        InterViewer temp;
        int id; bool is_valid;
        string name, password;

        file >> id >> name >> password >> is_valid;
        temp.id = id; temp.name = name; temp.password = password; temp.is_valid = is_valid;

        InterViewer_vector.push_back(temp);
    }
    file.close();

    file.open("score.txt");
    while(!file.eof())
    {
        score temp;
        int id1, id2, c_score;

        file >> id1 >> id2 >> c_score;
        temp.interviewee_id = id1; temp.interviewer_id = id2; temp.current_score = c_score;

        Score_vector.push_back(temp);
    }
    file.close();
}
