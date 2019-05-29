#include "PhieuMuon.h"


CPhieuMuon::CPhieuMuon(void)
{
}
CPhieuMuon::CPhieuMuon(int soPhieuMuon,string maBanDoc, string Khoa, string hoTen,string maSach,string tuaDe,
	string tacGia, string NXB,float triGia,int namPH,int soTrang,int ngay,int thang,int nam,
	int maPM, int tinhTrang):m_nguoiMuon(maBanDoc, Khoa, hoTen), m_maSach(maSach, tuaDe, tacGia, NXB, triGia, namPH, soTrang, ngay, thang, nam, namPH)
{
	m_soPhieuMuon = soPhieuMuon;
	m_tinhTrang = tinhTrang;
}

int CPhieuMuon::getsoPhieuMuon()
{
	return m_soPhieuMuon;
}

void CPhieuMuon::xuat()
{
	cout<<" So PM :" << m_soPhieuMuon << endl;
	cout<<" MA Sach:" << m_maSach.getmaSach() << endl;
	cout<<" ma ban doc :" << m_nguoiMuon.getmaBanDoc() << endl;
	cout<< " Tinh Trang :" << m_tinhTrang << endl;
}
