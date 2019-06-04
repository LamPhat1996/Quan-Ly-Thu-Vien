#include "Sach.h"

string Sach::getMS()
{
	return this->sMaSach;
}
string Sach::getTD()
{
	return this->sTuaDe;
}
string Sach::getTG()
{
	return this->sTacGia;
}
string Sach::getNXB()
{
	return this->sNXB;
}
float Sach::getGia()
{
	return this->fTriGia;
}
int Sach::getNPH()
{
	return this->nNamPhatHanh;
}
int Sach::getST()
{
	return this->nSoTrang;
}
int Sach::getNgayNK()
{
	return this->xNgayNhapKho.getNgay();
}
int Sach::getThangNK()
{
	return this->xNgayNhapKho.getThang();
}
int Sach::getNamNK()
{
	return this->xNgayNhapKho.getNam();
}
int Sach::getTinhTrang()
{
	return this->nTinhTrang;
}
void Sach::setTT(int a)
{
	this->nTinhTrang = a;
}
void Sach::outputSach() 
{
	cout << "*********************************************\n";
	cout << "Ma sach:       " << this->sMaSach << endl;
	cout << "Tieu de:       " << this->sTuaDe << endl;
	cout << "Tac gia:       " << this->sTacGia << endl;
	cout << "NXB:           " << this->sNXB << endl;
	cout << "Tri gia:       " << this->fTriGia << " VND" << endl;
	cout << "Nam phat hanh: " << this->nNamPhatHanh << endl;
	cout << "Ngay nhap kho: ";
	this->xNgayNhapKho.xuat();
	cout << endl;
}