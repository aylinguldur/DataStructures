// ConsoleApplication21.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
#define size 250
using namespace std;
class Hash
{
	int* HashT;
	int elemans;
public:
	Hash();
	void ekle(int deger);
	void sil(int deger);
	bool arama(int deger);
	void H_listele();
};
Hash::Hash()
{
	HashT = new int[size];
	elemans = 0;
	for (int i = 0; i < size; i++)
		HashT[i] = 0;
}
void Hash::ekle(int deger)
{
	int indis = deger % size;
	if (elemans == size)
	{
		cout << " Boş yer yok !!" << endl;
	}
	else if (elemans<size && HashT[indis]!=NULL && indis+1>=size)
	{
		indis = 0;
		while (HashT[indis] != NULL)
		{
			indis++;
		}
		HashT[indis] = deger;

	}
	else
	{
		if (HashT[indis] == NULL)
		{
			HashT[indis] = deger;
		}
		else
		{
			while (HashT[indis]!= NULL)
			{
				indis++;
			}
			HashT[indis] = deger;
		}
		
		elemans++;
	}
}
void Hash::sil(int deger)
{
	int indis = deger % size;
    if ( HashT[indis] != deger && indis + 1>=size)
	{
		indis = 0;
		while (HashT[indis] != deger)
		{
			indis++;
		}
		HashT[indis] = 0;
	}
	else
	{
		while (HashT[indis] != deger)
		{
			indis++;
		}
		HashT[indis] = 0;
	}
	elemans--;
}
bool Hash::arama(int deger)
{
	int indis = deger % size;
	int i;
	if (HashT[indis] != deger && indis+1 >= size)
	{
		indis = 0;
		while (HashT[indis] != deger && indis<size)
		{
			indis++;
		}
		if (HashT[indis] == deger)
		{
			cout << " Listede " << indis << ". indiste bulunuyor." << endl;
			return true;
		}
	}
	else
	{
		while (HashT[indis] != deger && indis<size)
		{
			indis++;	
		}
		if (HashT[indis] == deger )
		{
			cout << " Listede " << indis << ". indiste bulunuyor." << endl;
			return true;
		}
	}
}
	
void Hash::H_listele()
{
	int	indis = 0;
	while (indis < size)
	{
		if (HashT[indis] != 0)
		{
			cout << indis << ". " << HashT[indis] << endl;
			indis++;
		}
		else
		{
			indis++;
		}
	}

}
int main()
{
	Hash hashTable;
	int islem;
	int deger;
	do
	{
		cout << "Islem seciniz.  1-Ekleme 2-Arama 3-Silme 4-Listeleme   Cikmak icin -1 giriniz : ";
		cin >> islem;
		switch (islem)
		{
		case 1: cout << "Eklenecek veriyi giriniz : ";
			cin >> deger;
			hashTable.ekle(deger);  break;
		case 2: cout << "Listede aranacak veriyi giriniz : ";
			cin >> deger;
			if (hashTable.arama(deger) != true)
				cout << deger << " listede yok " << endl; break;
		case 3:
			cout << "Listeden silinecek veriyi giriniz : ";
			cin >> deger;
			hashTable.sil(deger); break;
		case 4: hashTable.H_listele();break;
		}
	} while (islem != -1);
	cout << "yanlis giris yaptiniz ." << endl;
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
