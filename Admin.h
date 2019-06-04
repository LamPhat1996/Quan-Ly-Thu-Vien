#pragma once
#include <iostream>
#include <string>
using namespace std;
class Admin
{
	string sUsername;
	string sPassword;
public:
	Admin(string sUsername = "", string sPassword = "")
	{
		this->sUsername = sUsername;
		this->sPassword = sPassword;
	}
	
	string getUser();
	string getPass();
	void setUser(string US);
	void setPass(string PA);
	~Admin(void){};
};

