#include "ThoiGian.h"
#include"stdafx.h"
#include"BangGia.h"
void ThoiGian::LayThoiGianTuHeThong() {
	time_t baygio = time(0);

	tm* ltm = localtime(&baygio);

	this->Gio = ltm->tm_hour;
	this->Phut = ltm->tm_min;
	this->Giay = ltm->tm_sec;
	this->Ngay = ltm->tm_mday;
	this->Thang = 1 + ltm->tm_mon;
	this->Nam = 1900 + ltm->tm_year;
}

void ThoiGian::Xuat() {
	cout << "\t\t| Ngay: " << this->Ngay << "/"
		<< this->Thang << "/" << this->Nam << endl;
	cout << "\t\t| Thoi gian: " << this->Gio << ":";
	cout << this->Phut << ":";
	cout << this->Giay << endl;
}

void ThoiGian::DocFileThoiGian(ifstream& FileIn) {
	FileIn >> this->Ngay;
	FileIn.seekg(1, 1);
	FileIn >> this->Thang;
	FileIn.seekg(1, 1);
	FileIn >> this->Nam;
	FileIn.seekg(1, 1);
	FileIn >> this->Gio;
	FileIn.seekg(1, 1);
	FileIn >> this->Phut;
	FileIn.seekg(1, 1);
	FileIn >> this->Giay;
}

void ThoiGian::GhiFileThoiGian(ofstream& FileOut) {
	FileOut << this->Ngay << " " << this->Thang << " "
		<< this->Nam << " " << this->Gio << " " << this->Phut << " " << this->Giay;
}

int ThoiGian::Getter_Gio() {
	return this->Gio;
}

void ThoiGian::Setter_Gio(int x) {
	this->Gio = x;
}

int ThoiGian::Getter_Phut() {
	return this->Phut;
}

void ThoiGian::Setter_Phut(int x) {
	this->Phut = x;
}

int ThoiGian::Getter_Ngay() {
	return this->Ngay;
}

void ThoiGian::Setter_Ngay(int x) {
	this->Ngay = x;
}

int ThoiGian::Getter_Thang() {
	return this->Thang;
}

void ThoiGian::Setter_Thang(int x) {
	this->Thang = x;
}

int ThoiGian::Getter_Nam() {
	return this->Nam;
}

void ThoiGian::Setter_Nam(int x) {
	this->Nam = x;
}

int ThoiGian::Getter_Giay() {
	return this->Giay;
}

void ThoiGian::Setter_Giay(int x) {
	this->Giay = x;
}

bool KTNamNhuan(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
	{
		return true;
	}
	return false;

}
int KiemTraThang(int mm, int yy) {
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		return 30;
	}
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
		return 31;
	}
	if (mm == 2 && KTNamNhuan(yy) == true) {
		return 29;
	}
	if (mm == 2 && KTNamNhuan(yy) == false) {
		return 28;
	}
	else return 0;
}

int ThoiGian::SoGiay() {
	stdafx STD;
	int ngay = this->Getter_Ngay();
	int thang = this->Getter_Thang();
	int nam = this->Getter_Nam();
	int gio = this->Getter_Gio();
	int phut = this->Getter_Phut();
	int giay = this->Getter_Giay();
	if (thang > 12 || thang < 1) {
		return 0;
	}

	else if (ngay < 1 || ngay>KiemTraThang(thang, nam)) {
		return 0;
	}
	else {
		int SoNamNhuan = 0;
		int SoNamKhongNhuan = 0;
		int tong = 0;
		int i;
		for (i = 1990; i < nam; i++) //moc thoi gian tinh tu: 1/1/1990 0:0:0
		{
			if (KTNamNhuan(i) == true) SoNamNhuan++;
			else SoNamKhongNhuan++;
		}

		for (i = 0; i < thang; i++) {
			tong = tong + KiemTraThang(i, nam);
		}
		int x1 = SoNamNhuan * 366;
		int x2 = SoNamKhongNhuan * 365;
		int TongSoNgay = x1 + x2 + ngay - 1 + tong;
		int TongGiay = TongSoNgay * 24 * 60 * 60 + gio * 60 * 60 + phut * 60 + giay;
		return (TongGiay);
	}
}
int ThoiGian::SoGioGuiXe(ThoiGian x) {

	int NgayLay = this->SoGiay();
	int NgayGui = x.SoGiay();
	int Gio;

	if (NgayLay > NgayGui && NgayGui > 0) {

		if ((NgayLay - NgayGui) < 60 * 60) {
			Gio = 1;
		}
		else {
			if ((NgayLay - NgayGui) % (60 * 60) <= 1799) {//18000 = 30*60 (30 phut)
				Gio = (NgayLay - NgayGui) / (60 * 60);
			}
			else {
				Gio = (NgayLay - NgayGui) / (60 * 60) + 1;
			}
		}
		return (Gio);
	}

	else {
		return 0;
	}

}

int ThoiGian::ThanhTien(string s, int SoGio) {
	BangGia bg;
	ifstream FileIn;
	FileIn.open("BangGia.txt", ios::in);
	bg.DocFileBangGia(FileIn);
	FileIn.close();
	int vitri;
	for (int i = 0; i < 2; i++) {
		if (bg.Getter_DS_BangGia()[i].Getter_Xe() == s) {
			vitri = i;
			break;
		}
		else {
			continue;
		}
	}
	if (SoGio < 5 && SoGio>0) {
		return bg.Getter_DS_BangGia()[vitri].Getter_Khung1();
	}
	else if (SoGio < 24) {
		return SoGio * bg.Getter_DS_BangGia()[vitri].Getter_Khung2();
	}
	else if (SoGio >= 24) {
		return SoGio * bg.Getter_DS_BangGia()[vitri].Getter_Khung3();
	}
	else return 0;

}