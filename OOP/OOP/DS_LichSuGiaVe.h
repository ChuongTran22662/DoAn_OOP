#pragma once
#include"LichSuThayDoiGiaVe.h"
#include<vector>
class DS_LichSuGiaVe
{
	vector< LichSuThayDoiGiaVe> ds_LichSuThayDoiGiaVe;
public:
	void Setter_ds_LichSuThayDoiGiaVe(LichSuThayDoiGiaVe);
	vector< LichSuThayDoiGiaVe> Getter_ds_LichSuThayDoiGiaVe();
	void HienThiLSTD();
	void DocFileLSGX(ifstream&,int );
};

