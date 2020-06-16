#include "NhanVien.h"

void NhanVien::DocFileNhanVien(ifstream& FileIn)
{
	getline(FileIn, this->MaNhanVien, '/');
	FileIn.seekg(0, 1);
	getline(FileIn, this->HoTen, '/');
	FileIn.seekg(1, 1);
	NgaySinh.DocFileThoiGian(FileIn);
	FileIn.seekg(1, 1);
	getline(FileIn, this->MatKhau, '/');
	//FileIn.seekg(1, 1);
	getline(FileIn, this->LoaiNhanVien);
}

void NhanVien::Xuat() {
	cout << "\n\t\tMa Nhan Vien :" << this->MaNhanVien;
	cout << "\n\t\tHo Ten :" << this->HoTen;
	cout << "\n\t\tNgay sinh :";
	NgaySinh.XuatNgay();
	cout << "\n\t\tMat khau :" << this->MatKhau;
	cout << "\n\t\tLoai nhan vien :" << this->LoaiNhanVien;
}

void NhanVien::Setter_LoaiNhanVien(string x) {
	this->LoaiNhanVien = x;
}

string NhanVien::Getter_LoaiNhanVien() {
	return this->LoaiNhanVien;
}

void NhanVien::Setter_HoTen(string x) {
	this->HoTen = x;
}

string NhanVien::Getter_HoTen() {
	return this->HoTen;
}

void NhanVien::Setter_MaNhanVien(string x) {
	this->MaNhanVien = x;
}

string NhanVien::Getter_MaNhanVien() {
	return this->MaNhanVien;
}

void NhanVien::Setter_MatKhau(string x) {
	this->MatKhau = x;
}

string NhanVien::Getter_MatKhau() {
	return this->MatKhau;
}



