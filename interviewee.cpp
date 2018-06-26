#include<iostream>
#include<vector>
#include<string>
#include"interviewee.h"

interviewee::interviewee(int id,
	std::string name,
	std::string stu_id,
	std::string major,
	std::string class_num,
	std::string phone,
	std::string birth_place,
	std::string birthday,
	std::string favor,
	std::string introduction,
	std::string aspiration1,
	std::string aspiration2,
	bool is_subject)
{
	this->id = id;
	this->name = name;
	this->stu_id = stu_id;
	this->phone = phone;
	this->birth_place = birth_place;
	this->birthday = birthday;
	this->favor = favor;
	this->introduction = introduction;
	this->is_subject = is_subject;

	for (int i = 0; i < Department.size(); ++i)
	{
		if (Department[i] == aspiration1)
			aspiration[0] = i;
		if (Department[i] == aspiration2)
			aspiration[1] = i;
	}

	for (int i = 0; i < Majority.size(); ++i)
	{
		if (Majority[i] == major)
			this->major = i;
	}

	switch (this->major)
	{
	case 0:this->class_num = "计科" + standardize_class_num(class_num); break;
	case 1:this->class_num = "软工" + standardize_class_num(class_num); break;
	case 2:this->class_num = "信安" + standardize_class_num(class_num); break;
	case 3:this->class_num = "数媒" + standardize_class_num(class_num); break;
	case 4:this->class_num = "工设" + standardize_class_num(class_num); break;
	case 5:this->class_num = "产设" + standardize_class_num(class_num); break;
	default:break;
	}
}
bool check_duplicate(interviewee i)//check whether the student has signed up or not. False means he/she has signed up already  
{
	for (int k = 0; k < interviewee_collection.size(); ++k)
	{
		if (interviewee_collection[k].get_stu_id() == i.get_stu_id())
			return false;
	}
	return true;
}

bool check_format_stuid(std::string stu_id)
{
	if (stu_id.size() != 10)
		return false;
	if (stu_id[0] != '3' || stu_id[1] != '1' || stu_id[3] != '0' || stu_id[4] != '1' || stu_id[5] != '0')
		return false;
	return true;
}

std::string standardize_class_num(std::string class_num)
{
	std::string class_num_std;
	for (int i = 0; i < class_num.size(); ++i)
	{
		if ((class_num[i] - '0') >= 0 && (class_num[i] - '0') <= 9)
		{
			class_num_std.push_back(class_num[i]);
		}
	}
	return class_num_std;
}

bool check_format_phone(std::string phone)
{
	if (phone.size() != 11)
		return false;
	return true;
}

int interviewee::get_session_id()
{
    int aspiration = get_first_aspiration();
    if (aspiration == 0 && is_subject == true) return 1;
    else if(aspiration == 1 && is_subject==true) return 2;
    else if (aspiration == 2 && is_subject == true) return 3;
    else if (aspiration == 3 && is_subject == true) return 4;
    else if (aspiration == 0 && is_subject == false) return 5;
    else if (aspiration == 1 && is_subject == false) return 6;
    else if (aspiration == 2 && is_subject == false) return 7;
    else if (aspiration == 3 && is_subject == false) return 8;
}
