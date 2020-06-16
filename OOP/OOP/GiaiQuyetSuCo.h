#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"ThoiGian.h"

class GiaiQuyetSuCo
{
private:
	string MaBB;
	string MaThe;
	string BienSo;
	string MaNhanVienQuanLy;
	string MaNhanVienNhanXe;
	string LoaiXe;
	ThoiGian ThoiGianGuiXe;
	ThoiGian ThoiGianGiaiQuyetSuCo;

public:
	void Nhap();
	void Xuat();

	void GhiFileSuCo(ofstream&);
	void DocFileSuCo(ifstream&);

	void Setter_MaBB(string);
	string Getter_MaBB();

	void Setter_MaThe(string);
	string Getter_MaThe();

	void Setter_BienSo(string);
	string Getter_BienSo();

	void Setter_MaNhanVienQuanLy(string);
	string Getter_MaNhanVienQuanLy();

	void Setter_MaNhanVienNhanXe(string);
	string Getter_MaNhanVienNhanXe();

	void Setter_LoaiXe(string);
	string Getter_LoaiXe();

	void Setter_ThoiGianGiaiQuyetSuCo(ThoiGian);
	ThoiGian Getter_ThoiGianGiaiQuyetSuCo();

	void Setter_ThoiGianGuiXe(ThoiGian);
	ThoiGian Getter_ThoiGianGuiXe();
};

