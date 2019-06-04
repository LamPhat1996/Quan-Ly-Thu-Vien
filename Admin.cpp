#include "Admin.h"


string Admin::getUser()
{
	return this->sUsername;
}
string Admin::getPass()
{
	return this->sPassword;
}
void Admin::setUser(string US)
{
	this->sUsername = US;
}
void Admin::setPass(string PA)
{
	this->sPassword = PA;
}