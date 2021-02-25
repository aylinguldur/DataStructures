// ConsoleApplication8.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//


#include <iostream>
using namespace std;
struct Node
{
    int veri;
    struct Node* next;
};
struct Node* bas=NULL;
struct Node* son=NULL;
void basa_ekle(int deger)
{
    Node* n = new Node();
    n->veri = deger;
    n->next = bas;
    if (bas == NULL)
    {
        son = n;
        bas = n;
    }
    else
    {
        bas = n;
    }
      
}
void sona_ekle(int deger)
{
    Node* n=new Node();
    n->veri = deger;
    n->next = NULL;
    son->next = n;
    son = n;

}
void araya_ekle(int deger)
{
    struct Node* n;
    Node* ara = new Node();
    Node* p;
    n = bas;
    while (n->veri != 9)
    {
        n = n->next;
    }
    p = n->next;
    n->next = ara;
    ara->veri = deger;
    ara->next = p;
    

}
void bastan_sil()
{ 
    Node* n;
    for (int i = 0; i < 3;i++)
    {
        n = bas;
        bas = n->next;
        free(n);
    }
}
void sondan_sil()
{
    Node* n;
    struct Node* p= new Node();
    for (int i = 0;i < 3;i++)
    {
        n = bas;
        while (n->next->next != NULL)
        {
            n = n->next;
        }
        free(n->next);
        n->next = NULL;
    }
}
void aradan_sil()
{
    Node* n;
    Node* p;
    Node* ara;
    n = bas;
    while (n->veri != 45)
    {
        n = n->next;
    }

    for (int i = 0; i < 3;i++)
    {
        p = n->next->next;
        ara = n->next;
        free(ara);
        n->next = p;
    }

}
void ara()
{
    cout << " 3'e bolunebilen sayilar :  ";
    Node* n;
    n = bas;
    do 
    {
        if ((n->veri) % 3 == 0)
            cout << n->veri <<"\t";
        n = n->next;
    } while (n != NULL);  
    cout << endl;
}
void yaz()
{
    struct Node* n;
    n = bas;
    int i = 1;
    while (n!=NULL)
    {
        cout << n->veri << "\t";
        n = n->next;
    }
    if (bas == NULL)
    {
        cout << "Liste bos !!" << endl;
    }
    cout << endl;
}
int main()
{

    basa_ekle(9);
    basa_ekle(19);
    basa_ekle(29);
    basa_ekle(39);
    basa_ekle(49);
    cout << " One ekleme yapildi : " ;
    yaz();
    sona_ekle(1);
    sona_ekle(21);
    sona_ekle(31);
    sona_ekle(41);
    sona_ekle(51);
    cout << " Sona ekleme yapildi : ";
    yaz();
    araya_ekle(5);
    araya_ekle(15);
    araya_ekle(25);
    araya_ekle(35);
    araya_ekle(45);
    cout << " Araya ekleme yapildi : ";
    yaz();
    ara();
    bastan_sil();
    cout << " Bastan 3 dugum silindi : ";
    yaz();
    sondan_sil();
    cout << " Sondan 3 dugum silindi : ";
    yaz();
    aradan_sil();
    cout << " Aradan 3 dugum silindi : ";
    yaz();
    



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
