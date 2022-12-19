/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			        BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				    PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				    ÖDEV NUMARASI…...: 2. Ödev
**				    ÖÐRENCÝ ADI...............:Ýlyas Kalfa
**				    ÖÐRENCÝ NUMARASI.: G211210056
**				    DERS GRUBU…………:      1. Öðretim A Grubu
****************************************************************************/


#include<iostream>
#include<string>
#include <sstream>
#include <string>
#include<math.h>
#include<cmath>
#include <complex>
 
using namespace std;

class komplex {                                        // Karmaþýk Sayý Sýnýfý

public:
	double reel;                                       // Sayýnýn Gerçek Kýsmý
	double sanal;                                      // Sayýnýn i li Sayýnýn Kat Sayýsý   
	komplex(double reel = 0, double sanal = 0) : reel(reel), sanal(sanal) {}


	komplex operator*=(const komplex& other) {            // *= (ÇARPIP ATAMA) Ýþlemi Ýçin Olan Fonksiyon
		double real_part = reel * other.reel - sanal * other.sanal;
		double imag_part = reel * other.sanal + sanal * other.reel;
		reel = real_part;
		sanal = imag_part;
		return *this;
	}
	komplex operator/=(const komplex& other) {           // /= (BÖLÜP ATAMA) Ýþlemi Ýçin Olan Fonksiyon
		double divisor = other.reel * other.reel + other.sanal * other.sanal;
		double real_part = (reel * other.reel + sanal * other.sanal) / divisor;
		double imag_part = (sanal * other.reel - reel * other.sanal) / divisor;
		reel = real_part;
		sanal = imag_part;
		return *this;
	}
	void yazdir() {                                     //  Sayýyý Yazdýrma Fonksiyonu 
		if(sanal>0)
			cout << reel << "+" << sanal << "i" << endl;
		if (sanal < 0)
			cout << reel << sanal << "i" << endl;
	}
	komplex operator+(komplex obj) {                     // + (TOPLAMA) Ýþlemi Ýçin Olan Fonksiyon
		komplex toplam;
		toplam.reel = reel + obj.reel;
		toplam.sanal = sanal + obj.sanal;
		return toplam;
	}
	friend komplex operator+=(komplex& obj, komplex& obj2) {           // += (TOPLAYIP ATAMA) Ýþlemi Ýçin Olan Fonksiyon
		obj.sanal += obj2.sanal; 
		obj.reel += obj2.reel;
		return obj;
	}
	komplex operator-(komplex obj) {                           // - (ÇIKARMA) Ýþlemi Ýçin Olan Fonksiyon
		komplex cýkarma;
		cýkarma.reel = reel - obj.reel;
		cýkarma.sanal = sanal - obj.sanal;
		return cýkarma;
	}
	friend komplex operator-=(komplex& obj, komplex& obj2) {          // -= (ÇIKARIP ATAMA) Ýþlemi Ýçin Olan Fonksiyon
		obj.sanal -= obj2.sanal;
		obj.reel -= obj2.reel;
		return obj;
	}
	komplex operator*(komplex obj) {                              // * (ÇARPMA) Ýþlemi Ýçin Olan Fonksiyon
		komplex carpma;
		carpma.reel = (reel * obj.reel) - (sanal * obj.sanal);
		carpma.sanal = (sanal * obj.reel) + (reel * obj.sanal);
		return carpma;
	} 
	komplex operator/(komplex obj) {                              // / (BÖLME) Ýþlemi Ýçin Olan Fonksiyon
		komplex bolum;
		double taban;
		taban = obj.reel * obj.reel + obj.sanal * obj.sanal;
		bolum.reel = (((reel * obj.reel) + (sanal * obj.sanal)) / taban);
		bolum.sanal = (((sanal * obj.reel) + (reel * -obj.sanal)) / taban);
		return bolum;
	}
};
void ciz() {
	cout << "-------------------------------------" << endl;                   // - ÝLE ÇÝZME FONKSÝYONU
}
void yildiz() { 
	cout<<"*************************************" << endl;                    // * ÝLE ÇÝZME FONKSÝYONU
}
int main() {
	setlocale(LC_ALL, "Turkish");
	ciz();
	cout << "Karmaþýk Sayýlarda Ýþlemler" << endl;
	ciz();
	while (true) {
		cout << "1-)TOPLAMA" << endl;
		cout << "2-)ÇIKARMA" << endl;
		cout << "3-)ÇARPMA" << endl;
		cout << "4-)BöLME" << endl;
		cout << "5-)(+=) ÝLE TOPLAMA" << endl;
		cout << "6-)(-=) ÝLE ÇIKARMA" << endl;
		cout << "7-)(*=) ÝLE ÇARPMA" << endl;
		cout << "8-)(/=) ÝLE BöLME" << endl;
		cout << "9-)KUTUPLARA AYIRMA" << endl;
		cout << "10-)ÇIKIÞ" << endl;
		int secim;
		cin >> secim;
		if (secim == 1) {
			system("cls");
			double reel1, reel2, sanal1, sanal2;
			cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
			cin >> reel1;
			cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
			cin >> sanal1;
			cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
			cin >> reel2;
			cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
			cin >> sanal2;
			yildiz();
			cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "+" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
			yildiz();
			komplex c1(reel1, sanal1);                        // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
			komplex c2(reel2, sanal2);                        // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
			komplex c3 = c1 + c2;                             // 3. NESNE OLUÞTURULUP 1. VE 2. NESNE TOPLANIYOR
			ciz();
			cout << "SONUÇ.....:";
			c3.yazdir();                                      // YAZDIRILIYOR
			ciz();
			cout << endl;
		}
		else if (secim == 2) {
			system("cls");
			double reel1, reel2, sanal1, sanal2;
			cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
			cin >> reel1;
			cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
			cin >> sanal1;
			cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
			cin >> reel2;
			cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
			cin >> sanal2;
			yildiz();
			cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "-" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
			yildiz();				
			komplex c1(reel1, sanal1);                       // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
			komplex c2(reel2, sanal2);                       // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
			komplex c3 = c1 - c2;                            // 3. NESNE OLUÞTURULUP 1. VE 2. NESNE ÇIKARTILIYOR
			ciz();
			cout << "SONUÇ.....:";
		    c3.yazdir();                                     // YAZDIRILIYOR
			ciz();
			cout << endl;
		}
		else if (secim == 3) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "*" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                         // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                         // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c3 = c1 * c2;                              // 3. NESNE OLUÞTURULUP 1. VE 2. NESNE ÇARPILIYOR
		ciz();
	    cout << "SONUÇ.....:";
		c3.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 4) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "/" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c3 = c1 / c2;                             // 3. NESNE OLUÞTURULUP 1. VE 2. NESNE BÖLÜNÜYOR
		ciz();
		cout << "SONUÇ.....:";
		c3.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 5) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "+=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		c1 += c2;                                         // 1. NESNEYE 2. NESNE EKLENÝYOR VE YENÝ 1. NESNE OLUÞUYOR
		ciz();
		cout << "SONUÇ.....:";
		c1.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 6) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "-=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		c1 -= c2;                                         // 1. NESNEYE 2. NESNE ÇIKARTILIYOR VE YENÝ 1. NESNE OLUÞUYOR
		ciz();
		cout << "SONUÇ.....:";
		c1.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 7) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "*=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		c1 *= c2;                                         // 1. NESNEYE 2. NESNE ÇARPILIYOR VE YENÝ 1. NESNE OLUÞUYOR
		ciz();
		cout << "SONUÇ.....:";
		c1.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 8) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Sayýnýn Reel Kýsmýný Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Sayýnýn Sanal Kýsmýný Giriniz...:" << endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapacaðýnýz Ýþlem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "/=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLUÞTURULUP ALININ DEÐERLER AKTARILIYOR
		c1 /= c2;                                         // 1. NESNEYE 2. NESNE BÖLÜNÜYOR VE YENÝ 1. NESNE OLUÞUYOR
		ciz();
		cout << "SONUÇ.....:";
		c1.yazdir();
		ciz();                                            // YAZDIRILIYOR
		cout << endl;
		}
		else if (secim == 9) {
			system("cls");
			double reel, sanal;
			cout << "Kutupsal Göstermek Ýstediðiniz Sayýnýn Reel Kýsmý...:" << endl;
			cin >> reel;
			cout << "Kutupsal Göstermek Ýstediðiniz Sayýnýn Sanal Kýsmý...:" << endl;
			cin >> sanal;
			if (sanal > 0)
				cout << "Sayýnýz:" << reel << "+" << sanal << "i" << endl;
			else if (sanal < 0)
				cout << "Sayýnýz:" << reel << sanal << "i" << endl;
			complex<double> z(reel, sanal);          // Z DEÐÝÞKENÝN DE DEÐERLER TUTULUYOR
			double r = abs(z);                       // SAYININ MUTLAK DEÐERÝ ALIYOR VE AKTARILIYOR 
			double theda = arg(z);
			ciz();
			cout << "Karmaþýk Sayýnýn Kutupsal Gösterimi: (" << r << "," << theda << ")" << endl;
			ciz();
		}
		else if (secim == 10) exit(0);
		else {
		ciz();
			cout << "Girdiðiniz Komut Yanlýþ"<<endl;
			ciz();
		}
	}
}