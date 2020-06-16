#pragma once
#include"SuCo.h"
#include<vector>

class DanhSachSuCo
{
private:
	vector<SuCo> DSSuCo;
public:
	void DocDanhSachSuCo(ifstream&);
	void Xuat();

	void Setter_DanhSachSuCo(vector<SuCo> list);
	vector<SuCo> Getter_DanhSachSuCo();
};



