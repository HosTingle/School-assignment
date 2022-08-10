#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cstring> 
#include <queue>
#include <limits>
#include <string>
#include <math.h>
using namespace std;

struct node{
	char harf;
	struct node* sonraki;
	struct node *gizli;
    };
    struct node *baslangic = NULL;
    struct node *olustur(int harf)
    {
	struct node *yenidugum = (struct node*)malloc(sizeof(struct node));
	yenidugum->harf=harf;
	yenidugum->sonraki=NULL;
	
	return yenidugum;
    }
    void bagla(){
    struct node *temp =baslangic;
	while( temp -> sonraki !=NULL)
	{
	temp= temp->sonraki;
	}
	temp->sonraki=baslangic;
	}
    void ekle(int harf){
	struct node *sonaek =olustur(harf);
	if(baslangic==NULL){
		baslangic=sonaek;
	}
	else
	{
	struct node *temp =baslangic;
	while( temp -> sonraki !=NULL)
	{
		temp= temp->sonraki;
	}
	temp->sonraki=sonaek;
	
    }
    }
	char dolas(int k){
	int say=0;
	struct node *zaba=baslangic;
	while(zaba!=NULL ){
		say++;
		if(say==k){
		return zaba->harf;
		}
		zaba=zaba->sonraki;
	}
    }
    int josephus(int q, int p) {
    if (q == 1)
    return 1;
    else
    return (josephus(q - 1, p) + p - 1) % q + 1;
    }  
int main() {
	int i,kisi,t;
	char a,b;
	cout<<"Kac Kisi olacak?:"<<endl;
	cin>>kisi;
	cout<<"Eklenecek harf:(ABCDE seklinde yazin)"<<endl;
	for(i=0;i<kisi;i++){
		cin>>a;
		ekle(a);
	}
	bagla();
	cout<<"Kac kiside bir olum olacak?:"<<endl;
	cin>>t;
	b=josephus(kisi,t);
    cout<<"Geriye kalan son kisi:"<<dolas(b)<<endl;
    
}
