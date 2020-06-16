#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Ngay.h"

class NhanVien
{
private:
	string MaNhanVien;
	string HoTen;
	Ngay NgaySinh;
	string MatKhau;
	string LoaiNhanVien;
public:
//	void Nhap();
	void Xuat();

	void DocFileNhanVien(ifstream&);

//	void GhiNhanVien(ofstream&);

	void Setter_LoaiNhanVien(string);
	string Getter_LoaiNhanVien();

	void Setter_MaNhanVien(string);
	string Getter_MaNhanVien();

	void Setter_HoTen(string);
	string Getter_HoTen();

	void Setter_MatKhau(string);
	string Getter_MatKhau();

	
};

