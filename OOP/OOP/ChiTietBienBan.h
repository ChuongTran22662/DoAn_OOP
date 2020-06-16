#pragma once
#include<iostream>
using namespace std;
#include<string>

class ChiTietBienBan
{
private:
	string MaBB;
	string MaSuCo;
	int TienGiaiQuyet;

public:
//	void Nhap();
	void Xuat();

	void GhiFileCTBB(fstream&);
	void DocFileCTBB(ifstream&);


	void Setter_MaSuCo(string);
	string Getter_MaSuCo();


	void Setter_TienGiaiQuyet(double);
	double Getter_TienGiaiQuyet();

	void Setter_MaBB(string);
	string Getter_MaBB();
};

