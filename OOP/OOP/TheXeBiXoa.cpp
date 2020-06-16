#include "TheXeBiXoa.h"
#include"stdafx.h"
void TheXeBiXoa::Setter_MaTheXe(string x) {
	this->MaTheXe = x;
}
string TheXeBiXoa::Getter_MaTheXe() {
	return this->MaTheXe;
}

int TheXeBiXoa::DemSoLuongThe() {
	stdafx st;
	ifstream FileIn;
	FileIn.open("TheXeBiXoa.txt", ios::in);
	int n = st.DemSoLuongXe(FileIn);
	FileIn.close();
	return n;
}

void TheXeBiXoa::DocTheXeBiXoa(ifstream& FileIn) {
	
	FileIn >> this->MaTheXe;
}
