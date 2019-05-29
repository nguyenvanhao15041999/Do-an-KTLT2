#include "Date.h"


CDate::CDate(void)
{
}
CDate::CDate(int ngay,int thang,int nam)
{
	m_ngay = ngay;
	m_thang = thang;
	m_nam = nam;
}
void CDate::xuat()
{
	cout<<"Ngay :" << m_ngay <<" Thang :" << m_thang << " NAM " << m_nam <<endl;
}
