#pragma once
#include"ThoiGian.h"
class PhieuGuiXe
{
private:
	string BienSo;
	string MaSoVe;
	string MaSoNV;
	ThoiGian ThoiGianGuiXe;
public:
	void Nhap();
	void Xuat();

	void GhiPhieuGuiXe(ofstream&);

	void Setter_BienSo(string);
	string Getter_BienSo();

	void Setter_MaSoVe(string);
	string Getter_MaSoVe();

	void Setter_MaSoNV(string);
	string Getter_MaSoNV();

	void Setter_ThoiGian(ThoiGian);
	ThoiGian Getter_ThoiGian();
	void DocThongTinXeGui(ifstream&);
};

