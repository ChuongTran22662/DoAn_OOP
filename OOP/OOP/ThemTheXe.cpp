#include "ThemTheXe.h"
#include"DanhSachVeXe.h"
#include <iomanip>	
#include"stdafx.h"
#include <sstream>

void ThemTheXe::HienThiVeXeOTO() {
	
	stdafx st;
	st.TextColor(14);
	cout << "\n\t\t________________________________________________________________________";
	cout << "\n\t\t|\t\t                                               \t\t|";
	cout << "\n\t\t|\t\tTHONG TIN THE XE OTO                           \t\t|";
	cout << "\n\t\t|\t ________________________________________________\t\t|";
	cout << "\n\t\t|\t| STT | Ma the xe | Tinh trang ve | Vi tri do xe |"; cout << "\t\t|";
	cout << "\n\t\t|\t|_____|___________|_______________|______________|"; cout << "\t\t|";
	
	DanhSachVeXe x;
	ifstream FileIn;
	FileIn.open("vexeoto.txt", ios::in);
	x.DocDSVeXeOto(FileIn);
	FileIn.close();
	int size = x.Getter_DSVeOTo().size();
	int stt = 0;
	for (int i = 0; i < size; i++) {
		stt++;
		cout << "\n\t\t|\t|";
		cout << setw(5) << left << stt;
		cout << "|";
		cout << setw(11) << left << x.Getter_DSVeOTo()[i].Getter_MaSo();
		cout << "|";
		if (x.Getter_DSVeOTo()[i].Getter_TrangThai() == 0) {
			st.TextColor(140);
			cout << setw(8) << right << x.Getter_DSVeOTo()[i].Getter_TrangThai();
			st.TextColor(14);
		}
		else {
			cout << setw(8) << right << x.Getter_DSVeOTo()[i].Getter_TrangThai();
		}
		cout << setw(8) << right << "|";
		cout << setw(7) << right << x.Getter_DSVeOTo()[i].Getter_DiemDoXe();
		cout << setw(8) << right << "|";
		cout << "\t\t|";
	}
	cout << "\n\t\t|\t|_____|___________|_______________|______________|"; cout << "\t\t|";
	cout << "\n\t\t|_______________________________________________________________________|";

}
void ThemTheXe::HienThiVeXeMay() {
	
	stdafx st;
	st.TextColor(14);
	cout << "\n\t\t _______________________________________________";
	cout << "\n\t\t|                                               |";
	cout << "\n\t\t|\t\tTHONG TIN THE XE MAY            |";
	cout << "\n\t\t|\t _________________________________\t|";
	cout << "\n\t\t|\t| STT | Ma the xe | Tinh trang ve |"; cout << "\t|";
	cout << "\n\t\t|\t|_____|___________|_______________|"; cout << "\t|";
	DanhSachVeXe x;
	ifstream FileIn;
	FileIn.open("vexemay.txt", ios::in);
	x.DocDSVeXeMay(FileIn);
	FileIn.close();
	int size = x.Getter_DSVeXeMay().size();
	int stt = 0;
	for (int i = 0; i < size; i++) {
		stt++;
		cout << "\n\t\t|\t|";
		cout << setw(5) << left << stt;
		cout << "|";
		cout << setw(11) << left << x.Getter_DSVeXeMay()[i].Getter_MaSo();
		cout << "|";
		if (x.Getter_DSVeXeMay()[i].Getter_TrangThai() == 0) {
			st.TextColor(140);
			cout << setw(8) << right << x.Getter_DSVeXeMay()[i].Getter_TrangThai();
			st.TextColor(14);
		}
		else {
			cout << setw(8) << right << x.Getter_DSVeXeMay()[i].Getter_TrangThai();
		}
		cout << setw(8) << right << "|";
		cout << "\t|";
	}
	cout << "\n\t\t|\t|_____|___________|_______________|"; cout << "\t|";

	cout << "\n\t\t|_______________________________________________|";
}
void ThemTheXe::ThemTheXeMay() {
	stdafx st;
	int n;
	string s_n;

	while (getline(cin, s_n))
	{
		stringstream ss(s_n);
		if (ss >> n)
		{
			if (ss.eof())
			{
				break;
			}
		}
		cout << "\n\t\t\tNhap so luong: ";
		st.TextColor(140);
	}
	system("cls");
	st.TextColor(14);
	DanhSachVeXe ds;
	ds.ThemVeXeMay(n);
	HienThiVeXeMay();
}

void ThemTheXe::ThemTheXeOTO() {
	stdafx st;
	int n;
	string s_n;
	string khu;

	while (getline(cin, s_n))
	{
		stringstream ss(s_n);
		if (ss >> n)
		{
			if (ss.eof())
			{
				break;
			}
		}
		
		cout << "\n\t\t\tNhap so luong: ";
		st.TextColor(140);
	}
	
	st.TextColor(14);
	cout << "\t\t\tNhap ten khu vuc do: "; cin >> khu;

	system("cls");
	DanhSachVeXe ds;
	ds.ThemVeXeOTo(n, khu);
	HienThiVeXeOTO();

}