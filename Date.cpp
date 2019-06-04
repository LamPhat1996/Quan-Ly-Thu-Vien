#include "Date.h"
void Date::setNgay(int d)
{
	this->nNgay = d;
}
void Date::setThang(int m)
{
	this->nThang = m;
}
void Date::setNam(int y)
{
	this->nNam = y;
}
void Date::setDate(int d, int m, int y)
{
	this->nNgay = d;
	this->nThang = m;
	this->nNam = y;
}
int Date::getNgay()
{
	return this->nNgay;
}
int Date::getThang()
{
	return this->nThang;
}
int Date::getNam()
{
	return this->nNam;
}
void Date::xuat()
{
	cout << this->nNgay << "/" << this->nThang << "/" << this->nNam;
}