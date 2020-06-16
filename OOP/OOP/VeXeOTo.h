#pragma once
#include "VeXe.h"
class VeXeOTo : public VeXe
{
private:
	string DiemDoXe;
public:
	void DocFileOto(ifstream&);

	void XuatVeXeOTo();

	void Setter_DiemDoXe(string);
	string Getter_DiemDoXe();
};

