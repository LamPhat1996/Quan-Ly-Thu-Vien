/*
Nhom: 
1. Nguyen Van Thai
2. Luong Thi Huyen Trang
3. Nguyen Huynh Lam Phat
4. Cáp Lê Minh Quân
5.  Pham Minh Vỹ
*/
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <sstream>
#include <iomanip>
#include "Admin.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
#include "Sach.h"
using namespace std;
int PhieuMuon::nTongPM = 0;
//Admin
void inputData_Admin(list <Admin> &L);
int outputData_Admin(list <Admin> L);
void login_Admin(list <Admin> L, list <Sach> L3, list <BanDoc*> L2, list <PhieuMuon> L4);
void changeColor(WORD color); 
string passwordInput(unsigned maxLength);
//DS ban doc
void inputData_BanDoc(list <BanDoc*> &L2);
void outputData_BanDoc_ToScreen(list <BanDoc*> L2);
void timKiemBanDoc(list <BanDoc*> L2);
bool kiemTraBD(list <BanDoc*> L2, string sMaBD);
void themBanDoc(list <BanDoc*> &L2);
int soLuongBanDocGiaoVien(list <BanDoc*> L2);
int soLuongBanDocSinhVien(list <BanDoc*> L2);
void inTheThuVien( int nLoai, string sMaBD, string HoTen, string sKhoa, int nNgay, int nThang, int nNam, string DC, string SDT, int KhoaHoc);
//Hàm chuyển kiểu số sang kiểu chuỗi --- tự động cập nhật Mã bạn đọc mới tạo
template <typename T>
string itos(T i)
{
	stringstream s;
	s << i;
	return s.str();
}
//DS sach
bool kiemTraSach_DuTieuChuanMuon(list <Sach> L3, string sMS);
void inputData_Sach(list <Sach> &L3);
void outputData_Sach_ToScreen(list <Sach> L3);
void outputData_Sach_File(list <Sach> L3);
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3);
void themSach(list <Sach> &L3);
void xoaSach(list <Sach> &L3);
void timKiem(list <Sach> L3);
int nDemSachChuaMuon(list <Sach> L3);
int nDemSachDaMuon(list <Sach> L3);
//Phieu muon
void inputData_PhieuMuon(list <PhieuMuon> &L4);
void them_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3);
void outputData_PhieuMuon_ToScreen(list <PhieuMuon> L4);
void outputData_PhieuMuon_File(list <PhieuMuon> L4, list <BanDoc*> L2, list <Sach> L3);
int demTongPhieuMuon(list <PhieuMuon> L4);
void traSach_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3);
void lietKeSach1BanDocDangMuon(list <PhieuMuon> L4, list <Sach> L3);
//Chuong trinh chinh
void main()
{	 
	list <Admin> L1;
	list <BanDoc*> L2;
	list <Sach> L3;
	list <PhieuMuon> L4;
	inputData_Admin(L1);
	inputData_BanDoc(L2);
	inputData_Sach(L3);
	inputData_PhieuMuon(L4);
	int nChucNangMenu = 0;
	while( true )
	{
		system("cls");
		changeColor(10);
		cout << "\t\t*******************************************\n";
		cout << "\t\t  1. Hien thi thong tin sach.              \n";
		cout << "\t\t  2. Hien thi thong tin ban doc.           \n";
		cout << "\t\t  3. Tim kiem thong tin                    \n";
		cout << "\t\t  4. Quan ly                               \n";
		cout << "\t\t  0. Thoat!                                \n";
		cout << "\t\t*******************************************\n";
		changeColor(4);
		cout << "\t\t   Nhap Lua Chon: ";
		cin >> nChucNangMenu;
		if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 4 && nChucNangMenu != 0)
		{
			changeColor(12);
			cout << "Nhap sai vui long lua chon lai.\n";
			changeColor(14);
			system("pause");
		}
		else if (nChucNangMenu == 1)
		{
			changeColor(6);
			cout << "\n\t*Thong tin sach*\n";
			changeColor(3);
			outputData_Sach_ToScreen(L3);
			changeColor(14);
			system("pause");
		}
		else if (nChucNangMenu == 2)
		{
			changeColor(6);
			cout << "\n\t*Thong tin ban doc*\n";
			changeColor(3);
			outputData_BanDoc_ToScreen(L2);
			changeColor(14);
			system("pause");
		}
		else if (nChucNangMenu == 3)
		{
			while(true)
			{		
				system("cls");
				changeColor(5);
				cout << "\t\t*******************************************\n";
				cout << "\t\t  1. Tim sach theo ma sach.                \n";
				cout << "\t\t  2. Tim ban doc theo ma ban doc.          \n";
				cout << "\t\t  0. Thoat!                                \n";
				cout << "\t\t*******************************************\n";
				changeColor(4);
				cout << "\t\t   Nhap Lua Chon: ";
				cin >> nChucNangMenu;
				if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 0)
				{
					changeColor(12);
					cout << "Nhap sai vui long lua chon lai.\n";
					changeColor(14);
					system("pause");					
				}
				else if (nChucNangMenu == 1)
				{
					changeColor(10);
					cout << "\t\t*Tim sach theo ma sach*\n";
					timKiem(L3);
					changeColor(14);
					system("pause");				
				}
				else if (nChucNangMenu == 2)
				{
					changeColor(10);
					cout << "\t\t*Tim ban doc theo ma ban doc*\n";
					timKiemBanDoc(L2);
					changeColor(14);
					system("pause");				
				}
				else if (nChucNangMenu == 0)
				{
					break;
				}
			}
			system("pause");
		}
		else if (nChucNangMenu == 4)
		{
			login_Admin(L1, L3, L2, L4);
			changeColor(14);
			system("pause");
		}
		else if (nChucNangMenu == 0)
		{
			break;
		}
	}
	changeColor(14);
	system("pause");
}
//Phieu muon
void lietKeSach1BanDocDangMuon(list <PhieuMuon> L4, list <Sach> L3)
{
	int flag = 0;
	string sMBD = "";
dd:
	changeColor(4);
	cout << "\t\tNhap N de thoat!\n";
	changeColor(7);
	cout << "\t\tNhap ma ban doc: ";
	rewind(stdin);
	fflush(stdin);
	getline(cin, sMBD);
	if (sMBD == "N")
	{
		changeColor(10);
		cout << "\t\tBan da con thoat!\n";
		changeColor(7);
		return;
	}
	list <PhieuMuon>::iterator p = L4.begin();
	cout << "\tDanh Sach Sach Ban Doc Dang Muon\n";
	while(p != L4.end())
	{
		if (sMBD == p->getBanDoc().getMBD() && p->getTrangThai() != 0)
		{
			
			list <Sach>::iterator q = L3.begin();
			while(q != L3.end())
			{
				if (q->getMS() == p->getSach().getMS())
				{
					flag = 1;
					q->outputSach();
				}
				q++;
			}
		}
		else 
		{
			flag = 0;
		}
		p++;
	}
	if (flag == 0)
	{
		changeColor(4);
		cout << "\t\tMa ban doc nay chua muon sach!\n";
		changeColor(7);
		system("pause");
		goto dd;
	}
}
void traSach_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3)
{
	int flag = 0;
	int nMPM = 0;
	while(true)
	{
		
		system("cls");
	dd:
		cout << "\t\tNhap ma phieu muon can tra sach: ";
		cin >> nMPM;
		list <PhieuMuon> ::iterator p = L4.begin();
		while(p != L4.end())
		{
			if (nMPM == p->getMaPM())
			{
				if (p->getTrangThai() != 0)
				{
					flag = 1;
					p->setTrangThai(0); // gán trạng thái 0 cho phiếu mượn đang muốn trả
					string sMaSach = p->getSach().getMS();
					list <Sach> ::iterator q = L3.begin();
					while(q != L3.end())
					{
						if (q->getMS() == sMaSach)
						{
							q->setTT(0); // gán tình trạng 0 cho sách đã được trả
							break;
						}
						q++;
					}
					outputData_Sach_File(L3);
					outputData_PhieuMuon_File(L4, L2, L3);
					changeColor(10);
					cout << "\t\tTra sach thanh cong!\n";
					changeColor(7);
					break;
				}
				changeColor(4);
				cout << "\t\tMa phieu muon da duoc tra!\n";
				changeColor(7);
				system("pause");
				goto dd;
			}
			p++;
		}
		if (flag == 0)
		{
			changeColor(4);
			cout << "\t\tMa phieu muon khong ton tai!\n";
			changeColor(7);
			system("pause");
		}
		else if(flag == 1)
		{
			break;
		}
	}
}
int demTongPhieuMuon(list <PhieuMuon> L4)
{
	int nDem = 0;
	list <PhieuMuon> ::iterator p = L4.begin();
	while(p != L4.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
void them_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3)
{
	string sMBD = "";
	while(true)
	{
		system("cls");
		changeColor(4);
		cout << "\t\tNhap N de thoat!\n";
		changeColor(7);
		cout << "\t\tNhap ma ban doc can muon sach: ";
		rewind(stdin);
		fflush(stdin);
		getline(cin, sMBD);
		if (sMBD == "")
		{
			changeColor(4);
			cout << "Khong duoc de trong ! \n";
			changeColor(7);
			system("pause");
		}
		else if (sMBD == "N")
		{
			changeColor(10);
			cout << "\t\tBan chon thoat!\n";
			changeColor(7);
			return;
		}
		else if (kiemTraBD(L2, sMBD) != true)
		{
			changeColor(4);
			cout << "\t\tMa ban doc khong ton tai!\n";
			changeColor(7);
			system("pause");
		}
		else
		{
			break;
		}
	}
	string sMS = "";
	while(true)
	{
		cout << "\t\tNhap ma sach: ";
		fflush(stdin);
		getline(cin, sMS);
		if (sMS == "")
		{
			changeColor(4);
			cout << "Khong duoc de trong ! \n";
			changeColor(7);
			system("pause");
		}
		else if (kiemTraSach_DuTieuChuanMuon(L3, sMS) == true)
		{
			break;
		}
		else 
		{
			changeColor(4);
			cout << "\t\tMa sach khong ton tai! hoac dang co ban doc muon.\n";
			changeColor(14);
			system("pause");
		}	
	}
	PhieuMuon pm(sMBD, sMS);
	L4.push_back(pm);
	changeColor(10);
	cout << "\t\tTao phieu muon thanh cong!\n";
	changeColor(7);
	ofstream File;
	File.open("PhieuMuon.txt", ios::app);
	File << "\n" << L4.rbegin()->getMaPM() << "," << L4.rbegin()->getBanDoc().getMBD() << "," << L4.rbegin()->getSach().getMS() << "," << L4.rbegin()->getNgayMuon().getNgay() << "," << L4.rbegin()->getNgayMuon().getThang() << "," << L4.rbegin()->getNgayMuon().getNam() << ","  << L4.rbegin()->getNgayTra().getNgay() << "," << L4.rbegin()->getNgayTra().getThang() << "," << L4.rbegin()->getNgayTra().getNam() << "," << L4.rbegin()->getTrangThai();
	File.close();
	int nTT = L4.rbegin()->getMaPM(); // trang thai
	list <Sach> ::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getMS() == sMS)
		{
			p->setTT(nTT);// tinh trang
			break;
		}
		p++;
	}
	outputData_Sach_File(L3);

}
void outputData_PhieuMuon_File(list <PhieuMuon> L4, list <BanDoc*> L2, list <Sach> L3)
{
	
	int nTongPM = demTongPhieuMuon(L4);
	int nDem = 1;
	ofstream File;
	File.open("PhieuMuon.txt");
	list <PhieuMuon> ::iterator p = L4.begin();
	while (p != L4.end())
	{
		File << p->getMaPM() << "," << p->getBanDoc().getMBD() << "," << p->getSach().getMS() << "," << p->getNgayMuon().getNgay() << "," << p->getNgayMuon().getThang() << "," << p->getNgayMuon().getNam() << "," << p->getNgayTra().getNgay() << "," << p->getNgayTra().getThang() << "," << p->getNgayTra().getNam() << "," << p->getTrangThai();
		if (nDem < nTongPM)
		{
			File << endl;
			nDem++;
		}
		p++;
	}
	File.close();
}
void outputData_PhieuMuon_ToScreen(list <PhieuMuon> L4)
{
	list <PhieuMuon> ::iterator p = L4.begin();
	while(p != L4.end())
	{
		p->xuat();
		p++;
	}
}
void inputData_PhieuMuon(list <PhieuMuon> &L4)
{
	int nSPM = 0;
	string sMBD = "";
	string sMS = "";
	int nNgayMuon = 0;
	int nThangMuon = 0;
	int nNamMuon = 0;
	int nNgayTra = 0;
	int nThangTra = 0;
	int nNamTra = 0;
	int nTrangThai = 0;
	ifstream File;
	File.open("PhieuMuon.txt");
	while(!File.eof())
	{
		File >> nSPM;
		File.ignore(1, ',');
		getline(File, sMBD, ',');
		getline(File, sMS, ',');
		File >> nNgayMuon;
		File.ignore(1, ',');
		File >> nThangMuon;
		File.ignore(1, ',');
		File >> nNamMuon;
		File.ignore(1, ',');
		File >> nNgayTra;
		File.ignore(1, ',');
		File >> nThangTra;
		File.ignore(1, ',');
		File >> nNamTra;
		File.ignore(1, ',');
		File >> nTrangThai;
		File.ignore(1, '\n');
		PhieuMuon pm(nSPM, sMBD,sMS,nNgayMuon,nThangMuon,nNamMuon,nNgayTra,nThangTra,nNamTra,nTrangThai);
		L4.push_back(pm);
	}
	File.close();
}
//DS Ban Doc
void inTheThuVien(int nLoai, string sMaBD, string HoTen, string sKhoa, int nNgay, int nThang, int nNam, string DC, string SDT, int KhoaHoc)
{
	if (nLoai == 1)
	{
		changeColor(10);
		cout << "\n\t\tDang in vui long doi !\n";
		changeColor(9);
		Sleep(200);
		cout << "\t*************************************************\n";
		Sleep(200);
		cout << "\t*     Truong Cao Dang Cong Nghe Thu Duc - TDC   *\n";
		Sleep(200);
		cout << "\t*           THE THU VIEN - GIAO VIEN            *\n";
		Sleep(200);
		cout << "\t*************************************************\n";
		Sleep(200);
		changeColor(11);
		cout << "\t* Ten : " << HoTen << "  -  Ma So: " << sMaBD << "           *\n";
		Sleep(200);
		cout << "\t* Khoa: " << sKhoa << "            -  SDT: " << SDT << "      *\n";
		Sleep(200);
		cout << "\t* Dia Chi: " << DC << "                               *\n";
		Sleep(200);
		cout << "\t* Ngay Dang Ky: " << nNgay << "/" << nThang << "/" << nNam << "                        *\n";
		Sleep(200);
		cout << "\t*************************************************\n";
		Sleep(200);
		changeColor(10);
		cout << "\n\n\t\t In the thanh cong !\n";
		changeColor(7);
	}
	else if (nLoai == 2)
	{
		changeColor(10);
		cout << "\n\t\tDang in vui long doi !\n";
		changeColor(9);
		Sleep(200);
		cout << "\t*************************************************\n";
		Sleep(200);
		cout << "\t*     Truong Cao Dang Cong Nghe Thu Duc - TDC   *\n";
		Sleep(200);
		cout << "\t*           THE THU VIEN - SINH VIEN            *\n";
		Sleep(200);
		cout << "\t*************************************************\n";
		Sleep(200);
		changeColor(11);
		cout << "\t* Ten: " << HoTen << "       Ma So: " << sMaBD << "           *\n";
		Sleep(200);
		cout << "\t* Khoa: " << sKhoa <<  "               Khoa Hoc: " << KhoaHoc << setw(10) << "*\n";
		Sleep(200);
		cout << "\t* Ngay Dang Ky: " << nNgay << "/" << nThang << "/" << nNam << setw(26) << "*\n";
		Sleep(200);
		cout << "\t*************************************************\n";
		Sleep(200);
		changeColor(10);
		cout << "\n\n\t\t In the thanh cong !\n";
		changeColor(7);
	}
}
int soLuongBanDocSinhVien(list <BanDoc*> L2)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	ifstream File;
	File.open("BanDoc.txt");
	while(!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, '\n');
		}
		else if(nLoai == 2)
		{
			nDem++;
			getline(File, sMaBD, '\n');
		}
	}
	return nDem;
}
int soLuongBanDocGiaoVien(list <BanDoc*> L2)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	while(!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			nDem++;
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
		}
	}
	File.close();
	return nDem;
}
void themBanDoc(list <BanDoc*> &L2)
{
	time_t t = time(0); 
	struct tm *Now =localtime(&t);
	int nLoaiBD = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = Now->tm_mday;         //
	int nThang = Now->tm_mon + 1;    // Ngày làm thẻ được lấy tự động
	int nNam = Now->tm_year + 1900;  //
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	while(true)
	{
		system("cls");
		changeColor(6);
		cout << "\t\t\t*************************************\n";
		cout << "\t\t\t  1. Them ban doc Giao Vien          \n";
		cout << "\t\t\t  2. Them ban doc Sinh Vien          \n";
		cout << "\t\t\t  0. Thoat!                          \n";
		cout << "\t\t\t*************************************\n";
		changeColor(12);
		cout << "\t\t\t Nhap chuc nang: ";
		cin >> nLoaiBD;
		if (nLoaiBD == 1)
		{
			changeColor(13);
			nLoaiBD = 1;
			int nTongSL = soLuongBanDocGiaoVien(L2);
			string str = itos(nTongSL+1);
			sMaBD = "GV" + str;
			cout << "\t\tNhap ho va ten: "; 
			rewind(stdin);
			fflush(stdin); 
			getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; 
			rewind(stdin);
			fflush(stdin); 
			getline(cin, sKhoa);
			cout << "\t\tNhap dia chi: "; 
			rewind(stdin);
			fflush(stdin); 
			getline(cin, sDC);
			cout << "\t\tNhap so dien thoai: "; 
			rewind(stdin);
			fflush(stdin); 
			getline(cin, sSDT);
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			L2.push_back(gv);
			ofstream File;
			File.open("BanDoc.txt", ios::app);
			File << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << sDC << "," << sSDT;
			File.close();
			changeColor(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			changeColor(7);
			inTheThuVien(1, sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT, 0);
			changeColor(14);
			system("pause");
			break;
		}
		else if (nLoaiBD == 2)
		{
			changeColor(13);
			nLoaiBD = 2;
			int nTongSL = soLuongBanDocSinhVien(L2);
			string str = itos(nTongSL+1);
			sMaBD = "SV" + str;
			cout << "\t\tNhap ho va ten: ";
			rewind(stdin); fflush(stdin); getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; 
			rewind(stdin); fflush(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap Khoa Hoc: "; cin >> nKhoaHoc;
			BanDoc *  sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L2.push_back(sv);
			ofstream File;
			File.open("BanDoc.txt", ios::app);
			File << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << nKhoaHoc;
			File.close();
			changeColor(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			changeColor(7);
			inTheThuVien(2, sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, "", "", nKhoaHoc);
			changeColor(14);
			system("pause");
			break;
		}
		else if (nLoaiBD == 0)
		{
			break;
		}
		else
		{
			cout << "Nhap sai! Vui long nhap lai. \n";
		}
	}
}
void timKiemBanDoc(list <BanDoc*> L2)
{
	string sMBD = "";
	changeColor(4);
	cout << "\t\t\tNhap N de thoat!\n";
	changeColor(9);
dd:
	list <BanDoc*>::iterator p = L2.begin();
	cout << "\t\tNhap ma ban doc can tim thong tin: ";
	cin >> sMBD;
	if (sMBD == "N")
	{
		changeColor(10);
		cout << "\t\t\tBan da chon thoat!\n";
		changeColor(7);
		return;
	}
	while(p != L2.end())
	{
		if (sMBD == (*p)->getMBD())
		{
			changeColor(3);
			(*p)->output();
			cout << "************************************";
			cout << endl;
			return;
		}
		p++;
	}
	changeColor(4);
	cout << "\t\t\tMa ban doc khong ton tai!\n";
	changeColor(7);
	goto dd;
}
bool kiemTraBD(list <BanDoc*> L2, string sMaBD)
{
	list <BanDoc*>::iterator p = L2.begin();
	while(p != L2.end())
	{
		if (sMaBD == (*p)->getMBD())
		{
			return true;
		}
		p++;
	}
	return false;
}
void outputData_BanDoc_ToScreen(list <BanDoc*> L2)
{
	list <BanDoc*> ::iterator p = L2.begin();
	while(p!= L2.end())
	{
		(*p)->output();
		p++;
	}
}
void inputData_BanDoc(list <BanDoc*> &L2)
{
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	while(!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			L2.push_back(gv);
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
			BanDoc * sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L2.push_back(sv);
		}
	}
	File.close();
}
//DS Sách
int nDemSachDaMuon(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getTinhTrang() != 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
int nDemSachChuaMuon(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getTinhTrang() == 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
void timKiem(list <Sach> L3)
{
	int flag = 0;
	changeColor(4);
	
	cout << "\t\tNhap N de thoat!\n";
	changeColor(23);
	string sTimKiem = "";
dd:
	cout << "\t\tNhap ma sach can tim: ";
	rewind(stdin);
	fflush(stdin);
	getline(cin, sTimKiem);
	if (sTimKiem == "N")
	{
		changeColor(10);
		cout << "\t\tBan da chon thoat! \n";
		changeColor(7);
	}
	else 
	{
		list <Sach>::iterator p = L3.begin();
		while(p != L3.end())
		{
			if (sTimKiem == p->getMS())
			{
				flag = 0;
				changeColor(11);
				cout << "\n\t\tTHONG TIN SACH\n";
				p->outputSach();
				cout << "*********************************************\n";
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			changeColor(4);
			cout << "\t\tMa sach khong ton tai !\n";
			changeColor(7);
			goto dd;
		}
	}

}
void xoaSach(list <Sach> &L3)
{
	cout << "\t\tNhap N de thoat! \n";
	string sSachCanXoa = "";
dd:
	rewind(stdin);
	fflush(stdin);
	cout << "\t\tNhap ma so sach can xoa: ";
	getline(cin, sSachCanXoa);
	if (sSachCanXoa == "N")
	{
		changeColor(10);
		cout << "\t\tBan da chon thoat! \n";
		changeColor(7);
	}
	else 
	{
		int flag = 0;
		list <Sach>::iterator p = L3.begin();
		while(p != L3.end())
		{
			if (sSachCanXoa == p->getMS() && p->getTinhTrang() == 0)
			{
				flag = 0;
				changeColor(10);
				cout << "\t\t\tXoa sach thanh cong!";
				changeColor(7);
				L3.erase(p);
				outputData_Sach_File(L3);
				cout << endl;
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			changeColor(4);
			cout << "\t\tMa so sach khong ton tai, hoac sach dang duoc muon!\n";
			changeColor(7);
			goto dd;
		}
	}

}
void themSach(list <Sach> &L3)
{
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fTriGia = NULL;
	int nNPH = 0;
	int nST = 0;
	int nNgay = Now->tm_mday;         
	int nThang = Now->tm_mon + 1;    
	int nNam = Now->tm_year + 1900;  
	int nTT = 0;
	dd:
	cout << "\t\tNhap ma so sach: ";
	rewind(stdin);
	fflush(stdin);
	getline(cin, sMS);
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
	
		if (sMS == p->getMS() || sMS == "")
		{
			changeColor(4);
			cout << "\t\t\tMa so sach da ton tai!!!\n";
			changeColor(7);
			system("pause");
			goto dd;
		}
		p++;
	}
	td:
	cout << "\t\tNhap tua de sach: ";
	fflush(stdin);
	getline(cin, sTD);
	if (sTD == "")
	{
		changeColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		changeColor(7);
		goto td;
	}
	tg:
	cout << "\t\tNhap ten tac gia: ";
	fflush(stdin);
	getline(cin, sTG);
		if (sTG == "")
	{
		changeColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		changeColor(7);
		goto tg;
	}
	nxb:
	cout << "\t\tNhap nha xuat ban: ";
	fflush(stdin);
	getline(cin, sNXB);
	if (sNXB == "")
	{
		changeColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		changeColor(7);
		goto nxb;
	}
	cout << "\t\tNhap gia cuon sach: ";
	cin >> fTriGia;
	cout << "\t\tNhap nam phat hanh: ";
	cin >> nNPH;
	cout << "\t\tNhap so trang: ";
	cin >> nST;
	nTT = 0;
	Sach s(sMS, sTD, sTG, sNXB, fTriGia, nNPH, nST, nNgay, nThang, nNam, nTT);
	L3.push_back(s);
	changeColor(10);
	cout << "\t\tthem sach thanh cong !\n";
	changeColor(7);
}
void outputData_Sach_File(list <Sach> L3)
{
	ofstream File;
	File.open("Sach.txt");
	int nDem = 1;
	int nTongSoSach = dem_Tong_So_Sach_Hien_Co(L3);
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		File << p->getMS() << "," << p->getTD() << "," << p->getTG() << "," << p->getNXB() << "," << p->getGia() << "," << p->getNPH() << "," << p->getST() << "," << p->getNgayNK() << "," << p->getThangNK() << "," << p->getNamNK() << "," << p->getTinhTrang();		
		if (nDem < nTongSoSach)
		{
			File << endl;
			nDem++;
		}	
		p++;
	}
	File.close();
}
void outputData_Sach_ToScreen(list <Sach> L3)
{
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		p->outputSach();
		p++;
	}
}
void inputData_Sach(list <Sach> &L3)
{
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fTriGia = 0.0;
	int nNPH = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTT = 0;
	ifstream File;
	File.open("Sach.txt");
	while(!File.eof())
	{
		getline(File, sMS, ',');
		getline(File, sTD, ',');
		getline(File, sTG, ',');
		getline(File, sNXB, ',');
		File >> fTriGia;
		File.ignore(1, ',');
		File >> nNPH;
		File.ignore(1, ',');
		File >> nST;
		File.ignore(1, ',');
		File >> nNgay;
		File.ignore(1, ',');
		File >> nThang;
		File.ignore(1, ',');
		File >> nNam;
		File.ignore(1, ',');
		File >> nTT;
		File.ignore(1, '\n');
		Sach s(sMS, sTD, sTG, sNXB, fTriGia, nNPH, nST, nNgay, nThang, nNam, nTT);
		L3.push_back(s);
	}
	File.close();
}
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
bool kiemTraSach_DuTieuChuanMuon(list <Sach> L3, string sMS)
{
	list <Sach> ::iterator p = L3.begin();
	while(p != L3.end())
	{
		if(sMS == p->getMS() && p->getTinhTrang() == 0)
		{
			return true;
		}
		p++;
	}
	return false;
}
//Admin
string passwordInput(unsigned maxLength)
{
	string pw = "";
	for (char c; (c = getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		} else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!pw.empty()) pw.erase(pw.size()-1);
		} else if (c == -32) { //phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		} else if (isprint(c) && pw.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			pw += c;
		}
	}
	return pw;
}
void changeColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
 
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void login_Admin(list <Admin> L, list <Sach> L3, list <BanDoc*> L2, list <PhieuMuon> L4)
{
	int nChucNangMenu = 0;
	string sU = "";
	string sP = "";
	int flag = 0;
	while (true)
	{
		system("cls");
		cout << "\t\t************************************\n";
		changeColor(10);
		cout << "\t\t*            Dang nhap             *\n";
		changeColor(7);
		cout << "\t\t************************************\n";
		changeColor(4);
		cout << "\t\t Nhap \"ESC\" de thoat!\n";
		changeColor(9);
		cout << "\n\t\tNhap Username: ";
		rewind(stdin);
		fflush(stdin);
		getline(cin, sU);
		if(sU == "ESC" || sU == "esc")
		{
			flag = 1;
			break;
		}
		cout << "\n\t\tNhap Password: ";
		fflush(stdin);
		sP = passwordInput(6);
		list <Admin>::iterator p = L.begin();
		while(p != L.end())
		{
			if(sU == p->getUser() && sP == p->getPass())
			{
				flag = 1;
				cout << "Login thanh cong !\n";
				while(true)
				{
					system("cls");
					changeColor(3);
					cout << "\t\t****************QUAN LY********************\n";
					cout << "\t\t  1. Quan ly phieu muon.                   \n";
					cout << "\t\t  2. Quan ly sach.                         \n";
					cout << "\t\t  3. Quan ly ban doc.                      \n";
					cout << "\t\t  4. Thong ke.                             \n";
					cout << "\t\t  0. Thoat!                                \n";
					cout << "\t\t*******************************************\n";
					cout << "\t\t   Nhap Lua Chon: ";
					cin >> nChucNangMenu;
					if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 4 && nChucNangMenu != 0)
					{
						cout << "Nhap sai vui long lua chon lai.\n";
						system("pause");
					}
					else if (nChucNangMenu == 1)
					{
						while(true)
						{
							system("cls");
							changeColor(10);
							cout << "\t\t*************QUAN LY PHIEU MUON************\n";
							cout << "\t\t  1. Them phieu muon.                     \n";
							cout << "\t\t  2. Tra Sach.                            \n";
							cout << "\t\t  3. Xuat danh dach phieu muon            \n";
							cout << "\t\t  0. Thoat!                               \n";
							cout << "\t\t******************************************\n";
							changeColor(12);
							cout << "\t\t   Nhap Lua Chon: ";
							rewind(stdin);
							cin >> nChucNangMenu;
						if (nChucNangMenu == 1)
						{
							changeColor(9);
							them_PhieuMuon(L4, L2, L3);
							changeColor(14);
							system("pause");
						}
						else if (nChucNangMenu == 2)
						{
							changeColor(9);
							traSach_PhieuMuon(L4, L2, L3);
							changeColor(14);
							system("pause");
						}
						else if (nChucNangMenu == 3)
						{
							changeColor(9);
							outputData_PhieuMuon_ToScreen(L4);
							changeColor(14);
							system("pause");
						}
						else if (nChucNangMenu == 0)
						{
							break;
						}
						else
						{
							changeColor(9);
							cout << "\t\tNhap sai vui long lua chon lai.\n";
							changeColor(14);
							system("pause");
						}
						}
					}
					else if (nChucNangMenu == 2)
					{
						while(true)
						{
							system("cls");
							changeColor(8);
							cout << "\t\t********Quan Ly Sach********\n";
							cout << "\t\t      1. Them sach moi.     \n";
							cout << "\t\t      2. Xoa Sach.          \n";
							cout << "\t\t      3. Xem ds sach.       \n";
							cout << "\t\t      0. Thoat!             \n";
							cout << "\t\t****************************\n";
							changeColor(12);
							cout << "\t\tNhap chuc nang can chon: ";
							cin >> nChucNangMenu;
							if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 0)
							{
								changeColor(12);
								cout << "\t\tNhap sai vui long lua chon lai.\n";
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 1)
							{
								changeColor(10);
								themSach(L3);
								outputData_Sach_File(L3);
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 2)
							{
								changeColor(10);
								xoaSach(L3);
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 3)
							{
								changeColor(10);
								outputData_Sach_ToScreen(L3);
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 0)
							{
								break;
							}
						}

						system("pause");
					}
					else if (nChucNangMenu == 3)
					{
						while(true)
						{
							system("cls");
							changeColor(2);
							cout << "\t\t\t********QUAN LY BAN DOC*********\n";
							cout << "\t\t\t  1. Them ban doc              \n";
							cout << "\t\t\t  0. Thoat!                    \n";
							cout << "\t\t\t*******************************\n"; 
							changeColor(12);
							cout << "\t\t\tNhap chuc nang can chon: ";
							cin  >> nChucNangMenu;
							if (nChucNangMenu == 1)
							{
								themBanDoc(L2);
							}
							else if (nChucNangMenu == 0)
							{
								break;
							}
							else
							{
								changeColor(4);
								cout << "\t\tNhap sai! Vui long nhap lai.\n";
								changeColor(14);
								system("pause");
							}
						}
						changeColor(14);
						system("pause");
					}
					else if (nChucNangMenu == 4)
					{
						while(true)
						{
							system("cls");
							changeColor(10);
							cout << "\t\t*************************Thong ke*************************\n";
							cout << "\t\t  1. Tong so sach con lai trong thua vien chua duoc muon. \n";
							cout << "\t\t  2. Tong so sach da muon.                                \n";
							cout << "\t\t  3. Liet ke sach ma 1 ban doc dang muon bang ma ban doc. \n";
							cout << "\t\t  4. Tong so ban doc la giao vien.                        \n";
							cout << "\t\t  5. Tong so ban doc la sinh vien.                        \n";
							cout << "\t\t  0. Thoat!                                               \n";
							cout << "\t\t**********************************************************\n";
							changeColor(12);
							cout << "\n\n\t\tNhap chuc nang: ";
							cin >> nChucNangMenu;
							if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 0 && nChucNangMenu != 4 && nChucNangMenu != 5)
							{
								changeColor(4);
								cout << "\t\tNhap sai! Vui long nhap lai.\n";
								changeColor(14);	
								system("pause");
							}
							else if (nChucNangMenu == 1)
							{
								changeColor(10);
								cout << "\t\tTong so sach con lai trong thu vien chua duoc muon la: " << nDemSachChuaMuon(L3) << endl;
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 2)
							{
								changeColor(10);
								cout << "\t\tTong so sach da duoc muon la: " << nDemSachDaMuon(L3) << endl;
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 3)
							{
								lietKeSach1BanDocDangMuon(L4, L3);
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 4)
							{
								changeColor(10);
								cout << "\t\tTong so ban doc la giao vien: " << soLuongBanDocGiaoVien(L2) << endl;
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 5)
							{
								changeColor(10);
								cout << "\t\tTong so ban doc la sinh vien: " << soLuongBanDocSinhVien(L2) << endl;
								changeColor(14);
								system("pause");
							}
							else if (nChucNangMenu == 0)
							{
								break;
							}
						}
					}
					else if (nChucNangMenu == 0)
					{
						break;
					}
				}
				system("pause");
			}
			p++;
		}
		if (flag == 0)
		{
			cout << "Nhap sai! Vui Long nhap lai.";
			system("pause");
		}
	}

}
int outputData_Admin(list <Admin> L)
{
	int nDem = 0;
	Admin Ad;
	list <Admin>::iterator p = L.begin();
	int dem = 1;
	while (p != L.end())
	{
		cout << "Ad Thu " << dem++ << endl;
		cout << "TK: " << p->getUser() << endl;
		cout << "MK: " << p->getPass() << endl;
		p++;
		nDem++;
	}
	return nDem;
}
void inputData_Admin(list <Admin> &L)
{
	ifstream File;
	File.open("Admin.txt");
	while(!File.eof())
	{
		Admin Ad;
		string u = "";
		string p = "";
		getline(File, u, ',');
		Ad.setUser(u);
		getline(File, p);
		Ad.setPass(p);
		L.push_back(Ad);
		File.ignore(0,'\n');
	}
	File.close();
	
}