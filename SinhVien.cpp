#include "SinhVien.h"


CSinhVien::CSinhVien(void)
{
}

CSinhVien::CSinhVien(string maBanDoc, string Khoa, string hoTen,string KhoaHoc):CBanDoc(maBanDoc,Khoa,hoTen)
{
	m_KhoaHoc = KhoaHoc;
}
void CSinhVien::xuat()
{
	CBanDoc::xuat();
	cout<<"Khoa Hoc" << m_KhoaHoc << endl;
}
