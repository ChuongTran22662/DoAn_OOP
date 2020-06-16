#pragma once
#include"NhanVien.h"
#include<vector>

class DanhSachNhanVien
{
private:
	vector<NhanVien> DSNV;
public:
	void DocDSNV(ifstream&);
	void Xuat();

	void Setter_DSNV(vector<NhanVien> list);
	vector<NhanVien> Getter_DSNV();
};

