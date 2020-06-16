#include "TimKiem_BaoCao.h"
#include"TT_SoXeRa.h"
#include"DanhSachXeTrongBen.h"
#include"stdafx.h"
#include"DanhSachGiaiQuyetSuCo.h"
void TimKiem_BaoCao::TKI_LSGX(TT_SoXeRa x, int n, string nv, string c,string Bien) {

	x.TimKiem_LSGX(n, Bien, nv, c);
}
void TimKiem_BaoCao::TK_TheoNgay_QL(TT_SoXeRa x, string nv, int n, int ngay, int thang, int nam) {
	x.Hienthi_TheoNgay_QL(nv, n, ngay, thang, nam);
}

void TimKiem_BaoCao::TK_MatDoGuiXe_TheoThang(TT_SoXeRa x, string nv, int n, int thang, int nam) {//theo thoi gian gui
	x.ThongKe_MatDoGuiXe_TheoThang(nv, n, thang, nam);
}

void TimKiem_BaoCao::TK_MatDoGuiXe_Thang1_Thang2(TT_SoXeRa x, string nv, int n, int thang1, int nam1, int thang2, int nam2) {
	x.ThongKe_MatDoGuiXe_Thang1_Thang2(nv, n, thang1, nam1, thang2, nam2);
}

void TimKiem_BaoCao::TK_TheoLoaiXe_TrongThang(TT_SoXeRa x, string nv, int n, int thang, int nam) {
	x.ThongKe_TheoLoaiXe_TrongThang(nv, n, thang, nam);
}
void TimKiem_BaoCao::TK_TheoLoaiXe_Thang1_Thang2(TT_SoXeRa x, string nv, int n, int thang1, int nam1, int thang2, int nam2) {
	x.ThongKe_TheoLoaiXe_Thang1_Thang2(nv, n, thang1, nam1,thang2,nam2);
}

void TimKiem_BaoCao::TK_TienThuDuocCuaNhanVien_QL(TT_SoXeRa x , string nvql, string nvtx, int n , int ngay, int thang, int nam) {
	x.ThonKe_TienThuDuocCuaNhanVien_QL(nvql, nvtx, n, ngay, thang, nam);
}
void TimKiem_BaoCao::Xem_Su_Co( string MaBB, string nvql) {
	DanhSachGiaiQuyetSuCo x;
	x.HienThiBienBan(MaBB, nvql);
}
void TimKiem_BaoCao::TK_TienThuDuocTrongNgay_NV(TT_SoXeRa x , string nv, int n) {
	x.ThonKe_TienThuDuocTrongNgay_NV(nv, n);
}

void TimKiem_BaoCao::TKI_XeTrongBen_BienSo(DanhSachXeTrongBen x , string nv, string bien, int n) {
	x.TK_XeTrongBen_BienSo(nv, bien, n);
}
void TimKiem_BaoCao::TKI_XeTrongBen_TheXe(DanhSachXeTrongBen x, string nv, string ve, int n) {
	x.TK_XeTrongBen_TheXe(nv, ve, n);
}