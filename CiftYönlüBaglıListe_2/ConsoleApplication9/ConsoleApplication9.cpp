// ConsoleApplication9.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
using namespace std;
struct Node
{
	int veri;
	Node* sonraki;
	Node* önceki;
};
struct Node* son=NULL;
struct Node* ilk = NULL;
void ekle(int deger)
{
	Node* n = new Node;
	if (ilk == NULL)
	{
		n->veri = deger;
		son = n;
		ilk = n;
		ilk->sonraki = NULL;
		ilk->önceki = NULL;
	}
	else
	{
		n->veri = deger;
		ilk->sonraki = n;
		n->sonraki = NULL;
		n->önceki = ilk;
		ilk = n;
	}
}
void sil(int deger)
{ 
	Node* n;
	Node* p;
	n = son;
	if (son->veri == deger)
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
	else if (ilk->veri == deger)
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
			if (n->veri == deger && n->sonraki != NULL && n->önceki != NULL)
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
void list()
{
	Node* n;
	n = ilk;
	if (n != NULL)
	{
		cout << "Listede bulunan elemanlar : ";
		while (n != NULL)
		{
			cout << n->veri << " ";
			n = n->önceki;
		}
	}
	else
	{
		cout << "Listede eleman yok!! " ;
	}

	cout << endl;
}
bool arama(int deger)
{
	Node* n;
	n = son;
	do 
	{
		if (n->veri == deger)
		{
			cout << deger << " listede bulunuyor. " << endl;
			return true;
		}	
		n = n->sonraki;
	} while (n != NULL);

}
int main()
{
	int islem;
	int deger;
	do
	{
		cout << "Islem seciniz.  1-Ekleme 2-Arama 3-Listeleme 4-Silme : ";
		cin >> islem;
		switch (islem)
		{
		case 1: cout << "Eklenecek veriyi giriniz : ";
			cin >> deger;
			ekle(deger);  break;
		case 2: cout << "Listede aranacak veriyi giriniz : ";
			cin >> deger;
			if (arama(deger) != true)
				cout << deger << " listede yok " << endl; break;
		case 3:
			list();  break;
		case 4:
			cout << "Listeden silinecek veriyi giriniz : ";
			cin >> deger;
			sil(deger);
		}
	} while (islem != -1);
	cout << "yanlis giris yaptiniz ." << endl;
	system("pause");
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
