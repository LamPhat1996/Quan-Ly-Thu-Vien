#pragma once
#include "Date.h"

class Date;
class PhieuMuon;
class BanDoc
{
protected:
	string sMaBD;
	string sHoTen;
	string sKhoa;
	Date xNgay;
public:
	friend Date;
	friend PhieuMuon;
	virtual void output(){};
	void xuat();
	string getMBD();
	BanDoc(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0):xNgay(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}
	~BanDoc(void){};
};

