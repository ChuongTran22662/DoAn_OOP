#include "DanhSachNhanVien.h"


void DanhSachNhanVien::DocDSNV(ifstream& FileIn) {
	while (!FileIn.eof())
	{
		NhanVien x;
		x.DocFileNhanVien(FileIn);
		DSNV.push_back(x);
	}
}

void DanhSachNhanVien::Xuat() {
	int size = DSNV.size();

	for (int i = 0; i < size; i++) {
		DSNV[i].Xuat();
	}
}

vector<NhanVien> DanhSachNhanVien::Getter_DSNV()
{
	return DSNV;
}

void DanhSachNhanVien::Setter_DSNV(vector<NhanVien> list)
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		DSNV.push_back(list[i]);
	}
}