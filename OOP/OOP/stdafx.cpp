#include "stdafx.h"
#include<Windows.h>
#include<string>
#include<math.h>
#include <sstream>
#include"TheXeBiXoa.h"
#include"DanhSachTheBiXoa.h"
using namespace std;

using namespace std;

void stdafx::TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
bool stdafx::KT_PhutGiay(int x) {
	if (x < 0 || x>59) return false;
	else return true;
}

bool stdafx::KT_Gio(int x) {
	if (x < 0 || x>23) return false;
	else return true;
}

int stdafx::DemSoLuongXe(ifstream& FileIn) {
	int n = 0;
	char c;
	FileIn.get(c);
	while (FileIn) {
		while (FileIn && c != '\n') {
			FileIn.get(c);
		}
		n = n + 1;
		FileIn.get(c);
	}
	FileIn.close();
	return n;
}

bool stdafx::KT_HienTai(int sogiay) {
	ThoiGian htai;
	htai.LayThoiGianTuHeThong();
	if (htai.SoGiay() < sogiay) return false;
	else return true;
}
int stdafx::KT_TrungBien(string bien, int n) {
	ifstream FileIn;
	FileIn.open("danhsachphieuguixe.txt", ios::in);
	DanhSachXeTrongBen dsx;
	stdafx kt;
	int dem = 0;
	dsx.DocSoXeVao(FileIn, n);
	for (int i = 0; i < n; i++) {
		string bien1 = dsx.Getter_Dsxg()[i].Getter_BienSo();
		if (bien1 == bien) {
			dem++;
		}
		else continue;
	}
	return dem;
}


string stdafx::HT_NgayGio(int a1, int a2, int a3, int b1, int b2, int b3) {

	fstream file;
	file.open("temp.txt", ios::out);
	file << a1 << "/" << a2 << "/" << a3 << " " << b1 << ":" << b2 << ":" << b3 << "E";
	file.close();
	file.open("temp.txt", ios::in);
	string c;
	getline(file, c, 'E');
	file.close();
	remove("temp.txt");
	return c;
}
string stdafx::HT_NgayThang(int a1, int a2, int a3) {

	fstream file;
	file.open("temp.txt", ios::out);
	file << a1 << "/" << a2 << "/" << a3 << "E";
	file.close();
	file.open("temp.txt", ios::in);
	string c;
	getline(file, c, 'E');
	file.close();
	remove("temp.txt");
	return c;
}


string stdafx::HT_ThangNam(int a1, int a2) {
	fstream file;
	file.open("temp.txt", ios::out);
	file << a1 << "/" << a2 << "E";
	file.close();
	file.open("temp.txt", ios::in);
	string c;
	getline(file, c, 'E');
	file.close();
	remove("temp.txt");
	return c;
}

string stdafx::HT_VeXeThem(string a1, int a2) {
	fstream file;
	file.open("temp.txt", ios::out);
	file << a1 << a2 << "/";
	file.close();
	file.open("temp.txt", ios::in);
	string c;
	getline(file, c, '/');
	file.close();
	remove("temp.txt");
	return c;
}

int stdafx::TienTungLoaiXe(string s, int SoGio) {
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
		return bg.Getter_DS_BangGia()[vitri].Getter_Khung2();
	}
	else if (SoGio >= 24) {
		return bg.Getter_DS_BangGia()[vitri].Getter_Khung3();
	}
	else return 0;
}


int  stdafx::ChuyenString_SangInt(string s) {
	int l1 = s.length();
	int num1 = 0;
	for (int i = l1 - 1; i >= 0; --i) {
		num1 += (int)(s[i] - '0') * pow(10, l1 - i - 1);
	}
	return num1;
}

bool stdafx::KT_NV(string s) {
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	bool check_NVG = false;


	for (int j = 0; j < size; j++) {
		if (s != y->Getter_DSNV()[j].Getter_MaNhanVien() || y->Getter_DSNV()[j].Getter_LoaiNhanVien() != "NVTX") {
			check_NVG = false;
			continue;
		}
		else {
			check_NVG = true;
			break;
		}
	}
	return check_NVG;
}
int stdafx::KT_Xe_SXR(string bien, int n) {
	ifstream FileIn;
	FileIn.open("SoXeRa.txt", ios::in);
	TT_SoXeRa S_XeRa;
	stdafx kt;
	int dem = 0;
	S_XeRa.DocSoXeRa(n, FileIn);
	for (int i = 0; i < n; i++) {
		string bien1 = S_XeRa.Getter_DS_SoXeRa()[i].Getter_BienSo();
		if (bien1 == bien) {
			dem++;
		}
		else continue;
	}
	return dem;
}
bool stdafx::KT_BienBan(string MaBB, string MaSC) {
	bool check = false;
	DanhSachCTBB dsctbb;
	ifstream FileIn;
	FileIn.open("ChiTIetBienBan.txt", ios::in);
	int size=DemSoLuongXe(FileIn);
	FileIn.close();
	FileIn.open("ChiTIetBienBan.txt", ios::in);
	dsctbb.DocDanhSachCTBB(FileIn);
	for (int i = 0; i < size; i++) {
		if (dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB() == MaBB && dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaSuCo() == MaSC) {
			check = true;
			break;
		}
		else {
			check = false;
			continue;
		}
	}
	return check;
}