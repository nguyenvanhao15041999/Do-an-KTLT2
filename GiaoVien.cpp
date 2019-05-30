#include "GiaoVien.h"
CGiaoVien::CGiaoVien(string maBanDoc, string Khoa, string hoTen,string diaChi, string SDT):CBanDoc(maBanDoc,Khoa,hoTen)
{
	m_diaChi = diaChi;
	m_SDT = SDT;
}
void CGiaoVien::xuat()
{
	CBanDoc::xuat();
	cout << "Dia Chi: " << m_diaChi<< endl;
	cout << "SDT: " << m_SDT << endl;
}
