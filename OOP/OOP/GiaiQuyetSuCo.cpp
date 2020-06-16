#include "GiaiQuyetSuCo.h"
#include<iomanip>

void GiaiQuyetSuCo::Nhap() {
	ThoiGianGiaiQuyetSuCo.LayThoiGianTuHeThong();
}

void GiaiQuyetSuCo::Xuat() {
	cout << "\nMa the :" << this->MaThe;
	cout << "\nBien so :" << this->BienSo;
	cout << "\nMa Nhan Vien Nhan Xe :" << this->MaNhanVienNhanXe;
	cout << "\nMa Nhan Vien Quan Ly :" << this->MaNhanVienQuanLy;
	cout << "\nLoai xe :" << this->LoaiXe;
	ThoiGianGiaiQuyetSuCo.Xuat();
}

void GiaiQuyetSuCo::GhiFileSuCo(ofstream& FileOut) {
	FileOut << this->MaBB << " " << this->MaThe << " " <<  
	this->BienSo << " " << this->LoaiXe << " " <<
	this->MaNhanVienNhanXe << " " << this->MaNhanVienQuanLy << " ";
	ThoiGianGuiXe.GhiFileThoiGian(FileOut);
	FileOut << " ";
	ThoiGianGiaiQuyetSuCo.GhiFileThoiGian(FileOut);
}


void GiaiQuyetSuCo::Setter_BienSo(string b) {
	this->BienSo = b;
}

void GiaiQuyetSuCo::Setter_MaThe(string ms) {
	this->MaThe = ms;
}

void GiaiQuyetSuCo::Setter_LoaiXe(string ms) {
	this->LoaiXe = ms;
}

void GiaiQuyetSuCo::Setter_MaNhanVienNhanXe(string ms) {
	this->MaNhanVienNhanXe = ms;
}

void GiaiQuyetSuCo::Setter_MaNhanVienQuanLy(string ms) {
	this->MaNhanVienQuanLy = ms;
}


string GiaiQuyetSuCo::Getter_MaThe() {
	return this->MaThe;
}

string GiaiQuyetSuCo::Getter_BienSo() {
	return this->BienSo;
}


void GiaiQuyetSuCo::Setter_ThoiGianGiaiQuyetSuCo(ThoiGian x) {
	this->ThoiGianGiaiQuyetSuCo = x;
}
ThoiGian  GiaiQuyetSuCo::Getter_ThoiGianGiaiQuyetSuCo() {
	return this->ThoiGianGiaiQuyetSuCo;
}

void GiaiQuyetSuCo::Setter_ThoiGianGuiXe(ThoiGian x) {
	this->ThoiGianGuiXe = x;
}
ThoiGian GiaiQuyetSuCo::Getter_ThoiGianGuiXe() {
	return this->ThoiGianGuiXe;
}


string GiaiQuyetSuCo::Getter_LoaiXe() {
	return this->LoaiXe;
}

string GiaiQuyetSuCo::Getter_MaNhanVienNhanXe() {
	return this->MaNhanVienNhanXe;
}

string GiaiQuyetSuCo::Getter_MaNhanVienQuanLy() {
	return this->MaNhanVienQuanLy;
}


void GiaiQuyetSuCo::DocFileSuCo(ifstream& FileIn) {
	FileIn >> this->MaBB;
	FileIn.seekg(1, 1);
	FileIn >> this->MaThe;
	FileIn.seekg(1, 1);
	FileIn >> this->BienSo;
	FileIn.seekg(1, 1);
	FileIn >> this->LoaiXe;
	FileIn.seekg(1, 1);
	FileIn >> this->MaNhanVienNhanXe;
	FileIn.seekg(1, 1);
	FileIn >> this->MaNhanVienQuanLy;
	FileIn.seekg(1, 1);
	this->ThoiGianGuiXe.DocFileThoiGian(FileIn);
	FileIn.seekg(1, 1);
	this->ThoiGianGiaiQuyetSuCo.DocFileThoiGian(FileIn);
}

void GiaiQuyetSuCo::Setter_MaBB(string x) {
	this->MaBB = x;
}
string GiaiQuyetSuCo::Getter_MaBB() {
	return this->MaBB;
}
