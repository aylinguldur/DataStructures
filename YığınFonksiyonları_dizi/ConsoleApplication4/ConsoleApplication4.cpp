// ConsoleApplication4.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
//AYLİNNUR GÜLDÜR 191307006
class stack
{
    char dizi[10];
    int ust;
public:

    stack();
    char pop();
    void push(char a);

};
stack::stack()
{
    ust = 0;
}
 char stack::pop()
{
    if (ust == 0)
    {
        cout << "Yiginda eleman yok." << endl;
        return -1;
    }
    else
    {
        ust--;
        return dizi[ust];
    }
}
 void stack::push(char a)
 {
     if (ust == 10)
     {
         cout << "Yigin dolu. "<< a << " yigina eklenemedi." << endl;
     }
     else
     {
         dizi[ust] = a;
         cout << "Eklenen eleman : " <<a<<endl;
         ust++;
     }

 }

int main()
{
    stack s1,s2;
    char a;
    s1.push('A');
    s1.push('B');
    s1.push('C');
    s1.push('D');
    s1.push('E');
    s1.push('F');
    s1.push('G');
    s1.push('H');
    s1.push('I');
    s1.push('J');
    s1.push('K');
    for (int i = 0;i < 11;i++)
    {
        a=s1.pop();
        if (a!=-1)
        {
            cout << "Yigindan cikarilan eleman : " << a << endl;
        }
        
    }

    //Yığına eklenen isim-soyisim ekrana yazdırıldığında ilk harften başlayarak sona doğru sırayla yazdırılır.
    //Yığından elemanlar çekildiğinde ise "son eklenen eleman ilk çıkar" mantığına dayanılarak 
    //isim-soyisim son harften başlayarak ilk harfe doğru yazdırılır.


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
