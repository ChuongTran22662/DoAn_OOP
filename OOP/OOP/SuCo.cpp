#include "SuCo.h"

void SuCo::DocFileSuCo(ifstream& FileIn)
{
	getline(FileIn, this->MaSuCo, '/');
	FileIn.seekg(0, 1);
	getline(FileIn, this->TenSuCo, '/');
	FileIn.seekg(0, 1);
	FileIn >> this->SoTien;
	FileIn.seekg(1, 1);
	getline(FileIn, this->LoaiXe);
}

void SuCo::Xuat() {
	cout << "\nMa su co :" << this->MaSuCo;
	cout << "\nTen su co :" << this->TenSuCo;
	cout << "\nLoai xe :" << this->LoaiXe;
	cout << "\nSo tien :" << this->SoTien;
}

void SuCo::Setter_MaSuCo(string x) {
	this->MaSuCo = x;
}

string SuCo::Getter_MaSuCo() {
	return this->MaSuCo;
}

void SuCo::Setter_TenSuCo(string x) {
	this->TenSuCo = x;
}

string SuCo::Getter_TenSuCo() {
	return this->TenSuCo;
}

void SuCo::Setter_LoaiXe(string x) {
	this->LoaiXe = x;
}

string SuCo::Getter_LoaiXe() {
	return this->LoaiXe;
}

void SuCo::Setter_SoTien(int x) {
	this->SoTien = x;
}

int SuCo::Getter_SoTien() {
	return this->SoTien;
}

