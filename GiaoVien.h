#ifndef GIAOVIEN_H
#define GIAOVIEN_H
#include "bandoc.h"
class CGiaoVien :
	public CBanDoc
{
public:
	CGiaoVien(void);
	~CGiaoVien(void){}
	CGiaoVien(string maBanDoc, string Khoa, string hoTen,string diaChi, string SDT);
	void xuat();
private:
	string m_diaChi;
	string m_SDT;
};

#endif