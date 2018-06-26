#include"admin.h"

extern string Admin_password;
string Admin::confirmation(string pass_word)
{
	string new_password;
	for (int i = 0; i < pass_word.length(); i++)
	{
		pass_word[i] = pass_word[i] ^ i;
	}

	new_password = pass_word;
	return new_password;
}

/*分组的函数*/
void Admin::judgeGroup()
{
    Session1_vector.clear(); Session2_vector.clear();
    Session3_vector.clear(); Session4_vector.clear();
    Session5_vector.clear(); Session6_vector.clear();
    Session7_vector.clear(); Session8_vector.clear();   Group.clear();

    for(int i = 0; i < interviewee_collection.size(); i++)
    {
        int aspiration = interviewee_collection[i].get_first_aspiration();
        bool is_subject = interviewee_collection[i].get_is_subject();
        if (aspiration == 0 && is_subject == true) Session1_vector.push_back(interviewee_collection[i]);
        else if(aspiration == 1 && is_subject==true) Session2_vector.push_back(interviewee_collection[i]);
        else if (aspiration == 2 && is_subject == true) Session3_vector.push_back(interviewee_collection[i]);
        else if (aspiration == 3 && is_subject == true) Session4_vector.push_back(interviewee_collection[i]);
        else if (aspiration == 0 && is_subject == false) Session5_vector.push_back(interviewee_collection[i]);
        else if (aspiration == 1 && is_subject == false) Session6_vector.push_back(interviewee_collection[i]);
        else if (aspiration == 2 && is_subject == false) Session7_vector.push_back(interviewee_collection[i]);
        else if (aspiration == 3 && is_subject == false) Session8_vector.push_back(interviewee_collection[i]);
    }

    /*放入Group里面*/
     Group.push_back(Session1_vector);   Group.push_back(Session2_vector);
     Group.push_back(Session3_vector);   Group.push_back(Session4_vector);
     Group.push_back(Session5_vector);   Group.push_back(Session6_vector);
     Group.push_back(Session7_vector);   Group.push_back(Session8_vector);
}

void Admin::judgeInterviewer(int num)
{
    InterViewer_vector[num - 1].is_valid = true;
}

/*判断管理员登录的全局函数*/
bool admin_login(string input)
{
	input = Admin:: confirmation(input);
	if (input == Admin_password) return true;
	else return false;
}
