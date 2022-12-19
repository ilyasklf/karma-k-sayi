/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			        B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				    PROGRAMLAMAYA G�R��� DERS�
**
**				    �DEV NUMARASI�...: 2. �dev
**				    ��RENC� ADI...............:�lyas Kalfa
**				    ��RENC� NUMARASI.: G211210056
**				    DERS GRUBU����:      1. ��retim A Grubu
****************************************************************************/


#include<iostream>
#include<string>
#include <sstream>
#include <string>
#include<math.h>
#include<cmath>
#include <complex>
 
using namespace std;

class komplex {                                        // Karma��k Say� S�n�f�

public:
	double reel;                                       // Say�n�n Ger�ek K�sm�
	double sanal;                                      // Say�n�n i li Say�n�n Kat Say�s�   
	komplex(double reel = 0, double sanal = 0) : reel(reel), sanal(sanal) {}


	komplex operator*=(const komplex& other) {            // *= (�ARPIP ATAMA) ��lemi ��in Olan Fonksiyon
		double real_part = reel * other.reel - sanal * other.sanal;
		double imag_part = reel * other.sanal + sanal * other.reel;
		reel = real_part;
		sanal = imag_part;
		return *this;
	}
	komplex operator/=(const komplex& other) {           // /= (B�L�P ATAMA) ��lemi ��in Olan Fonksiyon
		double divisor = other.reel * other.reel + other.sanal * other.sanal;
		double real_part = (reel * other.reel + sanal * other.sanal) / divisor;
		double imag_part = (sanal * other.reel - reel * other.sanal) / divisor;
		reel = real_part;
		sanal = imag_part;
		return *this;
	}
	void yazdir() {                                     //  Say�y� Yazd�rma Fonksiyonu 
		if(sanal>0)
			cout << reel << "+" << sanal << "i" << endl;
		if (sanal < 0)
			cout << reel << sanal << "i" << endl;
	}
	komplex operator+(komplex obj) {                     // + (TOPLAMA) ��lemi ��in Olan Fonksiyon
		komplex toplam;
		toplam.reel = reel + obj.reel;
		toplam.sanal = sanal + obj.sanal;
		return toplam;
	}
	friend komplex operator+=(komplex& obj, komplex& obj2) {           // += (TOPLAYIP ATAMA) ��lemi ��in Olan Fonksiyon
		obj.sanal += obj2.sanal; 
		obj.reel += obj2.reel;
		return obj;
	}
	komplex operator-(komplex obj) {                           // - (�IKARMA) ��lemi ��in Olan Fonksiyon
		komplex c�karma;
		c�karma.reel = reel - obj.reel;
		c�karma.sanal = sanal - obj.sanal;
		return c�karma;
	}
	friend komplex operator-=(komplex& obj, komplex& obj2) {          // -= (�IKARIP ATAMA) ��lemi ��in Olan Fonksiyon
		obj.sanal -= obj2.sanal;
		obj.reel -= obj2.reel;
		return obj;
	}
	komplex operator*(komplex obj) {                              // * (�ARPMA) ��lemi ��in Olan Fonksiyon
		komplex carpma;
		carpma.reel = (reel * obj.reel) - (sanal * obj.sanal);
		carpma.sanal = (sanal * obj.reel) + (reel * obj.sanal);
		return carpma;
	} 
	komplex operator/(komplex obj) {                              // / (B�LME) ��lemi ��in Olan Fonksiyon
		komplex bolum;
		double taban;
		taban = obj.reel * obj.reel + obj.sanal * obj.sanal;
		bolum.reel = (((reel * obj.reel) + (sanal * obj.sanal)) / taban);
		bolum.sanal = (((sanal * obj.reel) + (reel * -obj.sanal)) / taban);
		return bolum;
	}
};
void ciz() {
	cout << "-------------------------------------" << endl;                   // - �LE ��ZME FONKS�YONU
}
void yildiz() { 
	cout<<"*************************************" << endl;                    // * �LE ��ZME FONKS�YONU
}
int main() {
	setlocale(LC_ALL, "Turkish");
	ciz();
	cout << "Karma��k Say�larda ��lemler" << endl;
	ciz();
	while (true) {
		cout << "1-)TOPLAMA" << endl;
		cout << "2-)�IKARMA" << endl;
		cout << "3-)�ARPMA" << endl;
		cout << "4-)B�LME" << endl;
		cout << "5-)(+=) �LE TOPLAMA" << endl;
		cout << "6-)(-=) �LE �IKARMA" << endl;
		cout << "7-)(*=) �LE �ARPMA" << endl;
		cout << "8-)(/=) �LE B�LME" << endl;
		cout << "9-)KUTUPLARA AYIRMA" << endl;
		cout << "10-)�IKI�" << endl;
		int secim;
		cin >> secim;
		if (secim == 1) {
			system("cls");
			double reel1, reel2, sanal1, sanal2;
			cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
			cin >> reel1;
			cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
			cin >> sanal1;
			cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
			cin >> reel2;
			cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
			cin >> sanal2;
			yildiz();
			cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "+" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
			yildiz();
			komplex c1(reel1, sanal1);                        // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
			komplex c2(reel2, sanal2);                        // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
			komplex c3 = c1 + c2;                             // 3. NESNE OLU�TURULUP 1. VE 2. NESNE TOPLANIYOR
			ciz();
			cout << "SONU�.....:";
			c3.yazdir();                                      // YAZDIRILIYOR
			ciz();
			cout << endl;
		}
		else if (secim == 2) {
			system("cls");
			double reel1, reel2, sanal1, sanal2;
			cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
			cin >> reel1;
			cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
			cin >> sanal1;
			cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
			cin >> reel2;
			cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
			cin >> sanal2;
			yildiz();
			cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "-" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
			yildiz();				
			komplex c1(reel1, sanal1);                       // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
			komplex c2(reel2, sanal2);                       // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
			komplex c3 = c1 - c2;                            // 3. NESNE OLU�TURULUP 1. VE 2. NESNE �IKARTILIYOR
			ciz();
			cout << "SONU�.....:";
		    c3.yazdir();                                     // YAZDIRILIYOR
			ciz();
			cout << endl;
		}
		else if (secim == 3) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "*" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                         // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                         // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c3 = c1 * c2;                              // 3. NESNE OLU�TURULUP 1. VE 2. NESNE �ARPILIYOR
		ciz();
	    cout << "SONU�.....:";
		c3.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 4) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "/" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c3 = c1 / c2;                             // 3. NESNE OLU�TURULUP 1. VE 2. NESNE B�L�N�YOR
		ciz();
		cout << "SONU�.....:";
		c3.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 5) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "+=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		c1 += c2;                                         // 1. NESNEYE 2. NESNE EKLEN�YOR VE YEN� 1. NESNE OLU�UYOR
		ciz();
		cout << "SONU�.....:";
		c1.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 6) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "-=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		c1 -= c2;                                         // 1. NESNEYE 2. NESNE �IKARTILIYOR VE YEN� 1. NESNE OLU�UYOR
		ciz();
		cout << "SONU�.....:";
		c1.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 7) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl<<endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "*=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		c1 *= c2;                                         // 1. NESNEYE 2. NESNE �ARPILIYOR VE YEN� 1. NESNE OLU�UYOR
		ciz();
		cout << "SONU�.....:";
		c1.yazdir();                                      // YAZDIRILIYOR
		ciz();
		cout << endl;
		}
		else if (secim == 8) {
		system("cls");
		double reel1, reel2, sanal1, sanal2;
		cout << "1. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel1;
		cout << "1. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal1;
		cout << "2. Say�n�n Reel K�sm�n� Giriniz...:" << endl;
		cin >> reel2;
		cout << "2. Say�n�n Sanal K�sm�n� Giriniz...:" << endl;
		cin >> sanal2;
		yildiz();
		cout << "Yapaca��n�z ��lem :" << "(" << reel1 << "+" << sanal1 << "i" << ")" << "/=" << "(" << reel2 << "+" << sanal2 << "i" << ")" << endl;
		yildiz();
		komplex c1(reel1, sanal1);                        // 1. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		komplex c2(reel2, sanal2);                        // 2. NESNE OLU�TURULUP ALININ DE�ERLER AKTARILIYOR
		c1 /= c2;                                         // 1. NESNEYE 2. NESNE B�L�N�YOR VE YEN� 1. NESNE OLU�UYOR
		ciz();
		cout << "SONU�.....:";
		c1.yazdir();
		ciz();                                            // YAZDIRILIYOR
		cout << endl;
		}
		else if (secim == 9) {
			system("cls");
			double reel, sanal;
			cout << "Kutupsal G�stermek �stedi�iniz Say�n�n Reel K�sm�...:" << endl;
			cin >> reel;
			cout << "Kutupsal G�stermek �stedi�iniz Say�n�n Sanal K�sm�...:" << endl;
			cin >> sanal;
			if (sanal > 0)
				cout << "Say�n�z:" << reel << "+" << sanal << "i" << endl;
			else if (sanal < 0)
				cout << "Say�n�z:" << reel << sanal << "i" << endl;
			complex<double> z(reel, sanal);          // Z DE���KEN�N DE DE�ERLER TUTULUYOR
			double r = abs(z);                       // SAYININ MUTLAK DE�ER� ALIYOR VE AKTARILIYOR 
			double theda = arg(z);
			ciz();
			cout << "Karma��k Say�n�n Kutupsal G�sterimi: (" << r << "," << theda << ")" << endl;
			ciz();
		}
		else if (secim == 10) exit(0);
		else {
		ciz();
			cout << "Girdi�iniz Komut Yanl��"<<endl;
			ciz();
		}
	}
}