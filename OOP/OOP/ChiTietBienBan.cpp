#include "ChiTietBienBan.h"
#include<iomanip>
#include<fstream>

void ChiTietBienBan::Xuat() {
	cout << "\nMa su co :" << this->MaSuCo;
	cout << "\nTien giai quyet :" << this->TienGiaiQuyet;
}

void ChiTietBienBan::GhiFileCTBB(fstream& FileOut) {
	FileOut << this->MaBB << " " << this->MaSuCo << " "<< this->TienGiaiQuyet;
}

void ChiTietBienBan::Setter_MaSuCo(string b) {
	this->MaSuCo = b;
}

void ChiTietBienBan::Setter_TienGiaiQuyet(double ms) {
	this->TienGiaiQuyet = ms;
}

string ChiTietBienBan::Getter_MaSuCo() {
	return this->MaSuCo;
}

double ChiTietBienBan::Getter_TienGiaiQuyet() {
	return this->TienGiaiQuyet;
}

void ChiTietBienBan::DocFileCTBB(ifstream& FileIn) {
	FileIn >> this->MaBB;
	FileIn.seekg(1, 1);
	FileIn >> this->MaSuCo;
	FileIn.seekg(1, 1);
	FileIn >> this->TienGiaiQuyet;
}

void ChiTietBienBan::Setter_MaBB(string x) {
	this->MaBB = x;
}
string ChiTietBienBan::Getter_MaBB() {
	return this->MaBB;
}
