#pragma once
#include "DaTe.h"
class DaTe;
class BanDoc
{
protected:
	string sMaBD, sHoTen, sKhoa;
	DaTe xNgayDK;
public:
	friend DaTe;
	virtual void output(){};
	string getSoBD();
	void xuatBD();
	BanDoc(string sMaBD = "", string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0): xNgayDK(nNgay,nThang,nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}
	~BanDoc(void){};
};

