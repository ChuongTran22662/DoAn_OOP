#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class VeXe
{
protected:
	string MaSo;
	string LoaiXe;
	int TrangThai;
public:
	void DocFileVeXe(ifstream&);

	void XuatVeXe();

	void Setter_MaSo(string);
	string Getter_MaSo();

	void Setter_LoaiXe(string);
	string Getter_LoaiXe();

	void Setter_TrangThai(int);
	int Getter_TrangThai();
};

