#include "DanhSachXeTrongBen.h"
#include"NhanVien.h"
#include"stdafx.h"
#include <iomanip>	
#include"DanhSachNhanVien.h"
#include"BangGia.h"
void DanhSachXeTrongBen::Setter_Dsxg(PhieuGuiXe x) {
	Dsxg.push_back(x);
}
vector<PhieuGuiXe> DanhSachXeTrongBen::Getter_Dsxg() {
	return this->Dsxg;
}

int DanhSachXeTrongBen::DemSoLuongXe() {
	ifstream FileIn;
	FileIn.open("danhsachphieuguixe.txt", ios::in);
	int n = 0;
	char c;
	FileIn.get(c);
	while (FileIn) {
		while (FileIn && c != '\n') {
			FileIn.get(c);
		}
		n = n + 1;
		FileIn.get(c);
	}
	FileIn.close();
	return n;
}
void DanhSachXeTrongBen::DocSoXeVao(ifstream& FileIn, int n) {

	for (int i = 0; i < n; i++) {
		PhieuGuiXe x;
		x.DocThongTinXeGui(FileIn);
		Dsxg.push_back(x);
	}
}

void DanhSachXeTrongBen::Xuat() {
	int size = Dsxg.size();

	for (int i = 0; i < size; i++)
	{
		cout << "\n\t\tThong tin phieu thu : " << i + 1 << "\n";
		Dsxg[i].Xuat();
	}
}


void DanhSachXeTrongBen::CapNhatSoXeVao(ofstream& FileOut, int size, int n) {
	for (int i = 0; i < size; i++) {
		if (i != n) {
			FileOut << Dsxg[i].Getter_MaSoVe() << " " << Dsxg[i].Getter_BienSo() << " " << Dsxg[i].Getter_MaSoNV() << " " <<
				Dsxg[i].Getter_ThoiGian().Getter_Ngay() << " " <<
				Dsxg[i].Getter_ThoiGian().Getter_Thang() << " " <<
				Dsxg[i].Getter_ThoiGian().Getter_Nam() << " " <<
				Dsxg[i].Getter_ThoiGian().Getter_Gio() << " " <<
				Dsxg[i].Getter_ThoiGian().Getter_Phut() << " " <<
				Dsxg[i].Getter_ThoiGian().Getter_Giay() << " " << endl;
		}
		else continue;
	}
}
void DanhSachXeTrongBen::CapNhatLichSu(int n, ThoiGian TG, string MaNV, int TongThoiGianGui, string c) {
	stdafx st;
	int MucTien = st.TienTungLoaiXe(c, TongThoiGianGui);

	ofstream FileLS;
	FileLS.open("SoXeRa.txt", ios::app);
	FileLS << Dsxg[n].Getter_MaSoVe() << " " << Dsxg[n].Getter_BienSo() << " " << Dsxg[n].Getter_MaSoNV() << " " << MaNV << " " <<
		Dsxg[n].Getter_ThoiGian().Getter_Ngay() << " " <<
		Dsxg[n].Getter_ThoiGian().Getter_Thang() << " " <<
		Dsxg[n].Getter_ThoiGian().Getter_Nam() << " " <<
		Dsxg[n].Getter_ThoiGian().Getter_Gio() << " " <<
		Dsxg[n].Getter_ThoiGian().Getter_Phut() << " " <<
		Dsxg[n].Getter_ThoiGian().Getter_Giay() << " " <<
		TG.Getter_Ngay() << " " <<
		TG.Getter_Thang() << " " <<
		TG.Getter_Nam() << " " <<
		TG.Getter_Gio() << " " <<
		TG.Getter_Phut() << " " <<
		TG.Getter_Giay() << " " << MucTien << endl;
}

void DanhSachXeTrongBen::InPhieuThu(PhieuGuiXe Pgx, ThoiGian ThoiGian_LayXe, int SoGioGui, int Tien, string HoTenNV) {
	BangGia bg;
	ifstream FileIn;
	FileIn.open("BangGia.txt", ios::in);
	bg.DocFileBangGia(FileIn);
	FileIn.close();

	string c = Pgx.Getter_MaSoVe().substr(0, 2);
	string c1;
	int vitri;
	for (int i = 0; i < 2; i++) {
		if (bg.Getter_DS_BangGia()[i].Getter_Xe() == c) {
			vitri = i;
			break;
		}
		else {
			continue;
		}
	}

	stdafx KT;

	string N_Gui = KT.HT_NgayGio(Pgx.Getter_ThoiGian().Getter_Ngay(), Pgx.Getter_ThoiGian().Getter_Thang(), Pgx.Getter_ThoiGian().Getter_Nam(),
		Pgx.Getter_ThoiGian().Getter_Gio(), Pgx.Getter_ThoiGian().Getter_Phut(), Pgx.Getter_ThoiGian().Getter_Giay());
	string N_Xuat = KT.HT_NgayGio(ThoiGian_LayXe.Getter_Ngay(), ThoiGian_LayXe.Getter_Thang(), ThoiGian_LayXe.Getter_Nam(),
		ThoiGian_LayXe.Getter_Gio(), ThoiGian_LayXe.Getter_Phut(), ThoiGian_LayXe.Getter_Giay());
	cout << "\n\t\t\t\t ________________________________________________________";
	cout << "\n\t\t\t\t|           BAI DO XE - DAI HOC XAY DUNG                 | ";
	cout << "\n\t\t\t\t| 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi          |";
	cout << "\n\t\t\t\t|\t\t     * * * * *                           |";
	cout << "\n\t\t\t\t|\t\t      * * * *                            |";
	cout << "\n\t\t\t\t|             PHIEU TINH PHI GUI XE                      |";
	cout << "\n\t\t\t\t|	        (Ma the: "; cout << setw(7) << left << Pgx.Getter_MaSoVe() << ")" << "                        |";
	cout << "\n\t\t\t\t|                                                        |";
	if (Pgx.Getter_MaSoVe().substr(0, 2) == "XM") cout << "\n\t\t\t\t| Loai xe: Xe may                                        |";
	else 	cout << "\n\t\t\t\t| Loai xe: Xe o to                                       |";
	cout << "\n\t\t\t\t| Tinh tien:                                             |";


	cout << "\n\t\t\t\t|\tSo gio gui < 5: "; cout << setw(7) << left << bg.Getter_DS_BangGia()[vitri].Getter_Khung1(); cout << setw(10) << left << " vnd/ luot"; cout << "                |";
	cout << "\n\t\t\t\t|\tSo gio gui < 24: "; cout << setw(6) << left << bg.Getter_DS_BangGia()[vitri].Getter_Khung2(); cout << setw(10) << left << " vnd/ h"; cout << "                |";
	cout << "\n\t\t\t\t|\tSo gio gui >=24: "; cout << setw(6) << left << bg.Getter_DS_BangGia()[vitri].Getter_Khung3(); cout << setw(10) << left << " vnd/ h"; cout << "                |";


	cout << "\n\t\t\t\t|                                                        |";
	cout << "\n\t\t\t\t| Thoi Gian Vao: "; cout << setw(20) << left << N_Gui; cout << "                    |";
	cout << "\n\t\t\t\t| Thoi Gian Ra: "; cout << setw(20) << left << N_Xuat; cout << "                     |";

	cout << "\n\t\t\t\t|                                                        |";
	cout << "\n\t\t\t\t| So Gio Gui: "; cout << setw(5) << left << SoGioGui << " gio                                  | ";
	cout << "\n\t\t\t\t| Thanh Tien: "; cout << setw(10) << left << Tien << "vnd                              |       ";
	cout << "\n\t\t\t\t|________________________________________________________|";

	cout << "\n\t\t\t\t|Nhan vien thu tien: "; cout << setw(25) << left << HoTenNV; cout << "           |";
	cout << "\n\t\t\t\t|________________________________________________________|" << endl;
}




void DanhSachXeTrongBen::TK_XeTrongBen_TheXe(string nv, string ve, int n) {

	stdafx KT;
	int vitri;
	string c;
	for (int i = 0; i < n; i++) {
		if (ve == this->Getter_Dsxg()[i].Getter_MaSoVe()) {
			vitri = i;
			c = this->Getter_Dsxg()[i].Getter_MaSoVe().substr(0, 2);
			break;
		}
		else {
			continue;
		}
	}
	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileNV;
	FileNV.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileNV);
	int size = y->Getter_DSNV().size();
	int Vtri_NV;
	for (int i = 0; i < n; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_NV = i;
			break;
		}
	}
		cout << "\n\t\t _______________________________________________________________________________";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|\tBAI GIU XE                                                              |";
		cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                 |";
		cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                  |";
		cout << "\n\t\t|\t\t* * * * *                                                       |";
		cout << "\n\t\t|\t\t * * * *                                                        |";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|\t\t\tKET QUA TIM KIEM CHO THE XE: "; cout << setw(10) << left << ve; cout << "                 |";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|\tNhan vien thuc hien: "; cout << setw(25) << left << y->Getter_DSNV()[Vtri_NV].Getter_HoTen(); cout << "\t\t\t\t|";
		cout << "\n\t\t|\t _____________________________________________________________"; cout << "\t\t|";
		cout << "\n\t\t|\t|__Loai_Xe__|___Bien_So____|_MaNV_Nhan_xe_|_Thoi_Gian_Gui_Xe__|"; cout << "\t\t|";

		cout << "\n\t\t|\t|";
		if (c == "XM") {
			cout << setw(11) << left << "Xe May";
		}
		else {
			cout << setw(11) << left << "Xe OTo";
		}
		cout << "|";
		cout << setw(14) << left << this->Getter_Dsxg()[vitri].Getter_BienSo();
		cout << "|";
		cout << setw(14) << left << this->Getter_Dsxg()[vitri].Getter_MaSoNV();
		KT.TextColor(14);
		cout << "|";
		string N_Gui = KT.HT_NgayGio(this->Getter_Dsxg()[vitri].Getter_ThoiGian().Getter_Ngay(),
			this->Getter_Dsxg()[vitri].Getter_ThoiGian().Getter_Thang(),
			this->Getter_Dsxg()[vitri].Getter_ThoiGian().Getter_Nam(),
			this->Getter_Dsxg()[vitri].Getter_ThoiGian().Getter_Gio(),
			this->Getter_Dsxg()[vitri].Getter_ThoiGian().Getter_Phut(),
			this->Getter_Dsxg()[vitri].Getter_ThoiGian().Getter_Giay());
		cout << setw(19) << left << N_Gui;
		KT.TextColor(14);
		cout << "|"; cout << "\t\t|";
		cout << "\n\t\t|\t|___________|______________|______________|___________________|"; cout << "\t\t|";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|_______________________________________________________________________________|";
}


void DanhSachXeTrongBen::TK_XeTrongBen_BienSo(string nv, string bien, int n) {

	stdafx KT;

	int VTri[100];
	int size_ViTri = -1;

	for (int i = 0; i < n; i++) {
		string b = this->Getter_Dsxg()[i].Getter_BienSo();
		if (bien == b) {
			size_ViTri++;
			VTri[size_ViTri] = i;
		}
		else {
			continue;
		}
	}

	DanhSachNhanVien* y = new DanhSachNhanVien;
	ifstream FileNV;
	FileNV.open("danhsachnhanvien.txt", ios::in);
	y->DocDSNV(FileNV);
	int size = y->Getter_DSNV().size();
	int Vtri_NV;
	for (int i = 0; i < n; i++) {
		if (y->Getter_DSNV()[i].Getter_MaNhanVien() != nv) continue;
		else {
			Vtri_NV = i;
			break;
		}
	}
	if (size_ViTri < 0) {
		KT.TextColor(140);
		cout << "Thong tin bien xe vua nhap khong co trong ben, hay kiem tra lai";
		KT.TextColor(14);
	}
	else {
		string c;
		cout << "\n\t\t _______________________________________________________________________________";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|\tBAI GIU XE                                                              |";
		cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                 |";
		cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                  |";
		cout << "\n\t\t|\t\t* * * * *                                                       |";
		cout << "\n\t\t|\t\t * * * *                                                        |";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|\t\t\tKET QUA TIM KIEM CHO BIEN SO XE: "; cout << setw(15) << left << bien; cout << "        |";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|\tNhan vien thuc hien: "; cout << setw(25) << left << y->Getter_DSNV()[Vtri_NV].Getter_HoTen(); cout << "\t\t\t\t|";
		cout << "\n\t\t|\t _______________________________________________________________"; cout << "\t|";
		cout << "\n\t\t|\t|__Loai_Xe__|___Ma The Xe____|_MaNV_Nhan_xe_|_Thoi_Gian_Gui_Xe__|"; cout << "\t|";

		for (int i = 0; i <= size_ViTri; i++) {
			c = this->Getter_Dsxg()[VTri[i]].Getter_MaSoVe().substr(0, 2);
			cout << "\n\t\t|\t|";
			if (c == "XM") {
				cout << setw(11) << left << "Xe May";
			}
			else {
				cout << setw(11) << left << "Xe OTo";
			}
			cout << "|";
			cout << setw(16) << left << this->Getter_Dsxg()[VTri[i]].Getter_MaSoVe();
			cout << "|";
			cout << setw(14) << left << this->Getter_Dsxg()[VTri[i]].Getter_MaSoNV();
			KT.TextColor(14);
			cout << "|";
			string N_Gui = KT.HT_NgayGio(this->Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Ngay(),
				this->Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Thang(),
				this->Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Nam(),
				this->Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Gio(),
				this->Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Phut(),
				this->Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Giay());
			cout << setw(19) << left << N_Gui;
			KT.TextColor(14);
			cout << "|"; cout << "\t|";
		}
		cout << "\n\t\t|\t|___________|________________|______________|___________________|"; cout << "\t|";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|                                                                               |";
		cout << "\n\t\t|_______________________________________________________________________________|";

	}

}