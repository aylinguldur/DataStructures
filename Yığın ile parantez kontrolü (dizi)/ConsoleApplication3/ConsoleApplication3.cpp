// ConsoleApplication3.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
#define size 10

class stack
{
    char dizi[size];
    int ust;
public:

    stack();
    char pop();
    void push(char a);
    bool aynıMı(char b, char a);
    bool stackDolu();

};

stack::stack()
{
    ust = 0;
}
void stack::push(char a)
{
    if (ust==size)
    {
        cout << "Yigin dolu" << endl;
    }
    else
    {
        dizi[ust] = a;
        ust++;
    }
    
}
char stack::pop()
{
    if (ust==0)
    {
        cout << "Yigin bos" << endl;
        return -1;
    }
    else
    { 
        ust--;
        return dizi[ust];
    }
  
}
bool stack::aynıMı(char a , char b )
{
    if (a=='(' && b==')')
    {
        return true;
    }
    else if(a == '[' && b == ']')
    {
        return true;
    }
    else  if (a == '{' && b == '}')
    {
        return true;
    }
    else
    {
        cout << "Parantez dizilisleri yanlis!!" << endl;
        return false;
    }
   
}
bool stack::stackDolu()
{
    if (ust!=0)
    {
        return false;
    }
}
int elemanSayısı(string ifade)
{
    int i = 0;
    int eleman = 0;
    while(ifade[i]!='\0')
    {
        eleman++;
        i++;
    }
    return eleman;
    
}
int main()
{
    stack s1;
    string ifade = "{[()]}";
    int eleman = elemanSayısı(ifade);
    cout << ifade<<endl;
    char a;
    char b;
    for (int i = 0; i < eleman; i++)
    {
        if (ifade[i] == '(' || ifade[i] == '{' || ifade[i] == '[')
        {
            a = ifade[i];
            s1.push(a);
        }
        else if (ifade[i] == ')' || ifade[i] == '}' || ifade[i] == ']')
        {
            b = ifade[i];
            a = s1.pop();
            if (a==-1)
            {
                i = eleman;
            }
            else
            { 
                s1.aynıMı(a, b);
            }
            
        }
    }
    if(s1.stackDolu()==false)
    {
        cout << "Ifade bitti. Yigin hala dolu!!" << endl;
    } 

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
