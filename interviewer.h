#ifndef INTERVIEWER_H
#define INTERVIEWER_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

extern vector<class InterViewer> InterViewer_vector; //保存当前的面试官的vector
extern vector<class score> Score_vector; //保存当前打分的vector

/*Interviewer class*/
class InterViewer
{
public:
    InterViewer(){}
	InterViewer(int i, string n, string p, bool v = false)
	{
		id = i;
		name = n;
		password = p;
        is_valid = v;
	}
	~InterViewer();

	string confirmation(string pass_word); //处理当前密码

/*公有数据区，为了方便起见*/
	int id;
	string name;
	string password;
	bool is_valid; //判断是否有效的注册
};

/*score class*/
class score
{
public:
    score(){}
	score(int id_1, int id_2, int c_score) //构造函数
	{
		interviewee_id = id_1;
		interviewer_id = id_2;
		current_score = c_score;
	}

	int interviewee_id; //面试者编号
	int interviewer_id; //面试官编号
	int current_score; //当前的打分情况
};

bool interviewer_login(string name, string password);//判断当前的登录情况
#endif // !INTERVIEWER_H

