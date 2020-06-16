#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<string>

class SuCo
{
private:
	string MaSuCo;
	string TenSuCo;
	string LoaiXe;
	int SoTien;

public:
	void DocFileSuCo(ifstream&);
	void Xuat();

	void Setter_MaSuCo(string);
	string Getter_MaSuCo();

	void Setter_TenSuCo(string);
	string Getter_TenSuCo();

	void Setter_LoaiXe(string);
	string Getter_LoaiXe();

	void Setter_SoTien(int);
	int Getter_SoTien();
};

