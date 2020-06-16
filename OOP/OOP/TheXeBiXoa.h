#pragma once
#include <string>
#include<vector>
using namespace std;
class TheXeBiXoa
{
	string MaTheXe;
	vector< TheXeBiXoa> DS_TheXeBiXoa;
public:
	void Setter_MaTheXe(string);
	string Getter_MaTheXe();
	void DocTheXeBiXoa(ifstream&);
	int DemSoLuongThe();
};

