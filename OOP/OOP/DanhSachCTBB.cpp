#include "DanhSachCTBB.h"
//#include"stdafx.h"
//#include"DanhSachSuCo.h"
//#include"DanhSachNhanVien.h"
#include"ChiTietBienBan.h"
//#include <iomanip>	
//#include"DanhSachXeTrongBen.h"
#include<math.h>
#include<fstream>
int DemSo_LuongXe() {
	ifstream FileIn;
	FileIn.open("ChiTietBienBan.txt", ios::in);
	int n = 0;
	char c;
	FileIn.get(c);
	while (FileIn) {
		while (FileIn && c != '\n') {
			FileIn.get(c);
		}
		n = n + 1;
		FileIn.get(c);
	}
	FileIn.close();
	return n;
}

void DanhSachCTBB::DocDanhSachCTBB(ifstream& FileOut) {

	int size = DemSo_LuongXe();

	for (int i = 0; i < size; i++) {
		ChiTietBienBan x;
		x.DocFileCTBB(FileOut);
		DanhSach_CTBB.push_back(x);
	}
}

void DanhSachCTBB::Xuat()
{
	int size = DanhSach_CTBB.size();

	for (int i = 0; i < size; i++)
	{
		cout << "\n\t\tThong tin bien ban : " << i + 1 << "\n";
		DanhSach_CTBB[i].Xuat();
	}
}

vector<ChiTietBienBan> DanhSachCTBB::Getter_DanhSach_CTBB()
{
	return this->DanhSach_CTBB;
}

void DanhSachCTBB::Setter_DanhSach_CTBB(ChiTietBienBan x)
{
	DanhSach_CTBB.push_back(x);
}

void DanhSachCTBB::GhiDanhSachCTBB(fstream& FileOut/*,ThoiGian x*/) { 
	int size = DanhSach_CTBB.size();
	for (int i = 0; i < size; i++) {
		DanhSach_CTBB[i].GhiFileCTBB(FileOut);
		FileOut << endl;
	}
}