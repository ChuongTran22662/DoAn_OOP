#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include "console.h"
#include <iomanip>	
#include<string>
#include"stdafx.h"
#include"ChiTietBienBan.h"
#include"DanhSachCTBB.h"
#include"DS_LichSuGiaVe.h"
void textColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, true);
}

int ChuyenStringSangInt(string s) {
	int l1 = s.length();
	int num1 = 0;
	for (int i = l1 - 1; i >= 0; --i) {
		num1 += (int)(s[i] - '0') * pow(10, l1 - i - 1);
	}
	return num1;
}

int HienThiVeTrongXeMay(DanhSachVeXe x) {
	system("cls");
	int sizeXeMay = x.Getter_DSVeXeMay().size();
	cout << "\n\tDanh sach ve xe trong :";
	int empty = 0;
	int stt = 1;
	cout << "\n\t _________________";
	cout << "\n\t| STT | Ma The Xe |";
	cout << "\n\t|_____|___________|";

	for (int i = 0; i < sizeXeMay; i++) {
		if (x.Getter_DSVeXeMay()[i].Getter_TrangThai() == 1) {
			cout << "\n\t|"; cout << setw(5) << left << stt; cout << "|";
			cout << setw(11) << left << x.Getter_DSVeXeMay()[i].Getter_MaSo(); cout << "|";
			Sleep(100);
			empty++;
			stt++;
		}
	}
	cout << "\n\t|_____|___________|";
	if (empty == 0) {
		cout << "\n\t\tBai xe da het cho";
		system("pause");
		return 1;
	}
}

int HienThiVeTrongOto(DanhSachVeXe x) {
	system("cls");
	int sizeOto = x.Getter_DSVeOTo().size();
	cout << "\n\t\tDanh sach ve xe trong :" << endl << endl;
	int empty = 0;
	int stt = 1;
	cout << "\n\t _________________";
	cout << "\n\t| STT | Ma The Xe |";
	cout << "\n\t|_____|___________|";
	for (int i = 0; i < sizeOto; i++) {
		if (x.Getter_DSVeOTo()[i].Getter_TrangThai() == 1) {
			cout << "\n\t|"; cout << setw(5) << left << stt; cout << "|";
			cout << setw(11) << left << x.Getter_DSVeOTo()[i].Getter_MaSo(); cout << "|";
			Sleep(100);
			empty++;
			stt++;

		}
	}
	cout << "\n\t|_____|___________|";
	if (empty == 0) {
		cout << "\n\t\tBai xe da het cho";
		system("pause");
		return 1;
	}
}

void GQSuCo(DanhSachNhanVien x, int index) {

	stdafx st;
	DanhSachXeTrongBen dsx;
	ifstream FileSoXeVao;
	FileSoXeVao.open("danhsachphieuguixe.txt", ios::in);
	int size = dsx.DemSoLuongXe();
	dsx.DocSoXeVao(FileSoXeVao, size);
	FileSoXeVao.close();

	DanhSachSuCo dssc;
	ifstream FileSuCo;
	FileSuCo.open("danhsachsuco.txt", ios::in);
	dssc.DocDanhSachSuCo(FileSuCo);
	FileSuCo.close();

	GiaiQuyetSuCo gqsc;
	ChiTietBienBan ctbb;
	int sizeDsSuCo = dssc.Getter_DanhSachSuCo().size();
	string BienSo;

	bool quaylai = false;
	bool Co_BB = false;
bs:
	textColor(14);
	cout << "\nNhap bien so :";
	cin >> BienSo;
	int KT_Bien = st.KT_TrungBien(BienSo, size);
	bool checkbs = false;
	for (int i = 0; i < size; i++) {
		if (dsx.Getter_Dsxg()[i].Getter_BienSo() == BienSo) {
			checkbs = true;
			break;
		}
	}
	if (checkbs == false) {
		textColor(140);
		cout << "\tXe khong co trong ben,nhap lai !" << endl;
		Sleep(900);
		system("cls");
		goto bs;
	}
	string masovexx;
	int c = 1000;
	if (KT_Bien == 1) {
		int length = dsx.Getter_Dsxg().size();

		for (int i = 0; i < length; i++) {
			if (dsx.Getter_Dsxg()[i].Getter_BienSo() == BienSo) {
				c = i;
			}
		}

		masovexx = dsx.Getter_Dsxg()[c].Getter_MaSoVe();
	}
	if (KT_Bien > 1) {
		int VTri[100];
		int size_ViTri = -1;
		int stt = 0;
		for (int i = 0; i < size; i++) {
			string b = dsx.Getter_Dsxg()[i].Getter_BienSo();
			if (BienSo == b) {
				size_ViTri++;
				VTri[size_ViTri] = i;
			}
			else {
				continue;
			}
		}
		string lxe;
		cout << "\n\t\t _____________________________________________________________________";
		cout << "\n\t\t| STT |  Loai Xe  |   Ma The Xe    | MaNV Nhan xe | Thoi Gian Gui Xe  |";
		cout << "\n\t\t|_____|___________|________________|______________|___________________|";

		for (int i = 0; i <= size_ViTri; i++) {
			stt++;
			lxe = dsx.Getter_Dsxg()[VTri[i]].Getter_MaSoVe().substr(0, 2);
			cout << "\n\t\t|";
			cout << setw(5) << left << stt; cout << "|";
			if (lxe == "XM") {
				cout << setw(11) << left << "Xe May";
			}
			else {

				cout << setw(11) << left << "Xe OTo";
			}
			cout << "|";
			cout << setw(16) << left << dsx.Getter_Dsxg()[VTri[i]].Getter_MaSoVe();
			cout << "|";
			cout << setw(14) << left << dsx.Getter_Dsxg()[VTri[i]].Getter_MaSoNV();

			cout << "|";
			string N_Gui = st.HT_NgayGio(dsx.Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Ngay(),
				dsx.Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Thang(),
				dsx.Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Nam(),
				dsx.Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Gio(),
				dsx.Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Phut(),
				dsx.Getter_Dsxg()[VTri[i]].Getter_ThoiGian().Getter_Giay());
			cout << setw(19) << left << N_Gui;
			cout << "|";

		}

		cout << "\n\t\t|_____|___________|________________|______________|___________________|";
		int chonxe;
		string s_chonxe;
	cx:		while (getline(cin, s_chonxe))
	{
		stringstream ss(s_chonxe);
		if (ss >> chonxe)
		{
			if (ss.eof())
			{
				break;
			}
		}
		cout << "\n\tChon xe so(khong duoc nhap chuoi): ";
		st.TextColor(140);
	}
	if (chonxe < 1 || chonxe > size_ViTri + 1) {
		st.TextColor(140);
		cout << "\n\tLua chon khong chinh xac";
		st.TextColor(14);
		goto cx;
	}
	st.TextColor(14);
	system("cls");

	masovexx = dsx.Getter_Dsxg()[VTri[chonxe - 1]].Getter_MaSoVe();
	c = VTri[chonxe - 1];

	}

	int sizedsxtb = dsx.Getter_Dsxg().size();
	int vitri = 0;
	for (int i = 0; i < sizedsxtb; i++) {
		if (dsx.Getter_Dsxg()[i].Getter_MaSoVe() == masovexx) {
			vitri = i;
		}
	}

	bool check_xoave = false;
	string v = dsx.Getter_Dsxg()[c].Getter_MaSoVe().substr(0, 2);
	string luachonthem;
	ThoiGian TG_GiaiQuyet;
	TG_GiaiQuyet.LayThoiGianTuHeThong();
ql:
	do {
		string luachonsuco;
		do {
			if (v == "XM") {
				int sizesuco = dssc.Getter_DanhSachSuCo().size();



				cout << "\n\tXu ly su co cho xe may co bien so: " << BienSo;
				cout << "\n\tMa the xe su dung: " << masovexx;
				int z = 1;
				cout << "\n\t ______________________________________________________";
				cout << "\n\t| STT |       Ten su co       |  So tien den bu toi da |";
				cout << "\n\t|_____|_______________________|________________________|";

				for (int i = 0; i < sizesuco; i++) {
					if (dssc.Getter_DanhSachSuCo()[i].Getter_LoaiXe() == "xemay") {
						cout << "\n\t|";
						st.TextColor(202);
						cout << setw(5) << left << z; st.TextColor(14);; cout << "|";
						cout << setw(23) << left << dssc.Getter_DanhSachSuCo()[i].Getter_TenSuCo(); cout << "|";
						cout << setw(20) << right << dssc.Getter_DanhSachSuCo()[i].Getter_SoTien() << " VND"; cout << "|";
						z++;
					}
				}
				cout << "\n\t|_____|_______________________|________________________|";

				cout << "\nChon su co "; cout << "(Nhan "; st.TextColor(202); cout << "0"; st.TextColor(14); cout << " de quay lai): ";
				cin >> luachonsuco;

				if (luachonsuco == "1") {
					check_xoave = true;
					string masuco = "01";
					string tensuco = "Mat The Xe";
					string loaixe = "xemay";
					double giatien = 100000;

					gqsc.Setter_BienSo(BienSo);
					gqsc.Setter_LoaiXe(loaixe);
					ctbb.Setter_MaSuCo(masuco);
					ctbb.Setter_TienGiaiQuyet(giatien);
					gqsc.Setter_MaNhanVienQuanLy(x.Getter_DSNV()[index].Getter_MaNhanVien());
					gqsc.Setter_MaNhanVienNhanXe(dsx.Getter_Dsxg()[c].Getter_MaSoNV());
					gqsc.Setter_MaThe(dsx.Getter_Dsxg()[c].Getter_MaSoVe());
					gqsc.Nhap();
				}

				if (luachonsuco == "2") {
					string masuco = "02";
					string tensuco = "Hong Xe";
					string loaixe = "xemay";
					double giatien;

					cout << "\nNhap gia tien :";
					cin >> giatien;

					if (giatien > 1000000) {
						ctbb.Setter_TienGiaiQuyet(1000000);
					}
					else {
						ctbb.Setter_TienGiaiQuyet(giatien);
					}

					gqsc.Setter_BienSo(BienSo);
					gqsc.Setter_LoaiXe(loaixe);
					ctbb.Setter_MaSuCo(masuco);
					gqsc.Setter_MaNhanVienQuanLy(x.Getter_DSNV()[index].Getter_MaNhanVien());
					gqsc.Setter_MaNhanVienNhanXe(dsx.Getter_Dsxg()[c].Getter_MaSoNV());
					gqsc.Setter_MaThe(dsx.Getter_Dsxg()[c].Getter_MaSoVe());
					gqsc.Nhap();
				}

				if (luachonsuco == "3") {
					string masuco = "03";
					string tensuco = "Mat Xe";
					string loaixe = "xemay";
					double giatien;

					cout << "\nNhap gia tien :";
					cin >> giatien;

					if (giatien > 5000000) {
						ctbb.Setter_TienGiaiQuyet(5000000);
					}
					else {
						ctbb.Setter_TienGiaiQuyet(giatien);
					}

					gqsc.Setter_BienSo(BienSo);
					gqsc.Setter_LoaiXe(loaixe);
					ctbb.Setter_MaSuCo(masuco);
					gqsc.Setter_MaNhanVienQuanLy(x.Getter_DSNV()[index].Getter_MaNhanVien());
					gqsc.Setter_MaNhanVienNhanXe(dsx.Getter_Dsxg()[c].Getter_MaSoNV());
					gqsc.Setter_MaThe(dsx.Getter_Dsxg()[c].Getter_MaSoVe());
					gqsc.Nhap();
				}
			}
			if (v == "OT") {

				int sizesuco = dssc.Getter_DanhSachSuCo().size();

				//	int luachonsuco;

				cout << "\n\tGiai quyet su co che xe oto co bien so: " << BienSo;
				cout << "\n\tMa the xe su dung: " << masovexx;
				int z = 1;
				cout << "\n\t ______________________________________________________";
				cout << "\n\t| STT |       Ten su co       |  So tien den bu toi da |";
				cout << "\n\t|_____|_______________________|________________________|";
				for (int i = 0; i < sizesuco; i++) {
					if (dssc.Getter_DanhSachSuCo()[i].Getter_LoaiXe() == "oto") {
						cout << "\n\t|";
						st.TextColor(202);
						cout << setw(5) << left << z; st.TextColor(14);; cout << "|";
						cout << setw(23) << left << dssc.Getter_DanhSachSuCo()[i].Getter_TenSuCo(); cout << "|";
						cout << setw(20) << right << dssc.Getter_DanhSachSuCo()[i].Getter_SoTien() << " VND"; cout << "|";
						z++;
					}
				}
				cout << "\n\t|_____|_______________________|________________________|";

				cout << "\nChon su co "; cout << "(Nhan "; st.TextColor(202); cout << "0"; st.TextColor(14); cout << " de quay lai): ";
				cin >> luachonsuco;

				if (luachonsuco == "1") {
					check_xoave = true;
					string masuco = "04";
					string tensuco = "Mat The Xe";
					string loaixe = "oto";
					double giatien = 200000;

					gqsc.Setter_BienSo(BienSo);
					gqsc.Setter_LoaiXe(loaixe);
					ctbb.Setter_MaSuCo(masuco);
					ctbb.Setter_TienGiaiQuyet(giatien);
					gqsc.Setter_MaNhanVienQuanLy(x.Getter_DSNV()[index].Getter_MaNhanVien());
					gqsc.Setter_MaNhanVienNhanXe(dsx.Getter_Dsxg()[c].Getter_MaSoNV());
					gqsc.Setter_MaThe(dsx.Getter_Dsxg()[c].Getter_MaSoVe());
					gqsc.Nhap();
				}

				if (luachonsuco == "2") {
					string masuco = "05";
					string tensuco = "Hong Xe";
					string loaixe = "oto";
					double giatien;

					cout << "\nNhap gia tien :";
					cin >> giatien;

					if (giatien > 2000000) {
						ctbb.Setter_TienGiaiQuyet(2000000);
					}
					else {
						ctbb.Setter_TienGiaiQuyet(giatien);
					}

					gqsc.Setter_BienSo(BienSo);
					gqsc.Setter_LoaiXe(loaixe);
					ctbb.Setter_MaSuCo(masuco);
					gqsc.Setter_MaNhanVienQuanLy(x.Getter_DSNV()[index].Getter_MaNhanVien());
					gqsc.Setter_MaNhanVienNhanXe(dsx.Getter_Dsxg()[c].Getter_MaSoNV());
					gqsc.Setter_MaThe(dsx.Getter_Dsxg()[c].Getter_MaSoVe());
					gqsc.Nhap();
				}

				if (luachonsuco == "3") {
					string masuco = "06";
					string tensuco = "Mat Xe";
					string loaixe = "oto";
					double giatien;

					cout << "\nNhap gia tien :";
					cin >> giatien;

					if (giatien > 10000000) {
						ctbb.Setter_TienGiaiQuyet(10000000);
					}
					else {
						ctbb.Setter_TienGiaiQuyet(giatien);
					}

					gqsc.Setter_BienSo(BienSo);
					gqsc.Setter_LoaiXe(loaixe);
					ctbb.Setter_MaSuCo(masuco);
					gqsc.Setter_MaNhanVienQuanLy(x.Getter_DSNV()[index].Getter_MaNhanVien());
					gqsc.Setter_MaNhanVienNhanXe(dsx.Getter_Dsxg()[c].Getter_MaSoNV());
					gqsc.Setter_MaThe(dsx.Getter_Dsxg()[c].Getter_MaSoVe());
					gqsc.Nhap();
				}
			}
			if (luachonsuco != "1" && luachonsuco != "2" && luachonsuco != "3" && luachonsuco != "0") {
				st.TextColor(140);
				cout << "Lua chon khong dung, hay nhap lai";
				Sleep(800);
				st.TextColor(14);
				system("cls");
			}
			if (luachonsuco == "0") {
				quaylai = true;
				luachonthem = "no";
			}
		} while (luachonsuco != "1" && luachonsuco != "2" && luachonsuco != "3" && luachonsuco != "0");
		if (quaylai == false) {
			Co_BB = true;
			string mtx = gqsc.Getter_MaThe();
			bool check_bb;
			check_bb = st.KT_BienBan(ctbb.Getter_MaBB(), ctbb.Getter_MaSuCo());
			if (check_bb == true) {
				system("cls");
				st.TextColor(140);
				cout << "\n\tSu co da ton tai, hay nhap lai";
				Sleep(700);
				system("cls");
				st.TextColor(14);
				goto ql;
			}

			DanhSachGiaiQuyetSuCo dsgqsc;
			DanhSachCTBB dsctbb;
			ifstream FileIn;
			FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
			dsgqsc.DocDanhSachGiaiQuyetSuCo(FileIn);
			FileIn.close();

			FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
			int size_suco = st.DemSoLuongXe(FileIn);
			FileIn.close();

			int vitri_bienban = -1;
			for (int i = 0; i < size_suco; i++) {
				if (dsgqsc.Getter_DanhSachGQSC()[i].Getter_BienSo() == BienSo && dsgqsc.Getter_DanhSachGQSC()[i].Getter_MaThe() == mtx &&
					dsgqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Ngay() == TG_GiaiQuyet.Getter_Ngay() &&
					dsgqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang() == TG_GiaiQuyet.Getter_Thang() &&
					dsgqsc.Getter_DanhSachGQSC()[i].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam() == TG_GiaiQuyet.Getter_Nam()) {
					vitri_bienban = i;
					break;
				}
				else {
					continue;
				}
			}
			if (vitri_bienban >= 0) {
				gqsc.Setter_MaBB(dsgqsc.Getter_DanhSachGQSC()[vitri_bienban].Getter_MaBB());
				ctbb.Setter_MaBB(dsgqsc.Getter_DanhSachGQSC()[vitri_bienban].Getter_MaBB());
			}
			else {

				string Ma_BB = st.HT_VeXeThem("BB", size_suco + 1);
				gqsc.Setter_MaBB(Ma_BB);
				ctbb.Setter_MaBB(Ma_BB);
			}
			gqsc.Setter_ThoiGianGuiXe(dsx.Getter_Dsxg()[vitri].Getter_ThoiGian());

			dsgqsc.Setter_DanhSachGQSC(gqsc);
			dsctbb.Setter_DanhSach_CTBB(ctbb);

			if (vitri_bienban < 0) {
				ofstream FileOut;
				FileOut.open("danhsachgiaiquyetsuco.txt", ios::app);
				dsgqsc.GhiDanhSachGiaiQuyetSuCo(FileOut);
				FileOut.close();
			}


			fstream File_CTBB;
			File_CTBB.open("ChiTietBienBan.txt", ios::app);
			dsctbb.GhiDanhSachCTBB(File_CTBB);
			File_CTBB.close();


			cout << "\n\tLap bien ban thanh cong";
			do {
				cout << "\n\tBan muon them su co cho bien ban tren("; st.TextColor(202); cout << "yes"; st.TextColor(14);
				cout << "/"; st.TextColor(202); cout << "no"; st.TextColor(14); cout << "): ";
				cout << "\n\t>>>> ";
				cin >> luachonthem;
				if (luachonthem != "yes" && luachonthem != "no") {
					st.TextColor(140);
					cout << "\n\t\t\tDa xay ra loi, hay nhap lai." << endl;
					Sleep(400);
					st.TextColor(14);
				}
			} while (luachonthem != "yes" && luachonthem != "no");

			if (luachonthem == "yes") {
				system("cls");
				goto ql;
			}
			if (luachonthem == "no") {

				FileSoXeVao.open("danhsachphieuguixe.txt", ios::in);
				int size_sxv = dsx.DemSoLuongXe();
				FileSoXeVao.close();
				ofstream FCapNhat_SoXeVao;
				FCapNhat_SoXeVao.open("danhsachphieuguixe.txt", ios::out);
				dsx.CapNhatSoXeVao(FCapNhat_SoXeVao, size_sxv, vitri);

				int TongThoiGianGui = TG_GiaiQuyet.SoGioGuiXe(dsx.Getter_Dsxg()[vitri].Getter_ThoiGian()); //so gio gui xe	
				string loaixe = dsx.Getter_Dsxg()[vitri].Getter_MaSoVe().substr(0, 2); //kiem tra xem xe may hay oto
				dsx.CapNhatLichSu(vitri, TG_GiaiQuyet, gqsc.Getter_MaNhanVienNhanXe(), TongThoiGianGui, loaixe);

				//xoa the xe
				if (check_xoave == true) {
					DanhSachVeXe vx;
					vx.XoaVeKhiGQSC(v, masovexx);
					ofstream FileTheBiXoa;
					FileTheBiXoa.open("TheXeBiXoa.txt", ios::app);
					FileTheBiXoa << masovexx << endl;
				}
				//cap nhat tinh trang the xe
				if (check_xoave == false) {
					if (v == "XM") { //Xe May

						ifstream F_VeXeMay;
						DanhSachVeXe Doc_VeXeMay;
						F_VeXeMay.open("vexemay.txt", ios::in);
						Doc_VeXeMay.DocDSVeXeMay(F_VeXeMay);
						F_VeXeMay.close();

						DanhSachVeXe GoiHamVeXe;
						GoiHamVeXe.CapNhatVeXeXuatBen_XeMay(Doc_VeXeMay.Getter_DSVeXeMay(), masovexx);
						ofstream Ghi_VeXeMay;
						Ghi_VeXeMay.open("vexemay.txt");
						GoiHamVeXe.GhiDSVeXeMay(Ghi_VeXeMay);
						Ghi_VeXeMay.close();
					}
					if (v == "OT") { //OTO
						ifstream F_VeXeOTo;
						DanhSachVeXe Doc_VeXeOTo;
						F_VeXeOTo.open("vexeoto.txt", ios::in);
						Doc_VeXeOTo.DocDSVeXeOto(F_VeXeOTo);
						F_VeXeOTo.close();

						DanhSachVeXe GoiHamVeXe;
						GoiHamVeXe.CapNhatVeXeXuatBen_OTo(Doc_VeXeOTo.Getter_DSVeOTo(), masovexx);
						ofstream Ghi_VeXeOTo;
						Ghi_VeXeOTo.open("vexeoto.txt");
						GoiHamVeXe.GhiDSVeXeOto(Ghi_VeXeOTo);
						Ghi_VeXeOTo.close();
					}
				}
			}
		}

	} while (luachonthem != "no");
	if (Co_BB == true) {
		system("cls");
		TimKiem_BaoCao tk;
		string mjh = gqsc.Getter_MaBB();
		tk.Xem_Su_Co(gqsc.Getter_MaBB(), x.Getter_DSNV()[index].Getter_MaNhanVien());
	}

}

void QuanLyXeVaoBen(string MaSoNV) {

	//nhap loai xe muon gui
	string select;
	int luachon;

	do {
		//doc danh sach ve xe tu file
		DanhSachVeXe x;
		ifstream FileIn;
		FileIn.open("vexeoto.txt", ios::in);
		x.DocDSVeXeOto(FileIn);
		FileIn.close();
		FileIn.open("vexemay.txt", ios::in);
		x.DocDSVeXeMay(FileIn);
		FileIn.close();

		Sleep(100);
		do {
			cout << "\n\t\t ________________________________________________________________________________";
			cout << "\n\t\t|                                                                                |";
			cout << "\n\t\t|\tBAI GIU XE                                                               |";
			cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                  |";
			cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                   |";
			cout << "\n\t\t|\t\t* * * * *                                                        |";
			cout << "\n\t\t|\t\t * * * *                                                         |";
			cout << "\n\t\t|                                                                                |";
			cout << "\n\t\t|\t\t\tQUAN LY XE VAO BEN                                       |";
			cout << "\n\t\t|Cac chuc nang                                                                   |";
			cout << "\n\t\t|\t1.Xe may vao ben                                                         |";
			cout << "\n\t\t|\t2.Xe oto vao ben                                                         |";
			cout << "\n\t\t|\t0.Quay lai                                                               |";
			cout << "\n\t\t|________________________________________________________________________________|";
			cout << "\n";
			do {
				textColor(14);
				cout << "\n\t\t>>> ";
				cin >> select;

				if (select != "1" && select != "2" && select != "0") {
					textColor(140);
					cout << "\n\tDa xay ra loi , vui long nhap lai ";
				}

			} while (select != "1" && select != "2" && select != "0");

			luachon = ChuyenStringSangInt(select);

			if (luachon != 1 && luachon != 2 && luachon != 0)
			{
				textColor(140);
				cout << "\n\tLua chon khong hop le. Xin kiem tra lai !";
				textColor(14);
			}

		} while (luachon != 1 && luachon != 2 && luachon != 0);

		//xe may
		if (luachon == 1) {
			system("cls");

			if (HienThiVeTrongXeMay(x) != 1) {

				PhieuGuiXe pgx;

				bool check = false;
				string s;

				do {
					textColor(14);
					cout << "\n\n\tNhap phieu gui xe :" << endl;
				y:
					TextColor(14);
					cout << "\n\tNhap ma so the ( Nhap"; textColor(202); cout << " 1";  textColor(14); cout << " de tu dong chon ma so ve ) ";
					cin >> s;

					int k = 0;

					int size = x.Getter_DSVeXeMay().size();
					for (int i = 0; i < size; i++) {
						if (x.Getter_DSVeXeMay()[i].Getter_TrangThai() == 0) {
							if (s == x.Getter_DSVeXeMay()[i].Getter_MaSo()) {
								k = 1;
								break;
							}
						}
					}

					if (k == 1) {
						textColor(140);
						cout << "\n\tVe da dc su dung :";
						goto y;
					}

					if (s == "1") {

						for (int i = 0; i < size; i++) {
							if (x.Getter_DSVeXeMay()[i].Getter_TrangThai() == 1) {
								s = x.Getter_DSVeXeMay()[i].Getter_MaSo();
								break;
							}
						}

						check = true;
					}
					else
					{
						for (int i = 0; i < size; i++) {
							if (x.Getter_DSVeXeMay()[i].Getter_MaSo() == s) {
								check = true;
							}
						}

						if (check != true) {
							textColor(140);
							cout << "\n\tVui long nhap ma so trung voi danh sach ve trong :";
						}
					}
				} while (check != true);

				pgx.Setter_MaSoVe(s);
				pgx.Setter_MaSoNV(MaSoNV);
				pgx.Nhap();
				system("cls");
				cout << "\n\n\tPhieu gui xe cua ban :";
				Sleep(100);
				pgx.Xuat();

				DanhSachVeXe dsvx;
				dsvx.Setter_DSVeXeMay(x.Getter_DSVeXeMay(), pgx.Getter_MaSoVe());
				ofstream FileOutVeXeMay;
				FileOutVeXeMay.open("vexemay.txt");
				dsvx.GhiDSVeXeMay(FileOutVeXeMay);
				FileOutVeXeMay.close();

				DanhSachPhieuGuiXe dspgx;

				dspgx.Setter_DanhSachPhieuGuiXe(pgx);

				ofstream FileOutDSPhieuGuiXe;
				FileOutDSPhieuGuiXe.open("danhsachphieuguixe.txt", ios::app);
				dspgx.GhiDanhSachPhieuGuiXe(FileOutDSPhieuGuiXe);
				FileOutDSPhieuGuiXe.close();
				system("pause");
				system("cls");
			}
			else {
				cout << "\n\tDoi minh xay them cho da ban a";
				system("pause");
				system("cls");
			}
		}
		//oto
		else if (luachon == 2) {
			if (HienThiVeTrongOto(x) != 1) {
				PhieuGuiXe pgx;

				bool check = false;
				string s;

				do {
					textColor(14);
					cout << "\n\n\tNhap phieu gui xe " << endl;
				x:
					TextColor(14);
					cout << "\n\tNhap ma so the ( Nhap"; textColor(202); cout << " 1";  textColor(14); cout << " de tu dong chon ma so ve ) ";
					cin >> s;

					int k = 0;

					int size = x.Getter_DSVeOTo().size();
					for (int i = 0; i < size; i++) {
						if (x.Getter_DSVeOTo()[i].Getter_TrangThai() == 0) {
							if (s == x.Getter_DSVeOTo()[i].Getter_MaSo()) {
								k = 1;
								break;
							}
						}
					}

					if (k == 1) {
						textColor(140);
						cout << "\n\tVe da dc su dung ";
						goto x;
					}


					if (s == "1") {

						for (int i = 0; i < size; i++) {
							if (x.Getter_DSVeOTo()[i].Getter_TrangThai() == 1) {
								s = x.Getter_DSVeOTo()[i].Getter_MaSo();
								break;
							}
						}

						check = true;
					}
					else {
						for (int i = 0; i < size; i++) {
							if (x.Getter_DSVeOTo()[i].Getter_MaSo() == s) {
								check = true;
							}
						}

						if (check != true) {
							textColor(140);
							cout << "\n\tVui long nhap ma so trung voi danh sach ve trong ";
						}
					}

				} while (check != true);

				pgx.Setter_MaSoVe(s);
				pgx.Setter_MaSoNV(MaSoNV);
				pgx.Nhap();
				system("cls");
				cout << "\n\n\t\tPhieu gui xe cua ban";
				Sleep(100);
				pgx.Xuat();

				DanhSachVeXe dsvx;
				dsvx.Setter_DSVeOTo(x.Getter_DSVeOTo(), pgx.Getter_MaSoVe());

				ofstream FileOutVeOto;
				FileOutVeOto.open("vexeoto.txt");
				dsvx.GhiDSVeXeOto(FileOutVeOto);

				DanhSachPhieuGuiXe dspgx;

				dspgx.Setter_DanhSachPhieuGuiXe(pgx);

				ofstream FileOutDSPhieuGuiXe;
				FileOutDSPhieuGuiXe.open("danhsachphieuguixe.txt", ios::app);
				dspgx.GhiDanhSachPhieuGuiXe(FileOutDSPhieuGuiXe);
				system("pause");
				system("cls");
			}
			else {
				cout << "\n\t\tDoi minh xay them cho da ban a";
				system("pause");
				system("cls");
			}
		}

	} while (luachon != 0);
	system("cls");
}

void Hien_ThiPGX(DanhSachXeTrongBen dsx, int i, bool check) {
	stdafx st;
	system("cls");
	cout << "\t _______________________________________";
	cout << "\n\t|Thong tin the xe: "; cout << setw(11) << left << dsx.Getter_Dsxg()[i].Getter_MaSoVe(); cout << "          |";
	cout << "\n\t|Bien so: "; cout << setw(11) << left << dsx.Getter_Dsxg()[i].Getter_BienSo(); cout << "\t\t\t|";
	cout << "\n\t|Thoi gian vao ben: ";
	if (check == true) textColor(14);
	else textColor(140);
	string NG_G = st.HT_NgayGio(dsx.Getter_Dsxg()[i].Getter_ThoiGian().Getter_Ngay(), dsx.Getter_Dsxg()[i].Getter_ThoiGian().Getter_Thang(), dsx.Getter_Dsxg()[i].Getter_ThoiGian().Getter_Nam(),
		dsx.Getter_Dsxg()[i].Getter_ThoiGian().Getter_Gio(), dsx.Getter_Dsxg()[i].Getter_ThoiGian().Getter_Phut(), dsx.Getter_Dsxg()[i].Getter_ThoiGian().Getter_Giay());
	cout << setw(17) << left << NG_G; cout << "   |";
	textColor(14);
	cout << "\n\t|_______________________________________|";

}

void QuanLyXuatBen(DanhSachXeTrongBen  dsx, string MaSoNV, string HoTenNV) {
	stdafx st;
	ifstream FileSoXeVao;
	FileSoXeVao.open("danhsachphieuguixe.txt", ios::in);
	int size = dsx.DemSoLuongXe();

	dsx.DocSoXeVao(FileSoXeVao, size);
	FileSoXeVao.close();

	int  ViTri;
	bool check = false; //kiem tra xe trong ben
	bool check2 = false; //kiem tra quay lai
	bool check3 = false;

	int KT_Tgian;
	do {
		textColor(14);
		string NhapVeXe, NhapBienSo;
		cout << "\n\t\t ________________________________________________________________________________";
		cout << "\n\t\t|                                                                                |";
		cout << "\n\t\t|\tBAI GIU XE                                                               |";
		cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                  |";
		cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                   |";
		cout << "\n\t\t|\t\t* * * * *                                                        |";
		cout << "\n\t\t|\t\t * * * *                                                         |";
		cout << "\n\t\t|                                                                                |";
		cout << "\n\t\t|\t\t\tQUAN LY XE XUAT BEN                                      |";
		cout << "\n\t\t|________________________________________________________________________________|";


		cout << "\n\n\t\tNhap Ma the Xe: "; cin >> NhapVeXe;

		for (int i = 0; i < size; i++) {
			if (dsx.Getter_Dsxg()[i].Getter_MaSoVe() == NhapVeXe) {
				Hien_ThiPGX(dsx, i, true);
				string luachon;
				cout << "\n";
				cout << "\n\tXac nhan cho xe roi ben ("; st.TextColor(202); cout << "yes"; st.TextColor(14); cout << "/"; st.TextColor(202); cout << "no"; st.TextColor(14); cout << ")";

				cout << "\n\t>>>>> ";
				do {
					cin >> luachon;
					if (luachon != "yes" && luachon != "no") {
						check2 = false;
						textColor(140);
						cout << "\n\tLua chon khong dung,nhap lai!!!";
						textColor(14);
						cout << "\n\t>>>>> ";
					}
					if (luachon == "yes") {
						system("cls");
						check2 = true;
						check = true;
						ViTri = i;
					}
					if (luachon == "no") {
						system("cls");
						check = false;
						check2 = false;
						check3 = true;
					}
				} while (check2 == false && luachon != "no");
			}
		}
		if (check == false && check3 == false) {
			textColor(140);
			cout << "\t\tXe khong co trong ben!" << endl;
			string luachon;
			textColor(14);
			cout << "\n\t1.Nhap lai";
			cout << "\n\t0.quay lai";
			cout << "\n\tLuc chon: ";
			do {
				cin >> luachon;
				if (luachon != "0" && luachon != "1" /*&& luachon != 2*/) {
					check2 = false;
					textColor(140);
					cout << "\n\tLua chon khong dung,nhap lai!!!";
					textColor(14);
					cout << "\n\tLuc chon: ";
				}
				if (luachon == "1") {
					check2 = true;
				}
				if (luachon == "0") {
					check2 == false;
				}
			} while (check2 == false && luachon != "0");
			system("cls");
		}
	} while (check == false && check2 == true);

	if (check == true)
	{
		ThoiGian ThoiGianLayXe;
		ThoiGianLayXe.LayThoiGianTuHeThong();

		int TongThoiGianGui = ThoiGianLayXe.SoGioGuiXe(dsx.Getter_Dsxg()[ViTri].Getter_ThoiGian()); //so gio gui xe	
	//	if (TongThoiGianGui > 0) {
		string c = dsx.Getter_Dsxg()[ViTri].Getter_MaSoVe().substr(0, 2); //kiem tra xem xe may hay oto
		int TongTien = ThoiGianLayXe.ThanhTien(c, TongThoiGianGui);	//tinh so tien phai tra

	//cap nhat tinh trang the xe
		if (c == "XM") { //Xe May

			ifstream F_VeXeMay;
			DanhSachVeXe Doc_VeXeMay;
			F_VeXeMay.open("vexemay.txt", ios::in);
			Doc_VeXeMay.DocDSVeXeMay(F_VeXeMay);
			F_VeXeMay.close();

			DanhSachVeXe GoiHamVeXe;
			GoiHamVeXe.CapNhatVeXeXuatBen_XeMay(Doc_VeXeMay.Getter_DSVeXeMay(), dsx.Getter_Dsxg()[ViTri].Getter_MaSoVe());
			ofstream Ghi_VeXeMay;
			Ghi_VeXeMay.open("vexemay.txt");
			GoiHamVeXe.GhiDSVeXeMay(Ghi_VeXeMay);
			Ghi_VeXeMay.close();
		}
		if (c == "OT") { //OTO
			ifstream F_VeXeOTo;
			DanhSachVeXe Doc_VeXeOTo;
			F_VeXeOTo.open("vexeoto.txt", ios::in);
			Doc_VeXeOTo.DocDSVeXeOto(F_VeXeOTo);
			F_VeXeOTo.close();

			DanhSachVeXe GoiHamVeXe;
			GoiHamVeXe.CapNhatVeXeXuatBen_OTo(Doc_VeXeOTo.Getter_DSVeOTo(), dsx.Getter_Dsxg()[ViTri].Getter_MaSoVe());
			ofstream Ghi_VeXeOTo;
			Ghi_VeXeOTo.open("vexeoto.txt");
			GoiHamVeXe.GhiDSVeXeOto(Ghi_VeXeOTo);
			Ghi_VeXeOTo.close();
		}

		ofstream FCapNhat_SoXeVao;
		FCapNhat_SoXeVao.open("danhsachphieuguixe.txt", ios::out);
		dsx.CapNhatSoXeVao(FCapNhat_SoXeVao, size, ViTri);

		dsx.CapNhatLichSu(ViTri, ThoiGianLayXe, MaSoNV, TongThoiGianGui, c);

		dsx.InPhieuThu(dsx.Getter_Dsxg()[ViTri], ThoiGianLayXe, TongThoiGianGui, TongTien, HoTenNV);
		system("pause");
		system("cls");
		/*}
		else {
			Hien_ThiPGX(dsx, ViTri, false);
			cout << "Thong tin ve thoi gian gui sai, yeu cau kiem tra lai.";
			system("pause");
		}*/
	}
}

void TimKiemLS_XeMay(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {
	system("cls");
	string Bien;
	cout << "\n\t|Nhap bien so: "; cin >> Bien;
	int k = st.KT_Xe_SXR(Bien, n);
	if (k > 0) {
		system("cls");
		tk.TKI_LSGX(S_XeRa, n, nv, "XM", Bien);
	}
	else {
		st.TextColor(140);
		cout << "\n\tXe chua tung gui tai ben";
		st.TextColor(14);
	}
	cout << "\n\n";
	system("pause");
}

void TimKiemLS_OTO(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {

	system("cls");
	string Bien;
	cout << "\n\t|Nhap bien so: "; cin >> Bien;
	int k = st.KT_Xe_SXR(Bien, n);
	if (k > 0) {
		system("cls");
		tk.TKI_LSGX(S_XeRa, n, nv, "OT", Bien);
	}
	else {
		st.TextColor(140);
		cout << "\n\tXe chua tung gui tai ben";
		st.TextColor(14);
	}
	cout << "\n\n";
	system("pause");
}
void ThongKeTienThuDuocTheoNgay(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {
	int check_ThoiGian;
	bool check_HienTai = true;
	string ThoiGianNhap;
	string now;
	int ngay, thang, nam;
	string s_thang, s_nam;
	system("cls");
	cout << "\n\t(Nhan "; textColor(202); cout << "now"; textColor(14); cout << " de chon ngay hien tai)";
	cout << "\n\tNgay: ";
	cin >> now;
	if (now == "now") {
		ThoiGian TGHienTai;
		TGHienTai.LayThoiGianTuHeThong();
		ngay = TGHienTai.Getter_Ngay();
		thang = TGHienTai.Getter_Thang();
		nam = TGHienTai.Getter_Nam();
		check_ThoiGian = 1;
		check_HienTai = true;
	}
	else {
		ThoiGian TG;
		ngay = ChuyenStringSangInt(now);
		cout << "\tThang: "; cin >> s_thang;
		thang = ChuyenStringSangInt(s_thang);
		cout << "\tNam: "; cin >> s_nam;
		nam = ChuyenStringSangInt(s_nam);
		TG.Setter_Ngay(ngay);
		TG.Setter_Thang(thang);
		TG.Setter_Nam(nam);
		TG.Setter_Gio(0);
		TG.Setter_Phut(0);
		TG.Setter_Giay(0);
		check_ThoiGian = TG.SoGiay(); //kiem tra xem ngay nhap co dung khong (so ngay trong thang dung, nam khong nhuan)
		check_HienTai = st.KT_HienTai(check_ThoiGian);
	}
	ThoiGianNhap = st.HT_NgayThang(ngay, thang, nam);
	if (check_ThoiGian > 0 && check_HienTai == true) {
		system("cls");
		cout << "\n\tNgay ban vua nhap la: "; cout << setw(9) << left << ThoiGianNhap;
		tk.TK_TheoNgay_QL(S_XeRa, nv, n, ngay, thang, nam);

	}
	else {
		textColor(140);
		cout << "\n\tNgay ban vua nhap khong dung " << endl;
		textColor(14);
		cout << "\n\n";

	}
	cout << "\n\n";
	system("pause");
}

void ThongKeLuongXeGuiTheoKhungGio_Cua1Thang(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {
	int check_ThoiGian;//kiem tra thoi gian cos nhap dung khong (nam nhuan)
	bool check_HienTai = true;//kiem tra thoi gian nhap co lon hon ngay hien tai khong
	string now;
	int ngay, thang, nam;
	string s_nam;
	string ThoiGianNhap;
	system("cls");
	cout << "\n\t(Nhan "; textColor(202); cout << "now"; textColor(14); cout << " de chon thang hien tai)";
	cout << "\n\tThang: ";
	cin >> now;
	if (now == "now") {
		ThoiGian TGHienTai;
		TGHienTai.LayThoiGianTuHeThong();
		ngay = TGHienTai.Getter_Ngay();
		thang = TGHienTai.Getter_Thang();
		nam = TGHienTai.Getter_Nam();
		check_ThoiGian = 1;
		check_HienTai = true;
	}
	else {
		ThoiGian TG;
		thang = ChuyenStringSangInt(now);
		cout << "\tNam: "; cin >> s_nam;
		nam = ChuyenStringSangInt(s_nam);
		TG.Setter_Ngay(1);
		TG.Setter_Thang(thang);
		TG.Setter_Nam(nam);
		TG.Setter_Gio(0);
		TG.Setter_Phut(0);
		TG.Setter_Giay(0);
		check_ThoiGian = TG.SoGiay();
		check_HienTai = st.KT_HienTai(check_ThoiGian);
	}
	ThoiGianNhap = st.HT_ThangNam(thang, nam);
	if (check_ThoiGian > 0 && check_HienTai == true) {
		system("cls");
		cout << "\n\tThang can tim kiem: "; cout << setw(7) << left << ThoiGianNhap;
		tk.TK_MatDoGuiXe_TheoThang(S_XeRa, nv, n, thang, nam);

	}
	else {
		textColor(140);
		cout << "\n\Thang ban vua nhap khong dung ";
		textColor(14);
	}
	//		
	cout << "\n\n";
	system("pause");
}

void ThongKeLuongXeGuiTheoKhungGio_Giua2Thang(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {
	int check_ThoiGian1;//kiem tra thoi gian cos nhap dung khong (nam nhuan)
	bool check_HienTai1 = true;//kiem tra thoi gian nhap co lon hon ngay hien tai khong
	int ngay2, thang1, nam1;
	string s_thang1, s_nam1;
	system("cls");
	cout << "\n\tNhap thang thu nhat";
	cout << "\n\tThang 1: ";
	cin >> s_thang1;
	cout << "\tNam 1: "; cin >> s_nam1;
	thang1 = ChuyenStringSangInt(s_thang1);
	nam1 = ChuyenStringSangInt(s_nam1);
	ThoiGian TG1;
	ThoiGian TGHienTai;
	TG1.Setter_Ngay(1);
	TG1.Setter_Thang(thang1);
	TG1.Setter_Nam(nam1);
	TG1.Setter_Gio(0);
	TG1.Setter_Phut(0);
	TG1.Setter_Giay(0);
	check_ThoiGian1 = TG1.SoGiay();
	check_HienTai1 = st.KT_HienTai(check_ThoiGian1);
	if (check_ThoiGian1 > 0 && check_HienTai1 == true) {
		int check_ThoiGian2;//kiem tra thoi gian cos nhap dung khong (nam nhuan)
		bool check_HienTai2 = true;//kiem tra thoi gian nhap co lon hon ngay hien tai khong
		string now;
		int ngay2, thang2, nam2;
		string s_nam2;
		cout << "\n\t(Nhan "; textColor(202); cout << "now"; textColor(14); cout << " de chon thang hien tai)";
		cout << "\n\tThang 2: ";
		cin >> now;
		if (now == "now") {

			TGHienTai.LayThoiGianTuHeThong();
			ngay2 = TGHienTai.Getter_Ngay();
			thang2 = TGHienTai.Getter_Thang();
			nam2 = TGHienTai.Getter_Nam();
			check_ThoiGian2 = 1;
			check_HienTai2 = true;
		}
		else {
			ThoiGian TG2;
			thang2 = ChuyenStringSangInt(now);
			cout << "\tNam 2: "; cin >> s_nam2;
			nam2 = ChuyenStringSangInt(s_nam2);
			TG2.Setter_Ngay(1);
			TG2.Setter_Thang(thang2);
			TG2.Setter_Nam(nam2);
			TG2.Setter_Gio(0);
			TG2.Setter_Phut(0);
			TG2.Setter_Giay(0);
			check_ThoiGian2 = TG2.SoGiay();
			check_HienTai2 = st.KT_HienTai(check_ThoiGian2);
		}
		if (check_ThoiGian2 > 0 && check_HienTai2 == true && TGHienTai.SoGioGuiXe(TG1) > 0) {
			system("cls");
			tk.TK_MatDoGuiXe_Thang1_Thang2(S_XeRa, nv, n, thang1, nam1, thang2, nam2);

		}
		else {
			st.TextColor(140);
			cout << "\n\Thang ban vua nhap khong dung ";
			st.TextColor(14);
		}
	}
	else {
		st.TextColor(140);
		cout << "\n\Thang ban vua nhap khong dung ";
		st.TextColor(14);
	}
	cout << "\n\n";
	system("pause");
}

void ThongKeTienThuDuoc_Trong1Thang(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {
	int check_ThoiGian;//kiem tra thoi gian cos nhap dung khong (nam nhuan)
	bool check_HienTai = true;//kiem tra thoi gian nhap co lon hon ngay hien tai khong
	string now;
	int ngay, thang, nam;
	string s_nam;
	string ThoiGianNhap;
	system("cls");
	cout << "\n\t(Nhan "; textColor(202); cout << "now"; textColor(14); cout << " de chon thang hien tai)";
	cout << "\n\tThang: ";
	cin >> now;
	if (now == "now") {
		ThoiGian TGHienTai;
		TGHienTai.LayThoiGianTuHeThong();
		ngay = TGHienTai.Getter_Ngay();
		thang = TGHienTai.Getter_Thang();
		nam = TGHienTai.Getter_Nam();
		check_ThoiGian = 1;
		check_HienTai = true;
	}
	else {
		ThoiGian TG;
		thang = ChuyenStringSangInt(now);
		cout << "\tNam: "; cin >> s_nam;
		nam = ChuyenStringSangInt(s_nam);
		TG.Setter_Ngay(1);
		TG.Setter_Thang(thang);
		TG.Setter_Nam(nam);
		TG.Setter_Gio(0);
		TG.Setter_Phut(0);
		TG.Setter_Giay(0);
		check_ThoiGian = TG.SoGiay();
		check_HienTai = st.KT_HienTai(check_ThoiGian);
	}
	ThoiGianNhap = st.HT_ThangNam(thang, nam);
	if (check_ThoiGian > 0 && check_HienTai == true) {
		system("cls");
		cout << "Thang can tiem kiem: "; cout << setw(7) << left << ThoiGianNhap;
		tk.TK_TheoLoaiXe_TrongThang(S_XeRa, nv, n, thang, nam);

	}
	else {
		st.TextColor(140);
		cout << "\n\Thang ban vua nhap khong dung ";
		st.TextColor(14);
	}
	//		
	cout << "\n\n";
	system("pause");
}

void ThongKeTienThuDuoc_Giua2Thang(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {
	int check_ThoiGian1;//kiem tra thoi gian cos nhap dung khong (nam nhuan)
	bool check_HienTai1 = true;//kiem tra thoi gian nhap co lon hon ngay hien tai khong
	int ngay2, thang1, nam1;
	string s_thang1, s_nam1;
	system("cls");
	cout << "\n\tNhap thang thu nhat";
	cout << "\n\tThang 1: ";
	cin >> s_thang1;
	cout << "\tNam 1: "; cin >> s_nam1;
	thang1 = ChuyenStringSangInt(s_thang1);
	nam1 = ChuyenStringSangInt(s_nam1);
	ThoiGian TG1;
	ThoiGian TGHienTai;
	TG1.Setter_Ngay(1);
	TG1.Setter_Thang(thang1);
	TG1.Setter_Nam(nam1);
	TG1.Setter_Gio(0);
	TG1.Setter_Phut(0);
	TG1.Setter_Giay(0);
	check_ThoiGian1 = TG1.SoGiay();
	check_HienTai1 = st.KT_HienTai(check_ThoiGian1);
	if (check_ThoiGian1 > 0 && check_HienTai1 == true) {
		int check_ThoiGian2;//kiem tra thoi gian cos nhap dung khong (nam nhuan)
		bool check_HienTai2 = true;//kiem tra thoi gian nhap co lon hon ngay hien tai khong
		string now;
		int ngay2, thang2, nam2;
		string s_nam2;
		cout << "\n\t(Nhan "; textColor(202); cout << "now"; textColor(14); cout << " de chon thang hien tai)";
		cout << "\n\tThang 2: ";
		cin >> now;
		if (now == "now") {

			TGHienTai.LayThoiGianTuHeThong();
			ngay2 = TGHienTai.Getter_Ngay();
			thang2 = TGHienTai.Getter_Thang();
			nam2 = TGHienTai.Getter_Nam();
			check_ThoiGian2 = 1;
			check_HienTai2 = true;
		}

		else {
			ThoiGian TG2;
			thang2 = ChuyenStringSangInt(now);
			cout << "\tNam 2: "; cin >> s_nam2;
			nam2 = ChuyenStringSangInt(s_nam2);
			TG2.Setter_Ngay(1);
			TG2.Setter_Thang(thang2);
			TG2.Setter_Nam(nam2);
			TG2.Setter_Gio(0);
			TG2.Setter_Phut(0);
			TG2.Setter_Giay(0);
			check_ThoiGian2 = TG2.SoGiay();
			check_HienTai2 = st.KT_HienTai(check_ThoiGian2);
		}
		if (check_ThoiGian2 > 0 && check_HienTai2 == true && TGHienTai.SoGioGuiXe(TG1) > 0) {
			system("cls");
			tk.TK_TheoLoaiXe_Thang1_Thang2(S_XeRa, nv, n, thang1, nam1, thang2, nam2);

		}
		else {
			st.TextColor(140);
			cout << "\n\Thang ban vua nhap khong dung ";
			st.TextColor(14);
		}
	}
	else {
		st.TextColor(140);
		cout << "\n\Thang ban vua nhap khong dung ";
		st.TextColor(14);
	}
	cout << "\n\n";
	system("pause");
}

void XemTienThuHangNgayCuaNhanVien(stdafx st, TT_SoXeRa S_XeRa, TimKiem_BaoCao tk, string nv, int n) {

	int check_ThoiGian;
	bool check_HienTai = true;
	string ThoiGianNhap;
	string now;
	int ngay, thang, nam;
	string s_thang, s_nam;
	string nvtx;
	system("cls");
	cout << "\n\tNhap ma nhan vien trong xe: ";
	cin >> nvtx;
	bool check_NV = st.KT_NV(nvtx);
	if (check_NV == true) {
		cout << "\n\t(Nhan "; textColor(202); cout << "now"; textColor(14); cout << " de chon ngay hien tai)";
		cout << "\n\tNgay: ";
		cin >> now;
		if (now == "now") {
			ThoiGian TGHienTai;
			TGHienTai.LayThoiGianTuHeThong();
			ngay = TGHienTai.Getter_Ngay();
			thang = TGHienTai.Getter_Thang();
			nam = TGHienTai.Getter_Nam();
			check_ThoiGian = 1;
			check_HienTai = true;
		}
		else {
			ThoiGian TG;
			ngay = ChuyenStringSangInt(now);
			cout << "\tThang: "; cin >> s_thang;
			thang = ChuyenStringSangInt(s_thang);
			cout << "\tNam: "; cin >> s_nam;
			nam = ChuyenStringSangInt(s_nam);
			TG.Setter_Ngay(ngay);
			TG.Setter_Thang(thang);
			TG.Setter_Nam(nam);
			TG.Setter_Gio(0);
			TG.Setter_Phut(0);
			TG.Setter_Giay(0);
			check_ThoiGian = TG.SoGiay();
			check_HienTai = st.KT_HienTai(check_ThoiGian);
		}
		ThoiGianNhap = st.HT_NgayThang(ngay, thang, nam);
		if (check_ThoiGian > 0 && check_HienTai == true) {
			system("cls");
			cout << "\n\tNgay ban vua nhap la: "; cout << setw(9) << left << ThoiGianNhap;
			tk.TK_TienThuDuocCuaNhanVien_QL(S_XeRa, nv, nvtx, n, ngay, thang, nam);
			cout << "\n\n";
			system("pause");
		}
		else {
			st.TextColor(140);
			cout << "\n\tNgay ban vua nhap khong dung ";
			st.TextColor(14);
		}
	}
	else {
		st.TextColor(140);
		cout << "\n\tMa nhan vien khong ton tai hoac chuc vu sai";
		st.TextColor(14);
	}
	cout << "\n\n";
	system("pause");
}

void XemBienBan(string nvql) {
	system("cls");
	DanhSachGiaiQuyetSuCo dagqsc;
	stdafx st;
	ifstream FileIn;
	FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
	int size_sc = st.DemSoLuongXe(FileIn);
	FileIn.close();
	FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
	dagqsc.DocDanhSachGiaiQuyetSuCo(FileIn);

	string Ma_BB;
ql:	cout << "\n\tNhap ma bien ban: ";
	cin >> Ma_BB;
	bool check = false;
	for (int i = 0; i < size_sc; i++) {
		if (dagqsc.Getter_DanhSachGQSC()[i].Getter_MaBB() != Ma_BB) continue;
		else {
			check = true;
			break;
		}
	}
	if (check == false) {
		st.TextColor(140);
		cout << "\n\tMa bien ban khong ton tai, hay nhap lai: ";
		st.TextColor(14);
		goto ql;
	}
	else {
		TimKiem_BaoCao tk;
		tk.Xem_Su_Co(Ma_BB, nvql);
	}



}
void TimKiemXeTrongBen_TheoBienSo(stdafx st, DanhSachXeTrongBen dsx, TimKiem_BaoCao tk, string nv, int m) {
	system("cls");
	string bien;
	cout << "\n\tNhap bien so: ";
	cin >> bien;
	tk.TKI_XeTrongBen_BienSo(dsx, nv, bien, m);
	cout << "\n\n";

	system("pause");
}

void TimKiemXeTrongBen_TheoMaTheXe(stdafx st, DanhSachXeTrongBen dsx, TimKiem_BaoCao tk, string nv, int m) {
	system("cls");
	string ve;
	cout << "\n\tNhap ma so the xe: ";
	cin >> ve;
	tk.TKI_XeTrongBen_TheXe(dsx, nv, ve, m);
	cout << "\n\n";
	system("pause");
}

void XemSoTienThuDuocTrongNgay(stdafx st, TimKiem_BaoCao tk, string nv) {
	system("cls");
	TT_SoXeRa S_XeRa;
	ifstream File_In;
	File_In.open("SoXeRa.txt", ios::in);
	int n = st.DemSoLuongXe(File_In);
	File_In.close();
	File_In.open("SoXeRa.txt", ios::in);
	S_XeRa.DocSoXeRa(n, File_In);

	tk.TK_TienThuDuocTrongNgay_NV(S_XeRa, nv, n);
	cout << "\n\n";
	system("pause");
}

void ThayDoiGiaVe(string nv) {
	string LuaChon;
	do {
		BangGia bg;
		ifstream FileIn;
		FileIn.open("BangGia.txt", ios::in);
		bg.DocFileBangGia(FileIn);
		FileIn.close();
		bg.HT_BangGia();

		cout << "\n\t\t\t1.Thay doi gia cho xe may";
		cout << "\n\t\t\t2.Thay doi gia cho oto";
		cout << "\n\t\t\t0.Quay lai";
		do {
			cout << "\n\t\t\tLua chon: ";
			cin >> LuaChon;
			if (LuaChon != "1" && LuaChon != "2" && LuaChon != "0") {
				textColor(140);
				cout << "\n\t\t\tda xay ra loi, hay nhap lai";
				textColor(14);
			}
		} while (LuaChon != "0" && LuaChon != "1" && LuaChon != "2");
		system("cls");
		float k1, k2, k3;
		string s_k1, s_k2, s_k3;
		string c;
		if (LuaChon == "1") {
			system("cls");
			bg.HT_BangGia();
			c = "XM";
			cout << "\n\t\t\tThay doi gia tien cho xe may";
		}
		if (LuaChon == "2") {
			system("cls");
			bg.HT_BangGia();
			c = "OT";
			cout << "\n\t\t\tThay doi gia tien cho xe oto";
		}

		if (LuaChon == "1" || LuaChon == "2")
		{
			while (getline(cin, s_k1))
			{
				stringstream ss(s_k1);
				if (ss >> k1)
				{
					if (ss.eof())
					{
						break;
					}
				}
				cout << "\n\t\t\tGia Khung 1 (Thoi gian <5h): ";
			}
			while (getline(cin, s_k2))
			{
				stringstream ss(s_k2);
				if (ss >> k2)
				{
					if (ss.eof())
					{
						break;
					}
				}
				cout << "\n\t\t\tGia Khung 2 (Thoi gian <24h): ";
			}
			while (getline(cin, s_k3))
			{
				stringstream ss(s_k3);
				if (ss >> k3)
				{
					if (ss.eof())
					{
						break;
					}
				}
				cout << "\n\t\t\tGia Khung 3 (Thoi gian >24h): ";
			}
			ofstream FileOut;
			FileOut.open("BangGia.txt", ios::out);

			//ghi file lich su thay doi gia
			ThoiGian TGTD;
			TGTD.LayThoiGianTuHeThong();
			stdafx st;
			TGTD.LayThoiGianTuHeThong();
			string NgayThayDoi = st.HT_NgayGio(TGTD.Getter_Ngay(), TGTD.Getter_Thang(), TGTD.Getter_Nam(),
				TGTD.Getter_Gio(), TGTD.Getter_Phut(), TGTD.Getter_Giay());

			ofstream File_LS_TDGV;
			File_LS_TDGV.open("LichSuGiaVe.txt", ios::app);
			File_LS_TDGV << nv << " " << c << " " << k1 << " " << k2 << " " << k3 << " " << NgayThayDoi << endl;
			File_LS_TDGV.close();


			GiaTien GT;
			BangGia BG;
			GT.Setter_Xe(c);
			GT.Setter_Khung1(k1);
			GT.Setter_Khung2(k2);
			GT.Setter_Khung3(k3);

			BG.Setter_DS_BangGia(GT);

			BG.ThayDoiGia(FileOut, bg);
			BG.HT_BangGia();
		}
	} while (LuaChon != "0");

}

void DangNhap() {

	textColor(14);
	DanhSachNhanVien x;

	ifstream FileIn;
	FileIn.open("danhsachnhanvien.txt", ios::in);

	x.DocDSNV(FileIn);

	bool check = false;
	int index = -1;
	int er = 0;

	do {
		cout << "\n\t\t ________________________________________________________________________________";
		cout << "\n\t\t|                                                                                |";
		cout << "\n\t\t|\tBAI GIU XE                                                               |";
		cout << "\n\t\t|\tDAI HOC XAY DUNG HA NOI                                                  |";
		cout << "\n\t\t|\tDia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi                   |";
		cout << "\n\t\t|\t\t* * * * *                                                        |";
		cout << "\n\t\t|\t\t * * * *                                                         |";
		cout << "\n\t\t|                                                                                |";
		cout << "\n\t\t|\t\t\tCHAO MUNG BAN DEN VOI BAI GUI XE THONG MINH              |";
		cout << "\n\t\t|Hay dang nhap vao he thong de trai nghiem                                       |";
		cout << "\n\t\t|________________________________________________________________________________|" << endl;
		er++;
		string maso;
		textColor(14);
		cout << "\n\t\t  Nhap Ma So >>";
		cin >> maso;

		string mk;
		cout << "\n\t\t  Nhap Mat Khau >>";
		cin >> mk;

		int size = x.Getter_DSNV().size();

		for (int i = 0; i < size; i++) {
			if (x.Getter_DSNV()[i].Getter_MaNhanVien() == maso) {
				index = i;
			}
		}

		bool checktk = false;

		if (index == -1) {
			textColor(140);
			cout << "\n\t\tTen tai khoan khong ton tai !";
			system("pause");
			Sleep(100);
			system("cls");
			TextColor(14);
			checktk = true;
		}

		if (index != -1) {
			if (x.Getter_DSNV()[index].Getter_MatKhau() == mk) {
				check = true;
			}
		}


		if (check == true) {
			cout << "\n\t\tDang nhap thanh cong !";
			Sleep(500);
		}
		else if (checktk == false) {
			textColor(140);
			cout << "\n\t\tMat khau khong dung !";
			system("pause");
			index = -1;
			Sleep(100);
			system("cls");
			TextColor(14);

		}


	} while (check != true);
	// nhan vien quan ly
	if (x.Getter_DSNV()[index].Getter_LoaiNhanVien() == "NVQL") {
		int p = 0;
		for (int i = 0; i <= 4; i++) {
			cout << "\n\n\n\t\tLoading...";
			cout << p << "%";
			p = p + 25;
			system("cls");
			Sleep(100);
		}

		stdafx st;
		string luachon;
		do {
			system("cls");
			textColor(14);
			cout << "\n\t\tNhan vien : ";
			cout << x.Getter_DSNV()[index].Getter_HoTen();
			cout << "\n\t\tChuc vu :";
			cout << "Nhan vien quan ly";
			cout << "\n\t\t ______________________________________________________________________________";
			cout << "\n\t\t|\t                                                                       |";
			cout << "\n\t\t|\t                                                                       |";
			cout << "\n\t\t|\t1.Tim kiem lich su gui xe may                                          |";
			cout << "\n\t\t|\t2.Tim kiem lich su gui xe oto                                          |";
			cout << "\n\t\t|\t3.Thong tong tien thu duoc theo ngay                                   |";
			cout << "\n\t\t|\t4.Thong ke tien thu trong mot thang                                    |";
			cout << "\n\t\t|\t5.Thong ke tien thu giua 2 thang                                       |";
			cout << "\n\t\t|\t6.Thong ke luong xe gui theo khung gio (cua 1 thang)                   |";
			cout << "\n\t\t|\t7.Thong ke luong xe gui theo khung gio (giua 2 thang)                  |";
			cout << "\n\t\t|\t8.Thong ke tien thu duoc cua nhan vien trong ngay                      |";
			cout << "\n\t\t|\t9.Xem bien ban su so                                                   |";
			cout << "\n\t\t|\t10.Giai quyet su co                                                    |";
			cout << "\n\t\t|\t11.Them cho de xe                                                      |";
			cout << "\n\t\t|\t12.Thay doi gia gui xe                                                 |";
			cout << "\n\t\t|\t13.Lich su thay doi gia tien gui xe                                    |";
			cout << "\n\t\t|\t0.Quay lai                                                             |";
			cout << "\n\t\t|______________________________________________________________________________|";
			cout << "\n\n";
			do {
				cout << "\n\t\t\tNhap lua chon: ";
				cin >> luachon;
				if (luachon != "1" && luachon != "2" && luachon != "3" && luachon != "4" && luachon != "5"
					&& luachon != "6" && luachon != "7" && luachon != "8" && luachon != "9" && luachon != "10" && luachon != "11" && luachon != "12" && luachon != "13" && luachon != "0") {
					///	TextColor(140);
					cout << "\n\t\t\tDa xay ra loi, hay nhap lai." << endl;
					//	TextColor(14);
				}
			} while (luachon != "1" && luachon != "2" && luachon != "3" && luachon != "4" && luachon != "5"
				&& luachon != "6" && luachon != "7" && luachon != "8" && luachon != "9" && luachon != "10" && luachon != "11" && luachon != "12" && luachon != "13" && luachon != "0");
			TT_SoXeRa S_XeRa;
			ifstream FileIn;
			FileIn.open("SoXeRa.txt", ios::in);
			int n = st.DemSoLuongXe(FileIn);
			FileIn.close();
			FileIn.open("SoXeRa.txt", ios::in);
			S_XeRa.DocSoXeRa(n, FileIn);
			TimKiem_BaoCao tk;
			//x.Getter_DSNV()[index].Getter_MaNhanVien()
			if (luachon == "1") {
				TimKiemLS_XeMay(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");
			}
			if (luachon == "2") {
				TimKiemLS_OTO(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");
			}
			if (luachon == "3") {
				ThongKeTienThuDuocTheoNgay(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");
			}
			if (luachon == "4") {
				ThongKeTienThuDuoc_Trong1Thang(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");

			}
			if (luachon == "5") {
				ThongKeTienThuDuoc_Giua2Thang(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");
			}
			if (luachon == "6") {
				ThongKeLuongXeGuiTheoKhungGio_Cua1Thang(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");

			}
			if (luachon == "7") {
				ThongKeLuongXeGuiTheoKhungGio_Giua2Thang(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");

			}
			if (luachon == "8") {
				XemTienThuHangNgayCuaNhanVien(st, S_XeRa, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), n);
				system("cls");
			}
			if (luachon == "9") {
				XemBienBan(x.Getter_DSNV()[index].Getter_MaNhanVien());
				system("cls");
			}
			if (luachon == "10") {
				system("cls");
				cout << "Giai quyet su co" << endl;
				GQSuCo(x, index);
				system("pause");
			}
			if (luachon == "11") {
				system("cls");
				string lchon;
				do {
					cout << "\n\t\t __________________________________________________________";
					cout << "\n\t\t|\t                                                   |";
					cout << "\n\t\t|\t              THEM CHO DE XE                       |";
					cout << "\n\t\t|\t                                                   |";
					cout << "\n\t\t|\t1.Xe may                                           |";
					cout << "\n\t\t|\t2.OTo                                              |";
					cout << "\n\t\t|\t0.Quay lai                                         |";
					cout << "\n\t\t|__________________________________________________________|";
					cout << "\n\n";

					do {
						cout << "\n\t\t\tNhap lua chon: ";
						cin >> lchon;
						if (lchon != "1" && lchon != "2" && lchon != "0") {
							st.TextColor(140);
							cout << "\n\t\t\tDa xay ra loi, hay nhap lai." << endl;
							st.TextColor(14);
						}
					} while (lchon != "1" && lchon != "2" && lchon != "0");
					ThemTheXe ttx;
					if (lchon == "1") {
						ttx.ThemTheXeMay();
						system("pause");
						system("cls");
					}
					if (lchon == "2") {
						ttx.ThemTheXeOTO();
						system("pause");
						system("cls");

					}

					system("cls");
				} while (lchon != "0");
			}
			if (luachon == "12") {
				ThayDoiGiaVe(x.Getter_DSNV()[index].Getter_MaNhanVien());
				system("pause");
				system("cls");
			}
			if (luachon == "13") {
				system("cls");
				DS_LichSuGiaVe x;
				x.HienThiLSTD();
				system("pause");
				system("cls");
			}

		} while (luachon != "0");
	}


	//nhan vien trong xe
	else {
		int p = 0;
		for (int i = 0; i <= 4; i++) {
			cout << "\n\n\n\t\tLoading...";
			cout << p << "%";
			p = p + 25;
			system("cls");
			Sleep(100);
		}
		Sleep(1000);


		string select;
		int luachon = 0;
		textColor(14);
		stdafx st;
		do {
			system("cls");
			textColor(14);
			cout << "\n\t\tNhan vien : ";
			cout << x.Getter_DSNV()[index].Getter_HoTen();
			cout << "\n\t\tChuc vu :";
			cout << "Nhan vien coi xe";
			cout << "\n\t\t ______________________________________________________________________________";
			cout << "\n\t\t|\t                                                                       |";
			cout << "\n\t\t|\t1.Gui xe                                                               |";
			cout << "\n\t\t|\t2.Lay xe                                                               |";
			cout << "\n\t\t|\t3.Tim kiem xe trong ben (theo bien so)                                 |";
			cout << "\n\t\t|\t4.Tim kiem xe trong ben (theo ma so the xe)                            |";
			cout << "\n\t\t|\t5.Xem so tien thu duoc trong ngay                                      |";
			cout << "\n\t\t|\t0.Quay lai                                                             |";
			cout << "\n\t\t|______________________________________________________________________________|";
			cout << "\n\n";

			do {
				do {
					textColor(14);
					cout << "\n\t\t>>> ";
					cin >> select;

					if (select != "1" && select != "2" && select != "3" && select != "4" && select != "5" && select != "0") {
						textColor(140);
						cout << "\n\t\tDa xay ra loi , vui long nhap lai !";
					}

				} while (select != "1" && select != "2" && select != "3" && select != "4" && select != "5" && select != "0");

				luachon = ChuyenStringSangInt(select);

				if (luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon != 5 && select != "0")
				{
					textColor(140);
					cout << "\n\t\tLua chon khong hop le. Xin kiem tra lai !";
				}

			} while (luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon != 5 && select != "0");
			ifstream FIleIn;
			FIleIn.open("danhsachphieuguixe.txt", ios::in);
			DanhSachXeTrongBen dsx;
			int m = dsx.DemSoLuongXe();
			FIleIn.close();
			FIleIn.open("danhsachphieuguixe.txt", ios::in);
			dsx.DocSoXeVao(FIleIn, m);
			FIleIn.close();
			TimKiem_BaoCao tk;
			if (luachon == 1) {
				system("cls");
				QuanLyXeVaoBen(x.Getter_DSNV()[index].Getter_MaNhanVien());
			}
			if (luachon == 2) {
				system("cls");
				DanhSachXeTrongBen  dsx;
				QuanLyXuatBen(dsx, x.Getter_DSNV()[index].Getter_MaNhanVien(), x.Getter_DSNV()[index].Getter_HoTen());
				continue;
			}
			if (luachon == 3) {
				TimKiemXeTrongBen_TheoBienSo(st, dsx, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), m);
				system("cls");
			}
			if (luachon == 4) {
				TimKiemXeTrongBen_TheoMaTheXe(st, dsx, tk, x.Getter_DSNV()[index].Getter_MaNhanVien(), m);
			}
			if (luachon == 5) {
				XemSoTienThuDuocTrongNgay(st, tk, x.Getter_DSNV()[index].Getter_MaNhanVien());
			}

		} while (luachon != 0);
	}
}

int main() {
	resizeConsole(8000, 5000);
	textColor(14);


	int p = 0;
	for (int i = 0; i <= 4; i++) {
		cout << "\n\n\n\t\tLoading...";
		cout << " " << p << "%";
		p = p + 20;
		system("cls");
		Sleep(100);
	}

	DangNhap();

	cout << endl;
	system("pause");
	return 0;
}

/*
Kiem tra thoi gian
ThoiGian tg1;
	ThoiGian tg2;
	tg1.Setter_Ngay(1);
	tg1.Setter_Thang(1);
	tg1.Setter_Nam(1996);
	tg1.Setter_Gio(0);
	tg1.Setter_Phut(0);
	tg1.Setter_Giay(0);
	tg2.Setter_Ngay(1);
	tg2.Setter_Thang(1);
	tg2.Setter_Nam(1997);
	tg2.Setter_Gio(0);
	tg2.Setter_Phut(0);
	tg2.Setter_Giay(0);
	int sogioguixe=tg2.SoGioGuiXe(tg1);
	int x = sogioguixe / 24; //kiem tra nam nhuan
	int tien=tg2.ThanhTien("OT", sogioguixe);
	cout << sogioguixe << endl << tien;
*/