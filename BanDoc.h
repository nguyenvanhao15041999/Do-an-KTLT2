#ifndef BANDOC_H
#define BANDOC_H
#include<iostream>
#include<string>
using namespace std;
class CBanDoc
{
public:
	CBanDoc(void);
	~CBanDoc(void);
	CBanDoc(string maBanDoc, string Khoa, string hoTen);
	virtual void xuat();
	string getmaBanDoc();
private:
	string m_maBanDoc;
	string m_Khoa;
	string m_hoTen;
};
#endif
