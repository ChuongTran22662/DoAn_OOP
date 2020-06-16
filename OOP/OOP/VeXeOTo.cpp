#include "VeXeOTo.h"

void VeXeOTo::DocFileOto(ifstream& FileIn) {
	VeXe::DocFileVeXe(FileIn);
	FileIn >> this->DiemDoXe;
}

void VeXeOTo::XuatVeXeOTo() {
	VeXe::XuatVeXe();
	cout<<"\n\t\tDiem do xe :"<<this->DiemDoXe;
}

void VeXeOTo::Setter_DiemDoXe(string x) {
	this->DiemDoXe = x;
}

string VeXeOTo::Getter_DiemDoXe() {
	return this->DiemDoXe;
}
