#pragma once
#include<fstream>
#include<string>
#include<Windows.h>
#include"BangGia.h"
#include "DanhSachVeXe.h"
#include "DanhSachPhieuGuiXe.h"
#include "PhieuGuiXe.h"
#include"NhanVien.h"
#include"DanhSachNhanVien.h"
#include "DanhSachXeTrongBen.h"
#include"TT_SoXeRa.h"
#include "ThemTheXe.h"
#include "DanhSachXeTrongBen.h"
#include "DanhSachSuCo.h"
#include"SuCo.h"
#include"GiaiQuyetSuCo.h"
#include"DanhSachGiaiQuyetSuCo.h"
#include "TimKiem_BaoCao.h"
#include"ChiTietBienBan.h"
#include"DanhSachCTBB.h"
using namespace std;
class stdafx
{
public:

	int DemSoLuongXe(ifstream&);

	void TextColor(WORD );
//	bool KT_Ve(string);
	bool KT_NV(string);
//	bool KT_ThoiGian(int);
	bool KT_PhutGiay(int );
	bool KT_Gio(int );
	bool KT_HienTai(int);
	bool KT_BienBan(string, string);

	string HT_NgayGio(int, int, int, int, int, int);
	string HT_NgayThang(int, int, int);
	string HT_ThangNam(int, int);
	string HT_VeXeThem(string, int);

//	int KT_TrungTheXe(string, int);
	int KT_TrungBien(string, int);
	int TienTungLoaiXe(string, int);
	int ChuyenString_SangInt(string);
	int KT_Xe_SXR(string, int);
};

