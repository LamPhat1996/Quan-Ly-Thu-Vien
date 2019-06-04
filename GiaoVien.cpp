#include "GiaoVien.h"

void GiaoVien::output()
{
	BanDoc::xuat();
	cout << "Dia chi: " << this->sDiaChi << endl;
	cout << "SDT: " << this->sSDT << endl;
}