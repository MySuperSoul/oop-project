#ifndef ADMIN_H_
#define ADMIN_H_

#include"interviewee.h"
#include"interviewer.h"

extern vector<class interviewee> Session1_vector;
extern vector<class interviewee> Session2_vector;
extern vector<class interviewee> Session3_vector;
extern vector<class interviewee> Session4_vector;
extern vector<class interviewee> Session5_vector;
extern vector<class interviewee> Session6_vector;
extern vector<class interviewee> Session7_vector;
extern vector<class interviewee> Session8_vector;//根据一志愿以及是否服从调剂分为8个组，里面存放相应被面试者信息
extern vector<vector<class interviewee>> Group; //二维的数组,push进上面的8个vector

extern vector<class interviewee> interviewee_collection;

extern vector<class InterViewer> InterViewer_vector;

class Admin {
public:
	int signup_begin_month;
	int signup_begin_day;
	int signup_end_month;
	int signup_end_day;//管理员可以设置面试报名开始与截止的日期

	Admin(int a,int b,int c,int d) {
		signup_begin_month = a;
		signup_begin_day = b;
		signup_end_month= c;
		signup_end_day = d;
	}


	static string confirmation(string pass_word); //处理密码

    static void judgeGroup();//根据第一志愿与是否服从调剂进行分组

    static void judgeInterviewer(int num);//根据给定的面试者编号，将其登录权限改为true

};

bool admin_login(string password);//判断管理员登录情况
#endif
