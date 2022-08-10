#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int sayi;
	struct node* sonraki;
	int oncelik;
    };
    struct node *baslangic = NULL;
    struct node *olustur(int sayi,int once)
    {
	struct node *yenidugum = (struct node*)malloc(sizeof(struct node));
	yenidugum->sayi=sayi;
	yenidugum->oncelik=once;
	yenidugum->sonraki=NULL;
	
	return yenidugum;
    }
    void sonaekle(int sayi,int once){
	struct node *sonaek =olustur(sayi,once);
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
    void bassil(){
		if(baslangic==NULL){
			printf("Eleman kalmadi !!!!!!");
		}
		if(baslangic->sonraki==NULL){
			baslangic=NULL;
			return;
		}
		
		struct node *temp=baslangic->sonraki;
		free(baslangic);
		baslangic=temp;
		
	}
	 void arasile(int eleman){
    	
    	if(baslangic==NULL){
    		printf("Eleman kalmadý !!!");
    		return;
		}
    	if(baslangic->oncelik==eleman){
    		bassil();
    		return;
		}
    	struct node *temp=baslangic;
    	while(temp->sonraki!=NULL){
    		if(temp->sonraki->oncelik==eleman){
    			struct node *gecici=temp->sonraki->sonraki;
		        free(temp->sonraki);
		        temp->sonraki=gecici;
			}
			temp=temp->sonraki;
		}
	}
	void yazdir(){
	struct node *caba=baslangic;
	struct node *taba=baslangic;
	while(caba!=NULL){
		cout<<" Sayi "<<caba->sayi;
		caba=caba->sonraki;
	}
	cout<<endl;
	while(taba!=NULL){
		cout<<" Once: "<<taba->oncelik;
		taba=taba->sonraki;
	}
	cout<<endl;
    } 

int main()
{
	int ekle,once,t,m=0,kucuk=100,p=1,ont;
	while(1){	
	cout<<"Eklemek istediginiz sayiyi giriniz: "<<endl;
	cin>>ekle;
	cout<<"Onceligini giriniz: "<<endl;
	cin>>once;
	sonaekle(ekle,once);
	cout<<"Eklemeye devam etmek istiyor musunuz ?(1/0): "<<endl;
	cin>>t;
	if(t==0){
	break;
	m++;
	}
    }
    yazdir();
	while(p!=0){
    cout<<"Eleman silmek istiyor musunuz ?(1/0): "<<endl;
    cin>>p;
    if(p==0){
    break;
	}
	cout<<"Silmek istediginiz oncelik: "<<endl;
	cin>>ont;
	arasile(ont);
	yazdir();
    }	
}
