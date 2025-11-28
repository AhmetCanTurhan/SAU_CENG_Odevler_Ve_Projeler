/****************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** PROGRAMLAMAYA GİRİŞİ DERSİ
**
** ÖDEV NUMARASI…...: 1
** ÖĞRENCİ ADI...............:	AHMET CAN TURHAN
** ÖĞRENCİ NUMARASI.: B251210010
** DERS GRUBU…………: C GRUBU
****************************************************************************/


#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cmath>
#include <iomanip>

//İsim uzayının kullanılması
using namespace std;

//Öğrenci isimli yapının tanımlanması
struct Ogrenci
{
	//Öğrenci bilgileri ve notlarının tutulacağı değişkenler
	string isim, soyisim, sehir, dersinAdi, telefon;
	short int odev1, odev2, projeNot, vizeNot, finalNot;

	//Yıl içi not hesaplama fonksiyonu
	double YiliciHesapla(double odev1Yuzde, double odev2Yuzde, double projeYuzde, double vizeYuzde)
	{
		double YiliciNot = (odev1 * odev1Yuzde) + (odev2 * odev2Yuzde) + (projeNot * projeYuzde) + (vizeNot * vizeYuzde);
		return YiliciNot;
	}

	//Ders ortalamasını (sayısal) hesaplamak için fonksiyon
	double DersOrtHesapla(double yiliciNot, double finalYuzde)
	{
		return (yiliciNot * (1.0 - finalYuzde)) + (finalNot * finalYuzde);
	}

	//Harf notunu string olarak döndüren fonksiyon
	string HarfNotu(double dersOrt)
	{
		//Fonksiyon içindeki harf notu karşılaştırmaları ve notların döndürülmesi
		if (dersOrt >= 90) return "AA"; //90 ve üzeri için AA döndür
			else if (dersOrt >= 85) return "BA"; //85-89 için BA döndür
			else if (dersOrt >= 80) return "BB"; //80-84 için BB döndür
			else if (dersOrt >= 75) return "CB"; //75-79 için CB döndür
			else if (dersOrt >= 65) return "CC"; //65-74 için CC döndür
			else if (dersOrt >= 58) return "DC"; //58-64 için DC döndür
			else if (dersOrt >= 50) return "DD"; //50-57 için DD döndür
			else if (dersOrt >= 40) return "FD"; //40-49 için FD döndür
		else return "FF"; //40'ın altı için FF döndür
	}
};

int main()
{
	//Türkçe karakter barındıran isimleri yazdırmak için locale ayarı
	setlocale(LC_ALL, "Turkish");

	//Tablo başlıkları
	cout << "  Ad      Soyad          Ödev1 Ödev2 Proje Vize  Final Harf Sayısal    Telefon	    Şehir\n";
	cout << "------   -------         ----- ----- ----- ----- ----- ---- -------  -----------  ---------\n";

	//Küsüratlı sayılar için virgülden sonra 2 basamak gösterimi (sınıf ortalaması ve standart sapma için)
	cout << fixed << setprecision(2);

	//Yüz öğrencilik bir sınıf oluşturuldu
	Ogrenci ProgramlamayaGiris[100];

	//30 tane isim eklendi
	string isimler[30] =
	{
		"Ahmet", "Mehmet", "Ayşe", "Fatma", "Mustafa",
		"Zeynep", "Emre", "Elif", "Can", "Cem",
		"Deniz", "Burak", "Selin", "Esra", "Yusuf",
		"Ömer", "Gökhan", "Hakan", "İrem", "Kaan",
		"Leyla", "Merve", "Nihat", "Orhan", "Pınar",
		"Rıza", "Sinem", "Tolga", "Umut", "Yağmur"
	};

	//30 tane soyisim eklendi
	string soyisimler[30] =
	{
		"Yılmaz", "Kaya", "Demir", "Şahin", "Çelik",
		"Arslan", "Doğan", "Kılıç", "Aydın", "Öztürk",
		"Polat", "Güneş", "Yıldız", "Kurt", "Koç",
		"Aksoy", "Erdem", "Taş", "Bulut", "Duman",
		"Erdoğan", "Gül", "Işık", "Kara", "Turan",
		"Uçar", "Vural", "Yalçın", "Zengin", "Özdemir"
	};

	//15 tane şehir eklendi
	string sehirler[15] =
	{
		"İstanbul", "Ankara", "İzmir", "Bursa", "Antalya",
		"Muş", "Sivas", "Gaziantep", "Edirne", "Bolu",
		"Trabzon", "Konya", "Kayseri", "Adana", "Van"
	};


	double sinifYilIciToplam = 0.0; //Sınıfın yıl içi not toplamı
	double notlar[100]; //Öğrencilerin notlarını tutmak için dizi

	//Harf notu sayacı değişkenleri
	int sayacAA = 0, sayacBA = 0, sayacBB = 0, sayacCB = 0;
	int sayacCC = 0, sayacDC = 0, sayacDD = 0, sayacFD = 0, sayacFF = 0;

	//Rastgele sayı üretimi için
	srand(time(0));

	//100 öğrencinin bilgilerini ve notlarını doldurma döngüsü
	for (int i = 0; i < 100 ; i++)
	{
		string telefonNo = "05"; //Telefon numarasının ilk iki hanesi değişkene atandı

		//Telefon numarasının geri kalan 9 hanesi için döngü
		for (int t = 0; t < 9; t++)
		{
			telefonNo += static_cast<char>('0' + (rand() % 10));
		}

		//Öğrenci bilgilerini doldurma
		ProgramlamayaGiris[i].isim = isimler[rand() % 30]; //0-29 arasında rastgele isim seçimi
		ProgramlamayaGiris[i].soyisim = soyisimler[rand() % 30]; //0-29 arasında rastgele soyisim seçimi
		ProgramlamayaGiris[i].sehir = sehirler[rand() % 15]; //0-9 arasında rastgele şehir seçimi
		ProgramlamayaGiris[i].telefon = telefonNo; //Rastgele oluşturulan telefon numarasının atanması
		ProgramlamayaGiris[i].odev1 = rand() % 101; //0-100 arasında rastgele not verilmesi
		ProgramlamayaGiris[i].odev2 = rand() % 101;
		ProgramlamayaGiris[i].projeNot = rand() % 101;
		ProgramlamayaGiris[i].vizeNot = rand() % 101;
		ProgramlamayaGiris[i].finalNot = rand() % 101;
		ProgramlamayaGiris[i].dersinAdi = "Programlamaya Giriş";

		double yilIci = ProgramlamayaGiris[i].YiliciHesapla(0.10, 0.10, 0.20, 0.60); //Yıl içi not hesaplama
		double dersOrt = ProgramlamayaGiris[i].DersOrtHesapla(yilIci, 0.50); //Final ile birlikte genel ders ortalaması
		string harf = ProgramlamayaGiris[i].HarfNotu(dersOrt); //Harf notunun hesaplanması
		double notunSayisalDegeri = (yilIci * 0.50) + (ProgramlamayaGiris[i].finalNot * 0.50); //Öğrencinin notunun sayısal değerinin hesaplanması
		notlar[i] = notunSayisalDegeri; //Notların diziye eklenmesi
		sinifYilIciToplam += yilIci; //Sınıfın yıl içi not toplamının hesaplanması


		//Harf notu sayacının artırılmasını sağlayan karşılaştırma
		if (notunSayisalDegeri >= 90) { //90 ve üzeri için AA sayacı artırma
			sayacAA++;
		}
			else if (notunSayisalDegeri >= 85) { //85-89 için BA sayacı artırma
				sayacBA++;
		}
			else if (notunSayisalDegeri >= 80) { //80-84 için BB sayacı artırma
				sayacBB++;
		}
			else if (notunSayisalDegeri >= 75) { //75-79 için CB sayacı artırma
				sayacCB++;
		}
			else if (notunSayisalDegeri >= 65) { //65-74 için CC sayacı artırma
				sayacCC++;
		}
			else if (notunSayisalDegeri >= 58) { //58-64 için DC sayacı artırma
				sayacDC++;
		}
			else if (notunSayisalDegeri >= 50) { //50-57 için DD sayacı artırma	
				sayacDD++;
		}
			else if (notunSayisalDegeri >= 40) { //40-49 için FD sayacı artırma
				sayacFD++;
		}
		else { //40'ın altı için FF sayacı artırma
			sayacFF++; 
		}

		//Öğrenci bilgilerini tablo formatında yazdırma
		cout << left << setw(9) << ProgramlamayaGiris[i].isim
			<< setw(16) << ProgramlamayaGiris[i].soyisim
			<< setw(6) << ProgramlamayaGiris[i].odev1
			<< setw(6) << ProgramlamayaGiris[i].odev2
			<< setw(6) << ProgramlamayaGiris[i].projeNot
			<< setw(6) << ProgramlamayaGiris[i].vizeNot
			<< setw(6) << ProgramlamayaGiris[i].finalNot
			<< setw(5) << harf << setw(9) << dersOrt
			<< setw(13) << telefonNo
			<< ProgramlamayaGiris[i].sehir << endl;

	}

	//Sınıfın yıl içi not ortalaması
	double sinifYilIciOrt = sinifYilIciToplam / 100.0;

	//Standart sapma hesaplama
	double varyansToplami = 0.0;
	for (int i = 0; i < 100; i++) //Her öğrencinin notu için döngü
	{
		varyansToplami += pow((notlar[i] - sinifYilIciOrt), 2);
	}
	double standartSapma = sqrt(varyansToplami / 100.0);

	//Sınıf istatistiklerini yazdırma
	cout << "\n\n-------------------------------\n";
	cout << "DERSİN ADI: " << ProgramlamayaGiris[0].dersinAdi << endl;
	cout << "-------------------------------\n";

	cout << "\n\n-------------------------\n";
	cout << "SINIF ISTATISTIKLERI\n";
	cout << "-------------------------\n";

	cout << "Sınıfın Ortalaması: " << sinifYilIciOrt << endl;
	cout << "Standart Sapma: " << standartSapma << endl;
	cout << "\n\n----------------------------------\n";
	cout << "HARF NOTU YUZDELIK DAGILIMLARI (%)\n";
	cout << "----------------------------------\n";
	cout << "AA: %" << sayacAA << endl;
	cout << "BA: %" << sayacBA << endl;
	cout << "BB: %" << sayacBB << endl;
	cout << "CB: %" << sayacCB << endl;
	cout << "CC: %" << sayacCC << endl;
	cout << "DC: %" << sayacDC << endl;
	cout << "DD: %" << sayacDD << endl;
	cout << "FD: %" << sayacFD << endl;
	cout << "FF: %" << sayacFF << endl;

	return 0;
}