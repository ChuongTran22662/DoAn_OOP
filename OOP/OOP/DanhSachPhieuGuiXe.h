#pragma once
#include "PhieuGuiXe.h"
#include<vector>
#include<string>

class DanhSachPhieuGuiXe
{
private:
	vector<PhieuGuiXe> DanhSachPGX;
public:
	void Nhap();
	void Xuat();
	void GhiDanhSachPhieuGuiXe(ofstream&);

	void Setter_DanhSachPhieuGuiXe(PhieuGuiXe x);
	vector<PhieuGuiXe> Getter_DanhSachPhieuGuiXe();
};

