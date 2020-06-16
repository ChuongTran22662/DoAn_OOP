#pragma once
#include"GiaTien.h"
#include<vector>
class BangGia
{
private:
	vector<GiaTien> DS_BangGia;
public:
	void Setter_DS_BangGia(GiaTien);
	vector<GiaTien> Getter_DS_BangGia();
	void DocFileBangGia(ifstream&);
	void ThayDoiGia(ofstream&,BangGia);
	void HT_BangGia();
};

