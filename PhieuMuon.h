#ifndef PHIEUMUON_H
#define PHIEUMUON_H
#include "BanDoc.h"
#include "Sach.h"

class CPhieuMuon
{
public:
	CPhieuMuon(void);
	~CPhieuMuon(void){}
	CPhieuMuon(int soPhieuMuon,string maBanDoc, string Khoa, string hoTen,string maSach,string tuaDe,string tacGia, string NXB,float triGia,int namPH,int soTrang,int ngay,int thang,int nam,int maPM, int tinhTrang);
	void xuat();
	int getsoPhieuMuon();
private:
	int m_soPhieuMuon;
	CBanDoc m_nguoiMuon;
	CSach m_maSach;
	int m_tinhTrang;
	
};
#endif
