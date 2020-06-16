#include "GiaTien.h"
void GiaTien::DocBangGia(ifstream& FileIn) {
	FileIn >> this->Xe;
	FileIn.seekg(1, 1);
	FileIn >> this->Khung1;
	FileIn.seekg(1, 1);
	FileIn >> this->Khung2;
	FileIn.seekg(1, 1);
	FileIn >> this->Khung3;
}
void GiaTien::Setter_Khung1(float k) {
	this->Khung1 = k;
}
float GiaTien::Getter_Khung1() {
	return this->Khung1;
}

void GiaTien::Setter_Khung2(float k) {
	this->Khung2 = k;
}
float GiaTien::Getter_Khung2() {
	return this->Khung2;
}

void GiaTien::Setter_Khung3(float k) {
	this->Khung3 = k;
}
float GiaTien::Getter_Khung3() {
	return this->Khung3;
}

void GiaTien::Setter_Xe(string x) {
	this->Xe = x;
}
string GiaTien::Getter_Xe() {
	return this->Xe;
}
















