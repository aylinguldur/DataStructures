// ConsoleApplication7.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class kuyruk
{
	int ön = 0;
	int arka = -1;
	int eleman = 0;
public:
	int kuyruk[8];
	void ekle();
	void cıkar();
	void listele();
};
void kuyruk::ekle()
{
	int veri;
	if (arka == 7)
	{
		cout << "Kuyruk dolu" << endl;
	}
	else
	{
		++arka;
		veri = rand() % 100;
		kuyruk[arka] = veri;
		cout << "Kuyruga ekleme yapildi : " << veri<<endl;
		++eleman;
	}
}
void kuyruk::cıkar()
{
	if (eleman==0)
	{
		cout << "Kuyruk bos !!" << endl;
	}
	else
	{
		
		cout << "Kuyruktan eleman cikarildi : " << kuyruk[ön] << endl;
		ön++;
		--eleman;
	}
}
void kuyruk::listele()
{
	if (eleman == 0)
	{
		cout << "Kuyruk bos!!" << endl;
	}
	else
	{
		cout << "Kuyruktaki elemanlar : ";
		for (int i = ön;i <= arka;i++)
		{
			cout << kuyruk[i] <<" ";
		}
	}
}
int main()
{
	int islem;
	kuyruk k1;
	srand(time(NULL));
	do
	{
		cout << " " << endl;
		cout << "Yapilacak islemi seciniz. 1-Ekleme 2-Cikarma 3-Listeleme 4-Cikis :";
		cin >> islem;
		switch (islem)
		{
		case 1: k1.ekle(); break;
		case 2: k1.cıkar(); break;
		case 3: k1.listele();break;
		case 4: cout << "Uygulamadan cikis yaptiniz.." << endl;
		}
	} while (islem !=4);
	return 0;
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
