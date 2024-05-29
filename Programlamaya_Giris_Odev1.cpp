/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 1. ÖDEV
**				ÖĞRENCİ ADI...............: EREN KARTAL
**				ÖĞRENCİ NUMARASI.: B231210065
**				DERS GRUBU…………: A GRUBU 1. ÖĞRETİM
****************************************************************************/



#include <iostream>
using namespace std;

//Bu değişkenler fonksiyon içinde de kullanılacağı için main fonksiyonunun dışında tanımlanmıştır.
int sayiAA = 0, sayiBA = 0, sayiBB = 0, sayiCB = 0, sayiCC = 0, sayiDC = 0, sayiDD = 0, sayiFD = 0, sayiFF = 0;

string harfPuaniHesaplayici(int);								//Harf notu hesaplayan ve harf notu adetini sayan fonksiyonun deklarasyonu

int main() {

	system("Color 30");											//Konsol ekranı renk ayarı
	setlocale(LC_ALL, "Turkish");								//Türkçe desteği					

	//Değişken tanımlama
	float yil_ici_agirlik, vize_agirlik, odev_1_agirlik, odev_2_agirlik, kisaSinav_1_agirlik, kisaSinav_2_agirlik, final_agirlik;
	int sinif_mevcudu;
	float vizeToplam = 0, odev1Toplam = 0, odev2Toplam = 0, kisaSinav1Toplam = 0, kisaSinav2Toplam = 0, finalToplam = 0, yil_sonuToplam = 0;
	int vizeMAX = 0, odev1MAX = 0, odev2MAX = 0, kisaSinav1MAX = 0, kisaSinav2MAX = 0, finalMAX = 0, yil_sonuMAX = 0;
	int vizeMIN = 100, odev1MIN = 100, odev2MIN = 100, kisaSinav1MIN = 100, kisaSinav2MIN = 100, finalMIN = 100, yil_sonuMIN = 100;
	int standart_sapma_vize = 0, standart_sapma_odev1 = 0, standart_sapma_odev2 = 0, standart_sapma_kisaSinav1 = 0, standart_sapma_kisaSinav2 = 0, standart_sapma_final = 0, standart_sapma_yilsonu = 0;
	int sapvize = 0, sapOdev1 = 0, sapOdev2 = 0, sapKisaSinav1 = 0, sapKisaSinav2 = 0, sapFinal = 0, sapYilsonu = 0;


	//Kullanıcıdan girdi alma
	cout << "Sınıf mevcudunu giriniz" << endl;
	cin >> sinif_mevcudu;
	cout << "(ondalıklı olarak giriniz)" << endl << endl;
	cout << "Vize notunun yıl içi puanına etkisini giriniz:" << endl;
	cin >> vize_agirlik;
	cout << "1. ödev notunun yıl içi puanına etkisini giriniz:" << endl;
	cin >> odev_1_agirlik;
	cout << "2. ödev notunun yıl içi puanına etkisini giriniz:" << endl;
	cin >> odev_2_agirlik;
	cout << "1. kısa sınav notunun yıl içi puanına etkisini giriniz:" << endl;
	cin >> kisaSinav_1_agirlik;
	cout << "2. kısa sınav notunun yıl içi puanına etkisini giriniz:" << endl;
	cin >> kisaSinav_2_agirlik;

	cout << "Yıl içi notunun yıl sonu puanına etkisini giriniz:" << endl;
	cin >> yil_ici_agirlik;
	system("CLS");									//Ekran temizleme


	final_agirlik = 1 - yil_ici_agirlik;			//Final notunun ağırlık hesabı


	//İsim ve Soyisim Dizileri
	int rastgele_isim = 0, rastgele_soyisim = 0;
	string isim_dizi[108] =
	{

			"Eren",		"İrem",		"Hilal",	"Hakan",	"Lütfi",	"Ahmet",	"Zülfiye",	"Aydanur",	"Taha",
			"Furkan",	"Faruk",	"Emin",		"Ertuğrul",	"Berat",	"Muhammed",	"Gönül",	"Melike",	"Gizem",
			"Duru",		"Sema",		"Gülizar",	"Mehmet",	"Nejat",	"Selman",	"Berkay",	"Faik",		"Orçun",
			"Sago",		"Behzat",	"İsmet",	"Yücel",	"Nilay",	"Dilay",	"Tuğba",	"Beyza",	"Ebrar",
			"Cenk",		"Ayşegül",	"Ryan",		"Patrick",	"Adem",		"Ela",		"Iana",		"Mustafa",	"Ömer",
			"Batuhan",	"Nazlı",	"Naz",		"Eylül",	"Eylem",	"Kutay",	"Katip",	"Firdevs",	"Fazıl",
			"Fazlı",	"Süleyman",	"Hakkı",	"Hamid",	"Selman",	"Nurhayat",	"Oğuz",		"Kaan",		"Abdülhamit",
			"Meryem",	"İsa",		"Musa",		"Dilan",	"Engin",	"Subutay",	"Lale",		"Menekşe",	"Sümbül",
			"Uğur",		"Irmak",	"Sinem",	"Gökhan",	"Hale",		"Yücel",	"Yusuf",	"Yücel",	"Veysel",
			"Zöhre",	"Elif",		"Polat",	"Marla",	"Carla",	"Samet",	"Rıza",		"Ramiz",	"Sinan",
			"Gül",		"Jale",		"Tülay",	"Tülin",	"Nuran",	"Hatice",	"Hilmi",	"Muhsin",	"Kemal",
			"Nurullah", "Ferhunde", "Alihan",   "Alişan",   "Julide",   "Fadime",	"Eyşan",	"Ezel",		"Cengiz",

	};

	string soyisim_dizi[108] =
	{

			"Kartal",	"Koc",		"Firtina",	"Altas",	"Özdin",	"Sağlam",	"Özturk",	"Purut",	"Tur",
			"Duyuş",	"İzgi",		"Dokumacı",	"Göksu",	"Büyükgöz",	"İşleyen",	"Kütük",	"İnci",		"Kızgır",
			"İşler",	"Kaya",		"Mutlu",	"Kevgir",	"Yanbasan",	"Sonuç",	"İşler",	"Batemoğlu","Hatipoğlu",
			"Şimşir",	"Safitürk",	"Kajmer",	"Felek",	"Bağdat",	"Arıkan",	"Clint",	"Gosli",	"Şerefli",
			"Dindar",	"Koru",		"Adıgüzel",	"Anlı",		"Tugay",	"Çe",		"Sardunya",	"Morsümbül","Ertan",
			"Kaf",		"Hancıkızı","Hansancar","Almış",	"Çalık",	"Elma",		"Yıldız",	"Yılmaz",	"Yaren",
			"Yener",	"Kutlu",	"Kutalmış",	"Gündoğan",	"Gündoğdu",	"Güneş",	"Damsız",	"Atsız",	"Erkan",
			"Kazım",	"Orhanoğlu","Ispıtkızı","Fırfır",	"Vestel",	"Şatoğlu",	"Alemdar",	"Zeloğlu",	"Sömüncü",
			"Somuncu",	"Tutarlı",	"Fadıl",	"Ömür",		"Tıngır",	"Zanlı",	"Tılsım",	"Erdoğan",	"Bayraktar",
			"Babacan",	"Ağlayan",	"Binali",	"Özaslan",	"Saldıray",	"Kaldıray",	"Daldıray", "Hatipoğlu","Altun",
			"Bozkurt",	"Olcay",	"Uysal",	"Aboubakar","Çebi",		"Fatımi",	"Yazıcım",	"Yaren",	"Yazıcıoğlu",
			"Süngü",	"Irgat",	"Delgeç",	"Dolayan",	"Qabip",	"Manduri",	"Uzunyayla","Pal",		"Bal",


	};


	//Öğrenci veri yapısı
	struct
	{

		string isim, soyisim;
		int vizeNotu, odev_1Notu, odev_2Notu, kisaSinav_1Notu, kisaSinav_2Notu, finalNotu, yil_iciNotu;
		float yil_sonuNotu;

	}ogrenci;

	ogrenci.isim = isim_dizi[rastgele_isim];
	ogrenci.soyisim = soyisim_dizi[rastgele_soyisim];

	srand(time(0));						//Ürettiğimiz rastgele sayıların her zaman aynı olmamasını sağlar.


	int sayac = 0;


	while (sayac < sinif_mevcudu)		//Her öğrenci için döngü döner.(sınıf mevcudu sayısınca)
	{
		//Öğrencilerin her bir notunun %20’si  80 ile 100 arası, %50'si 80 ile 50 arası, %30’u 50 ile 0 arası random olarak belirlenir.
		if (sayac < sinif_mevcudu * 0.2)
		{

			ogrenci.vizeNotu = rand() % 21 + 80;
			ogrenci.odev_1Notu = rand() % 21 + 80;
			ogrenci.odev_2Notu = rand() % 21 + 80;
			ogrenci.kisaSinav_1Notu = rand() % 21 + 80;
			ogrenci.kisaSinav_2Notu = rand() % 21 + 80;
			ogrenci.finalNotu = rand() % 21 + 80;

		}
		if (sayac < sinif_mevcudu * 0.7 && sayac >= sinif_mevcudu * 0.2)
		{

			ogrenci.vizeNotu = rand() % 31 + 50;
			ogrenci.odev_1Notu = rand() % 31 + 50;
			ogrenci.odev_2Notu = rand() % 31 + 50;
			ogrenci.kisaSinav_1Notu = rand() % 31 + 50;
			ogrenci.kisaSinav_2Notu = rand() % 31 + 50;
			ogrenci.finalNotu = rand() % 31 + 50;

		}
		if (sayac < sinif_mevcudu * 1 && sayac >= sinif_mevcudu * 0.7)
		{

			ogrenci.vizeNotu = rand() % 51;
			ogrenci.odev_1Notu = rand() % 51;
			ogrenci.odev_2Notu = rand() % 51;
			ogrenci.kisaSinav_1Notu = rand() % 51;
			ogrenci.kisaSinav_2Notu = rand() % 51;
			ogrenci.finalNotu = rand() % 51;

		}
		//Rastgele isim ve soyisim için rastgele sayı üretir.
		rastgele_isim = rand() % sinif_mevcudu;
		rastgele_soyisim = rand() % sinif_mevcudu;

		ogrenci.yil_iciNotu =
			ogrenci.vizeNotu * vize_agirlik +									//Yil içi notu hesaplama
			ogrenci.odev_1Notu * odev_1_agirlik +
			ogrenci.odev_2Notu * odev_2_agirlik +
			ogrenci.kisaSinav_1Notu * kisaSinav_1_agirlik +
			ogrenci.kisaSinav_2Notu * kisaSinav_2_agirlik;

		ogrenci.yil_sonuNotu = ogrenci.yil_iciNotu * yil_ici_agirlik + ogrenci.finalNotu * final_agirlik;  //Yıl sonu notu hesaplama


		//Öğrencileri yazdırma
		cout << isim_dizi[rastgele_isim] << " " << soyisim_dizi[rastgele_soyisim] << endl << endl
			<< "\tVize Notu:" << ogrenci.vizeNotu << " " << harfPuaniHesaplayici(ogrenci.vizeNotu) << endl
			<< "\t1.Odev Notu:" << ogrenci.odev_1Notu << " " << harfPuaniHesaplayici(ogrenci.odev_1Notu) << endl
			<< "\t2.Odev Notu:" << ogrenci.odev_2Notu << " " << harfPuaniHesaplayici(ogrenci.odev_2Notu) << endl
			<< "\t1.Kisa Sinav Notu:" << ogrenci.kisaSinav_1Notu << " " << harfPuaniHesaplayici(ogrenci.kisaSinav_1Notu) << endl
			<< "\t2.Kisa Sinav Notu:" << ogrenci.kisaSinav_2Notu << " " << harfPuaniHesaplayici(ogrenci.kisaSinav_2Notu) << endl
			<< "\tFinal Notu:" << ogrenci.finalNotu << " " << harfPuaniHesaplayici(ogrenci.finalNotu) << endl
			<< "\tYıl Sonu Notu:" << ogrenci.yil_sonuNotu << " " << harfPuaniHesaplayici(ogrenci.yil_sonuNotu) << endl << endl;


		vizeToplam = vizeToplam + ogrenci.vizeNotu;
		odev1Toplam = odev1Toplam + ogrenci.odev_1Notu;
		odev2Toplam = odev2Toplam + ogrenci.odev_2Notu;
		kisaSinav1Toplam = kisaSinav1Toplam + ogrenci.kisaSinav_1Notu;
		kisaSinav2Toplam = kisaSinav2Toplam + ogrenci.kisaSinav_2Notu;
		finalToplam = finalToplam + ogrenci.finalNotu;
		yil_sonuToplam = yil_sonuToplam + ogrenci.yil_sonuNotu;


		//En yüksek notu bulma
		if (vizeMAX < ogrenci.vizeNotu)
		{

			vizeMAX = ogrenci.vizeNotu;

		}
		if (odev1MAX < ogrenci.odev_1Notu)
		{

			odev1MAX = ogrenci.odev_1Notu;

		}
		if (odev2MAX < ogrenci.odev_2Notu)
		{

			odev2MAX = ogrenci.odev_2Notu;

		}
		if (kisaSinav1MAX < ogrenci.kisaSinav_1Notu)
		{

			kisaSinav1MAX = ogrenci.kisaSinav_1Notu;

		}
		if (kisaSinav2MAX < ogrenci.kisaSinav_2Notu)
		{

			kisaSinav2MAX = ogrenci.kisaSinav_2Notu;

		}
		if (finalMAX < ogrenci.finalNotu)
		{

			finalMAX = ogrenci.finalNotu;

		}
		if (yil_sonuMAX < ogrenci.yil_sonuNotu)
		{

			yil_sonuMAX = ogrenci.yil_sonuNotu;

		}


		//En düşük notu bulma
		if (vizeMIN > ogrenci.vizeNotu)
		{

			vizeMIN = ogrenci.vizeNotu;

		}
		if (odev1MIN > ogrenci.odev_1Notu)
		{

			odev1MIN = ogrenci.odev_1Notu;

		}
		if (odev2MIN > ogrenci.odev_2Notu)
		{

			odev2MIN = ogrenci.odev_2Notu;

		}
		if (kisaSinav1MIN > ogrenci.kisaSinav_1Notu)
		{

			kisaSinav1MIN = ogrenci.kisaSinav_1Notu;

		}
		if (kisaSinav2MIN > ogrenci.kisaSinav_2Notu)
		{

			kisaSinav2MIN = ogrenci.kisaSinav_2Notu;

		}
		if (finalMIN > ogrenci.finalNotu)
		{

			finalMIN = ogrenci.finalNotu;

		}
		if (yil_sonuMIN > ogrenci.yil_sonuNotu)
		{

			yil_sonuMIN = ogrenci.yil_sonuNotu;

		}


		sayac++;
	}


	int sayac2 = 0;

	//Standart sapma hesaplayan döngü
	while (sayac2 < sinif_mevcudu)
	{
		standart_sapma_vize = pow(ogrenci.vizeNotu - (vizeToplam / sinif_mevcudu), 2);
		sapvize = sapvize + standart_sapma_vize;

		standart_sapma_odev1 = pow(ogrenci.odev_1Notu - (odev1Toplam / sinif_mevcudu), 2);
		sapOdev1 = sapOdev1 + standart_sapma_odev1;

		standart_sapma_odev2 = pow(ogrenci.odev_2Notu - (odev2Toplam / sinif_mevcudu), 2);
		sapOdev2 = sapOdev2 + standart_sapma_odev2;

		standart_sapma_kisaSinav1 = pow(ogrenci.kisaSinav_1Notu - (kisaSinav1Toplam / sinif_mevcudu), 2);
		sapKisaSinav1 = sapKisaSinav1 + standart_sapma_kisaSinav1;

		standart_sapma_kisaSinav2 = pow(ogrenci.kisaSinav_2Notu - (kisaSinav2Toplam / sinif_mevcudu), 2);
		sapKisaSinav2 = sapKisaSinav2 + standart_sapma_kisaSinav2;

		standart_sapma_final = pow(ogrenci.finalNotu - (finalToplam / sinif_mevcudu), 2);
		sapFinal = sapFinal + standart_sapma_final;

		standart_sapma_yilsonu = pow(ogrenci.yil_sonuNotu - (yil_sonuToplam / sinif_mevcudu), 2);
		sapYilsonu = sapYilsonu + standart_sapma_yilsonu;

		sayac2++;
	}



	sapvize = sapvize / (sinif_mevcudu - 1);
	sapvize = sqrt(sapvize);

	sapOdev1 = sapOdev1 / (sinif_mevcudu - 1);
	sapOdev1 = sqrt(sapOdev1);

	sapOdev2 = sapOdev2 / (sinif_mevcudu - 1);
	sapOdev2 = sqrt(sapOdev2);

	sapKisaSinav1 = sapKisaSinav1 / (sinif_mevcudu - 1);
	sapKisaSinav1 = sqrt(sapKisaSinav1);

	sapKisaSinav2 = sapKisaSinav2 / (sinif_mevcudu - 1);
	sapKisaSinav2 = sqrt(sapKisaSinav2);

	sapFinal = sapFinal / (sinif_mevcudu - 1);
	sapFinal = sqrt(sapFinal);

	sapYilsonu = sapYilsonu / (sinif_mevcudu - 1);
	sapYilsonu = sqrt(sapYilsonu);


	//Ekrana sonuçları yazdırma
	cout << endl << "Sınıfın Vize Ortalaması: " << vizeToplam / sinif_mevcudu << endl;
	cout << "Sınıfın 1.Ödev Ortalaması: " << odev1Toplam / sinif_mevcudu << endl;
	cout << "Sınıfın 2.Ödev Ortalaması: " << odev2Toplam / sinif_mevcudu << endl;
	cout << "Sınıfın 1.Kısa Ödev Ortalaması: " << kisaSinav1Toplam / sinif_mevcudu << endl;
	cout << "Sınıfın 2.Kısa Ödev Ortalaması: " << kisaSinav2Toplam / sinif_mevcudu << endl;
	cout << "Sınıfın Final Ortalaması: " << finalToplam / sinif_mevcudu << endl;
	cout << "Sınıfın Yıl Sonu Ortalaması: " << yil_sonuToplam / sinif_mevcudu << endl;

	cout << endl;

	cout << "Sınıfın En Yüksek Vize Notu: " << vizeMAX << endl;
	cout << "Sınıfın En Yüksek 1.Ödev Notu: " << odev1MAX << endl;
	cout << "Sınıfın En Yüksek 2.Ödev Notu: " << odev2MAX << endl;
	cout << "Sınıfın En Yüksek 1.Kısa Sınav Notu: " << kisaSinav1MAX << endl;
	cout << "Sınıfın En Yüksek 2.Kısa Sınav Notu: " << kisaSinav2MAX << endl;
	cout << "Sınıfın En Yüksek Final Notu: " << finalMAX << endl;
	cout << "Sınıfın En Yüksek Yıl Sonu Notu: " << yil_sonuMAX << endl;

	cout << endl;

	cout << "Sınıfın En Düşük Vize Notu: " << vizeMIN << endl;
	cout << "Sınıfın En Düşük 1.Ödev Notu: " << odev1MIN << endl;
	cout << "Sınıfın En Düşük 2.Ödev Notu: " << odev2MIN << endl;
	cout << "Sınıfın En Düşük 1.Kısa Sınav Notu: " << kisaSinav1MIN << endl;
	cout << "Sınıfın En Düşük 2.Kısa Sınav Notu: " << kisaSinav2MIN << endl;
	cout << "Sınıfın En Düşük Final Notu: " << finalMIN << endl;
	cout << "Sınıfın En Düşük Yıl Sonu Notu: " << yil_sonuMIN << endl;

	cout << endl;

	cout << "Vize notlarının standart sapması: " << sapvize << endl;
	cout << "1.Ödev notlarının standart sapması: " << sapOdev1 << endl;
	cout << "2.Ödev notlarının standart sapması: " << sapOdev2 << endl;
	cout << "1.Kısa Sınavın notlarının standart sapması: " << sapKisaSinav1 << endl;
	cout << "2.Kısa Sınavın notlarının standart sapması: " << sapKisaSinav2 << endl;
	cout << "Final notlarının standart sapması: " << sapFinal << endl;
	cout << "Yıl Sonu notlarının standart sapması: " << sapYilsonu << endl;

	cout << endl;

	cout << "Toplam AA notu alan sayısı:" << sayiAA << endl;
	cout << "Toplam BA notu alan sayısı:" << sayiBA << endl;
	cout << "Toplam BB notu alan sayısı:" << sayiBB << endl;
	cout << "Toplam CB notu alan sayısı:" << sayiCB << endl;
	cout << "Toplam CC notu alan sayısı:" << sayiCC << endl;
	cout << "Toplam DC notu alan sayısı:" << sayiDC << endl;
	cout << "Toplam DD notu alan sayısı:" << sayiDD << endl;
	cout << "Toplam FD notu alan sayısı:" << sayiFD << endl;
	cout << "Toplam FF notu alan sayısı:" << sayiFF << endl;

	cout << endl;

}

string harfPuaniHesaplayici(int puan)					//Harf notu hesaplayan ve harf notu adetini sayan fonksiyon.

{
	string a;
	if (puan <= 100 and puan >= 90)
	{

		a = "AA";
		sayiAA++;

	}
	else if (puan <= 89, 99 and puan >= 85)
	{

		a = "BA";
		sayiBA++;

	}
	else if (puan <= 84, 99 and puan >= 80)
	{

		a = "BB";
		sayiBB++;

	}
	else if (puan <= 79, 99 and puan >= 75)
	{

		a = "CB";
		sayiCB++;

	}
	else if (puan <= 74, 99 and puan >= 65)
	{

		a = "CC";
		sayiCC++;

	}
	else if (puan <= 64, 99 and puan >= 58)
	{

		a = "DC";
		sayiDC++;

	}
	else if (puan <= 57, 99 and puan >= 50)
	{

		a = "DD";
		sayiDD++;

	}
	else if (puan <= 49, 99 and puan >= 40)
	{

		a = "FD";
		sayiFD++;

	}
	else if (puan <= 39, 99 and puan >= 0)
	{

		a = "FF";
		sayiFF++;

	}
	else
	{

		cout << " HATA";

	}
	return a;
}


