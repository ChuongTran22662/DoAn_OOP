#include "DanhSachSuCo.h"

void DanhSachSuCo::DocDanhSachSuCo(ifstream& FileIn) {
	while (!FileIn.eof())
	{
		SuCo x;
		x.DocFileSuCo(FileIn);
		DSSuCo.push_back(x);
	}
}

void DanhSachSuCo::Xuat() {
	int size = DSSuCo.size();

	for (int i = 0; i < size; i++) {
		DSSuCo[i].Xuat();
	}
}

vector<SuCo> DanhSachSuCo::Getter_DanhSachSuCo()
{
	return DSSuCo;
}

void DanhSachSuCo::Setter_DanhSachSuCo(vector<SuCo> list)
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		DSSuCo.push_back(list[i]);
	}
}
