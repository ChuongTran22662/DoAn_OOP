#pragma once
#include "ChiTietBienBan.h"
#include<vector>
#include<string>

class DanhSachCTBB
{
private:
	vector<ChiTietBienBan> DanhSach_CTBB;
public:
	void Xuat();
	void GhiDanhSachCTBB(fstream&);
	void DocDanhSachCTBB(ifstream&);

	void Setter_DanhSach_CTBB(ChiTietBienBan x);
	vector<ChiTietBienBan> Getter_DanhSach_CTBB();
};


