#pragma once
#include "VeXeMay.h"
#include "VeXeOTo.h"
#include<vector>
class DanhSachVeXe
{
private:
	vector<VeXeMay> DSVeXeMay;
	vector<VeXeOTo> DSVeXeOTo;
public:
	void DocDSVeXeMay(ifstream&);
	void GhiDSVeXeMay(ofstream&);

	void XuatDanhSachVeXeMay();

	void DocDSVeXeOto(ifstream&);
	void GhiDSVeXeOto(ofstream&);
	void XuatDanhSachVeOTo();

	void Setter_DSVeXeMay(vector<VeXeMay> list,string s);
	vector<VeXeMay> Getter_DSVeXeMay();

	void Setter_DSVeOTo(vector<VeXeOTo> list,string s);
	vector<VeXeOTo> Getter_DSVeOTo();

	
	void CapNhatVeXeXuatBen_XeMay(vector<VeXeMay> list, string s);
	void CapNhatVeXeXuatBen_OTo(vector<VeXeOTo> list, string s);

	void ThemVeXeMay(int n);
	void ThemVeXeOTo(int n,string khu);

	void XoaVeKhiGQSC(string v,string);
	
};

