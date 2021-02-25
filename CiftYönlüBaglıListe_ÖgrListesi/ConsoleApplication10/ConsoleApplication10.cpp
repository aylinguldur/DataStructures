// ConsoleApplication10.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

struct ogrenciDugum
{
	ogrenciDugum* sonraki;
	ogrenciDugum* önceki;
public:
	int kimlikNo;
	string adSoyad;
	char cinsiyet;

};
struct ogrenciDugum* ilk;
struct ogrenciDugum* son;
void ogrenci_ekle(string ad, int no,char c)
{
	ogrenciDugum* n = new ogrenciDugum;
	n->adSoyad = ad;
	n->kimlikNo = no;
	n->cinsiyet=c;
	if (ilk == NULL)
	{
		son = n;
		ilk = n;
		ilk->sonraki = NULL;
		ilk->önceki = NULL;
	}
	else
	{
		ilk->sonraki = n;
		n->sonraki = NULL;
		n->önceki = ilk;
		ilk = n;
	}
}
void ogrenci_sil(int no)
{
	{
		ogrenciDugum* n;
		ogrenciDugum* p;
		n = son;
		if (son->kimlikNo == no)
		{
			if (n->sonraki == NULL && n->önceki == NULL)
			{
				free(n);
				son = NULL;
				ilk = NULL;
			}
			else if (n->sonraki != NULL && n->önceki == NULL)
			{
				p = n;
				n = n->sonraki;
				n->önceki = NULL;
				n = son;
				free(p);
			}
		}
		else if (ilk->kimlikNo == no)
		{
			n = ilk;
			p = n;
			n = n->önceki;
			ilk = n;
			ilk->sonraki = NULL;
			free(p);

		}
		else
		{
			while (n)
			{
				if (n->kimlikNo == no && n->sonraki != NULL && n->önceki != NULL)
				{
					p = n;
					n = n->sonraki;
					n->önceki = p->önceki;
					free(p);
				}
				n = n->sonraki;
			}
		}

	}
}
void listele()
{
	ogrenciDugum* n;
	n = ilk;
	int i = 1;
	if (n != NULL)
	{
		cout << "Listede bulunan ogrenciler : " << endl;
		while (n != NULL)
		{
			cout << i << ". ogrenci : " << endl;
			cout << "Ad-Soyad : " << n->adSoyad << endl;
			cout << "Kimlik no : " << n->kimlikNo << endl;
			cout << "Cinsiyet : " << n->cinsiyet << endl;
			n = n->önceki;
			i++;
		}
	}
	else
	{
		cout << "Listede ogrenci yok!! ";
	}

	cout << endl;
}
int main()
{
	ogrenci_ekle("Ali",18,'E' );
	ogrenci_ekle("Ayse", 25, 'K');
	ogrenci_ekle("Aynur", 5, 'K');
	ogrenci_ekle("Efe", 7, 'K');
	ogrenci_ekle("Sebnem", 36, 'K');
	ogrenci_ekle("Ahmet", 57, 'E');
	ogrenci_ekle("Sema", 61, 'K');
	ogrenci_ekle("Melis ", 23, 'K');
	ogrenci_ekle("Hakan", 18, 'E');
	ogrenci_ekle("Cem", 30 , 'E');
	listele();
	ogrenci_sil(18);
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
