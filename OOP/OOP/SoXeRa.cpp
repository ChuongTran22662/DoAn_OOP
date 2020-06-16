#include "SoXeRa.h"
#include"stdafx.h"

void SoXeRa::DocTTSoXeRa(ifstream&  FileIn) {	
	FileIn >> this->MaSoVe;
	FileIn.seekg(1, 1);	
	FileIn >> this->BienSo;
	FileIn.seekg(1, 1);
	FileIn >> this->MaSoNV_Gui;
	FileIn.seekg(1, 1);
	FileIn >> this->MaSoNV_Xuat;
	FileIn.seekg(1, 1);
	this->ThoiGian_Gui.DocFileThoiGian(FileIn);
	this->ThoiGian_Xuat.DocFileThoiGian(FileIn);
	FileIn.seekg(1, 1);
	FileIn >> this->GiaTinhTien;
}

void SoXeRa::Setter_BienSo(string x) {
	this->BienSo = x;
}

string SoXeRa::Getter_BienSo() {
	return this->BienSo;
}

void SoXeRa::Setter_MaSoVe(string x) {
	this->MaSoVe = x;
}

string SoXeRa::Getter_MaSoVe() {
	return this->MaSoVe;
}

void SoXeRa::Setter_MaSoNV_Gui(string x) {
	this->MaSoNV_Gui = x;
}

string SoXeRa::Getter_MaSoNV_Gui() {
	return this->MaSoNV_Gui;
}

void SoXeRa::Setter_MaSoNV_Xuat(string x) {
	this->MaSoNV_Xuat = x;
}
string SoXeRa::Getter_MaSoNV_Xuat() {
	return this->MaSoNV_Xuat;
}

void SoXeRa::Setter_ThoiGian_Gui(ThoiGian x) {
	this->ThoiGian_Gui = x;
}
ThoiGian SoXeRa::Getter_ThoiGian_Gui() {
	return this->ThoiGian_Gui;
}

void SoXeRa::Setter_ThoiGian_Xuat(ThoiGian x) {
	this->ThoiGian_Xuat = x;
}
ThoiGian SoXeRa::Getter_ThoiGian_Xuat() {
	return this->ThoiGian_Xuat;
}

void SoXeRa::Setter_GiaTinhTien(int x) {
	this->GiaTinhTien = x;
}
int SoXeRa::Getter_GiaTinhTien() {
	return this->GiaTinhTien;
}

