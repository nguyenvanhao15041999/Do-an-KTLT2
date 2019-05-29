#ifndef SACH_H
#define SACH_H
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;
class CSach
{
public:
	CSach(void);
	~CSach(void){}
	CSach(string maSach,string tuaDe,string tacGia, string NXB,float triGia,int namPH,int soTrang,int ngay,int thang,int nam,int maPM);
	void xuat();
	string getTuaDe();
	string getmaSach();
	
	int getmaPM();
private:

	string m_maSach;
	string m_tuaDe;
	string m_tacGia;
	string m_NXB;
	float m_triGia;
	int m_namPH;
	int m_soTrang;
	CDate m_ngayNK;
	int m_maPM;
};

#endif