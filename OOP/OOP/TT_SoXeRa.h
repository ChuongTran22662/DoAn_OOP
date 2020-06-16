#pragma once
#include "ThoiGian.h"
#include<vector>
#include "SoXeRa.h"
#include"DanhSachGiaiQuyetSuCo.h"
class TT_SoXeRa
{
private:
	vector< SoXeRa> DS_SoXeRa;
//	vector< DanhSachGiaiQuyetSuCo> DS_SuCo;
public:
	void DocSoXeRa(int n, ifstream&);

	void Setter_DS_SoXeRa(SoXeRa x);
	vector< SoXeRa> Getter_DS_SoXeRa();

	void TimKiem_LSGX(int, string, string, string);

	void Hienthi_TheoNgay_QL(string, int, int, int, int);

	void ThongKe_TheoLoaiXe_TrongThang(string, int, int, int);
	void ThongKe_TheoLoaiXe_Thang1_Thang2(string, int, int, int, int, int);

	void ThonKe_TienThuDuocTrongNgay_NV(string, int); 
	void ThonKe_TienThuDuocCuaNhanVien_QL(string,string, int,int,int,int);

	void ThongKe_MatDoGuiXe_TheoThang(string, int, int, int);//theo thoi gian gui
	void ThongKe_MatDoGuiXe_Thang1_Thang2(string, int, int, int, int, int);//theo thoi gian gui

};

