#include "Sach.h"
CSach::CSach(string maSach, string tuaDe, string tacGia, string NXB, float triGia, int namPH, int soTrang, int ngay, int thang , int nam,int maPM):m_ngayNK(ngay,thang,nam)
{
	m_maSach = maSach;
	m_tacGia = tacGia;
	m_NXB  = NXB;
	m_triGia = triGia;
	m_namPH = namPH;
	m_soTrang = soTrang;
	m_maPM = maPM;
	m_tuaDe = tuaDe;
}
void CSach::xuat()
{
	cout << "Ma Sach: " << m_maSach << endl;
	cout << "Tua De: " << m_tuaDe << endl;
	cout << "Tac Gia: " << m_tacGia << endl;
	cout << "NXB: " << m_NXB << endl;
	cout << "Nam Phat hanh: " << m_namPH << endl;
	cout << "Tri gia: " << m_triGia << endl;
	cout << "so Trang: " << m_soTrang << endl;
	cout << "Ngay nhap kho: ";
	m_ngayNK.xuat();
	cout <<"Ma PM: " << m_maPM << endl;
}

string  CSach::getTuaDe()
{
	return m_tuaDe;
}
int CSach::getmaPM()
{
	return m_maPM;
}
string CSach::getmaSach()
{
	return m_maSach;
}

