#include "DanhSachVeXe.h"
#include"stdafx.h"
void DanhSachVeXe::XuatDanhSachVeOTo() {
	int size = DSVeXeOTo.size();

	for (int i = 0; i < size; i++) {
		DSVeXeOTo[i].XuatVeXeOTo();
	}
}

vector<VeXeMay> DanhSachVeXe::Getter_DSVeXeMay()
{
	return DSVeXeMay;
}

void DanhSachVeXe::Setter_DSVeXeMay(vector<VeXeMay> list, string s)
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		if (list[i].Getter_MaSo() == s) {
			list[i].Setter_TrangThai(0);
		}
		DSVeXeMay.push_back(list[i]);
	}
}


vector<VeXeOTo> DanhSachVeXe::Getter_DSVeOTo()
{
	return DSVeXeOTo;
}

void DanhSachVeXe::Setter_DSVeOTo(vector<VeXeOTo> list, string s)
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		if (list[i].Getter_MaSo() == s) {
			list[i].Setter_TrangThai(0);
		}
		DSVeXeOTo.push_back(list[i]);
	}
}

//cap nhat danh sach khi xe xuat ben
void DanhSachVeXe::CapNhatVeXeXuatBen_XeMay(vector<VeXeMay> list, string s) {
	int size = list.size();
	for (int i = 0; i < size; i++) {
		if (list[i].Getter_MaSo() == s) {
			list[i].Setter_TrangThai(1);
		}
		DSVeXeMay.push_back(list[i]);
	}
}
void DanhSachVeXe::CapNhatVeXeXuatBen_OTo(vector<VeXeOTo> list, string s) {
	int size = list.size();
	for (int i = 0; i < size; i++) {
		if (list[i].Getter_MaSo() == s) {
			list[i].Setter_TrangThai(1);
		}
		DSVeXeOTo.push_back(list[i]);
	}
}

void DanhSachVeXe::ThemVeXeMay(int n) {
	stdafx st;
	DanhSachVeXe x;
	ifstream FileIn;
	FileIn.open("vexemay.txt", ios::in);
	x.DocDSVeXeMay(FileIn);
	FileIn.close();
	int size = x.Getter_DSVeXeMay().size();
	for (int i = 0; i < size; i++) {
		DSVeXeMay.push_back(x.Getter_DSVeXeMay()[i]);
	}
	
	string MaTheCuoiCung = x.Getter_DSVeXeMay()[size - 1].Getter_MaSo();
	int dodai = MaTheCuoiCung.size();
	int so = st.ChuyenString_SangInt(MaTheCuoiCung.substr(2, dodai - 2));

	for (int i = size; i < n + size; i++) {
		string tx = st.HT_VeXeThem("XM", i + so+ size);
		VeXeMay y;
		y.Setter_LoaiXe("XeMay");
		y.Setter_MaSo(tx);
		y.Setter_TrangThai(1);
		DSVeXeMay.push_back(y);
	}
	ofstream FileOut;
	FileOut.open("vexemay.txt", ios::out);
	FileOut << size + n << endl;
	for (int i = 0; i < size + n; i++) {
		FileOut << this->Getter_DSVeXeMay()[i].Getter_MaSo() << " " << this->Getter_DSVeXeMay()[i].Getter_LoaiXe() << " " << this->Getter_DSVeXeMay()[i].Getter_TrangThai() << endl;
	}

	FileOut.close();
	cout << "\n\tThem thanh cong" << endl;
}

void DanhSachVeXe::ThemVeXeOTo(int n, string khu) {
	stdafx st;
	DanhSachVeXe x;
	ifstream FileIn;
	FileIn.open("vexeoto.txt", ios::in);
	x.DocDSVeXeOto(FileIn);
	FileIn.close();
	int chech_khu = 0;
	int size = x.Getter_DSVeOTo().size();
	for (int i = 0; i < size; i++) {
		DSVeXeOTo.push_back(x.Getter_DSVeOTo()[i]);
	}
	string MaTheCuoiCung = x.Getter_DSVeOTo()[size - 1].Getter_MaSo();
	int dodai = MaTheCuoiCung.size();
	int so = st.ChuyenString_SangInt(MaTheCuoiCung.substr(2, dodai - 2));
	int stt = 0;
	for (int i = size; i < n + size; i++) {
		stt++;
		string the_xe = st.HT_VeXeThem("OT", i + so+ size);
		string diem_do = st.HT_VeXeThem(khu, stt);
		VeXeOTo y;
		y.Setter_LoaiXe("OTO");
		y.Setter_MaSo(the_xe);
		y.Setter_TrangThai(1);
		y.Setter_DiemDoXe(diem_do);
		DSVeXeOTo.push_back(y);
	}
	for (int i = 0; i < n + size - 1; i++) {
		string dd_i = this->Getter_DSVeOTo()[i].Getter_DiemDoXe();
		for (int j = i + 1; j < n + size; j++) {
			string dd_j = this->Getter_DSVeOTo()[j].Getter_DiemDoXe();
			if (dd_i == dd_j) {
				chech_khu = 1;
				break;
			}
			else {
				continue;
			}
		}

	}
	if (chech_khu == 0) {
		ofstream FileOut;
		FileOut.open("vexeoto.txt", ios::out);
		FileOut << size + n << endl;
		for (int i = 0; i < size + n; i++) {
			FileOut << this->Getter_DSVeOTo()[i].Getter_MaSo() << " " << this->Getter_DSVeOTo()[i].Getter_LoaiXe() << " " <<
				this->Getter_DSVeOTo()[i].Getter_TrangThai() << " " << this->Getter_DSVeOTo()[i].Getter_DiemDoXe() << endl;
		}
		FileOut.close();
		cout << "\n\tThem thanh cong" << endl;
	}

	else {
		st.TextColor(140);
		cout << "\n\tMot so vi tri do xe da bi trung";
		cout << "\n\tHay dat mot ten khu khac de dam bao he thong tu cap nhat duoc";
		st.TextColor(14);
	}


}
void DanhSachVeXe::DocDSVeXeOto(ifstream& FileIn) {
	int size;
	FileIn >> size;
	for (int i = 0; i < size; i++) {
		VeXeOTo x;
		x.DocFileOto(FileIn);
		DSVeXeOTo.push_back(x);
	}
}

void DanhSachVeXe::GhiDSVeXeOto(ofstream& FileOut) {
	int size = this->DSVeXeOTo.size();

	FileOut << size;
	FileOut << endl;

	for (int i = 0; i < size; i++) {
		FileOut << DSVeXeOTo[i].Getter_MaSo() << " " << DSVeXeOTo[i].Getter_LoaiXe() << " " << DSVeXeOTo[i].Getter_TrangThai() << " " << DSVeXeOTo[i].Getter_DiemDoXe() << endl;
	}
}
void DanhSachVeXe::DocDSVeXeMay(ifstream& FileIn) {
	int size;
	FileIn >> size;
	for (int i = 0; i < size; i++) {
		VeXeMay x;
		x.DocFileVeXe(FileIn);
		DSVeXeMay.push_back(x);
	}
}

//De cap nhat
void DanhSachVeXe::GhiDSVeXeMay(ofstream& FileOut) {
	int size = this->DSVeXeMay.size();

	FileOut << size;
	FileOut << endl;

	for (int i = 0; i < size; i++) {
		FileOut << DSVeXeMay[i].Getter_MaSo() << " " << DSVeXeMay[i].Getter_LoaiXe() << " " << DSVeXeMay[i].Getter_TrangThai() << endl;
	}
}

void DanhSachVeXe::XuatDanhSachVeXeMay() {
	int size = DSVeXeMay.size();

	for (int i = 0; i < size; i++) {
		DSVeXeMay[i].XuatVeXe();
	}
}

void DanhSachVeXe::XoaVeKhiGQSC(string v, string ve) {
	DanhSachVeXe y;
	int vitri = -1;
	ifstream FileIn;
	ofstream FileOut;
	if (v == "XM") {
		
		FileIn.open("vexemay.txt", ios::in);
		y.DocDSVeXeMay(FileIn);
		FileIn.close();
		int size = y.DSVeXeMay.size();
		for (int i = 0; i < size; i++) {
			VeXeMay x;
			if (ve != y.Getter_DSVeXeMay()[i].Getter_MaSo()) continue;
			else {
				vitri = i;
				break;
			}
		}		
		FileOut.open("vexemay.txt", ios::out);
		FileOut << size - 1;
		FileOut << endl;
		for (int j = 0; j < size; j++) {
			if (j == vitri) continue;
			else {
				FileOut << y.DSVeXeMay[j].Getter_MaSo() << " " << y.DSVeXeMay[j].Getter_LoaiXe() 
					<< " " << y.DSVeXeMay[j].Getter_TrangThai() << endl;
			}
		}
		FileOut.close();
	}

	if (v == "OT") {

		FileIn.open("vexeoto.txt", ios::in);
		y.DocDSVeXeOto(FileIn);
		FileIn.close();
		int size = y.DSVeXeOTo.size();
		for (int i = 0; i < size; i++) {
			VeXeOTo x;
			if (ve != y.Getter_DSVeOTo()[i].Getter_MaSo()) continue;
			else {
				vitri = i;
				break;
			}
		}
		FileOut.open("vexeoto.txt", ios::out);
		FileOut << size - 1;
		FileOut << endl;
		for (int j = 0; j < size; j++) {
			if (j == vitri) continue;
			else {
				FileOut << y.DSVeXeOTo[j].Getter_MaSo() << " " << y.DSVeXeOTo[j].Getter_LoaiXe()
					<< " " << y.DSVeXeOTo[j].Getter_TrangThai()<<" "<<y.DSVeXeOTo[j].Getter_DiemDoXe() << endl;
			}
		}
		FileOut.close();
	}
}
