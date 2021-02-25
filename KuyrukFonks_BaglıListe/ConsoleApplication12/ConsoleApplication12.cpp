 // ConsoleApplication12.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
using namespace std;
class kuyrukDugumu
{
public:
	int veri;
	kuyrukDugumu* next;
};
class kuyruk
{
	kuyrukDugumu* ilk;
	kuyrukDugumu* son;
public:
	kuyruk();
	void ekle(int deger);
	void cikar();
	void listele();
};
kuyruk::kuyruk()
{
	ilk = NULL;
	son = NULL;
}
void kuyruk::ekle(int deger)
{
	kuyrukDugumu *k = new kuyrukDugumu();
	if (ilk == NULL)
	{
		k->veri = deger;
		k->next = NULL;
		ilk = k;
		son = ilk;

		
	}
	else
	{
		k->veri = deger;
		k->next = NULL;
		son->next = k;
		son = k;	
	}
}
void kuyruk::cikar()
{
	if (ilk == NULL)
	{
		cout << " Kuyrukta eleman yok!!" << endl;
	}
	else
	{
		kuyrukDugumu* k;
		kuyrukDugumu* t;
		k = ilk;
		t = k;
		k = k->next;
		ilk = k;
		free(t);
		cout << " Kuyruktan eleman cikarildi " << endl;
	}
}
void kuyruk::listele()
{
	if (ilk == NULL)
	{
		cout << " Kuyrukta listelenecek eleman yok!!" << endl;
    }
	else
	{
		kuyrukDugumu* k;
		k = ilk;
		do
		{
			cout << k->veri<<" ";
			k = k->next;
		} while (k);
	}
	cout << endl;
}
int main()
{
	kuyruk k;
	int deger;
	int islem;
	cout << " Kuyrukta yapmak istediginiz islemi seciniz " << endl;
	cout << " 1- ekle " << endl;
	cout << " 2- cikar " << endl;
	cout << " 3- listele " << endl;
	do
	{
		cout << "islem :";
		cin >> islem;
		switch (islem)
		{
		case 1: cout << " Eklemek istediginiz degeri giriniz : ";
			cin >> deger;
			k.ekle(deger);
			break;
		case 2: k.cikar();
			break;
		case 3: k.listele(); break;
		}
	} while (islem != 0);
	system("pause");
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
