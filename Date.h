#include<iostream>
#include<string>
using namespace std;
class CDate
{
public:
	CDate(void);
	~CDate(void);
	CDate(int ngay,int thang,int nam);
	void xuat();
private:
	int m_ngay ;
	int m_thang;
	int m_nam;
};

