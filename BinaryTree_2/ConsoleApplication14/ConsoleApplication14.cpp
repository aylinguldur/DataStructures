// ConsoleApplication14.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
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
		if (data<root->data)
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
int size(BTREE*root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return size(root->sol) + 1 + size(root->sag);
	}
}
int height(BTREE* root)
{
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		int sol_height, sag_height;
		sol_height = height(root->sol);
		sag_height = height(root->sag);
		if (sag_height > sol_height)
		{
			return sag_height + 1;
		}
		else
			return sol_height + 1;
	}
}
void mirror(BTREE*root)
{
	node* k;
	node* t;
	k = root->sag;
	t = root->sol;
	root->sag = t;
	root->sol = k;
	
}
void preorder(BTREE*root) // ROOT - L - R
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->sol);
		preorder(root->sag);
	}
}
void inorder(BTREE*root) // L - root - R
{
	if (root!=NULL)
	{
		inorder(root->sol);
		cout << root->data << " ";
		inorder(root->sag);
	}
}
void postorder(BTREE*root) // L-root -R
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
	BTREE* Root=NULL;
	int i = 0;
	do
	{
		cout << " Agaca integer veri ekleyiniz. Çıkmak için -1 giriniz.." << endl;
		cout << " Sayi : " << endl;
		cin >> i;
		if (i != -1)
		{
			Root = insert(Root, i);
		}
	} while (i != -1);

	cout << " Preorder : " << endl;
	preorder(Root);
	cout << endl;
	cout << " Inorder : " << endl;
	inorder(Root);
	cout << endl;
	cout << " Postorder : " << endl;
	postorder(Root);
	cout << endl;
	cout << "Rootun eleman sayisi : "<<size(Root);
	cout << endl;
	cout << "Root yuksekligi : "<< height(Root) <<endl;
	mirror(Root);
	cout << "mirror fonksiyonu calistirildi. Agac sag ve sol cocukları yer degistirdi : " << endl;
	cout << " Mirror() Preorder : " << endl;
	preorder(Root);
	cout << endl;
	cout << " Mirror() Inorder : " << endl;
	inorder(Root);
	cout << endl;
	cout << " Mirror() Postorder : " << endl;
	postorder(Root);
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
