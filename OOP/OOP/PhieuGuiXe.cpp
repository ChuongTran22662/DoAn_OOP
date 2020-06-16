#include "PhieuGuiXe.h"
#include <iomanip>	
#include"stdafx.h"
void PhieuGuiXe::Nhap() {
	cout << "\n\t\tNhap bien so :";
	cin >> this->BienSo;
	ThoiGianGuiXe.LayThoiGianTuHeThong();
}

void PhieuGuiXe::Xuat() {
	stdafx st;
	string TG=st.HT_NgayGio(ThoiGianGuiXe.Getter_Ngay(), ThoiGianGuiXe.Getter_Thang(), ThoiGianGuiXe.Getter_Nam(),
		ThoiGianGuiXe.Getter_Gio(), ThoiGianGuiXe.Getter_Phut(), ThoiGianGuiXe.Getter_Giay());

	cout << "\n\t\t\t\t ________________________________________________________";
	cout << "\n\t\t\t\t|              BAI DO XE - DAI HOC XAY DUNG              | ";
	cout << "\n\t\t\t\t|     55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi      |";
	cout << "\n\t\t\t\t|\t\t     * * * * *                           |";
	cout << "\n\t\t\t\t|\t\t      * * * *                            |";
	cout << "\n\t\t\t\t|                    PHIEU  GUI XE                       |";
	cout << "\n\t\t\t\t|                                                        |";
	cout << "\n\t\t\t\t| Bien so:    "; cout << setw(10) << left << this->BienSo << "                                 |       ";
	cout << "\n\t\t\t\t| Ma the xe : "; cout << setw(13) << left << this->MaSoVe << "                              |       ";
	cout << "\n\t\t\t\t| Ma so nhan vien : "; cout << setw(13) << left << this->MaSoNV << "                        |       ";
	cout << "\n\t\t\t\t| Thoi gian gui xe : "; cout << setw(20) << left << TG << "                |       ";
	cout << "\n\t\t\t\t|                                                        |";
	cout << "\n\t\t\t\t|                                                        |";
	cout << "\n\t\t\t\t|                                                        |";
	cout << "\n\t\t\t\t|________________________________________________________|" << endl;

	
}

void PhieuGuiXe::GhiPhieuGuiXe(ofstream& FileOut) {
	FileOut << this->MaSoVe << " " << this->BienSo << " " << this->MaSoNV << " ";
	ThoiGianGuiXe.GhiFileThoiGian(FileOut);
}

void PhieuGuiXe::Setter_BienSo(string b) {
	this->BienSo = b;
}

void PhieuGuiXe::Setter_MaSoVe(string ms) {
	this->MaSoVe = ms;
}

string PhieuGuiXe::Getter_BienSo() {
	return this->BienSo;
}

string PhieuGuiXe::Getter_MaSoVe() {
	return this->MaSoVe;
}

void PhieuGuiXe::Setter_ThoiGian(ThoiGian x) {
	this->ThoiGianGuiXe = x;
}

ThoiGian PhieuGuiXe::Getter_ThoiGian() {
	return this->ThoiGianGuiXe;
}

string PhieuGuiXe::Getter_MaSoNV() {
	return this->MaSoNV;
}

void PhieuGuiXe::Setter_MaSoNV(string ms) {
	this->MaSoNV = ms;
}

void PhieuGuiXe::DocThongTinXeGui(ifstream& FileIn) {
	FileIn >> this->MaSoVe;
	FileIn.seekg(1, 1);
	FileIn >> this->BienSo;
	FileIn.seekg(1, 1);
	FileIn >> this->MaSoNV;
	FileIn.seekg(1, 1);
	this->ThoiGianGuiXe.DocFileThoiGian(FileIn);
}

