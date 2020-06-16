#pragma once
#include"ThoiGian.h"
class SoXeRa
{
private:
	string BienSo;
	string MaSoVe;
	string MaSoNV_Gui;
	string MaSoNV_Xuat;
	ThoiGian ThoiGian_Gui;
	ThoiGian ThoiGian_Xuat;
	int GiaTinhTien;
public:
	void DocTTSoXeRa(ifstream&);

	void Setter_BienSo(string);
	string Getter_BienSo();

	void Setter_MaSoVe(string);
	string Getter_MaSoVe();

	void Setter_MaSoNV_Gui(string);
	string Getter_MaSoNV_Gui();

	void Setter_MaSoNV_Xuat(string);
	string Getter_MaSoNV_Xuat();

	void Setter_ThoiGian_Gui(ThoiGian);
	ThoiGian Getter_ThoiGian_Gui();

	void Setter_ThoiGian_Xuat(ThoiGian);
	ThoiGian Getter_ThoiGian_Xuat();

	void Setter_GiaTinhTien(int);
	int Getter_GiaTinhTien();

};

