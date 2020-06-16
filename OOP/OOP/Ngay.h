#pragma once
#include <iostream>
#include<fstream>
using namespace std;

class Ngay
{
private:
	int Ngay, Thang, Nam;
public:
	void NhapNgay();
	void XuatNgay();

	void Setter_NgaySinh(int);
	int Getter_NgaySinh();

	void Setter_ThangSinh(int);
	int Getter_ThangSinh();

	void Setter_NamSinh(int);
	int Getter_NamSinh();

	void DocFileThoiGian(ifstream&);
	void GhiFileThoiGian(ofstream&);
};