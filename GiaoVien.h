#pragma once
#include "BanDoc.h"
class GiaoVien :
	public BanDoc
{
	string sDiaChi;
	string sSDT;
public:
	void output();
	GiaoVien(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0, string sDiaChi = "", string sSDT = ""):BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sDiaChi = sDiaChi;
		this->sSDT = sSDT;
	}
	~GiaoVien(void){};
};

