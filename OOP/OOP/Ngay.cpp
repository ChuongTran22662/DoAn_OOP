#include "Ngay.h"

// Trả về true nếu là năm nhuận, false nếu không là năm nhuận.
bool KiemTraNamNhuan(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
	{
		return true;
	}
	return false;

	//return ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0);
}

void Ngay::NhapNgay()
{
	do {
		cout << "\n\t\tNhap nam: ";
		cin >> Nam;

		if (Nam < 1940)
		{
			cout << "\n\t\tNam khong hop le. Xin kiem tra lai !";
		}
	} while (Nam < 1940);

	do {
		cout << "\n\t\tNhap thang: ";
		cin >> Thang;

		if (Thang < 1 || Thang > 12)
		{
			cout << "\n\t\tThang khong hop le. Xin kiem tra lai !";
		}
	} while (Thang < 1 || Thang > 12);

	bool CheckNgay;
	do {
		CheckNgay = true;

		cout << "\n\t\tNhap ngay: ";
		cin >> Ngay;

		if (Ngay < 1)
		{
			CheckNgay = false;
		}
		else
		{
			// Có tối đa 30 ngày.
			if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
			{
				if (Ngay > 30)
				{
					CheckNgay = false;
				}
			}
			// Có 31 ngày.
			else if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
			{
				if (Ngay > 31)
				{
					CheckNgay = false;
				}
			}
			// Tháng 2 có thể có 28 hoặc 29 ngày.
			else
			{
				if (KiemTraNamNhuan(Nam))
				{
					if (Ngay > 29)
					{
						CheckNgay = false;
					}
				}
				else
				{
					if (Ngay > 28)
					{
						CheckNgay = false;
					}
				}
			}
		}

		if (CheckNgay == false)
		{
			cout << "\n\t\tNgay khong hop le. Xin kiem tra lai !";
		}
	} while (CheckNgay == false);
}

void Ngay::XuatNgay()
{
	cout << "\t\tNgay :" << this->Ngay << " thang :" << this->Thang << " nam :" << this->Nam;
}

void Ngay::DocFileThoiGian(ifstream& FileIn) {
	FileIn >> this->Ngay;
	FileIn.seekg(1, 1);
	FileIn >> this->Thang;
	FileIn.seekg(1, 1);
	FileIn >> this->Nam;
}

void Ngay::GhiFileThoiGian(ofstream& FileOut) {
	FileOut << this->Ngay << " " << this->Thang << " " << this->Nam;
}

int Ngay::Getter_NgaySinh() {
	return this->Ngay;
}

void Ngay::Setter_NgaySinh(int x) {
	this->Ngay = x;
}

int Ngay::Getter_ThangSinh() {
	return this->Thang;
}

void Ngay::Setter_ThangSinh(int x) {
	this->Thang = x;
}

int Ngay::Getter_NamSinh() {
	return this->Nam;
}

void Ngay::Setter_NamSinh(int x) {
	this->Nam = x;
}