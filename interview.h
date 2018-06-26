#ifndef INTERVIEW_H
#define INTERVIEW_H

#include "admin.h"

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

std::vector<std::string> Department = { "办公室", "人资部门", "组织部", "宣传部" };
std::vector<std::string> Majority = { "计算机科学与技术", "软件工程", "信息安全", "数字媒体技术", "工业设计", "产业设计" };

string Admin_password = "12345";

int a()
{
	score temp(1, 1, 1);
	Score_vector.push_back(temp);
	return 1;
}

#endif // !INTERVIEW_H

