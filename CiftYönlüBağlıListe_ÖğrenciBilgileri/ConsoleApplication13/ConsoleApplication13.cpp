// ConsoleApplication13.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
using namespace std;
struct Ogrenci
{
	int kimlikNo;
	char cinsiyet;
	string ad;
	Ogrenci* sonraki;
	Ogrenci* önceki;
};
struct Ogrenci* son = NULL;
struct Ogrenci* ilk = NULL;
void ogrenci_ekle(string ad,int no,char c)
{
	Ogrenci* ogr = new Ogrenci;
	if (ilk == NULL)
	{
		ogr->kimlikNo = no;
		ogr->cinsiyet = c;
		ogr->ad = ad;
		son = ogr;
		ilk = ogr;
		ilk->sonraki = NULL;
		ilk->önceki = NULL;
	}
	else
	{
		ogr->kimlikNo = no;
		ogr->cinsiyet = c;
		ogr->ad = ad;
		son->sonraki = ogr;
		ogr->sonraki = NULL;
		ogr->önceki = son;
		son = ogr;
	}
}
void listele()
{
	Ogrenci* ogr;
	int i = 1;
	ogr = ilk;
	if (ogr != NULL)
	{
		cout << "Listede bulunan elemanlar : " << endl;
		while (ogr != NULL)
		{
			cout << i << ". ogrenci : " << endl;
			cout << "Ad :  " << ogr->ad << endl;
			cout << "Kimlik no : " << ogr->kimlikNo << endl;
			cout << "Cinsiyet : " << ogr->cinsiyet << endl;
			ogr= ogr->sonraki;
			i = i + 1;
			cout << endl;
		}
	}
	else
	{
		cout << "Listede eleman yok!! ";
	}

	cout << endl;
}
void ogrenci_sil(int no)
{
	Ogrenci* ogr;
	Ogrenci* p;
    ogr= ilk;
	bool silindi = false;
	if (ilk != NULL)
	{
		if (ilk->kimlikNo == no)
		{
			if (ogr->sonraki == NULL && ogr->önceki == NULL)
			{
				free(ogr);
				son = NULL;
				ilk = NULL;
			}
			else if (ogr->sonraki != NULL && ogr->önceki == NULL)
			{
				p = ogr;
				ogr = ogr->sonraki;
				ogr->önceki = NULL;
				ilk = ogr;
				free(p);
			}
		}
		else if (son->kimlikNo == no)
		{
			ogr = son;
			p = ogr;
			ogr = ogr->önceki;
			son = ogr;
			son->sonraki = NULL;
			free(p);

		}
		else
		{
			while (silindi != true)
			{
				if (ogr->kimlikNo == no && ogr->sonraki != NULL && ogr->önceki != NULL)
				{
					p = ogr;
					ogr = ogr->önceki;
					ogr->sonraki = p->sonraki;
					free(p);
					silindi = true;
				}
				ogr = ogr->sonraki;
			}
		}
		cout << "ogrenci listeden silindi. " << endl;
	}
	else
	{
		cout << "Listede  ogrenci bulunmuyor ." << endl;
	}
	cout << endl;
}
void araya_ekle(string ad,int no,char c)
{
	Ogrenci* p;
	p = ilk;
	bool eklendi = false;
	Ogrenci* ogr = new Ogrenci;
	ogr->ad = ad;
	ogr->kimlikNo = no;
	ogr->cinsiyet = c;
	if (ilk != NULL)
	{
		while (eklendi != true)
		{
			if (p->kimlikNo < no && p->sonraki->kimlikNo>no)
			{
				ogr->sonraki = p->sonraki;
				p->sonraki = ogr;
				ogr->önceki = p;
				p->önceki = ogr;
				eklendi = true;
			}
			p = p->sonraki;
		}
		cout << "Araya ekleme yapildi . " << endl;
	}
	else
	{
		cout << "Listede  ogrenci bulunmuyor ." << endl;
	}
	cout << endl;
}
int main()
{
	ogrenci_ekle("Ali", 5, 'E');
	ogrenci_ekle("Ayse", 7, 'K');
	ogrenci_ekle("Aynur", 18, 'K');
	ogrenci_ekle("Efe", 25, 'K');
	ogrenci_ekle("Sebnem", 36, 'K');
	ogrenci_ekle("Ahmet", 57, 'E');
	ogrenci_ekle("Sema", 61, 'K');
	ogrenci_ekle("Melis ", 73, 'K');
	ogrenci_ekle("Hakan", 88, 'E');
	ogrenci_ekle("Cem", 90, 'E');
	listele();
	araya_ekle("Zeynep",20,'K');
	listele();
	ogrenci_sil(5);
	listele();
	ogrenci_sil(90);
	listele();
	ogrenci_sil(20);
	listele();
	araya_ekle("Selin", 58, 'K');
	listele();
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
