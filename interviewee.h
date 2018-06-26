#ifndef INTERVIEWEE_H_
#define INTERVIEWEE_H_

#include"session.h"

extern std::vector<std::string> Department;
extern std::vector<std::string> Majority;
extern std::vector<class interviewee> interviewee_collection;

class interviewee
{
public:
	int id;
	std::string name;
	std::string stu_id;
	int major;
	std::string class_num;
	std::string phone;
	std::string birth_place;
	std::string birthday;
	std::string favor;
	std::string introduction;
	int aspiration[2];
	bool is_subject;
	session s;
public:
    interviewee(){}
	interviewee(int id,
		std::string name,
		std::string stu_id,
		std::string major,
		std::string class_num,
		std::string phone,
		std::string birth_place,
		std::string birthday,
		std::string favor,
		std::string introdution,
		std::string aspiration1,
		std::string aspiration2,
		bool is_subject);

	void set_session(session s)
	{
		this->s = s;
	}
	int get_id() { return id; }
	std::string get_name(){ return name; }
	std::string get_stu_id(){ return stu_id; }
	int get_major(){ return major; }
	std::string get_class_num(){ return class_num; }
	std::string get_phone(){ return phone; }
	std::string get_birth_place(){ return birth_place; }
	std::string get_birthday(){ return birthday; }
	std::string get_favor(){ return favor; }
	std::string get_introduction(){ return introduction; }
    int get_first_aspiration(){ return aspiration[0]; }
	int get_second_aspiration(){ return aspiration[1]; }
	bool get_is_subject(){ return is_subject; }
	std::string get_session(){ return s.session_to_string(); }
    int get_session_id();
};

bool check_duplicate(interviewee);//check whether the student has signed up or not. False means he/she has signed up already  

bool check_format_stuid(std::string);

std::string standardize_class_num(std::string);

std::string standardize_major(std::string);

bool check_format_phone(std::string);

#endif
