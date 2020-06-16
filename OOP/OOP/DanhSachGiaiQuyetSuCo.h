#pragma once
#include "GiaiQuyetSuCo.h"
#include<vector>
#include<string>

class DanhSachGiaiQuyetSuCo
{
private:
	vector<GiaiQuyetSuCo> DanhSachGQSC;
public:
	void Nhap();
	void Xuat();
	void GhiDanhSachGiaiQuyetSuCo(ofstream&);
	void DocDanhSachGiaiQuyetSuCo(ifstream&);

	void Setter_DanhSachGQSC(GiaiQuyetSuCo x);
	vector<GiaiQuyetSuCo> Getter_DanhSachGQSC();

	void HienThiBienBan(string,string);
};

