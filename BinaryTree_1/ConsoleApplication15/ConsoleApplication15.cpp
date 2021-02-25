// ConsoleApplication15.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* sag;
	struct node* sol;
};
typedef struct node BTREE;

BTREE* new_node(int data)
{
	BTREE* p = new BTREE;
	p->data = data;
	p->sol = NULL;
	p->sag = NULL;
	return p;
}
BTREE* insert(BTREE* root, int data)
{
	if (root != NULL)
	{
		if (data < root->data)
		{
			root->sol = insert(root->sol, data);
		}
		else
		{
			root->sag = insert(root->sag, data);
		}
	}
	else
	{
		root = new_node(data);
	}

	return root;
}
int dugumSayısı(BTREE* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return dugumSayısı(root->sol) + 1 + dugumSayısı(root->sag);
	}
}
int yukseklik(BTREE* root)
{
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		int sol_yukseklik, sag_yukseklik;
		sol_yukseklik = yukseklik(root->sol);
		sag_yukseklik = yukseklik(root->sag);
		if (sag_yukseklik > sol_yukseklik)
		{
			return sag_yukseklik + 1;
		}
		else
			return sol_yukseklik + 1;
	}
}
void preorder(BTREE* root) // ROOT - L - R
{
	if (root != NULL)
	{
		cout << root->data<<" ";
		preorder(root->sol);
		preorder(root->sag);
	}
}
void inorder(BTREE* root) // L - root - R
{
	if (root != NULL)
	{
		inorder(root->sol);
		cout << root->data<<" ";
		inorder(root->sag); 
	}
}
void postorder(BTREE* root) // L-root -R
{
	if (root != NULL)
	{
		postorder(root->sol);
		postorder(root->sag);
		cout << root->data<<" ";
	}
}
int main()
{
	BTREE* Root = NULL;
	Root = insert(Root, 27);
	Root = insert(Root, 18);
	Root = insert(Root, 14);
	Root = insert(Root, 2);
	Root = insert(Root, 17);
	Root = insert(Root, 15);
	Root = insert(Root, 22);
	Root = insert(Root, 12);
	Root = insert(Root, 24);
	Root = insert(Root, 23);
	Root = insert(Root, 39);
	Root = insert(Root, 29);
	Root = insert(Root, 42);
	Root = insert(Root, 34);
	cout << "Preorder : "<<endl;
	preorder(Root);
	cout << endl;
	cout << "Inorder : "<<endl;
	inorder(Root);
	cout << endl;
	cout << "Postorder :"<<endl;
	postorder(Root);
	cout << endl;
	cout << "Agac eleman sayisi : " << dugumSayısı(Root);
	cout << endl;
	cout << "Agac yuksekligi : " << yukseklik(Root) << endl;
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
