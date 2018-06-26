#include"interviewer.h"

/*处理密码*/
string InterViewer::confirmation(string pass_word)
{
	string new_password;
	for (int i = 0; i < pass_word.length(); i++)
	{
		pass_word[i] = pass_word[i] ^ i;
	}

	new_password = pass_word;
	return new_password;
}

InterViewer::~InterViewer()
{
}

/*判断面试者登录的全局函数*/
bool interviewer_login(string name, string password)
{
	for (int i = 0; i < InterViewer_vector.size(); i++)
	{
		if (InterViewer_vector[i].name == name)
		{
			password = InterViewer_vector[i].confirmation(password);
			if (password == InterViewer_vector[i].password && InterViewer_vector[i].is_valid == true)
				return true;
			else
				return false;
		}
	}

	return false;
}