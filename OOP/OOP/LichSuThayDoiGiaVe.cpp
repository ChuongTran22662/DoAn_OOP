#include "LichSuThayDoiGiaVe.h"
#include<fstream>
void LichSuThayDoiGiaVe::Setter_NV(string nv) {
	this->nv = nv;
}

string  LichSuThayDoiGiaVe::Getter_NV() {
	return this->nv;
}

void  LichSuThayDoiGiaVe::Setter_LoaiXe(string lx) {
	this->LoaiXe = lx;
}
string  LichSuThayDoiGiaVe::Getter_LoaiXe() {
	return this->LoaiXe;
}

void LichSuThayDoiGiaVe::Setter_Khung1(int k1) {
	this->Khung1 = k1;
}
int LichSuThayDoiGiaVe::Getter_Khung1() {
	return this->Khung1;
}

void LichSuThayDoiGiaVe::Setter_Khung2(int k2) {
	this->Khung2 = k2;
}
int LichSuThayDoiGiaVe::Getter_Khung2() {
	return this->Khung2;
}

void LichSuThayDoiGiaVe::Setter_Khung3(int k3) {
	this->Khung3 = k3;
}
int LichSuThayDoiGiaVe::Getter_Khung3() {
	return this->Khung3;
}

void LichSuThayDoiGiaVe::Setter_NgayGui(string NgayGui) {
	this->NgayGui = NgayGui;
}
string LichSuThayDoiGiaVe::Getter_NgayGui() {
	return this->NgayGui;
}

void LichSuThayDoiGiaVe::Setter_GioGui(string GioGui) {
	this->GioGui = GioGui;
}
string LichSuThayDoiGiaVe::Getter_GioGui() {
	return this->GioGui;
}

void LichSuThayDoiGiaVe::DocLSGV(ifstream& FileIn) {
	FileIn >> this->nv;
	FileIn.seekg(1, 1);
	FileIn >> this->LoaiXe;
	FileIn.seekg(1, 1);
	FileIn >> this->Khung1;
	FileIn.seekg(1, 1);
	FileIn >> this->Khung2;
	FileIn.seekg(1, 1);
	FileIn >> this->Khung3;
	FileIn.seekg(1, 1);
	FileIn >> this->NgayGui;
	FileIn.seekg(1, 1);
	FileIn >> this->GioGui;

}