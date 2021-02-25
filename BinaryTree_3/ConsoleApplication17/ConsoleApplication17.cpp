// ConsoleApplication17.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

struct node
{
    int veri;
    struct node* sag;
    struct node* sol;
};
typedef struct node Btree;
Btree* yeni_node(int data)
{
    Btree* n = new Btree;
    n->veri = data;
    n->sag = NULL;
    n->sol = NULL;
    return n;
}
void preorder(Btree* root)
{
    if (root != NULL)
    {
        cout << root->veri << " ";
        preorder(root->sol);
        preorder(root->sag);
    }
}
Btree* Ekle(Btree*root, int data)
{
    if (root != NULL)
    {
        if (data<root->veri)
        {
            root->sol = Ekle(root->sol, data);
        }
        else
        {
            root->sag = Ekle(root->sag, data);
        }
    }
    else
    {
        root = yeni_node(data);
    }
    return root;
}
Btree* Ara(Btree* root,int x)
{
 
        if (root == NULL)
        {
            return NULL;
        }
        else if(root->veri==x)
        {
            cout << x << " agacta var " << endl;
            return root;
        }
        else if (x < root->veri)
        {
            Ara(root->sol, x);
        }
        else if (x > root->veri)
        {
            Ara(root->sag, x);
        }
}
Btree* Bul(Btree* root)
{
    node* yeni_root;
    root = root->sag;
    yeni_root = root;
    while (root != NULL)
    {
        if (60 < root->veri && root->veri < 70)
        {
            return root;
        }
        else
        {
            root = root->sag;
            if (root == NULL)
            {
                root = yeni_root->sol;
                return root;
            }
        }
    }
}
int main()
{
    Btree* root = NULL;
    int x;
    int dizi[] = { 50,28,46,80,47,96,14,10,68,20,34,71,61,41,82,64,13,18,27,95,74,81,11,36 };
    for (int i = 0; i < 24;i++)
    {
        root = Ekle(root, dizi[i]);
    }
    cout << "Agac olusturuldu " << endl;
    preorder(root);
    cout << endl;
    cout << " Agacta aranacak veriyi giriniz : ";
    cin >> x;
    if (Ara(root, x) == NULL)
    {
        cout << " Aradiginiz veri agacta yok " << endl;
    }
    Btree* yeni_root = Bul(root);
    cout << "Aranilan deger ve sonraki degerler ile yeni agac olusturuldu" << endl;
    preorder(yeni_root);
    cout << endl;
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
