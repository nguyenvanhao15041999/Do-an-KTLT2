#include "Date.h"
CDate::CDate(int ngay,int thang,int nam)
{
	m_ngay = ngay;
	m_thang = thang;
	m_nam = nam;
}
void CDate::xuat()
{
	cout << setw(2) << setfill('0') << m_ngay << "-" << setw(2) << setfill('0') << m_thang << "-" << setw(2) << setfill('0') << m_nam << endl;
}

