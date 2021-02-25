// ConsoleApplication18.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
struct node
{
	int veri;
	struct node* sag;
	struct node* sol;
};
typedef struct node BSTree;
BSTree* new_node(int veri)
{
	BSTree* n = new BSTree;
	n->veri = veri;
	n->sag = NULL;
	n->sol = NULL;
	return n;
}
void preorder(BSTree* root)
{
	if (root != NULL)
	{
		cout << root->veri << " ";
		preorder(root->sol);
		preorder(root->sag);
	}
}
BSTree* Ekle(BSTree* root, int veri)
{
	if (root != NULL)
	{
		if (veri < root->veri)
		{
			root->sol = Ekle(root->sol, veri);
		}
		else
		{
			root->sag = Ekle(root->sag, veri);
		}
	}
	else
	{
		root = new_node(veri);
	}
	return root;
}
BSTree* Tek(BSTree* root, BSTree* roottek)
{
	if (root != NULL)
	{
		
		if (root->veri % 2 != 0)
		{
			roottek = Ekle(roottek, root->veri);
		}
		Tek(root->sol, roottek);
		Tek(root->sag, roottek);
	}
	return roottek;
}
BSTree* Cift(BSTree * root, BSTree * rootcift) {
		if (root != NULL) {
			if (root->veri % 2 == 0)
			{
				rootcift = Ekle(rootcift, root->veri);
			}	
			rootcift = Cift(root->sol, rootcift);
			rootcift = Cift(root->sag, rootcift);
		}
		return rootcift;
	}
int Carpım(BSTree * root,int deger)
{
	int sonuc = 1;
	while (root != NULL)
	{
		if (root == NULL)
		{
			return 0;
		}
		else if (deger == root->veri)
		{
			if (sonuc == deger)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		else if (deger < root->veri)
		{
			sonuc = sonuc * root->veri;
			root = root->sol;

		}
		else if (deger > root->veri)
		{
			sonuc = sonuc * root->veri;
			root = root->sag;
		}
	}
}
bool CarpımB(BSTree* root,int deger)
{
	int sonuc = 1;
	while (root != NULL)
	{
		if (root == NULL)
		{
			return false;
		}
		else if (deger == root->veri)
		{
			if (sonuc == deger)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		else if (deger < root->veri)
		{
			sonuc = sonuc * root->veri;
			root = root->sol;

		}
		else if (deger > root->veri)
		{
			sonuc = sonuc * root->veri;
			root = root->sag;
		}
	}
}
int main()
{
	BSTree* BST = NULL;
	BSTree* BSTTek = NULL;
	BSTree* BSTCıft = NULL;
	int deger=0;
	int dizi[] = {7,5,15,8,105,12,18};
	for (int i = 0;i <7;i++)
	{
		BST = Ekle(BST, dizi[i]);
	}
	cout << "BST olusturuldu " << endl;
	preorder(BST);
	cout << endl;
	BSTTek=Tek(BST,BSTTek);
	cout << "BSTTek olusturuldu" << endl;
	preorder(BSTTek);
	cout << endl;
	BSTCıft = Cift(BST, BSTCıft);
	cout << "BSTCift olusturuldu " << endl;
	preorder(BSTCıft);
	cout << endl;
	cout << " Bir deger giriniz : ";
	cin >> deger;
	cout << endl;
	if (Carpım(BST, deger) == 1)
	{
		cout << deger << " dugumlerin carpimina esittir." << endl;
	}
	else
	{
		cout << deger << " dugumlerin carpimina esit degil." << endl;
	}
	if (CarpımB(BST, deger) == true)
	{
		cout << deger << " dugumlerin carpimina esittir." << endl;
	}
	else
	{
		cout << deger << " dugumlerin carpimina esit degil." << endl;
	}
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
