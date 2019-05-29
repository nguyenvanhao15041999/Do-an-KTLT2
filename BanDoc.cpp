#include "BanDoc.h"


CBanDoc::CBanDoc(void)
{
}
CBanDoc::CBanDoc(string maBanDoc, string Khoa ,string hoTen)
{
	m_maBanDoc = maBanDoc;
	m_Khoa = Khoa;
	m_hoTen = hoTen;
}
 void CBanDoc::xuat()
 {
	 cout<<" Ma Ban Doc :" << m_maBanDoc << endl;
	 cout << "Khoa " << m_Khoa << endl;
	 cout <<" Ho Ten :" << m_hoTen << endl;
 }

 string CBanDoc::getmaBanDoc()
 {
	 return m_maBanDoc;
 }
