#pragma once
#include "Date.h"
class Date;
class Sach
{
private:
	string sMaSach, sTuaDe, sTacGia, sNXB;
	float fTriGia;
	int nNamPhatHanh, nSoTrang;
	Date xNgayNhapKho;
	int nTinhTrang;
public:
	friend Date;
	void outputSach();
	string getMS();
	string getTD();
	string getTG();
	string getNXB();
	float getGia();
	int getNPH();
	int getST();
	int getNgayNK();
	int getThangNK();
	int getNamNK();
	int getTinhTrang();
	void setTT(int a);
	Sach(string sMaSach = "", string sTuaDe = "", string sTacGia = "", string sNXB = "", float fTriGia = 0.0, int nNamPhatHanh = 0, int nSoTrang = 0, int nNgay = 0, int nThang = 0, int nNam = 0, int nTinhTrang = 0):xNgayNhapKho(nNgay, nThang, nNam)
	{
		this->sMaSach = sMaSach;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNXB = sNXB;
		this->fTriGia = fTriGia;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = nTinhTrang;
	}
	~Sach(void){};
};

