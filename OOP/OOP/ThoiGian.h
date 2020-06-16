#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

class ThoiGian
{
private:
	int Ngay;
	int Thang;
	int Nam;
	int Gio;
	int Phut;
	int Giay;

public:
	void LayThoiGianTuHeThong();
	void Xuat();

	void Setter_Ngay(int);
	int Getter_Ngay();

	void Setter_Thang(int);
	int Getter_Thang();

	void Setter_Nam(int);
	int Getter_Nam();

	void Setter_Gio(int);
	int Getter_Gio();

	void Setter_Phut(int);
	int Getter_Phut();

	void Setter_Giay(int);
	int Getter_Giay();

	void DocFileThoiGian(ifstream&);
	void GhiFileThoiGian(ofstream&);

	int SoGioGuiXe(ThoiGian);
	int ThanhTien(string, int);
	int SoGiay();
};

