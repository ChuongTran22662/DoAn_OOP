#include "DanhSachGiaiQuyetSuCo.h"
#include"stdafx.h"
#include"DanhSachSuCo.h"
#include"DanhSachNhanVien.h"
#include <iomanip>	
#include"DanhSachXeTrongBen.h"
#include<math.h>
#include"DanhSachCTBB.h"
#include"ChiTietBienBan.h"
void DanhSachGiaiQuyetSuCo::Nhap() {
	int luachon;

	do {
		cout << "\n\t\t--------------- Menu ---------------\n";
		cout << "\n\t\t1. Nhap su co";
		cout << "\n\t\t2. Thoat";
		cout << "\n\t\t------------------------------------\n";
		do {
			cout << "\n\t\tNhap vao lua chon: ";
			cin >> luachon;

			if (luachon != 1 && luachon != 2)
			{
				cout << "\n\t\tLua chon khong hop le. Xin kiem tra lai !";
			}
		} while (luachon != 1 && luachon != 2);
		if (luachon == 2) {
			break;
		}
		GiaiQuyetSuCo p;
		p.Nhap();
		DanhSachGQSC.push_back(p);
	} while (luachon != 2);
}

int DemSoLuongXe() {
	ifstream FileIn;
	FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
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

void DanhSachGiaiQuyetSuCo::DocDanhSachGiaiQuyetSuCo(ifstream& FileOut) {

	int size = DemSoLuongXe();

	for (int i = 0; i < size; i++) {
		GiaiQuyetSuCo x;
		x.DocFileSuCo(FileOut);
		DanhSachGQSC.push_back(x);
	}
}

void DanhSachGiaiQuyetSuCo::Xuat()
{
	int size = DanhSachGQSC.size();

	for (int i = 0; i < size; i++)
	{
		cout << "\n\t\tThong tin bien ban : " << i + 1 << "\n";
		DanhSachGQSC[i].Xuat();
	}
}



vector<GiaiQuyetSuCo> DanhSachGiaiQuyetSuCo::Getter_DanhSachGQSC()
{
	return this->DanhSachGQSC;
}

void DanhSachGiaiQuyetSuCo::Setter_DanhSachGQSC(GiaiQuyetSuCo x)
{
	DanhSachGQSC.push_back(x);
}

void DanhSachGiaiQuyetSuCo::GhiDanhSachGiaiQuyetSuCo(ofstream& FileOut/*,ThoiGian x*/) {
	
	int size = DanhSachGQSC.size();
//	for (int i = 0; i < size; i++) {
		DanhSachGQSC[size-1].GhiFileSuCo(FileOut);
		FileOut << endl;
	//}
}
void DanhSachGiaiQuyetSuCo::HienThiBienBan(string Ma_BB, string nvql) {
	system("cls");
	stdafx st;
	ifstream FileIn;
	FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
	int size_sc = st.DemSoLuongXe(FileIn);
	FileIn.close();
	FileIn.open("danhsachgiaiquyetsuco.txt", ios::in);
	this->DocDanhSachGiaiQuyetSuCo(FileIn);
	//int size_suco = -1;
	int ViTri_TheXe;
	
	for (int i = 0; i < size_sc; i++) {
		if (this->Getter_DanhSachGQSC()[i].Getter_MaBB() != Ma_BB) continue;
		else {
		//	size_suco++;
			ViTri_TheXe = i;
			break;
		}
	}

	DanhSachCTBB dsctbb;
	ifstream FileCTBB;
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	int size_bb = st.DemSoLuongXe(FileCTBB);
	FileCTBB.close();
	FileCTBB.open("ChiTietBienBan.txt", ios::in);
	dsctbb.DocDanhSachCTBB(FileCTBB);
	int size_ctbb = -1;
	int sosuco = -1;
	int ViTri_BB[100];
	for (int i = 0; i < size_bb; i++) {
		if (dsctbb.Getter_DanhSach_CTBB()[i].Getter_MaBB() != Ma_BB) continue;
		else {
			size_ctbb++;
			ViTri_BB[size_ctbb] = i;
			sosuco++;
		}
	}

//	string nvtx = ;
	string thexe = this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_MaThe();
	string NG_XL = st.HT_NgayGio(this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Ngay(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Gio(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Phut(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Giay());

	string loaixe = thexe.substr(0, 2);

	DanhSachNhanVien y;
	ifstream FileIn_NV;
	FileIn_NV.open("danhsachnhanvien.txt", ios::in);
	y.DocDSNV(FileIn_NV);
	FileIn_NV.close();
	int size_nv = y.Getter_DSNV().size();
	int Vtri_nvql;
	int Vtri_nvtx;
	for (int i = 0; i < size_nv; i++) {
		if (y.Getter_DSNV()[i].Getter_MaNhanVien() != nvql) continue;
		else {
			Vtri_nvql = i;
			break;
		}
	}
	for (int i = 0; i < size_nv; i++) {
		if (y.Getter_DSNV()[i].Getter_MaNhanVien() != this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_MaNhanVienNhanXe()) continue;
		else {
			Vtri_nvtx = i;
			break;
		}
	}

	string Ng_Gui = st.HT_NgayGio(this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGuiXe().Getter_Ngay(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGuiXe().Getter_Thang(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGuiXe().Getter_Nam(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGuiXe().Getter_Gio(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGuiXe().Getter_Phut(),
		this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGuiXe().Getter_Giay());

	cout << "\n\t\t __________________________________________________________________________________________";
	cout << "\n\t\t|                                                                                          |";
	cout << "\n\t\t| BAI GIU XE                                                                               |";
	cout << "\n\t\t| DAI HOC XAY DUNG HA NOI                             CONG HOA XA HOI CHU NGHIA VIET NAM   |";
	cout << "\n\t\t| Dia chi: 55 Giai Phong, Dong Tam, Hai Ba Trung,HN      DOC LAP - TU DO - HANH PHUC       |";
	cout << "\n\t\t|   ___________________________________________               ___________________          |";
	cout << "\n\t\t|\t ________________                                                                  |";
	cout << "\n\t\t|\t| So: "; cout << setw(5) << left << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_MaBB(); cout << "/";
	cout << setw(4) << left << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();
	cout << " |                                                                 |";
	cout << "\n\t\t|\t|________________|                                                                 |";

	cout << "\n\t\t|                                                                                          |";
	cout << "\n\t\t|                                                                                          |";
	cout << "\n\t\t|                                  BIEN BAN GIAI QUYET SU CO                               |";
	cout << "\n\t\t|                                                                                          |";
	cout << "\n\t\t| Chung toi gom:                                                                           |";
	cout << "\n\t\t|       1: Nhan vien quan ly: "; cout << setw(25) << left << y.Getter_DSNV()[Vtri_nvql].Getter_HoTen(); cout << "                                    |";
	cout << "\n\t\t|       2: Nhan vien trong giu xe: "; cout << setw(25) << left << y.Getter_DSNV()[Vtri_nvtx].Getter_HoTen(); cout << "                               |";
	cout << "\n\t\t| La dai dien cua bai giu xe DAI HOC XAY DUNG HA NOI                                       |";
	cout << "\n\t\t|                                                                                          |";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t| Vao thoi gian: "; cout << setw(25) << left << Ng_Gui; cout << "                                                 |";
	cout << "\n\t\t| Ong (ba): Nguyen Van A da gui tai bai xe chung toi xe:                                   |";
	cout << "\n\t\t| Co bien so: "; cout << setw(10) << left << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_BienSo(); cout << "                                                                   |";
	cout << "\n\t\t| Loai xe: ";
	if (loaixe == "XM")  cout << setw(6) << left << "Xe may";
	else cout << setw(6) << left << "Xe oto";
	cout << "                                                                          |";
	cout << "\n\t\t| Su dung the xe: "; cout << setw(5) << left << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_MaThe(); cout << "                                                                    |";
	cout << "\n\t\t| Da xay ra su co khi gui xe tai day.                                                      |";
	cout << "\n\t\t| Cu the nhu sau:                                                                          |";
	cout << "\n\t\t|\t _____________________________________________________________"; cout << "                     |";
	cout << "\n\t\t|\t| STT | Ma su co |  Ten su co  |  Tien thoa thuan giai quyet  |"; cout << "                    |";
	cout << "\n\t\t|\t|_____|__________|_____________|______________________________|"; cout << "                    |";


	int stt = 1;
	int TongTienGQ = 0;
	DanhSachSuCo dssc;
	ifstream FileSuCo;
	FileSuCo.open("danhsachsuco.txt", ios::in);
	dssc.DocDanhSachSuCo(FileSuCo);
	FileSuCo.close();

	for (int i = 0; i <= sosuco; i++) {
		int vitri_tensuco;
		cout << "\n\t\t|\t|";
		cout << setw(5) << left << stt; cout << "|";
		cout << setw(10) << left << dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_MaSuCo();cout << "|";
		for (int j = 0; j < 6; j++) {
			if (dssc.Getter_DanhSachSuCo()[j].Getter_MaSuCo() != dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_MaSuCo()) continue;
			else {
				vitri_tensuco = j;
				break;
			}
		}
		
		cout << setw(13) << left << dssc.Getter_DanhSachSuCo()[vitri_tensuco].Getter_TenSuCo();  cout << "|";
		cout << setw(26) << right << dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_TienGiaiQuyet() << " VND"; cout << "|";
		if (dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_MaSuCo() == "01" || dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_MaSuCo() == "04") {
			TongTienGQ = TongTienGQ + dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_TienGiaiQuyet();
		}
		else {
			TongTienGQ = TongTienGQ - dsctbb.Getter_DanhSach_CTBB()[ViTri_BB[i]].Getter_TienGiaiQuyet();
		}
		cout << "\t\t           |";
		stt++;
	}
	cout << "\n\t\t|\t|_____|__________|_____________|______________________________|"; cout << "\t\t           |";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|\tSau khi thong nhat, hai ben da di den quyet dinh                                   | ";
	if (TongTienGQ >= 0) {
		cout << "\n\t\t|\tNha xe thu lai tu khach: "; cout << setw(9) << left << TongTienGQ << " VND"; cout << "                                             |";
	}
	else {
		cout << "\n\t\t|\tNha xe thu den bu cho khach: "; cout << setw(9) << left << abs(TongTienGQ) << " VND"; cout << "                                         |";
	}

	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";

	cout << "\n\t\t|\t\t\t\t" << "\t\tHa Noi, Ngay "; cout << setw(2) << right << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Ngay()
		<< " thang"; cout << setw(2) << right << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Thang()
		<< " nam "; 	cout << setw(2) << right << this->Getter_DanhSachGQSC()[ViTri_TheXe].Getter_ThoiGianGiaiQuyetSuCo().Getter_Nam();
	cout << "           |";
	cout << "\n\t\t|\t\t\t\t\t\t         Nguoi lap                         |";
	cout << "\n\t\t|\t\t\t\t\t\t"; cout << setw(25) << y.Getter_DSNV()[Vtri_nvql].Getter_HoTen(); cout << "                  |";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|                                                                                          | ";
	cout << "\n\t\t|__________________________________________________________________________________________|";
	system("pause");
}