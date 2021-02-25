// ConsoleApplication6.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
struct Node {
	int veri;
	struct Node* next;
};
struct Node* ilk = NULL;
void push(int deger)
{
	struct Node* n = new Node;
	n->veri = deger;
	n->next = ilk;
	ilk = n;
}
void list()
{
	struct Node* n;
	n = ilk;
	int i = 1;
	if (ilk == NULL)
	{
		cout << "Listede eleman yok!!" << endl;
	}
	else
	{ 
		while (n != NULL)
		{
			cout << "Listenin " << i << ". elemani :" << n->veri << endl;
			n = n->next;
			++i;
		}
	}
	
}
struct Node* arama(int aranan)
{
	struct Node* n;
	n = ilk;
	if (ilk == NULL)
	{
		cout << "Listede eleman yok!!" << endl;
	}
	else 
	{
		while (n)
		{
			if (n->veri == aranan)
			{
				cout << aranan << " listede var." << endl;
				return n;
			}
			n = n->next;
		}

	}

}
void sil(int silinen)
{
	struct Node* n;
	struct Node* temp = NULL;
	n = ilk;
	if (ilk == NULL)
	{
		cout << "Liste bos !!" << endl;
	}
	else if (ilk->veri == silinen)
	{
		n = ilk;
		if (ilk->next == NULL)
		{
			free(n);
			ilk = NULL;
		}
		else
		{
			ilk = ilk->next;
			free(n);
		}
	}
	else
	{
		n = ilk;
		while (n->next != NULL)
		{
			temp = n;
			n = n->next;
		}
		if (n->veri == silinen && n->next == NULL)
		{

			temp->next = NULL;
			free(n);

		}
		else
		{
			Node* birönceki;
			birönceki = NULL;
			n = ilk;
			while (n)
			{
				if (n->veri == silinen)
				{
					temp = n->next;
					free(n);
					break;
				}
				else
				{
					birönceki = n;
				}
				n = n->next;
			}
			birönceki->next = temp;

		}
	}

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
			push(deger);  break;
		case 2: cout << "Listede aranacak veriyi giriniz : ";
			cin >> deger;
			arama(deger);  break;
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
