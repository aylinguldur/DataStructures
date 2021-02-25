// ConsoleApplication16.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
using namespace std;
struct  MaxHeap
{
	int MaxH[17];
	int ust;
public:
	MaxHeap();
	void push(int veri);
	void sırala(int i);
	void Yazdır(int elemans);
	int Sil();
};
MaxHeap::MaxHeap()
{
	ust = 1;
	cout << "MaxHeap olusturuluyor.." << endl;

}
void MaxHeap::push(int veri)
{
		MaxH[ust] = veri;
		ust++;
		sırala(ust - 1);
}
void MaxHeap::sırala(int i)
{
	int kökd = i / 2;
	if (kökd != 0)
	{
		if (MaxH[i] > MaxH[kökd])
		{
			int t = MaxH[i];
			MaxH[i] = MaxH[kökd];
			MaxH[kökd] = t;
			sırala(kökd);
		}
	}

}
int MaxHeap::Sil()
{
	int i = 1;
	int elemans = sizeof(MaxH) / sizeof(*MaxH);
	MaxH[i] = MaxH[16];
	MaxH[16] = 0;
	while ((MaxH[i] < MaxH[2*i] || MaxH[i] < MaxH[2*i+1]) && 2*i+1<=elemans && 2*i<=elemans)
	{
		if (MaxH[2 * i] > MaxH[2 * i + 1] && 2*i<=elemans && 2*i+1<=elemans )
		{
			int t;
			t = MaxH[i];
			MaxH[i] = MaxH[2 * i];
			MaxH[2 * i] = t;
			i = 2 * i;
		}
		else if (MaxH[2 * i] < MaxH[2 * i + 1] && 2 * i <= elemans && 2 * i + 1 <= elemans)
		{
			int t;
			t = MaxH[i];
			MaxH[i] = MaxH[2 * i + 1];
			MaxH[2 * i + 1] = t;
			i = 2*i + 1;
		}
	}
	elemans = elemans - 2;
	return elemans;
}
void MaxHeap::Yazdır(int elemans)
{
	cout << " Olusturulan dizi yazdiriliyor.." << endl;
	for (int i = 1;i <= elemans;i++)
	{
		cout << MaxH[i]<<" ";
	}   
}
int main()
{
	MaxHeap maxheap;
	int dizi[] = {15,7,12,28,36,1,37,13,4,25,3,9,27,2,5,16};
	for (int i = 0; i <=15 ;i++)
	{
		maxheap.push(dizi[i]);
	}
	int elemans = sizeof(dizi) / sizeof(*dizi);
	cout << "MaxHeap elemanlar eklendi.. MaxHeap dizisi yazdiriliyor : " << endl;
	maxheap.Yazdır(elemans);
	cout << endl;
	elemans = maxheap.Sil();
	cout << "Max eleman silindi .." << endl;
	maxheap.Yazdır(elemans);
	return 0;

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
