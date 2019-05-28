/*
	=====DO AN KY THUAT LAP TRINH===
	CHUONG TRINH: QUAN LY THU VIEN
*/
#include"PhieuMuon.h"
#include"BanDoc.h"
#include"Sach.h"
#include"GiaoVien.h"
#include"SinhVien.h"
#include<fstream>
#include<string.h>
#include <ctime>
#include <Windows.h>

void setColor(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void nhapUser();//Ham lay du lieu tu file User
void nhapSach(CSach* arrSach[], int &nS);//Nhap sach moi
void xuatDS(CSach* arrSach[], int &nS);// xuat ra man hinh file sach
void nhapDS(CSach* arrSach[], int &nS,ifstream &fin);//Ham lay du ieu sach tu file
void TimKiemVaHienThi(CSach* arrSach[],int &nS , string nKeyTuaDe);//Tim kiem va hien thi theo ten tua de
void nhapDSUser(CBanDoc* arrB[],int &nb,ifstream &sin);//dang ky user
void xuatUser(CBanDoc* arrB[], int &nb);//xuat user
void TimKiemBanDoc(CBanDoc* arrB[], int &nb,string KeyMaBD);//Tim kiem a in thong tin ban doc qua ma ban doc
int  TongsoLuongSachCL(CSach* arrSach[], int &nS);//Ham tinh tong so luong sach con lai trong thu vien
int  TongsoLuongSachDaMuon(CSach* arrSach[], int &nS);//Ham tinh tong so luong sach da muon
void nhapPhieuMuon (CBanDoc* arr[], int &nb, CPhieuMuon* arrPM[], CSach* arrSach[], int &nS);//Nhap phieu muon, va in ra file
void xuatPhieuMuon(CBanDoc* arr[], int nb, CPhieuMuon* arrPM[]);// xuat phieu muon ra man hinh
void getNgayMuon();// Ham ngay muon
void getNgayTra();//Ham ngay tra
int searchBook (CSach* arrB[], int ns);//ham tiem kiem sach trong thu vien


struct ltm 
{
  int tm_sec;   // so giay trong mot phut, tu 0 toi 61
  int tm_min;   // so phut trong mot gio, tu 0 toi 59
  int tm_hour;  // so gio trong mot ngay, tu 0 toi 24
  int tm_mday;  // ngay trong thang, tu 1 toi 31
  int tm_mon;   // thang trong nam, tu 0 toi 11
  int tm_year;  // nam, bat dau tu 1900
  int tm_wday;  // ngay, bat dau tu Sunday
  int tm_yday;  // ngay, bat dau tu 1/1
  int tm_isdst; // so gio cua Daylight Savings Time
};

int main()
{
	
	int nS = 0; 
	CSach* arrSach[20];
	CBanDoc* arrB[30];
	CPhieuMuon* arrPM[30];
	int nb =0;
	string KeyMaBD;
	//mo file Sach
	ifstream fin;
	fin.open("Book_Data.txt");
	if (fin.is_open())
	{
		fin >> nS;
		nhapDS(arrSach, nS, fin);
	}else
	{
		cout << "mo file khong thanh cong" << endl;
	}
	//mo file Ban doc
	ifstream sin;
	sin.open("User_DATA.txt");
	if (sin.is_open()== true)
	{
		sin >> nb;
		nhapDSUser(arrB, nb,sin);
	}else
	{
		cout << "mo file khong thanh cong" << endl;
	}
	
	int chon;
	setColor(10);
	cout << "\t\tChuong Trinh Quan Li Phieu Muon \n";
	cout << "1_In ra thong tin sach trong thu vien " << endl;
	cout << "2_Tim kiem va in ra chi tiet sach thong qua tua de" << endl;
	cout << "3_Tim kiem va in ra chi tiet ban doc thong qua ma ban doc" << endl;
	setColor(14);
	cout << "Quan ly, bao gom:" << endl;
	setColor(7);
	cout << "\t 4_Chuc Nang Quan Li" << endl;
	cout << "\t 5_Thoat" << endl;
	setColor(12);
	cout << "Moi chon 1 || 2 || 3 || 4 : ";
	setColor(7);
	cin >> chon;
	switch (chon) 
	{
	case 1 :
		{
			xuatDS(arrSach, nS);
			break;
		}
	case 2:
		{
			string nKeyTuaDe;
			cout<<"Nhap vao ten tua de can tim ";
			cin>> nKeyTuaDe;
			TimKiemVaHienThi(arrSach,nS,nKeyTuaDe);
			break;
		}
	case 3:
		{
			string KeyBD;
			TimKiemBanDoc(arrB,nb,KeyBD);
			break;
		}
		
	case 4:
		{
			int maTruyCap;
			cout << "Nhap ma truy cap: ";
			cin >> maTruyCap;
			if (maTruyCap == 1234)
			{
				cout << "1_Tao phieu muon moi va in ra file" << endl;
				cout << "2_Them Sach vao danh sach sach " << endl;
				cout << "3_Them ban doc" << endl;
				
				cout << "4_Thong ke so sach da muon" << endl;
				cout << "5_Thong ke so luong sach con lai trong thu vien " << endl;
				int chon1;
				setColor(12);
				cout << "Moi chon 1 || 2 || 3 || 4 || 5 : ";
				setColor(7);
				cin >> chon1;
				switch (chon1)
				{
				case 1:
					{
						nhapPhieuMuon(arrB, nb, arrPM, arrSach, nS);
						break;
					}
				case 2:
					{
						nhapSach(arrSach, nS);
						break;
					}
				case 3:
					{
						nhapUser();
						break;
					}
				case 4:
					{
						cout << "so luong sach da muon la:" << TongsoLuongSachDaMuon(arrSach, nS) << endl;
						break;
					}
				case 5:
					{
						cout << "So sach con lai trong thu vien la:" << TongsoLuongSachCL(arrSach, nS) << endl;
						break;
					}
				}
			}
			else
			{
				cout << "Ma truy cap khong dung!!\n";
				break;
			}
		}

	default:
		return 0;
	}
	system("pause");
	return 0;
}
//xuat thong tin cua ban doc
void xuat(CBanDoc* arr[], int &nb)
{
	for(int i = 0; i < nb ; i++)
	{
		arr[i]->xuat();
	}
}
//nhap va xuat danh sach sach vao file Book_Data.txt
void  nhapSach(CSach* arrSach[], int &nS)
{
	ofstream fout;
	fout.open("Book_Data.txt",ios::app);
	string maSach;
	string tacGia;
	string NXB;
	float triGia;
	int namPH;
	int soTrang;
	int ngay;
	int thang;
	int nam;
	int maPM;

	cout << "Nhap ma sach: ";
	cin >> maSach;
	cout << "Nhap vao tac gia: ";
	cin >> tacGia;
	cout << "Nhap NXB: ";
	cin >> NXB;
	cout << "Nhap vao tri gia: ";
	cin >> triGia;
	cout << "Nhap nam Phat hanh: ";
	cin >> namPH;
	cout << "Nhap so trang:";
	cin >> soTrang;
	cout <<" Nhap ngay nhap kho: ";
	cin >> ngay >> thang >> nam;
	maPM = 0;

	fout << maSach << endl;
	fout << tacGia << endl;
	fout << NXB << endl;
	fout << namPH << endl;
	fout << triGia << endl;
	fout << soTrang << endl;
	fout << ngay << endl;
	fout << thang << endl;
	fout << nam << endl;
	fout << maPM << endl;
	

	fout.close();
}
//nhap thong tin user vao file User
void nhapUser()
{
	ofstream fout;
	fout.open("User_Data.txt",ios::app);
	string maBanDoc;
	string Khoa;
	string hoTen;
	cout << "Nhap ma Ban Doc :" ;
	cin >> maBanDoc;
	cout << "Nhap khoa";
	cin >> Khoa;
	cout << "Nhap ho Ten :" ;
	fflush(stdin);
	getline(cin,hoTen);
	fout << maBanDoc << endl;
	fout << Khoa << endl;
	fout << hoTen << endl;
	int chon;
	cout << "1.Sinh vien " << endl << "2.Giao Vien" << endl;
	cout << "Nhap vao lua chon: ";
	cin >> chon;
	if(chon == 1)
	{
		int KhoaHoc;
		cout << "Nhap vao khoa hoc: ";
		cin >> KhoaHoc;
		fout << KhoaHoc << endl;
	}
	else if( chon == 2)
	{
		string diaChi;
		string SDT;
		cout << "Nhap dia chi: ";
		fflush(stdin);
		getline(cin,diaChi);
		cout << "Nhap vao SDT: ";
		cin >> SDT;
		fout << diaChi << endl;
		fout << SDT << endl;
	}

}
//nhap danh sach sach
void nhapDS(CSach* arrSach[], int &nS,ifstream &fin)
{
	string maSach;
	string tuaDe;
	string tacGia;
	string NXB;
	int namPH;
	float triGia;
	int soTrang;
	int ngay;
	int thang;
	int nam;
	int maPM;	

	for(int i = 0; i < nS ; i++)
	{
		fin >> maSach;
		fin >> tuaDe;
		fin >> tacGia;
		fin >> NXB;
		fin >> namPH;
		fin >> triGia;
		fin >> soTrang;
		fin >> ngay;
		fin >> thang;
		fin >> nam;
		fin >> maPM;
		arrSach[i] = new CSach(maSach,tuaDe,tacGia,NXB,namPH,triGia,soTrang,ngay,thang,nam,maPM);
	}
}

//xuat danh sach sach ra man hinh
void xuatDS(CSach* arrSach[], int &nS)
{
	cout<<" Trong thu vien gom :" << nS << "cuon sach "<< endl;
	for(int i = 0; i < nS ; i++)
	{
		arrSach[i]->xuat();
	}
}
//tim kiem va xuat thong tin cua sach
void TimKiemVaHienThi(CSach* arrSach[],int &nS , string nKeyTuaDe)
{

	for(int i = 0; i < nS; i++)
	{
		if(arrSach[i]->getTuaDe() == nKeyTuaDe)
		{
			arrSach[i]->xuat();
			break;
		}
		else
		{
			cout<< "Khong tim thay sach";
		}
	}
}

//nhap thong tin user
void nhapDSUser(CBanDoc* arrB[], int &nb, ifstream &sin)
{
	
	string maBanDoc;
	string Khoa;
	string hoTen;
	for(int i = 0; i < nb ; i++)
	{
		string diaChi;
		string SDT;
		string KhoaHoc;
		sin >> maBanDoc;
		sin >> Khoa;
		sin >> hoTen;
		string Temp;
		Temp = maBanDoc.substr(0,2);
		if(Temp == "gv")
		{
			sin >> diaChi;
			sin >> SDT;
			arrB[i] = new CGiaoVien(maBanDoc,Khoa,hoTen,diaChi,SDT);
		}
		else
		{
			sin >> KhoaHoc;
			arrB[i] = new CSinhVien(maBanDoc,Khoa,hoTen,KhoaHoc);
		}
	}
	
}
//xuat thong tin user
void xuatUser(CBanDoc* arrB[], int &nb)
{
	cout<<"Danh sach gom " << nb << endl;
	
	for(int i = 0; i < nb; i++)
	{
	
		arrB[i]->xuat();
	}
}

//tim kiem ban doc 
void TimKiemBanDoc(CBanDoc* arrB[], int &nb,string KeyMaBD)
{
	cout <<"Nhap vao ma ban doc can tim ";
	cin >> KeyMaBD;

	for (int i = 0; i < nb ; i++)
	{
		if(arrB[i]->getmaBanDoc() == KeyMaBD)
		{
			arrB[i]->xuat();
			break;
		}	
	}	
}
//Tong so luong sach con lai trong thu vien
int  TongsoLuongSachCL(CSach* arrSach[], int &nS)
{ 
	int nDem = 0;
	for(int i = 0; i < nS; i++)
	{
		if(arrSach[i]->getmaPM() == 0)
		{
			nDem++;
		}
	}
	return nDem;
}

//tong so luong sach da muon
int  TongsoLuongSachDaMuon(CSach* arrSach[], int &nS)
{ 
	int nDem = 0;
	for(int i = 0; i < nS; i++)
	{
		if(arrSach[i]->getmaPM() != 0)
		{
			nDem++;
		}
	}
	return nDem;
}
//tim kiem sach
int searchBook (CSach* arrSach[], int nS)
{
	ifstream fin;
	fin.open("Sach.txt");
	string keyNameBook;
	cout << "Nhap ten sach can muon: ";
	cin >> keyNameBook;
	int nVT = 0;
	for (int i = 0; i < nS; i++)
	{
		if (keyNameBook == arrSach[i]->getTuaDe())
		{
			nVT = i;
			return nVT;
		}	
	}
	return -1;
	fin.close();
	
}

//nhap thong tin phieu muon
void nhapPhieuMuon (CBanDoc* arrB[], int &nb, CPhieuMuon* arrPM[], CSach* arrSach[], int &nS)
{
	ifstream fin;
	fin.open("Book_Data.txt");
	if (fin.is_open())
	{
		fin >> nS;
		nhapDS(arrSach, nS, fin);
	}else
	{
		cout << "mo file khong thanh cong" << endl;
	}

	ifstream sin;
	sin.open("User_Data.txt");
	if (sin.is_open()== true)
	{
		sin >> nb;
		nhapDSUser(arrB, nb,sin);
	}else
	{
		cout << "mo file khong thanh cong" << endl;
	}

	int soPhieuMuon = 0;
	string maBanDoc;
	string Khoa;
	string hoTen;
	string maSachMuon;
	string tuaDe;
	string tacGia;
	string NXB;
	float triGia = 0;
	int namPH = 0;
	int soTrang = 0;
	int ngay = 0;
	int thang = 0;
	int nam = 0;
	int maPM = 0;
	int tinhTrang = 0;
	string keyPerson;
	cout << "Nhap Ma Ban Doc: ";
	cin >> keyPerson;
	int nVT = searchBook(arrSach, nS);
	for (int i = 0; i < nb ;i++)
	{
		//kiem tra xem nguoi dung da dang ky chua
		if(arrB[i]->getmaBanDoc() == keyPerson)
		{
			keyPerson = arrB[i]->getmaBanDoc();
			for( int j = 0; j < nS ; j++)
			{
				if (nVT != -1)
				{
					maSachMuon = arrSach[nVT]->getmaSach();
					tinhTrang = 1;
					soPhieuMuon++;	
					maPM = soPhieuMuon;
				}
				else if (nVT == -1)
				{
					cout << "Khong tim thay sach trong thu vien: " << endl;
					return;
				}
			
			}
			arrPM[i] = new CPhieuMuon(soPhieuMuon, keyPerson, Khoa, hoTen, maSachMuon, tuaDe, tacGia, NXB, triGia, namPH, soTrang, ngay, thang, nam, maPM, tinhTrang);	
		}
	}
		ofstream fout;
		fout.open("PhieuMuon.txt",ios::app);
		fout <<"so phieu muon " << soPhieuMuon <<endl;
		fout <<"Ma nguoi muon " << keyPerson << endl;
		fout <<"Ma Sach " << maSachMuon << endl;
		fout <<"Tinh trang :" << tinhTrang << endl;
		getNgayMuon();
		getNgayTra();
		fout.close();
}


//
//	
//}
////
////xuat phieu muon
void xuatPhieuMuon(CBanDoc* arrB[], int nb, CPhieuMuon* arrPM[])
{
	
	cout << "===>Thong tin phieu muon" << endl;
	for (int i = 0; i < nb; i++)
	{
		arrPM[i]->xuat();

		break;
		//getNgayMuon();
	}

}
void getNgayMuon()
{
	 ofstream fout;
	fout.open("PhieuMuon.txt",ios::app);
   // tra ve date/time hien tai dua tren system hien tai
   time_t baygio = time(0);
   tm *ltm = localtime(&baygio);
  
   // in cac thanh phan cua cau truc tm struct.
   fout << "Ngay Muon: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon  << "/";
   fout <<  1900 + ltm->tm_year << endl;
   fout << "Thoi gian: "<< ltm->tm_hour << ":";
   fout << 1 + ltm->tm_min << ":";
   fout << 1 + ltm->tm_sec << endl;
}
void getNgayTra()
{
	ofstream fout;
	fout.open("PhieuMuon.txt",ios::app);
   // tra ve date/time hien tai dua tren system hien tai
   time_t baygio = time(0);
   tm *ltm = localtime(&baygio);
   // in cac thanh phan cua cau truc tm struct.
   fout << "Ngay Tra "<< ltm->tm_mday + 7 << "/" << 1 + ltm->tm_mon << "/" <<  1900 + ltm->tm_year << endl;
   fout << "Thoi gian: "<< 1 + ltm->tm_hour << ":";
   fout << 1 + ltm->tm_min << ":";
   fout << 1 + ltm->tm_sec << endl;
}
