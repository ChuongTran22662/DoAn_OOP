#include "DS_LichSuGiaVe.h"
#include <iomanip>
#include"stdafx.h"
#include<iostream>
using namespace std;
void DS_LichSuGiaVe::Setter_ds_LichSuThayDoiGiaVe(LichSuThayDoiGiaVe x) {
	ds_LichSuThayDoiGiaVe.push_back(x);
}

vector< LichSuThayDoiGiaVe> DS_LichSuGiaVe::Getter_ds_LichSuThayDoiGiaVe() {
	return this->ds_LichSuThayDoiGiaVe;
}

void  DS_LichSuGiaVe::DocFileLSGX(ifstream& FileIn, int n) {
	for (int i = 0; i < n; i++) {
		LichSuThayDoiGiaVe x;
		x.DocLSGV(FileIn);
		ds_LichSuThayDoiGiaVe.push_back(x);
	}
}

void DS_LichSuGiaVe::HienThiLSTD() {
	stdafx st;
	ifstream FileIn;
	FileIn.open("LichSuGiaVe.txt", ios::in);
	int size_ls = st.DemSoLuongXe(FileIn);
	FileIn.close();
	FileIn.open("LichSuGiaVe.txt", ios::in);
	DocFileLSGX(FileIn, size_ls);

	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileNV;
	FileNV.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileNV);
	int size = y->Getter_DSNV().size();
	int Vtri_nv=-1;
	int stt_sc = 0;
	st.TextColor(202);
	cout << "\n\t\t\t\t\t\tLICH SU THAY DOI GIA TIEN GUI XE";
	cout << "\n\t\t ______________________________________________________________________________________________________________________________________";
	cout << "\n\t\t| STT |    Nhan vien thay doi   |    Loai xe   |     Khung gio 1     |     Khung gio 2     |     Khung gio 3     | Thoi gian thay doi  |";
	cout << "\n\t\t|_____|_________________________|______________|_____________________|_____________________|_____________________|_____________________|";
	st.TextColor(14);
	for (int i = 0; i < size_ls; i++) {
		stt_sc++;

		cout << "\n\t\t|"; cout << setw(5) << left << stt_sc; cout << "|";
		for (int j = 0; j < size; j++) {
			if (y->Getter_DSNV()[j].Getter_MaNhanVien() != this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_NV()) continue;
			else {
				Vtri_nv = j;
				break;
			}
		}
		cout << setw(25) << left << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "|";
		if (this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_LoaiXe() == "XM") {
		cout << setw(14) << left << "Xe may"; cout << "|";
		}	
		else {
			cout << setw(14) << left << "Xe oto"; cout << "|";
		}
		cout << setw(17) << right << this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_Khung1() << " VND"; cout << "|";
		cout << setw(17) << right << this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_Khung2() << " VND"; cout << "|";
		cout << setw(17) << right << this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_Khung3() << " VND"; cout << "|";
		cout << setw(11) << left << this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_NgayGui() ;
		cout << setw(8) << left << this->Getter_ds_LichSuThayDoiGiaVe()[i].Getter_GioGui(); cout << "  |";

	}
	cout << "\n\t\t|_____|_________________________|______________|_____________________|_____________________|_____________________|_____________________|";

}