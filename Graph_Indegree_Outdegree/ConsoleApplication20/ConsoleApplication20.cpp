// ConsoleApplication20.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
void outdegree(int matris[7][7])
{
	int derece;
	cout << "-- Node cikis dereceleri -- " << endl;
	for (int i = 0;i < 7;i++)
	{
		derece = 0;
		for (int t = 0;t < 7;t++)
		{
			if (matris[i][t] == 1)
			{ 
				derece++;
			}
		}
		cout << i + 1 << ". Node cikis derecesi : "<< derece << endl;
	}
}
void indegree(int matris[7][7])
{
	int derece;
	cout << "-- Node giris dereceleri --" << endl;
	for (int i = 0;i < 7;i++)
	{
		derece = 0;
		for (int t = 0;t < 7;t++)
		{
			if (matris[t][i] == 1)
			{
				derece++;
			}
		}
		cout << i + 1 << ". Node giris derecesi : " << derece << endl;
	}
}
int main()
{
	int matris[7][7] = {
		{0,1,1,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,1,0,1,0},
		{0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0}
	};
		outdegree(matris);
		indegree(matris);
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
