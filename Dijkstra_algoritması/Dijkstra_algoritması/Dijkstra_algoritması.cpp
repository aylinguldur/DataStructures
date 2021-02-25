// Dijkstra_algoritması.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
#include<climits>   
#define size 6
using namespace std;
int minimum(int uzaklık[], bool Dugum[])
{
	int min = INT_MAX;
	int indis;

	for (int i = 0;i < size;i++)
	{
		if (Dugum[i] == false && uzaklık[i] <= min)
		{
			min = uzaklık[i];
			indis = i;
		}
	}
	return indis;
}
void Dijkstra(int graph[size][size], int baslangıc)
{
	int uzaklık[6];
	bool Dugum[6];
	for (int i = 0; i < size; i++)
	{
		uzaklık[i] = INT_MAX;
		Dugum[i] = false;
	}

	uzaklık[baslangıc] = 0;

	for (int i = 0; i < size; i++)
	{
		int t = minimum(uzaklık, Dugum);
		Dugum[t] = true;
		for (int i = 0; i < size; i++)
		{

			if (Dugum[i] == false && graph[t][i] && uzaklık[t] != INT_MAX && uzaklık[t] + graph[t][i] < uzaklık[i])
				uzaklık[i] = uzaklık[t] + graph[t][i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << i << " . dugum  :    " << uzaklık[i] << endl;
	}
}

int main()
{
	int graph[size][size] = {
		{0,4,2,0,0,0},
		{4,0,1,5,0,0},
		{2,1,0,8,10,0},
		{0,5,8,0,2,6},
		{0,0,10,2,0,3},
		{0,0,0,6,3,0},
	};
	Dijkstra(graph, 0);
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
