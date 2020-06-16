#pragma once
#include<string>
#include"TT_SoXeRa.h"
#include"DanhSachXeTrongBen.h"

using namespace std;
class TimKiem_BaoCao
{
public:
	void TKI_LSGX(TT_SoXeRa,int, string,string,string);

	void TK_TheoNgay_QL(TT_SoXeRa,string, int, int, int, int);
	void TK_MatDoGuiXe_TheoThang(TT_SoXeRa,string, int, int, int);//theo thoi gian gui
	void TK_MatDoGuiXe_Thang1_Thang2(TT_SoXeRa,string, int, int, int, int, int);//theo thoi gian gui
	void TK_TheoLoaiXe_TrongThang(TT_SoXeRa,string, int, int, int);
	void TK_TheoLoaiXe_Thang1_Thang2(TT_SoXeRa,string, int, int, int, int, int);	
	void TK_TienThuDuocCuaNhanVien_QL(TT_SoXeRa,string, string, int, int, int, int);
	void Xem_Su_Co(string, string);
	//------------------------------------------
	void TK_TienThuDuocTrongNgay_NV(TT_SoXeRa,string, int);

	void TKI_XeTrongBen_TheXe(DanhSachXeTrongBen,string, string, int);

	void TKI_XeTrongBen_BienSo(DanhSachXeTrongBen,string, string, int);
};

