#pragma once
#include<vector>
#include"PhieuGuiXe.h"
#include"VeXeMay.h"
#include"VeXeOTo.h"
class DanhSachXeTrongBen
{
private:
	vector<PhieuGuiXe > Dsxg;

public:
	void Setter_Dsxg(PhieuGuiXe);
	vector<PhieuGuiXe > Getter_Dsxg();
	void DocSoXeVao(ifstream&, int n);
	int DemSoLuongXe();
	void CapNhatSoXeVao(ofstream&, int, int);
	void Xuat();
	void CapNhatLichSu(int, ThoiGian, string,int,string);

	void InPhieuThu(PhieuGuiXe, ThoiGian, int, int,string);

	void TK_XeTrongBen_TheXe(string,string, int);
	void TK_XeTrongBen_BienSo(string,string, int);
};

