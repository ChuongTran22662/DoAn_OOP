#pragma once
using namespace std;
#include<string>
#include<fstream>
class GiaTien
{
private:
	string Xe;
	float Khung1;
	float Khung2;
	float Khung3;
public:
	void DocBangGia(ifstream&);
	
	void Setter_Xe(string);
	string Getter_Xe();

	void Setter_Khung1(float);
	float Getter_Khung1();

	void Setter_Khung2(float);
	float Getter_Khung2();

	void Setter_Khung3(float);
	float Getter_Khung3();
};

