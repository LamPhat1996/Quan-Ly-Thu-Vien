#include "BanDoc.h"

void BanDoc::xuat()
{
	cout << "************************************\n";
	cout << "Ma doc gia: " << this->sMaBD << endl;
	cout << "Ngay dang ky the: ";
	xNgay.xuat(); cout << endl;
	cout << "Ho va Ten: " << this->sHoTen << endl;
	cout << "Khoa: " << this->sKhoa << endl;
}

string BanDoc::getMBD()
{
	return this->sMaBD;
}