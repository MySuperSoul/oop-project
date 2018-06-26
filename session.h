#ifndef SESSION_H_
#define SESSION_H_

#include<iostream>
#include<string>
#include<vector>

class session
{
private:
	int id;//存储面试者报名id
	int month;
	int day;
	int start_hour;//0-24
	int start_minute;//0-59
	int end_hour;//0-24
	int end_minute;//0-59
	int num;//面试者在某场中的编号
public:
	session(){}
	session(int i,int a,int b,int c,int d,int e,int f,int g)
	{
		id = i;
		month = a;
		day = b;
		start_hour = c;
		start_minute = d;
		end_hour = e;
		end_minute = f;
		num = g;
	}
	std::string session_to_string()
	{
		std::string result;
		result.push_back(month / 10 + '0');
		result.push_back(month % 10 + '0');
		result.push_back('-');
		result.push_back(day / 10 + '0');
		result.push_back(day % 10 + '0');
		result.push_back(' ');
		result.push_back(start_hour / 10 + '0');
		result.push_back(start_hour % 10 + '0');
		result.push_back(':');
		result.push_back(start_minute / 10 + '0');
		result.push_back(start_minute % 10 + '0');
		result.push_back('-');
		result.push_back(end_hour / 10 + '0');
		result.push_back(end_hour % 10 + '0');
		result.push_back(':');
		result.push_back(end_minute / 10 + '0');
		result.push_back(end_minute % 10 + '0');
		result.push_back(' ');
		result.push_back(num + '0');
		return result;
	}
};


#endif SESSION_H_

