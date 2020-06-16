#pragma once
#include<string>
using namespace std;
class LichSuThayDoiGiaVe
{
	string nv;
	string LoaiXe;
	int Khung1;
	int Khung2;
	int Khung3;
	string NgayGui;
	string GioGui;

public:
	void Setter_NV(string);
	string Getter_NV();

	void Setter_LoaiXe(string);
	string Getter_LoaiXe();

	void Setter_Khung1(int);
	int Getter_Khung1();

	void Setter_Khung2(int);
	int Getter_Khung2();

	void Setter_Khung3(int);
	int Getter_Khung3();

	void Setter_NgayGui(string);
	string Getter_NgayGui();

	void Setter_GioGui(string);
	string Getter_GioGui();

	void DocLSGV(ifstream&);
};

