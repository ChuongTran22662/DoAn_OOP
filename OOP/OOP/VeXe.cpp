#include "VeXe.h"

void VeXe::DocFileVeXe(ifstream& FileIn) {
	FileIn >> this->MaSo;
	FileIn >> this->LoaiXe;
	FileIn >> this->TrangThai;
}

void VeXe::XuatVeXe() {
	cout << "\n\t\tMa so ve xe :" << this->MaSo;
	cout << "\n\t\tLoai xe :" << this->LoaiXe;
	cout << "\n\t\tTrang thai :" << this->TrangThai;
}

void VeXe::Setter_MaSo(string x) {
	this->MaSo = x;
}

string VeXe::Getter_MaSo() {
	return this->MaSo;
}

void VeXe::Setter_LoaiXe(string x) {
	this->LoaiXe = x;
}

string VeXe::Getter_LoaiXe() {
	return this->LoaiXe;
}

void VeXe::Setter_TrangThai(int x) {
	this->TrangThai = x;
}

int VeXe::Getter_TrangThai() {
	return this->TrangThai;
}
