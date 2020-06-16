#include "DanhSachTheBiXoa.h"
#include<fstream>
void DanhSachTheBiXoa::Setter_DS_TheXeBiXoa(TheXeBiXoa x) {
	DS_TheXeBiXoa.push_back(x);
}
vector< TheXeBiXoa> DanhSachTheBiXoa::Getter_DS_TheXeBiXoa() {
	return this-> DS_TheXeBiXoa;
}

void DanhSachTheBiXoa::DocDanhSachTheXeBiXoa() {
	TheXeBiXoa x;
	int size = x.DemSoLuongThe();
	ifstream FileIn;
	FileIn.open("TheXeBiXoa.txt", ios::in);
	for (int i = 0; i < size; i++) {
		TheXeBiXoa y;
		y.DocTheXeBiXoa(FileIn);
		DS_TheXeBiXoa.push_back(y);
	}
}