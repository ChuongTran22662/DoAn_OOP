#include "TT_SoXeRa.h"
#include<math.h>
#include"DanhSachVeXe.h"
#include"DanhSachNhanVien.h"
#include"ThoiGian.h"
#include"stdafx.h"
#include "SoXeRa.h"
#include <iomanip>	
#include"DanhSachGiaiQuyetSuCo.h"
#include"DanhSachSuCo.h"

void TT_SoXeRa::Setter_DS_SoXeRa(SoXeRa x) {
	DS_SoXeRa.push_back(x);
}

vector< SoXeRa> TT_SoXeRa::Getter_DS_SoXeRa() {
	return this->DS_SoXeRa;
}

void TT_SoXeRa::DocSoXeRa(int size, ifstream& FileIn) {

	for (int i = 0; i < size; i++) {
		SoXeRa x;
		x.DocTTSoXeRa(FileIn);
		DS_SoXeRa.push_back(x);
	}
}

void TT_SoXeRa::TimKiem_LSGX(int n, string Bien, string nv, string c) {
	int stt = 0;
	string loaixe;
	if (c == "XM") loaixe = "Xe may";
	else loaixe = "Xe OTo";
	cout << "\n\t\t _______________________________________________________________________________________________________________________________________________________________";
	cout << "\n\t\t|                                                                                                                                               \t\t|";
	cout << "\n\t\t|\tBAI GIU XE                                                                                                                              \t\t|";
	cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                                                                                 \t\t|";
	cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                                                                                  \t\t|";
	cout << "\n\t\t|\t\t* * * * *                                                                                                                       \t\t|";
	cout << "\n\t\t|\t\t * * * *                                                                                                                        \t\t|";
	cout << "\n\t\t|                                                                                                                                               \t\t|";
	cout << "\n\t\t|\t\t\t\t\t\t\tLICH SU GUI XE CO BIEN SO: "; cout << setw(10) << left << Bien; cout << "                                                                   |";
	cout << "\n\t\t|\t\t\t\t\t\t\t\t   (Loai xe: "; cout << loaixe; cout << ")"; cout << "                                                                            |";
	cout << "\n\t\t|\t _______________________________________________________________________________________________________________________________________"; cout << "\t\t|";
	cout << "\n\t\t|\t| STT | Ma The | MaNV Nhan xe | MaNV Thu Tien | Thoi Gian Gui Xe  | Thoi Gian Lay Xe  |   So Gio Gui  |   Gia gui xe  |    Thanh Tien   |"; cout << "\t\t|";
	cout << "\n\t\t|\t|_____|________|______________|_______________|___________________|___________________|_______________|_______________|_________________|"; cout << "\t\t|";

	int TongTienThu = 0;
	stdafx KT;
	int Tien = 0;

	for (int i = 0; i < n; i++) {
		if (this->Getter_DS_SoXeRa()[i].Getter_BienSo() == Bien && this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2) == c)
		{
			stt++;
			int SoGio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().SoGioGuiXe(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui());
			if (SoGio < 5) Tien = this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
			else {
				Tien = SoGio * this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
			}
			cout << setw(5) << left << "\n\t\t|\t| " << stt << "   |";
			cout << setw(8) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoVe();
			cout << "|";
			cout << setw(14) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Gui();
			cout << "|";
			cout << setw(15) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Xuat();
			cout << "|";
			string N_Gui = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Ngay(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam(),
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Gio(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Phut(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Giay());
			cout << setw(19) << left << N_Gui; cout << "|";
			string N_Xuat = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam(),
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Gio(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Phut(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Giay());
			cout << setw(19) << left << N_Xuat; cout << "|";

			if (SoGio <= 0) {
				SoGio = 0;
				Tien = 0;
				cout << setw(15) << right << "NULL";
				cout << "|";
				cout << setw(11) << right << this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien() << " VND|";
				cout << setw(17) << right << " 0 VND";
				cout << "|";
				cout << "\t\t|";
			}
			else {
				cout << setw(15) << right << SoGio;
				cout << "|";
				cout << setw(11) << right << this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien() << " VND|";
				cout << setw(13) << right << Tien << " VND|";
				cout << "\t\t|";
			}
			TongTienThu += Tien;
		}
	}
	cout << "\n\t\t|\t|_____|________|______________|_______________|___________________|___________________|_______________|_______________|_________________|"; cout << "\t\t|";
	cout << "\n\t\t|\t|                                                                                                 Tong tien thu duoc: |"; cout << setw(13) << right << TongTienThu << " VND|"; cout << "\t\t|";
	cout << "\n\t\t|\t|_____________________________________________________________________________________________________________________|_________________|"; cout << "\t\t|";

	cout << "\n\t\t|                                                                                                                                               \t\t|";
	cout << "\n\t\t|                                                                                                                                               \t\t|";
	ThoiGian ngaylap;
	ngaylap.LayThoiGianTuHeThong();
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	cout << "\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t" << "Ha Noi, Ngay "; cout << setw(2) << right << ngaylap.Getter_Ngay() << " thang";
	cout << setw(2) << right << ngaylap.Getter_Thang() << " nam "; cout << setw(2) << right << ngaylap.Getter_Nam();
	cout << "                \t\t|";
	cout << "\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t    Nguoi lap                            \t\t|";
	cout << "\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                       \t\t|";
	cout << "\n\t\t|                                                                                                                                               \t\t|";
	cout << "\n\t\t|                                                                                                                                               \t\t|";
	cout << "\n\t\t|                                                                                                                                               \t\t|";
	cout << "\n\t\t|_______________________________________________________________________________________________________________________________________________________________|" << endl;
}

void TT_SoXeRa::Hienthi_TheoNgay_QL(string nv, int n, int ngay, int thang, int nam) {

	stdafx KT;
	string NgayThang = KT.HT_NgayThang(ngay, thang, nam);
	cout << "\n _______________________________________________________________________________________________________________________________________________________________________________________";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\tBAI GIU XE                                                                                                                                                      \t\t|";
	cout << "\n|\tDAI HOC XAY DUNG HA NOI                                                                                                                                         \t\t|";
	cout << "\n|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                                                                                                          \t\t|";
	cout << "\n|\t\t* * * * *                                                                                                                                               \t\t|";
	cout << "\n|\t\t * * * *                                                                                                                                                \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\t\t\t\t\t\tBAO CAO DOANH THU TRONG NGAY: "; cout << setw(10) << left << NgayThang; cout << "                                                                                        \t|";
	cout << "\n|\t _____________________________________________________________________________________________________________________________________________________________________"; cout << "\t\t|";
	cout << "\n|\t| STT  | Ma The |  Loai Xe  |    Bien So   | MaNV Nhan xe | MaNV Thu Tien |  Thoi Gian Gui Xe |  Thoi Gian Lay Xe |  So Gio Gui   |  Gia gui xe     |    Thanh Tien   |"; cout << "\t\t|";
	cout << "\n|\t|______|________|___________|______________|______________|_______________|___________________|___________________|_______________|_________________|_________________|"; cout << "\t\t|";
	int TongTienTheoNgay = 0;
	int stt = 0;
	string c;
	int x1;
	int x2;
	int SoGio;
	int Tien;
	int TienGQ = 0;
	for (int i = 0; i < n; i++) {
		c = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);
		SoGio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().SoGioGuiXe(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui());
		if (SoGio < 5) Tien = this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
		else {
			Tien = SoGio * this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
		}
		int ngay1 = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay();
		int thang1 = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang();
		int nam1 = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam();
		if (ngay1 == ngay &&
			thang1 == thang &&
			nam1 == nam)
		{
			stt++;
			cout << "\n|\t|";
			cout << setw(3) << left << stt;
			cout << "   |";
			cout << setw(8) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoVe();
			KT.TextColor(14);
			cout << "|";
			if (c == "XM")cout << setw(11) << left << "Xe May";
			else if (c == "OT") cout << setw(11) << left << "Xe OTO";
			else cout << setw(11) << left << "NULL";
			cout << "|";
			cout << setw(14) << left << this->Getter_DS_SoXeRa()[i].Getter_BienSo(); cout << "|";
			cout << setw(14) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Gui();
			KT.TextColor(14);
			cout << "|";
			cout << setw(15) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Xuat();
			KT.TextColor(14);
			cout << "|";
			string N_Gui = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Ngay(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam(),
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Gio(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Phut(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Giay());
			cout << setw(19) << left << N_Gui;
			KT.TextColor(14); cout << "|";
			string N_Xuat = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam(),
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Gio(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Phut(), this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Giay());
			cout << setw(19) << left << N_Xuat;
			KT.TextColor(14); cout << "|";
			KT.TextColor(14);
			if (SoGio <= 0) {
				SoGio = 0;
				Tien = 0;
				cout << setw(15) << right << "NULL";
				cout << "|";
				cout << setw(13) << right << this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien() << " VND|";
				cout << setw(17) << right << "0 VND";
				cout << "|";
				cout << "\t\t|";
			}
			else {
				cout << setw(15) << right << SoGio;
				cout << "|";
				cout << setw(13) << right << this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien() << " VND|";
				cout << setw(13) << right << Tien << " VND|";
				cout << "\t\t|";
			}
			TongTienTheoNgay += Tien;
		}
	}
	cout << "\n|\t|______|________|___________|______________|______________|_______________|___________________|___________________|_______________|_________________|_________________|"; cout << "\t\t|";
	cout << "\n|\t|                                                                                                                               Tong tien thu duoc: |"; cout << setw(13) << right << TongTienTheoNgay << " VND|"; cout << "\t\t|";
	cout << "\n|\t|___________________________________________________________________________________________________________________________________________________|_________________|"; cout << "\t\t|";	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";

	int vitri_SuCo = -1;
	int SuCo[100];
	DanhSachGiaiQuyetSuCo gqsc;

	ifstream FileSuCo;
	FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
	int size_SuCo = KT.DemSoLuongXe(FileSuCo);
	FileSuCo.close();
	FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
	gqsc.DocDanhSachGiaiQuyetSuCo(FileSuCo);
	FileSuCo.close();

	for (int i = 0; i < size_SuCo; i++) {
		int n1 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Ngay();
		int n2 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang();
		int n3 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();
		if (n1 == ngay &&
			n2 == thang &&
			n3 == nam) {
			vitri_SuCo++;
			SuCo[vitri_SuCo] = i;
		}
		else {
			continue;
		}
	}
	int vitri_ctbb = -1;
	int CTBB[100];
	DanhSachCTBB dsctbb;
	ifstream FileCTBB;
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	int size_CTBB = KT.DemSoLuongXe(FileCTBB);
	FileCTBB.close();
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	dsctbb.DocDanhSachCTBB(FileCTBB);
	FileCTBB.close();
	for (int i = 0; i < size_CTBB; i++) {
		for (int j = 0; j < size_SuCo; j++) {
			if (gqsc.Getter_DanhSachGQSC()[SuCo[j]].Getter_MaBB() == dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB()) {
				vitri_ctbb++;
				CTBB[vitri_ctbb] = i;
			}
			else {
				continue;
			}
		}

	}

	if (vitri_ctbb >= 0) {
		DanhSachSuCo dssc;
		ifstream FileDSSuCo;
		FileDSSuCo.open("danhsachsuco.txt", ios::in);
		int size_DSSuCo = KT.DemSoLuongXe(FileDSSuCo);
		FileDSSuCo.close();
		FileDSSuCo.open("danhsachsuco.txt", ios::in);
		dssc.DocDanhSachSuCo(FileDSSuCo);
		FileDSSuCo.close();
		int vitri_dssc;
		int stt_sc = 0;

		cout << "\n|                                                                                                                                                                       \t\t|";
		cout << "\n|\t\t\t\t\tSU CO XAY RA TRONG NGAY: "; cout << "                                                                                                                       |";
		cout << "\n|\t ____________________________________________________________                                                                                "; cout << "\t\t\t\t\t|";
		cout << "\n|\t| STT | Ma BB | Ma Su Co |   Ten su co     | Tien giai quyet |"; cout << "\t\t\t\t\t                                                                                |";
		cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";
		

		for (int i = 0; i <= vitri_ctbb; i++) {
			stt_sc++;

			cout << "\n|\t|"; cout << setw(5) << left << stt_sc; cout << "|";
			cout << setw(7) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaBB(); cout << "|";
			for (int j = 0; j < size_DSSuCo; j++) {
				if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == dssc.Getter_DanhSachSuCo()[j].Getter_MaSuCo()) {
					vitri_dssc = j;
					break;
				}
			}
			cout << setw(10) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo(); cout << "|";
			cout << setw(17) << left << dssc.Getter_DanhSachSuCo()[vitri_dssc].Getter_TenSuCo(); cout << "|";
			if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "01" || dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "04") {
				cout << setw(13) << right << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
				TienGQ = TienGQ + dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
			}
			else {
				cout << setw(13) << right << -dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
				TienGQ = TienGQ - dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
			}
			cout << setw(22) << left << " ";cout << "\t\t\t\t\t                                                        |";
		}
		cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";
		cout << "\n|\t|                      Tong tien giai quyet|"; cout << setw(13) << right << TienGQ << " VDN|"; cout << "                                      "; cout << "\t\t\t\t\t                                        |";
		cout << "\n|\t|__________________________________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";

		if (TienGQ <= 0) {
			cout << "\n|     (*) So tien phai chi ra cho su co la: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                                             \t\t| ";
			cout << "\n|     (*)Tong so tien thu duoc trong ngay = Tien ve xe - Tien giai quyet: "; cout << setw(13) << left << TongTienTheoNgay + TienGQ << " VDN"; cout << "                                                                               \t\t| ";

		}
		else {

			cout << "\n|      (*) So tien thu vao do su co: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                                                       \t\t| ";
			cout << "\n|      (*)Tong so tien thu duoc trong ngay = Tien ve xe + Tien giai quyet: "; cout << setw(13) << left << TongTienTheoNgay + TienGQ << " VDN"; cout << "                                                                              \t\t| ";

		}
		cout << "\n|                                                                                                                                                                       \t\t|";
		cout << "\n|                                                                                                                                                                       \t\t|";

	}
	ThoiGian ngaylap;
	ngaylap.LayThoiGianTuHeThong();
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t" << "\t\tHa Noi, Ngay "; cout << setw(2) << right << ngaylap.Getter_Ngay() << " thang";
	cout << setw(2) << right << ngaylap.Getter_Thang() << " nam "; cout << setw(2) << right << ngaylap.Getter_Nam();
	cout << "                                |";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \tNguoi lap                                               |";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                                       |";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|_______________________________________________________________________________________________________________________________________________________________________________________|";
	cout << "\n\n\n";

}

void TT_SoXeRa::ThongKe_TheoLoaiXe_TrongThang(string nv, int n, int Thang, int Nam) {
	stdafx KT;

	int TienXeMay = 0;
	int SoLuotGuiXM = 0;
	int SoLuotGuiOT = 0;
	int TienOTo = 0;
	int TongSoXe = 0;
	int TongTien = 0;
	int Tien = 0;

	for (int i = 0; i < n; i++) {
		int SoGio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().SoGioGuiXe(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui());
		if (this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang() == Thang &&
			this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam() == Nam) {
			string c = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);

			if (SoGio < 5) Tien = this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
			else {
				Tien = SoGio * this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
			}
			TongSoXe++;
			TongTien = TongTien + Tien;
			if (c == "XM") {
				TienXeMay = TienXeMay + Tien;
				SoLuotGuiXM++;
			}
			if (c == "OT") {
				TienOTo = TienOTo + Tien;
				SoLuotGuiOT++;
			}
		}
	}
	string ThangNam = KT.HT_ThangNam(Thang, Nam);

	cout << "\n _______________________________________________________________________________________________________________________________________________________________________________________";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\tBAI GIU XE                                                                                                                                                      \t\t|";
	cout << "\n|\tDAI HOC XAY DUNG HA NOI                                                                                                                                         \t\t|";
	cout << "\n|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                                                                                                          \t\t|";
	cout << "\n|\t\t* * * * *                                                                                                                                               \t\t|";
	cout << "\n|\t\t * * * *                                                                                                                                                \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\t\t\tBANG DOANH THU THANG "; cout << setw(5) << left << ThangNam; cout << " CUA CAC LOAI XE                                                                                 \t\t\t\t\t|";
	cout << "\n|\t ________________________________________________________________________________                                                                                               |";
	cout << "\n|\t| Loai xe   | So Luot Gui | Tien Thu Duoc  | Ty Le Gui Xe |  Phan Tram Doanh Thu |"; cout << "                                                                       \t\t\t|";
	cout << "\n|\t|___________|_____________|________________|______________|______________________|"; cout << "                                                                       \t\t\t|";

	KT.TextColor(14);
	cout << setw(15) << left << "\n|\t|Xe May"; cout << "|";
	cout << setw(7) << right << SoLuotGuiXM;
	cout << setw(7) << right << "|";
	cout << setw(12) << right << TienXeMay << " VND|";
	if (SoLuotGuiOT > 0 && SoLuotGuiXM > 0) {
		cout << setw(7) << right << round(100 * (float)SoLuotGuiXM / TongSoXe) << "%";
	}
	else {
		cout << setw(7) << right << 0 << "%";
	}
	cout << setw(7) << right << "|";
	if (SoLuotGuiXM > 0 && SoLuotGuiOT > 0) {
		cout << setw(11) << right << round(100 * (float)TienXeMay / TongTien) << "%";
	}
	else {
		cout << setw(11) << right << 0 << "%";
	}

	cout << setw(11) << right << "|";
	cout << "                                                                       \t\t\t|";

	cout << setw(15) << left << "\n|\t|Xe OTO"; cout << "|";
	cout << setw(7) << right << SoLuotGuiOT;
	cout << setw(7) << right << "|";
	cout << setw(12) << right << TienOTo << " VND|";

	if (SoLuotGuiOT > 0 && SoLuotGuiXM > 0) {
		cout << setw(7) << right << round(100 * (float)SoLuotGuiOT / TongSoXe) << "%";
	}
	else {
		cout << setw(7) << right << 0 << "%";
	}
	cout << setw(7) << right << "|";
	if (SoLuotGuiOT > 0 && SoLuotGuiXM > 0) {
		cout << setw(11) << right << round(100 * (float)TienOTo / TongTien) << "%";
	}
	else {
		cout << setw(11) << right << 0 << "%";
	}
	cout << setw(11) << right << "|";
	cout << "                                                                       \t\t\t|";

	cout << "\n|\t|___________|_____________|________________|______________|______________________|"; cout << "                                                                       \t\t\t|";
	cout << "\n|\t|              Tong tien: |";

	cout << setw(12) << right << TongTien << " VND                                      |"; cout << "\t                                                                                \t|";
	cout << "\n|\t|_________________________|______________________________________________________|"; cout << "                                                                       \t\t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";

	int vitri_SuCo = -1;
	int SuCo[100];
	DanhSachGiaiQuyetSuCo gqsc;

	ifstream FileSuCo;
	FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
	int size_SuCo = KT.DemSoLuongXe(FileSuCo);
	FileSuCo.close();
	FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
	gqsc.DocDanhSachGiaiQuyetSuCo(FileSuCo);
	FileSuCo.close();

	for (int i = 0; i < size_SuCo; i++) {
		int n2 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang();
		int n3 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();
		if (
			n2 == Thang &&
			n3 == Nam) {
			vitri_SuCo++;
			SuCo[vitri_SuCo] = i;
		}
		else {
			continue;
		}
	}
	int vitri_ctbb = -1;
	int CTBB[100];
	DanhSachCTBB dsctbb;
	ifstream FileCTBB;
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	int size_CTBB = KT.DemSoLuongXe(FileCTBB);
	FileCTBB.close();
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	dsctbb.DocDanhSachCTBB(FileCTBB);
	FileCTBB.close();
	for (int i = 0; i < size_CTBB; i++) {
		for (int j = 0; j < size_SuCo; j++) {
			if (gqsc.Getter_DanhSachGQSC()[SuCo[j]].Getter_MaBB() == dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB()) {
				vitri_ctbb++;
				CTBB[vitri_ctbb] = i;
			}
			else {
				continue;
			}
		}

	}

	if (vitri_ctbb >= 0) {
		DanhSachSuCo dssc;
		ifstream FileDSSuCo;
		FileDSSuCo.open("danhsachsuco.txt", ios::in);
		int size_DSSuCo = KT.DemSoLuongXe(FileDSSuCo);
		FileDSSuCo.close();
		FileDSSuCo.open("danhsachsuco.txt", ios::in);
		dssc.DocDanhSachSuCo(FileDSSuCo);
		FileDSSuCo.close();
		int vitri_dssc;
		int stt_sc = 0;
		int TienGQ = 0;
		cout << "\n|                                                                                                                                                                       \t\t|";
		cout << "\n|\t\t\t\t\tSU CO XAY RA TRONG THANG: "; cout << "                                                                                                                      |";
		cout << "\n|\t ____________________________________________________________                                                                                "; cout << "\t\t\t\t\t|";
		cout << "\n|\t| STT | Ma BB | Ma Su Co |   Ten su co     | Tien giai quyet |"; cout << "\t\t\t\t\t                                                                                |";
		cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";


		for (int i = 0; i <= vitri_ctbb; i++) {
			stt_sc++;

			cout << "\n|\t|"; cout << setw(5) << left << stt_sc; cout << "|";
			cout << setw(7) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaBB(); cout << "|";
			for (int j = 0; j < size_DSSuCo; j++) {
				if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == dssc.Getter_DanhSachSuCo()[j].Getter_MaSuCo()) {
					vitri_dssc = j;
					break;
				}
			}
			cout << setw(10) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo(); cout << "|";
			cout << setw(17) << left << dssc.Getter_DanhSachSuCo()[vitri_dssc].Getter_TenSuCo(); cout << "|";


			if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "01" || dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "04") {
				cout << setw(13) << right << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
				TienGQ = TienGQ + dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
			}
			else {
				cout << setw(13) << right << -dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
				TienGQ = TienGQ - dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
			}
			cout << setw(22) << left << " "; cout << "\t\t\t\t\t                                                        |";
		}
		cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";
		cout << "\n|\t|                      Tong tien giai quyet|"; cout << setw(13) << right << TienGQ << " VDN|"; cout << "                                      "; cout << "\t\t\t\t\t                                        |";
		cout << "\n|\t|__________________________________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";

		cout << "\n|                                                                                                                                                                       \t\t|";
		cout << "\n|                                                                                                                                                                       \t\t|";
		if (TienGQ <= 0) {
			cout << "\n|     (*) So tien phai chi ra cho su co la: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                                             \t\t| ";
			cout << "\n|     (*)Tong so tien thu duoc trong thang = Tien ve xe - Tien giai quyet: "; cout << setw(13) << left << TongTien + TienGQ << " VDN"; cout << "                                                                               \t\t| ";

		}
		else {

			cout << "\n|      (*) So tien thu vao do su co: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                                                       \t\t| ";
			cout << "\n|      (*)Tong so tien thu duoc trong thang = Tien ve xe + Tien giai quyet: "; cout << setw(13) << left << TongTien + TienGQ << " VDN"; cout << "                                                                              \t\t| ";

		}

	}
	ThoiGian ngaylap;
	ngaylap.LayThoiGianTuHeThong();
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t" << "\t\tHa Noi, Ngay "; cout << setw(2) << right << ngaylap.Getter_Ngay() << " thang";
	cout << setw(2) << right << ngaylap.Getter_Thang() << " nam "; cout << setw(2) << right << ngaylap.Getter_Nam();
	cout << "                                |";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \tNguoi lap                                               |";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                                       |";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|_______________________________________________________________________________________________________________________________________________________________________________________|";
	cout << "\n\n\n";
}

void TT_SoXeRa::ThongKe_TheoLoaiXe_Thang1_Thang2(string nv, int n, int Thang, int Nam, int Thang1, int Nam1)  {
	stdafx KT;

	int TienXeMay = 0;
	int SoLuotGuiXM = 0;
	int SoLuotGuiOT = 0;
	int TienOTo = 0;
	int TongSoXe = 0;
	int TongTien = 0;
	int Tien = 0;

	for (int i = 0; i < n; i++) {
		int SoGio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().SoGioGuiXe(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui());
			if (this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang() >= Thang &&
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang() <= Thang1 &&
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam() >= Nam &&
				this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam() <= Nam1) {
				string c = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);

				if (SoGio < 5) Tien = this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
				else {
					Tien = SoGio * this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
				}

				TongSoXe++;
				TongTien = TongTien + Tien;
				if (c == "XM") {
					TienXeMay = TienXeMay + Tien;
					SoLuotGuiXM++;
				}
				if (c == "OT") {
					TienOTo = TienOTo + Tien;
					SoLuotGuiOT++;
				}
			}
	}
	string ThangNam = KT.HT_ThangNam(Thang, Nam);
	string ThangNam1 = KT.HT_ThangNam(Thang1, Nam1);
	cout << "\n _______________________________________________________________________________________________________________________________________________________________________________________";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\tBAI GIU XE                                                                                                                                                      \t\t|";
	cout << "\n|\tDAI HOC XAY DUNG HA NOI                                                                                                                                         \t\t|";
	cout << "\n|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                                                                                                          \t\t|";
	cout << "\n|\t\t* * * * *                                                                                                                                               \t\t|";
	cout << "\n|\t\t * * * *                                                                                                                                                \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\t\t\tBANG DOANH THU TU THANG "; cout << setw(7) << left << ThangNam; cout << "DEN "; cout << setw(7) << left << ThangNam1; cout << " CUA CAC LOAI XE                                                                                                      |";
	cout << "\n|\t ________________________________________________________________________________                                                                                               |";
	cout << "\n|\t| Loai xe   | So Luot Gui | Tien Thu Duoc  | Ty Le Gui Xe |  Phan Tram Doanh Thu |"; cout << "                                                                       \t\t\t|";
	cout << "\n|\t|___________|_____________|________________|______________|______________________|"; cout << "                                                                       \t\t\t|";

	KT.TextColor(14);
	cout << setw(15) << left << "\n|\t|Xe May"; cout << "|";
	cout << setw(7) << right << SoLuotGuiXM;
	cout << setw(7) << right << "|";
	cout << setw(12) << right << TienXeMay << " VND|";
	if (SoLuotGuiXM > 0 && SoLuotGuiOT > 0) {
		cout << setw(7) << right << round(100 * (float)SoLuotGuiXM / TongSoXe) << "%";
	}
	else {
		cout << setw(7) << right << 0 << "%";
	}

	cout << setw(7) << right << "|";
	if (SoLuotGuiXM > 0 && SoLuotGuiOT > 0) {
		cout << setw(11) << right << round(100 * (float)TienXeMay / TongTien) << "%";
	}
	else {
		cout << setw(11) << right << 0 << "%";
	}

	cout << setw(11) << right << "|";
	cout << "                                                                       \t\t\t|";

	cout << setw(15) << left << "\n|\t|Xe OTO"; cout << "|";
	cout << setw(7) << right << SoLuotGuiOT;
	cout << setw(7) << right << "|";
	cout << setw(12) << right << TienOTo << " VND|";

	if (SoLuotGuiXM > 0 && SoLuotGuiOT > 0) {
		cout << setw(7) << right << round(100 * (float)SoLuotGuiOT / TongSoXe) << "%";
	}
	else {
		cout << setw(7) << right << 0 << "%";
	}
	cout << setw(7) << right << "|";
	if (SoLuotGuiXM > 0 && SoLuotGuiOT > 0) {
		cout << setw(11) << right << round(100 * (float)TienOTo / TongTien) << "%";
	}
	else {
		cout << setw(11) << right << 0 << "%";
	}

	cout << setw(11) << right << "|";
	cout << "                                                                       \t\t\t|";

	cout << "\n|\t|___________|_____________|________________|______________|______________________|"; cout << "                                                                       \t\t\t|";
	cout << "\n|\t|              Tong tien: |";

	cout << setw(12) << right << TongTien << " VND                                      |"; cout << "\t                                                                                \t|";
	cout << "\n|\t|_________________________|______________________________________________________|"; cout << "                                                                       \t\t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";

	int vitri_SuCo = -1;
	int SuCo[100];
	DanhSachGiaiQuyetSuCo gqsc;
	ifstream FileSuCo;
	FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
	int size_SuCo = KT.DemSoLuongXe(FileSuCo);
	FileSuCo.close();
	FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
	gqsc.DocDanhSachGiaiQuyetSuCo(FileSuCo);
	FileSuCo.close();

	for (int i = 0; i < size_SuCo; i++) {
		int n2 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang();
		int n3 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();

		if (n2 == Thang && n3 == Nam || n2 == Thang1 && n3 == Nam1) {
			vitri_SuCo++;
			SuCo[vitri_SuCo] = i;
		}
		else {
			continue;
		}
	}
	int vitri_ctbb = -1;
	int CTBB[100];
	DanhSachCTBB dsctbb;
	ifstream FileCTBB;
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	int size_CTBB = KT.DemSoLuongXe(FileCTBB);
	FileCTBB.close();
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	dsctbb.DocDanhSachCTBB(FileCTBB);
	FileCTBB.close();
	for (int i = 0; i < size_CTBB; i++) {
		for (int j = 0; j < size_SuCo; j++) {
			if (gqsc.Getter_DanhSachGQSC()[SuCo[j]].Getter_MaBB() == dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB()) {
				vitri_ctbb++;
				CTBB[vitri_ctbb] = i;
			}
			else {
				continue;
			}
		}

	}
	if (vitri_ctbb >= 0) {
		DanhSachSuCo dssc;
		ifstream FileDSSuCo;
		FileDSSuCo.open("danhsachsuco.txt", ios::in);
		int size_DSSuCo = KT.DemSoLuongXe(FileDSSuCo);
		FileDSSuCo.close();
		FileDSSuCo.open("danhsachsuco.txt", ios::in);
		dssc.DocDanhSachSuCo(FileDSSuCo);
		FileDSSuCo.close();
		int vitri_dssc;
		int stt_sc = 0;
		int TienGQ = 0;
		cout << "\n|                                                                                                                                                                       \t\t|";
		cout << "\n|\t\t\t\t\tSU CO XAY RA TRONG THANG: "; cout << "                                                                                                                      |";
		cout << "\n|\t ____________________________________________________________                                                                                "; cout << "\t\t\t\t\t|";
		cout << "\n|\t| STT | Ma BB | Ma Su Co |   Ten su co     | Tien giai quyet |"; cout << "\t\t\t\t\t                                                                                |";
		cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";

		for (int i = 0; i <= vitri_ctbb; i++) {
			stt_sc++;

			cout << "\n|\t|"; cout << setw(5) << left << stt_sc; cout << "|";
			cout << setw(7) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaBB(); cout << "|";
			for (int j = 0; j < size_DSSuCo; j++) {
				if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == dssc.Getter_DanhSachSuCo()[j].Getter_MaSuCo()) {
					vitri_dssc = j;
					break;
				}
			}
			cout << setw(10) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo(); cout << "|";
			cout << setw(17) << left << dssc.Getter_DanhSachSuCo()[vitri_dssc].Getter_TenSuCo(); cout << "|";
			if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "01" || dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "04") {
				cout << setw(13) << right << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
				TienGQ = TienGQ + dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
			}
			else {
				cout << setw(13) << right << -dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
				TienGQ = TienGQ - dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
			}
			cout << setw(22) << left << " "; cout << "\t\t\t\t\t                                                        |";
		}
		cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";
		cout << "\n|\t|                      Tong tien giai quyet|"; cout << setw(13) << right << TienGQ << " VDN|"; cout << "                                      "; cout << "\t\t\t\t\t                                        |";
		cout << "\n|\t|__________________________________________|_________________|                                                                               "; cout << "\t\t\t\t\t|";

		cout << "\n|                                                                                                                                                                       \t\t|";
		cout << "\n|                                                                                                                                                                       \t\t|";
		if (TienGQ <= 0) {
			cout << "\n|     (*) So tien phai chi ra cho su co la: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                                             \t\t| ";
			cout << "\n|     (*)Tong so tien thu duoc trong ngay = Tien ve xe - Tien giai quyet: "; cout << setw(13) << left << TongTien + TienGQ << " VDN"; cout << "                                                                                \t\t| ";

		}
		else {

			cout << "\n|      (*) So tien thu vao do su co: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                                                       \t\t| ";
			cout << "\n|      (*)Tong so tien thu duoc trong ngay = Tien ve xe + Tien giai quyet: "; cout << setw(13) << left << TongTien + TienGQ << " VDN"; cout << "                                                                               \t\t| ";

		}

	}
	ThoiGian ngaylap;
	ngaylap.LayThoiGianTuHeThong();
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t" << "\t\tHa Noi, Ngay "; cout << setw(2) << right << ngaylap.Getter_Ngay() << " thang";
	cout << setw(2) << right << ngaylap.Getter_Thang() << " nam "; cout << setw(2) << right << ngaylap.Getter_Nam();
	cout << "                                |";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \tNguoi lap                                               |";
	cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                                       |";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|                                                                                                                                                                       \t\t|";
	cout << "\n|_______________________________________________________________________________________________________________________________________________________________________________________|";
	cout << "\n\n\n";
}


void TT_SoXeRa::ThongKe_MatDoGuiXe_TheoThang(string nv, int n, int thang, int nam)  {
	stdafx KT;
	int tongxe = 0;
	string thangnam = KT.HT_ThangNam(thang, nam);
	int Mang_OT[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int Mang_XM[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < n; i++) {

		if (this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang() == thang && this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam() == nam) {
			tongxe++;
			string ve = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);
			int gio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Gio();
				if (ve == "XM") {
					for (int j = 0; j < 24; j++)
					{
						if (gio == j)
						{
							Mang_XM[j]++;
							break;
						}
						else {
							continue;
						}
					}
				}
				else {
					for (int j = 0; j < 24; j++)
					{
						if (gio == j)
						{
							Mang_OT[j]++;
							break;
						}
						else {
							continue;
						}
					}
				}

			//}
		}
	}
	int Tong_Luot = 0;;
	int TongLuot[24];
	for (int i = 0; i < 24; i++) {
		TongLuot[i] = Mang_XM[i] + Mang_OT[i];
		Tong_Luot += TongLuot[i];
	}

	int TongPT = 0;
	int PhanTram[24];
	for (int i = 0; i < 24; i++) {
		PhanTram[i] = round(100 * (float)TongLuot[i] / tongxe);
		TongPT += PhanTram[i];
	}

	int tongOT = 0;
	int tongXM = 0;
	for (int i = 0; i < 24; i++) {
		tongOT += Mang_OT[i];
		tongXM += Mang_XM[i];
	}
	cout << "\n\t\t __________________________________________________________________________________";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\tBAI GIU XE                                                                 |";
	cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                    |";
	cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                     |";
	cout << "\n\t\t|\t\t* * * * *                                                          |";
	cout << "\n\t\t|\t\t * * * *                                                           |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\t\t\tTHONG KE MAT DO GUI XE TRONG THANG "; cout << setw(7) << left << thangnam; cout << "                 |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\tTong luot gui: "; cout << setw(4) << left << tongxe; cout << "\t\t                                           |";
	cout << "\n\t\t|\t _____________________________________________________________"; cout << "             |";
	cout << "\n\t\t|\t|            |_____Loai_Xe_______|               |            |"; cout << "            |";
	cout << "\n\t\t|\t| Khung Gio  | Xe May |  Xe OTo  | Tong so luot  | Phan tram  |"; cout << "\t\t   |";
	cout << "\n\t\t|\t|____________|________|__________|_______________|____________|"; cout << "\t\t   |";

	for (int i = 0; i < 24; i++) {
		cout << "\n\t\t|\t|";
		cout << setw(2) << left << i << "-"; cout << setw(9) << left << i + 1;
		cout << "|";
		cout << setw(4) << right << Mang_XM[i]; cout << setw(5) << right << "|";
		cout << setw(5) << right << Mang_OT[i]; cout << setw(6) << right << "|";

		if (TongLuot[i] > 0) {
			cout << setw(8) << right << TongLuot[i]; cout << setw(8) << right << "|";
		}
		else {
			cout << setw(8) << right << " "; cout << setw(8) << right << "|";
		}

		if (PhanTram[i] > 0) {
			cout << setw(5) << right << PhanTram[i] << "%"; cout << setw(7) << right << "|";
		}
		else {
			cout << setw(5) << right << " "; cout << setw(8) << right << "|";
		}
		cout << "\t\t   |";

	}
	cout << "\n\t\t|\t|____________|________|__________|_______________|____________|"; cout << "\t\t   |";
	cout << "\n\t\t|\t|      Tong: |";
	if (tongxe != Tong_Luot) KT.TextColor(140);
	else KT.TextColor(14);
	cout << setw(4) << right << tongXM; cout << setw(5) << right; KT.TextColor(14); cout << "|";

	if (tongxe != Tong_Luot) KT.TextColor(140);
	else KT.TextColor(14);
	cout << setw(5) << right << tongOT; cout << setw(6) << right; KT.TextColor(14); cout << "|";

	if (tongxe != Tong_Luot) KT.TextColor(140);
	else KT.TextColor(14);
	cout << setw(8) << right << Tong_Luot; cout << setw(8) << right; KT.TextColor(14); cout << "|";

	if (tongxe != Tong_Luot) {
		KT.TextColor(140);
		cout << setw(5) << right << TongPT << "%"; cout << setw(7) << right; KT.TextColor(14); cout << "|"; cout << "\t\t   |";
	}
	else if (tongxe > 0) {
		KT.TextColor(14);
		cout << setw(5) << right << 100 << "%"; cout << setw(7) << right; KT.TextColor(14); cout << "|"; cout << "\t\t   |";
	}
	else {
		KT.TextColor(14);
		cout << setw(5) << right << 0 << "%"; cout << setw(7) << right; KT.TextColor(14); cout << "|"; cout << "\t\t   |";
	}
	cout << "\n\t\t|\t|____________|________|__________|_______________|____________|"; cout << "\t\t   |";


	ThoiGian ngaylap;
	ngaylap.LayThoiGianTuHeThong();
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\t\t\t\t\t" << "Ha Noi, Ngay "; cout << setw(2) << right << ngaylap.Getter_Ngay() << " thang";
	cout << setw(2) << right << ngaylap.Getter_Thang() << " nam "; cout << setw(2) << right << ngaylap.Getter_Nam();
	cout << "           |";
	cout << "\n\t\t|\t\t\t\t\t\t    Nguoi lap                      |";
	cout << "\n\t\t|\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                  |";
	cout << "\n\t\t|                                                                                  |";

	cout << "\n\t\t|__________________________________________________________________________________|";}

void TT_SoXeRa::ThongKe_MatDoGuiXe_Thang1_Thang2(string nv, int n, int thang, int nam, int thang1, int nam1) {
	stdafx KT;
	int tongxe = 0;
	string thangnam = KT.HT_ThangNam(thang, nam);
	string thangnam1 = KT.HT_ThangNam(thang1, nam1);
	int Mang_OT[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int Mang_XM[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < n; i++) {

		if (this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang() >= thang &&
			this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang() <= thang1 &&
			this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam() >= nam &&
			this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam() <= nam1) {
			tongxe++;
			string ve = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);
			int gio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Gio();
				if (ve == "XM") {
					for (int j = 0; j < 24; j++)
					{
						if (gio == j)
						{
							Mang_XM[j]++;
							break;
						}
						else {
							continue;
						}
					}
				}
				else {
					for (int j = 0; j < 24; j++)
					{
						if (gio == j)
						{
							Mang_OT[j]++;
							break;
						}
						else {
							continue;
						}
					}
				}

		//	}
		}
	}
	int Tong_Luot = 0;;
	int TongLuot[24];
	for (int i = 0; i < 24; i++) {
		TongLuot[i] = Mang_XM[i] + Mang_OT[i];
		Tong_Luot += TongLuot[i];
	}

	int TongPT = 0;
	int PhanTram[24];
	for (int i = 0; i < 24; i++) {
		PhanTram[i] = round(100 * (float)TongLuot[i] / tongxe);
		TongPT += PhanTram[i];
	}

	int tongOT = 0;
	int tongXM = 0;
	for (int i = 0; i < 24; i++) {
		tongOT += Mang_OT[i];
		tongXM += Mang_XM[i];
	}
	cout << "\n\t\t __________________________________________________________________________________";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\tBAI GIU XE                                                                 |";
	cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                    |";
	cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                     |";
	cout << "\n\t\t|\t\t* * * * *                                                          |";
	cout << "\n\t\t|\t\t * * * *                                                           |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\t\tTHONG KE MAT DO GUI XE TU THANG "; cout << setw(8) << left << thangnam; cout << "den: "; cout << setw(8) << left << thangnam1; cout << "              |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\tTong luot gui: "; cout << setw(4) << left << tongxe; cout << "\t\t                                           |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\t _____________________________________________________________"; cout << "             |";
	cout << "\n\t\t|\t|            |_____Loai_Xe_______|               |            |"; cout << "            |";
	cout << "\n\t\t|\t| Khung Gio  | Xe May |  Xe OTo  | Tong so luot  | Phan tram  |"; cout << "\t\t   |";
	cout << "\n\t\t|\t|____________|________|__________|_______________|____________|"; cout << "\t\t   |";

	for (int i = 0; i < 24; i++) {
		cout << "\n\t\t|\t|";
		cout << setw(2) << left << i << "-"; cout << setw(9) << left << i + 1;
		cout << "|";
		cout << setw(4) << right << Mang_XM[i]; cout << setw(5) << right << "|";
		cout << setw(5) << right << Mang_OT[i]; cout << setw(6) << right << "|";

		if (TongLuot[i] > 0) {
			cout << setw(8) << right << TongLuot[i]; cout << setw(8) << right << "|";
		}
		else {
			cout << setw(8) << right << " "; cout << setw(8) << right << "|";
		}

		if (PhanTram[i] > 0) {
			cout << setw(5) << right << PhanTram[i] << "%"; cout << setw(7) << right << "|";
		}
		else {
			cout << setw(5) << right << " "; cout << setw(8) << right << "|";
		}
		cout << "\t\t   |";

	}
	cout << "\n\t\t|\t|____________|________|__________|_______________|____________|"; cout << "\t\t   |";
	cout << "\n\t\t|\t|      Tong: |";
	if (tongxe != Tong_Luot) KT.TextColor(140);
	else KT.TextColor(14);
	cout << setw(4) << right << tongXM; cout << setw(5) << right; KT.TextColor(14); cout << "|";

	if (tongxe != Tong_Luot) KT.TextColor(140);
	else KT.TextColor(14);
	cout << setw(5) << right << tongOT; cout << setw(6) << right; KT.TextColor(14); cout << "|";

	if (tongxe != Tong_Luot) KT.TextColor(140);
	else KT.TextColor(14);
	cout << setw(8) << right << Tong_Luot; cout << setw(8) << right; KT.TextColor(14); cout << "|";

	if (tongxe != Tong_Luot) {
		KT.TextColor(140);
		cout << setw(5) << right << TongPT << "%"; cout << setw(7) << right; KT.TextColor(14); cout << "|"; cout << "\t\t   |";
	}
	else if (tongxe > 0) {
		KT.TextColor(14);
		cout << setw(5) << right << 100 << "%"; cout << setw(7) << right; KT.TextColor(14); cout << "|"; cout << "\t\t   |";
	}
	else {
		KT.TextColor(14);
		cout << setw(5) << right << 0 << "%"; cout << setw(7) << right; KT.TextColor(14); cout << "|"; cout << "\t\t   |";
	}
	cout << "\n\t\t|\t|____________|________|__________|_______________|____________|"; cout << "\t\t   |";


	ThoiGian ngaylap;
	ngaylap.LayThoiGianTuHeThong();
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|\t\t\t\t\t" << "Ha Noi, Ngay "; cout << setw(2) << right << ngaylap.Getter_Ngay() << " thang";
	cout << setw(2) << right << ngaylap.Getter_Thang() << " nam "; cout << setw(2) << right << ngaylap.Getter_Nam();
	cout << "           |";
	cout << "\n\t\t|\t\t\t\t\t\t    Nguoi lap                      |";
	cout << "\n\t\t|\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                  |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|                                                                                  |";
	cout << "\n\t\t|__________________________________________________________________________________|";
}

void TT_SoXeRa::ThonKe_TienThuDuocCuaNhanVien_QL(string nvql, string nv, int n, int ngay, int thang, int nam)  {
	stdafx KT;
	int TongTien = 0;
	string NgayThang = KT.HT_NgayThang(ngay, thang, nam);
	int stt = 0;
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv, Vtri1;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nvql) continue;
		else {
			Vtri1 = i;
			break;
		}
	}
	int Tien = 0;
	int TienThu = 0;

	if (y->Getter_DSNV()[Vtri_nv].Getter_LoaiNhanVien() != "NVTX") {
		KT.TextColor(140);
		cout << "Thong tin tai khoan bi sai !!!";
		KT.TextColor(14);
	}
	else {
		cout << "\n _______________________________________________________________________________________________________________________________________________________";
		cout << "\n|                                                                                                                                       \t\t|";
		cout << "\n|\tBAI GIU XE                                                                                                                      \t\t|";
		cout << "\n|\tDAI HOC XAY DUNG HA NOI                                                                                                         \t\t|";
		cout << "\n|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                                                                          \t\t|";
		cout << "\n|\t\t* * * * *                                                                                                               \t\t|";
		cout << "\n|\t\t * * * *                                                                                                                \t\t|";
		cout << "\n|                                                                                                                                       \t\t|";
		cout << "\n|\t\t\tTIEN THU DUOC TRONG NGAY "; cout << setw(8) << left << NgayThang; cout << "\t\t\t                                                        \t\t|";
		cout << "\n|\tThong tin nhan vien:"; cout << "\t\t\t                                                                                        \t\t|";
		cout << "\n|\t\tMa nhan vien: "; cout << setw(10) << left << y->Getter_DSNV()[Vtri_nv].Getter_MaNhanVien(); cout << "\t\t\t                                                                        \t\t|";
		cout << "\n|\t\tHo va ten: "; cout << setw(25) << left << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "\t\t\t                                                                \t\t|";
		cout << "\n|\t\tChuc vu: ";
		cout << setw(25) << left << "Nhan vien trong xe                                                                                             \t\t|";
		cout << "\n|\t ______________________________________________________________________________________________________________________________________         |";
		cout << "\n|\t| STT | Ma The |  Bien So   | MaNV Nhan xe | Thoi Gian Gui Xe  | Thoi Gian Lay Xe  |  So Gio Gui   |  Gia gui xe     |   Thanh Tien    |"; cout << "\t|";
		cout << "\n|\t|_____|________|____________|______________|___________________|___________________|_______________|_________________|_________________|"; cout << "\t|";

		int Tien = 0;
		for (int i = 0; i < n; i++) {
			if (this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Xuat() == nv) {
				if (this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay() == ngay
					&& this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang() == thang
					&& this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam() == nam) {
					string c = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);
					int SoGio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().SoGioGuiXe(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui());
					if (SoGio < 5) Tien = this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
					else {
						Tien = SoGio * this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
					}
					stt++;
					cout << "\n|\t|" << setw(5) << left << stt; cout << "|";
					cout << setw(8) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoVe();
					KT.TextColor(14);
					cout << "|";
					cout << setw(12) << left << this->Getter_DS_SoXeRa()[i].Getter_BienSo();
					cout << "|";
					cout << setw(14) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Gui();
					KT.TextColor(14);
					cout << "|";
					string N_Gui = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Ngay(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Gio(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Phut(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Giay());
					cout << setw(19) << left << N_Gui;
					KT.TextColor(14);
					cout << "|";

					string N_Xuat = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Gio(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Phut(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Giay());
					cout << setw(19) << left << N_Xuat;
					KT.TextColor(14);
					cout << "|";
						cout << setw(15) << left << SoGio;
						cout << "|";
						cout << setw(13) << right << this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien() << " VND|";
						cout << setw(13) << right << Tien << " VND";
						cout << "|";
					TienThu += Tien;
					cout << "\t|";
				}
			}
		}
		cout << "\n|\t|_____|________|____________|______________|___________________|___________________|_______________|_________________|_________________|"; cout << "\t|";
		cout << "\n|\t|                                                                                                     Tong tien thu: |";

		ThoiGian TGHienTai;
		TGHienTai.LayThoiGianTuHeThong();
		cout << setw(13) << right << TienThu << " VND";
		cout << "|"; cout << "\t|";
		cout << "\n|\t|____________________________________________________________________________________________________________________|_________________|"; cout << "\t|";
		cout << "\n|                                                                                                                                                       |";

		int vitri_SuCo = -1;
		int SuCo[100];
		DanhSachGiaiQuyetSuCo gqsc;
		ifstream FileSuCo;
		FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
		int size_SuCo = KT.DemSoLuongXe(FileSuCo);
		FileSuCo.close();
		FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
		gqsc.DocDanhSachGiaiQuyetSuCo(FileSuCo);
		FileSuCo.close();
		int Ngay = TGHienTai.Getter_Ngay();
		int Thang = TGHienTai.Getter_Thang();
		int Nam = TGHienTai.Getter_Nam();
		for (int i = 0; i < size_SuCo; i++) {
			int n1 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Ngay();
			int n2 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang();
			int n3 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();

			if (n1 == Ngay && n2 == Thang && n3 == Nam && gqsc.Getter_DanhSachGQSC()[i].Getter_MaNhanVienNhanXe() == nv) {
				vitri_SuCo++;
				SuCo[vitri_SuCo] = i;
			}
			else {
				continue;
			}
		}

		int vitri_ctbb = -1;
		int CTBB[100];
		DanhSachCTBB dsctbb;
		ifstream FileCTBB;
		FileCTBB.open("ChiTietBienBan.txt", ios::in);
		int size_CTBB = KT.DemSoLuongXe(FileCTBB);
		FileCTBB.close();
		FileCTBB.open("ChiTietBienBan.txt", ios::in);
		dsctbb.DocDanhSachCTBB(FileCTBB);
		FileCTBB.close();
		for (int i = 0; i < size_CTBB; i++) {
			for (int j = 0; j < size_SuCo; j++) {
				if (gqsc.Getter_DanhSachGQSC()[SuCo[j]].Getter_MaBB() == dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB()) {
					vitri_ctbb++;
					CTBB[vitri_ctbb] = i;
				}
				else {
					continue;
				}
			}

		}
		if (vitri_ctbb >= 0) {
			DanhSachSuCo dssc;
			ifstream FileDSSuCo;
			FileDSSuCo.open("danhsachsuco.txt", ios::in);
			int size_DSSuCo = KT.DemSoLuongXe(FileDSSuCo);
			FileDSSuCo.close();
			FileDSSuCo.open("danhsachsuco.txt", ios::in);
			dssc.DocDanhSachSuCo(FileDSSuCo);
			FileDSSuCo.close();
			int vitri_dssc;
			int stt_sc = 0;
			int TienGQ = 0;
			cout << "\n|                                                                                                                                                       |";
			cout << "\n|\t\t\t\t\tSU CO XAY RA TRONG THANG: "; cout << "                                                                                      |";
			cout << "\n|\t ____________________________________________________________                                                                                "; cout << "\t|";
			cout << "\n|\t| STT | Ma BB | Ma Su Co |   Ten su co     | Tien giai quyet |"; cout << "\t\t\t\t                                                        |";
			cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t|";
			for (int i = 0; i <= vitri_ctbb; i++) {
				stt_sc++;

				cout << "\n|\t|"; cout << setw(5) << left << stt_sc; cout << "|";
				cout << setw(7) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaBB(); cout << "|";

				for (int j = 0; j < size_DSSuCo; j++) {
					if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == dssc.Getter_DanhSachSuCo()[j].Getter_MaSuCo()) {
						vitri_dssc = j;
						break;
					}
				}
				cout << setw(10) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo(); cout << "|";

				cout << setw(17) << left << dssc.Getter_DanhSachSuCo()[vitri_dssc].Getter_TenSuCo(); cout << "|";

				if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "01" || dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "04") {
					cout << setw(13) << right << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
					TienGQ = TienGQ + dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
				}
				else {
					cout << setw(13) << right << -dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
					TienGQ = TienGQ - dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
				}
				cout << setw(22) << left << " "; cout << "\t\t                                 \t\t|";
			}
			cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t|";
			cout << "\n|\t|                      Tong tien giai quyet|"; cout << setw(13) << right << TienGQ << " VDN|"; cout << "                                      "; cout << "\t\t                                |";
			cout << "\n|\t|__________________________________________|_________________|                                                                               "; cout << "\t|";

			cout << "\n|                                                                                                                                           \t\t|";
			cout << "\n|                                                                                                                                           \t\t|";
			if (TienGQ <= 0) {
				cout << "\n|     (*) So tien phai chi ra cho su co la: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                  \t\t| ";
				cout << "\n|     (*)Tong so tien thu duoc trong ngay = Tien ve xe - Tien giai quyet: "; cout << setw(13) << left << TienThu + TienGQ << " VDN"; cout << "                                                    \t\t| ";

			}
			else {
				cout << "\n|      (*) So tien thu vao do su co: "; cout << setw(13) << left << abs(TienGQ) << " VDN"; cout << "                                                                                         \t\t| ";
				cout << "\n|      (*)Tong so tien thu duoc trong ngay = Tien ve xe + Tien giai quyet: "; cout << setw(13) << left << TienThu + TienGQ << " VDN"; cout << "                                                   \t\t| ";

			}
		}
		cout << "\n|                                                                                                                                                 \t|";
		cout << "\n|                                                                                                                                                 \t|";
		cout << "\n|                                                                                                                                                 \t|";
		cout << "\n|\t\t\t\t\t\t\t\t\t\t\t" << "\t\tHa Noi, Ngay "; cout << setw(2) << right << TGHienTai.Getter_Ngay() << " thang";
		cout << setw(2) << right << TGHienTai.Getter_Thang() << " nam "; cout << setw(2) << right << TGHienTai.Getter_Nam();
		cout << "                |";
		cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t    \tNguoi lap                          \t|";
		cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                          \t|";
		cout << "\n|                                                                                                                                                       |";
		cout << "\n|                                                                                                                                                       |";
		cout << "\n|                                                                                                                                                       |";
		cout << "\n|_______________________________________________________________________________________________________________________________________________________|";
		cout << "\n\n\n";
	}
}

void TT_SoXeRa::ThonKe_TienThuDuocTrongNgay_NV(string nv, int n)  {
	stdafx KT;
	ThoiGian TGHienTai;
	TGHienTai.LayThoiGianTuHeThong();
	string NgayThang = KT.HT_NgayThang(TGHienTai.Getter_Ngay(), TGHienTai.Getter_Thang(), TGHienTai.Getter_Nam());
	int stt = 0;
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileIn);
	int size = y->Getter_DSNV().size();
	int Vtri_nv;
	for (int i = 0; i < size; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_nv = i;
			break;
		}
	}
	int Tien = 0;
	int TienThu = 0;

	if (y->Getter_DSNV()[Vtri_nv].Getter_LoaiNhanVien() != "NVTX") {
		KT.TextColor(140);
		cout << "Thong tin tai khoan bi sai !!!";
		KT.TextColor(14);
	}
	else {
		cout << "\n _______________________________________________________________________________________________________________________________________________________";
		cout << "\n|                                                                                                                                       \t\t|";
		cout << "\n|\tBAI GIU XE                                                                                                                      \t\t|";
		cout << "\n|\tDAI HOC XAY DUNG HA NOI                                                                                                         \t\t|";
		cout << "\n|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                                                                          \t\t|";
		cout << "\n|\t\t* * * * *                                                                                                               \t\t|";
		cout << "\n|\t\t * * * *                                                                                                                \t\t|";
		cout << "\n|                                                                                                                                       \t\t|";
		cout << "\n|\t\t\tTIEN THU DUOC TRONG NGAY "; cout << setw(8) << left << NgayThang; cout << "\t\t\t                                                        \t\t|";
		cout << "\n|\tThong tin nhan vien:"; cout << "\t\t\t                                                                                        \t\t|";
		cout << "\n|\t\tMa nhan vien: "; cout << setw(10) << left << y->Getter_DSNV()[Vtri_nv].Getter_MaNhanVien(); cout << "\t\t\t                                                                        \t\t|";
		cout << "\n|\t\tHo va ten: "; cout << setw(25) << left << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "\t\t\t                                                                \t\t|";
		cout << "\n|\t\tChuc vu: ";
		cout << setw(25) << left << "Nhan vien trong xe                                                                                             \t\t|";
		cout << "\n|\t ______________________________________________________________________________________________________________________________________         |";
		cout << "\n|\t| STT | Ma The |  Bien So   | MaNV Nhan xe | Thoi Gian Gui Xe  | Thoi Gian Lay Xe  |  So Gio Gui   |  Gia gui xe     |   Thanh Tien    |"; cout << "\t|";
		cout << "\n|\t|_____|________|____________|______________|___________________|___________________|_______________|_________________|_________________|"; cout << "\t|";
			int Tien = 0;
		for (int i = 0; i < n; i++) {
			if (this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Xuat() == nv) {
				if (this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay() == TGHienTai.Getter_Ngay()
					&& this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang() == TGHienTai.Getter_Thang()
					&& this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam() == TGHienTai.Getter_Nam()) {
					string c = this->Getter_DS_SoXeRa()[i].Getter_MaSoVe().substr(0, 2);
					int SoGio = this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().SoGioGuiXe(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui());
					if (SoGio < 5) Tien = this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
					else {
						Tien = SoGio * this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien();
					}
					stt++;
					cout << "\n|\t|" << setw(5) << left << stt; cout << "|";
					cout << setw(8) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoVe();
					KT.TextColor(14);
					cout << "|";
					cout << setw(12) << left << this->Getter_DS_SoXeRa()[i].Getter_BienSo();
					cout << "|";
					cout << setw(14) << left << this->Getter_DS_SoXeRa()[i].Getter_MaSoNV_Gui();
					KT.TextColor(14);
					cout << "|";
					string N_Gui = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Ngay(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Thang(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Nam(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Gio(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Phut(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Gui().Getter_Giay());
					cout << setw(19) << left << N_Gui;
					KT.TextColor(14);
					cout << "|";
					string N_Xuat = KT.HT_NgayGio(this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Ngay(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Thang(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Nam(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Gio(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Phut(),
						this->Getter_DS_SoXeRa()[i].Getter_ThoiGian_Xuat().Getter_Giay());
					cout << setw(19) << left << N_Xuat;
					KT.TextColor(14);
					cout << "|";
						cout << setw(15) << left << SoGio;
						cout << "|";
						cout << setw(13) << right << this->Getter_DS_SoXeRa()[i].Getter_GiaTinhTien() << " VND|";
						cout << setw(13) << right << Tien << " VND";
						cout << "|";
					TienThu += Tien;
					cout << "\t|";
				}
			}
		}

		cout << "\n|\t|_____|________|____________|______________|___________________|___________________|_______________|_________________|_________________|"; cout << "\t|";
		cout << "\n|\t|                                                                                                     Tong tien thu: |";
		cout << setw(13) << right << TienThu << " VND";
		cout << "|"; cout << "\t|";
		cout << "\n|\t|____________________________________________________________________________________________________________________|_________________|        |";
		cout << "\n|                                                                                                                                       \t\t|";

		int vitri_SuCo = -1;
		int SuCo[100];
		DanhSachGiaiQuyetSuCo gqsc;
		ifstream FileSuCo;
		FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
		int size_SuCo = KT.DemSoLuongXe(FileSuCo);
		FileSuCo.close();
		FileSuCo.open("danhsachgiaiquyetsuco.txt", ios::in);
		gqsc.DocDanhSachGiaiQuyetSuCo(FileSuCo);
		FileSuCo.close();
		int Ngay = TGHienTai.Getter_Ngay();
		int Thang = TGHienTai.Getter_Thang();
		int Nam = TGHienTai.Getter_Nam();
		for (int i = 0; i < size_SuCo; i++) {
			int n1 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Ngay();
			int n2 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang();
			int n3 = gqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();

			if (n1 == Ngay && n2 == Thang && n3 == Nam && gqsc.Getter_DanhSachGQSC()[i].Getter_MaNhanVienNhanXe() == nv) {
				vitri_SuCo++;
				SuCo[vitri_SuCo] = i;
			}
			else {
				continue;
			}
		}
		int vitri_ctbb = -1;
		int CTBB[100];
		DanhSachCTBB dsctbb;
		ifstream FileCTBB;
		FileCTBB.open("ChiTietBienBan.txt", ios::in);
		int size_CTBB = KT.DemSoLuongXe(FileCTBB);
		FileCTBB.close();
		FileCTBB.open("ChiTietBienBan.txt", ios::in);
		dsctbb.DocDanhSachCTBB(FileCTBB);
		FileCTBB.close();
		for (int i = 0; i < size_CTBB; i++) {
			for (int j = 0; j < size_SuCo; j++) {
				if (gqsc.Getter_DanhSachGQSC()[SuCo[j]].Getter_MaBB() == dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB()) {
					vitri_ctbb++;
					CTBB[vitri_ctbb] = i;
				}
				else {
					continue;
				}
			}

		}
		if (vitri_ctbb >= 0) {
			DanhSachSuCo dssc;
			ifstream FileDSSuCo;
			FileDSSuCo.open("danhsachsuco.txt", ios::in);
			int size_DSSuCo = KT.DemSoLuongXe(FileDSSuCo);
			FileDSSuCo.close();
			FileDSSuCo.open("danhsachsuco.txt", ios::in);
			dssc.DocDanhSachSuCo(FileDSSuCo);
			FileDSSuCo.close();
			int vitri_dssc;
			int stt_sc = 0;
			int TienGQ = 0;
			cout << "\n|                                                                                                                                                       |";
			cout << "\n|\t\t\t\t\tSU CO XAY RA TRONG THANG: "; cout << "                                                                                      |";
			cout << "\n|\t ____________________________________________________________                                                                                "; cout << "\t|";
			cout << "\n|\t| STT | Ma BB | Ma Su Co |   Ten su co     | Tien giai quyet |"; cout << "\t\t\t\t                                                        |";
			cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t|";

			for (int i = 0; i <= vitri_ctbb; i++) {
				stt_sc++;

				cout << "\n|\t|"; cout << setw(5) << left << stt_sc; cout << "|";
				cout << setw(7) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaBB(); cout << "|";
				for (int j = 0; j < size_DSSuCo; j++) {
					if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == dssc.Getter_DanhSachSuCo()[j].Getter_MaSuCo()) {
						vitri_dssc = j;
						break;
					}
				}
				cout << setw(10) << left << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo(); cout << "|";
				cout << setw(17) << left << dssc.Getter_DanhSachSuCo()[vitri_dssc].Getter_TenSuCo(); cout << "|";
				if (dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "01" || dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_MaSuCo() == "04") {
					cout << setw(13) << right << dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
					TienGQ = TienGQ + dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
				}
				else {
					cout << setw(13) << right << -dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet() << " VDN"; cout << "|";
					TienGQ = TienGQ - dsctbb.Getter_DanhSach_CTBB()[CTBB[i]].Getter_TienGiaiQuyet();
				}
				cout << setw(22) << left << " "; cout << "\t\t                                 \t\t|";

			}
			cout << "\n|\t|_____|_______|__________|_________________|_________________|                                                                               "; cout << "\t|";
			cout << "\n|\t|                      Tong tien giai quyet|"; cout << setw(13) << right << TienGQ << " VDN|"; cout << "                                      "; cout << "\t\t                                |";
			cout << "\n|\t|__________________________________________|_________________|                                                                               "; cout << "\t|";
			cout << "\n|                                                                                                                                           \t\t|";
			cout << "\n|                                                                                                                                           \t\t|";
			if (TienGQ <= 0) {
				cout << "\n|     (*) So tien phai chi ra cho su co la: "; cout << setw(10) << left << abs(TienGQ) << " VDN"; cout << "                                                                                     \t\t| ";
				cout << "\n|     (*)Tong so tien thu duoc trong ngay = Tien ve xe - Tien giai quyet: "; cout << setw(10) << left << TienThu + TienGQ << " VDN"; cout << "                                                       \t\t| ";
			}
			else {
				cout << "\n|      (*) So tien thu vao do su co: "; cout << setw(10) << left << abs(TienGQ) << " VDN"; cout << "                                                                                            \t\t| ";
				cout << "\n|      (*)Tong so tien thu duoc trong ngay = Tien ve xe + Tien giai quyet: "; cout << setw(10) << left << TienThu + TienGQ << " VDN"; cout << "                                                      \t\t| ";
			}

		}
		cout << "\n|                                                                                                                                                 \t|";
		cout << "\n|                                                                                                                                                 \t|";
		cout << "\n|                                                                                                                                                 \t|";
		cout << "\n|\t\t\t\t\t\t\t\t\t\t\t" << "\t\tHa Noi, Ngay "; cout << setw(2) << right << TGHienTai.Getter_Ngay() << " thang";
		cout << setw(2) << right << TGHienTai.Getter_Thang() << " nam "; cout << setw(2) << right << TGHienTai.Getter_Nam();
		cout << "                |";
		cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t\t    \tNguoi lap                          \t|";
		cout << "\n|\t\t\t\t\t\t\t\t\t\t\t\t"; cout << setw(25) << y->Getter_DSNV()[Vtri_nv].Getter_HoTen(); cout << "                          \t|";
		cout << "\n|                                                                                                                                                       |";
		cout << "\n|                                                                                                                                                       |";
		cout << "\n|                                                                                                                                                       |";
		cout << "\n|_______________________________________________________________________________________________________________________________________________________|";
		cout << "\n\n\n";
	}

}

