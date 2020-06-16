#include "BangGia.h"
#include<iostream>
#include <iomanip>	
using namespace std;
void BangGia::Setter_DS_BangGia(GiaTien x) {
	DS_BangGia.push_back(x);
}
vector<GiaTien> BangGia::Getter_DS_BangGia() {
	return this->DS_BangGia;
}
void BangGia::DocFileBangGia(ifstream& FileIn) {
	for (int i = 0; i < 2; i++) {
		GiaTien x;
		x.DocBangGia(FileIn);
		DS_BangGia.push_back(x);
	}
}
void BangGia::ThayDoiGia(ofstream& FileOut, BangGia x) {
	string x1 = this->Getter_DS_BangGia()[0].Getter_Xe();
	for (int i = 0; i < 2; i++) {

		string x2 = x.Getter_DS_BangGia()[i].Getter_Xe();
		if (x1 == x2) {
			continue;
		}
		else {
			DS_BangGia.push_back(x.Getter_DS_BangGia()[i]);
			continue;
		}
	}
	DS_BangGia.push_back(this->Getter_DS_BangGia()[0]);

	for (int i = 0; i < 2; i++) {

		FileOut << DS_BangGia[i].Getter_Xe();
		FileOut << " ";
		FileOut << DS_BangGia[i].Getter_Khung1();
		FileOut << " ";
		FileOut << DS_BangGia[i].Getter_Khung2();
		FileOut << " ";
		FileOut << DS_BangGia[i].Getter_Khung3() << endl;
	}
}

void BangGia::HT_BangGia() {
	system("cls");
	cout << "\n\t\t _______________________________________________________________________________________________";
	cout << "\n\t\t|                                                                                               |";
	cout << "\n\t\t|\t\t\t\t\tTHONG TIN BANG GIA                                      |";
	cout << "\n\t\t|\t ___________________________________________________________________________"; cout << "\t\t|";
	cout << "\n\t\t|\t|         |       Khung 1       |       Khung 2       |       Khung 3       |"; cout << "\t\t|";
	cout << "\n\t\t|\t| Loai Xe |     (TG gui<5h)     |  (5h <=TG gui< 24h) |     (TG gui<= 24h)  |"; cout << "\t\t|";
	cout << "\n\t\t|\t|_________|_____________________|_____________________|_____________________|"; cout << "\t\t|";

	for (int i = 0; i < 2; i++) {
		string c = this->Getter_DS_BangGia()[i].Getter_Xe();
		cout << "\n\t\t|\t|";
		if (c == "XM") cout << " Xe May  ";
		else cout << " Xe OTo  ";
		cout << "|"; cout << setw(17) << right << this->Getter_DS_BangGia()[i].Getter_Khung1() << " VND"; cout << "|";
		cout << setw(17) << right << this->Getter_DS_BangGia()[i].Getter_Khung2() << " VND"; cout << "|";
		cout << setw(17) << right << this->Getter_DS_BangGia()[i].Getter_Khung3() << " VND"; cout << "|"; cout << "\t\t|";
	}
	cout << "\n\t\t|\t|_________|_____________________|_____________________|_____________________|"; cout << "\t\t|";
	cout << "\n\t\t|                                                                                               |";
	cout << "\n\t\t|_______________________________________________________________________________________________|";


}