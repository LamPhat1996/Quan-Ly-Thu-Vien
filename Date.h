#ifndef Date_h
#define Date_h

#pragma once
#include <iostream>
#include <string>
#include <time.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <dos.h>
using namespace std;
class BanDoc;
class Sach;
class PhieuMuon;
class SinhVien;
class GiaoVien;
class Date
{
	int nNgay;
	int nThang;
	int nNam;
public:
	friend BanDoc;
	friend Sach;
	friend SinhVien;
	friend GiaoVien;
	friend PhieuMuon;
	Date(int nNgay = 0, int nThang = 0, int nNam = 0)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	void setNgay(int d);
	void setThang(int m);
	void setNam(int y);
	void setDate(int d, int m, int y);
	int getNgay();
	int getThang();
	int getNam();
	void xuat();
	~Date(void){};
};
#endif // !Date_h