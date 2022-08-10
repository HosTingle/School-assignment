 #include <iostream>
#include <queue>
#include <cstdlib>
#include <math.h>
using namespace std;

void radixsort(int q[], int n);

int main() {
  const int boyut=10;
  int radix[boyut], *sortedRadix;
  cout<<"Sayilari giriniz(10 adet):"<<endl;
  for (int i=0;i<boyut;i++){
    cin>>radix[i];
  }
  radixsort(radix, boyut);
  cout << "Sonuc:";
  for (int j=0;j<boyut;j++)
    cout << radix[j] << " ";
    cout<<"\nKarmasiklik O(n^2)";
    cout << endl;
    return 0;
}

void radixsort(int q[], int n) {
    queue<int> dizi[10]; 
    int basamak=3; 
    int sayi=0; 
    while (sayi < basamak) {
        for(int i=0; i<n; i++){ 
            int bol=pow(10,sayi);
            int b = q[i]; 
            int a = static_cast<int>((b/bol)%10); 
            dizi[a].push(b); 
        }
        int i=0;
        for(int k=0;k<10;k++){ 
            while (!dizi[k].empty()){ 
                int temp=dizi[k].front();
                q[i]=temp;
                dizi[k].pop();
                i++;
            }
        }
        sayi++;
    }
}
