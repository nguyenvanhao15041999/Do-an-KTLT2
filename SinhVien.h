#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "bandoc.h"
class CSinhVien :
	public CBanDoc
{
public:
	CSinhVien(void);
	~CSinhVien(void){}
	CSinhVien(string maBanDoc, string Khoa, string hoTen,string KhoaHoc);
	 void xuat();
private:
	string m_KhoaHoc;
	
};

#endif