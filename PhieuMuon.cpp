#include "PhieuMuon.h"


void PhieuMuon::xuat()
{
	cout << "***********************************************\n";
	cout << "<So phieu muon>:    " << this->nMaPM << endl;
	cout << "<Ma sach>:          " << this->xSach.getMS() << endl;
	cout << "<Ma ban doc>:       " << this->xBanDoc.getMBD() << endl;
	cout << "<Ngay muon>:        "; this->xNgayMuon.xuat(); cout << endl;
	cout << "<Ngay tra>:         "; this->xNgayTra.xuat(); cout << endl;
	cout << "<Tinh trang>:       " << this->nTrangThai << endl;
}
int PhieuMuon::getTPM()
{
	return this->nTongPM;
}
BanDoc PhieuMuon::getBanDoc()
{
	return this->xBanDoc.getMBD();
}
Sach PhieuMuon::getSach()
{
	return this->xSach.getMS();
}
Date PhieuMuon::getNgayMuon()
{
	return this->xNgayMuon;
}
Date PhieuMuon::getNgayTra()
{
	return this->xNgayTra;
}
int PhieuMuon::getMaPM()
{
	return this->nMaPM;
}
int PhieuMuon::getTrangThai()
{
	return this->nTrangThai;
}
void PhieuMuon::setTrangThai(int a)
{
	this->nTrangThai = a;
}
void PhieuMuon::setSach(Sach s)
{
	this->xSach = s;
}
void PhieuMuon::setBanDoc(BanDoc xBD)
{
	this->xBanDoc = xBD;
}
int PhieuMuon::nNgayPlus(int nN)
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_mon = ta->tm_mon + 1;
	ta->tm_year = ta->tm_year + 1900;
	if (ta->tm_mon == 1 || ta->tm_mon == 3 || ta->tm_mon == 5 || ta->tm_mon == 7 || ta->tm_mon == 8 || ta->tm_mon == 10)
	{
		//1 tháng có 31 ngày: gọi tổng ngày =  lấy ngày hiện tại + nN số ngày nhập vào. đem so sánh với số 31
		//Nếu nhỏ hơn hoặc bằng 31 thì tháng vẫn giữ nguyên, tổng ngày = ngày
		//Nếu lớn hơn 31 thì lấy tổng ngày trừ cho 31 -> số tháng tăng lên 1, số ngày là kết quả của phép trừ
		
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if(nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mday;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon += 1;
			return ta->tm_mday;
		}
	}
	else if (ta->tm_mon == 4 || ta->tm_mon == 6 || ta->tm_mon == 9 || ta->tm_mon == 11)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 30)
		{
			ta->tm_mday += nN;
			return ta->tm_mday;
		}
		else
		{
			ta->tm_mday = nTongNgay - 30;
			ta->tm_mon += 1;
			return ta->tm_mday;
		}
	}
	else if (ta->tm_mon == 12)
	{
		int nTongNgay = 0;
		int nTongThang = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mday;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon = 1;
			ta->tm_year += 1;
			return ta->tm_mday;
		}
	}
	if (ktrNamNhuan() == true )
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 29)
			{
				ta->tm_mday += nN;
				return ta->tm_mday;
			}
			else
			{
				ta->tm_mday = nTongNgay - 29;
				ta->tm_mon += 1;
				return ta->tm_mday;
			}
		}
	}
	else
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 28)
			{
				ta->tm_mday += nN;
				return ta->tm_mday;
			}
			else
			{
				ta->tm_mday = nTongNgay - 28;
				ta->tm_mon += 1;
				return ta->tm_mday;
			}
		}
	}
	return 0;
}
int PhieuMuon::nThangPlus(int nN)
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_mon = ta->tm_mon + 1;
	ta->tm_year = ta->tm_year + 1900;
	if (ta->tm_mon == 1 || ta->tm_mon == 3 || ta->tm_mon == 5 || ta->tm_mon == 7 || ta->tm_mon == 8 || ta->tm_mon == 10)
	{
		//1 tháng có 31 ngày: gọi tổng ngày =  lấy ngày hiện tại + nN số ngày nhập vào. đem so sánh với số 31
		//Nếu nhỏ hơn hoặc bằng 31 thì tháng vẫn giữ nguyên, tổng ngày = ngày
		//Nếu lớn hơn 31 thì lấy tổng ngày trừ cho 31 -> số tháng tăng lên 1, số ngày là kết quả của phép trừ
		//
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if(nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mon;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon += 1;
			return ta->tm_mon;
		}
	}
	else if (ta->tm_mon == 4 || ta->tm_mon == 6 || ta->tm_mon == 9 || ta->tm_mon == 11)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 30)
		{
			ta->tm_mday += nN;
			return ta->tm_mon;
		}
		else
		{
			ta->tm_mday = nTongNgay - 30;
			ta->tm_mon += 1;
			return ta->tm_mon;
		}
	}
	else if (ta->tm_mon == 12)
	{
		int nTongNgay = 0;
		int nTongThang = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mon;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon = 1;
			ta->tm_year += 1;
			return ta->tm_mon;
		}
	}
	if (ktrNamNhuan() == true )
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 29)
			{
				ta->tm_mday += nN;
				return ta->tm_mon;
			}
			else
			{
				ta->tm_mday = nTongNgay - 29;
				ta->tm_mon += 1;
				return ta->tm_mon;
			}
		}
	}
	else
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 28)
			{
				ta->tm_mday += nN;
				return ta->tm_mon;
			}
			else
			{
				ta->tm_mday = nTongNgay - 28;
				ta->tm_mon += 1;
				return ta->tm_mon;
			}
		}
	}
	return 0;
}
int PhieuMuon::nNamPlus(int nN)
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_mon = ta->tm_mon + 1;
	ta->tm_year = ta->tm_year + 1900;
	if (ta->tm_mon == 12)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay > 31)
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon = 1;
			ta->tm_year += 1;
			return ta->tm_year;
		}
	}
	return ta->tm_year;
}
bool PhieuMuon::ktrNamNhuan()
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_year = ta->tm_year + 1900;
	if(ta->tm_year % 400 == 0 || ta->tm_year  % 4 == 0 && ta->tm_year % 100 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
