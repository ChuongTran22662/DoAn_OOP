#include "DanhSachPhieuGuiXe.h"

void DanhSachPhieuGuiXe::Nhap() {
	int luachon;

	do {
		cout << "\n\t\t--------------- Menu ---------------\n";
		cout << "\n\t\t1. Nhap phieu gui xe";
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

			PhieuGuiXe p;
			p.Nhap();
			DanhSachPGX.push_back(p);
	} while (luachon != 2);
}

void DanhSachPhieuGuiXe::Xuat()
{
	int size = DanhSachPGX.size();

	for (int i = 0; i < size; i++)
	{
		cout << "\n\t\tThong tin phieu thu : " << i + 1 << "\n";
		DanhSachPGX[i].Xuat();
	}
}

vector<PhieuGuiXe> DanhSachPhieuGuiXe::Getter_DanhSachPhieuGuiXe()
{
	return this->DanhSachPGX;
}

void DanhSachPhieuGuiXe::Setter_DanhSachPhieuGuiXe(PhieuGuiXe x)
{
		DanhSachPGX.push_back(x);
}

void DanhSachPhieuGuiXe::GhiDanhSachPhieuGuiXe(ofstream& FileOut) {
	int size = DanhSachPGX.size();
	for (int i = 0; i < size; i++) {
		DanhSachPGX[i].GhiPhieuGuiXe(FileOut);
		FileOut << endl;
	}
}
