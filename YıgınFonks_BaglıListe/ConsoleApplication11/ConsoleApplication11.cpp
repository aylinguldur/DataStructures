// ConsoleApplication11.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
using namespace std;
class yiginDugum
{
public:
    int veri;
    yiginDugum* next;
};
class yigin
{
    yiginDugum* ust;
public:
    yigin();
    void pop();
    void push(int deger);
    void listele();
};
yigin::yigin()
{
    ust = NULL;
}
void yigin::push(int deger)
{ 
    yiginDugum* y = new yiginDugum();
    if (ust == NULL)
    {
        
        y->veri = deger;
        y->next = NULL;
        ust = y;
    }
    else
    {
        y->veri = deger;
        y->next = ust;
        ust = y;
    }
}
void yigin::pop()
{
    yiginDugum* y;
    yiginDugum* t;
    y = ust;
    if (ust == NULL)
    {
        cout << " Yigin bos !!" << endl;
    }
    else
    {
        t = y;
        y = y->next;
        ust = y;
        free(t);
        cout << " Yigindan eleman cikarildi . " << endl;
    }
}
void yigin::listele()
{
    if (ust == NULL)
    {
        cout << " Yigin bos !!" << endl;
    }
    else
    {
        yiginDugum* y;
        y = ust;
        int i = 1;
        do
        {
            cout << i << ". eleman : " << y->veri << endl;
            i++;
            y = y->next;
        } while (y);
    }
}
int main()
{
    yigin y;
    int islem ;
    int deger ;
    cout << " Yiginda yapmak istediginiz islemi seciniz " << endl;
    cout << " 1- ekle " << endl;
    cout << " 2- cikar " << endl;
    cout << " 3- listele " << endl;
    do
    {
        cout << "islem :";
        cin >> islem;
        switch (islem)
        {
        case 1: cout << " Eklemek istediginiz degeri giriniz : ";
            cin >> deger;
            y.push(deger); 
            break;
        case 2: y.pop();
            break;
        case 3: y.listele(); break;
        }
    } while (islem != 0);
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
