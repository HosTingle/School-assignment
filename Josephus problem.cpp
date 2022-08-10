#include <iostream>
#include <sstream>
#include <cstring> 
#include <queue>
#include <limits>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string elemanlar;
	int i,a,b,c,d,n,say=0;
	char temp;
	queue <char> daire;
	cout<<"Kisi harflerini giriniz:(ABCDEF.. seklinde)"<<endl;
	getline(cin, elemanlar);
	cout<<"Kac Kiside bir elenme olacak?(n):"<<endl;
	cin>>n;
	for(i=0;i<elemanlar.length();i++){
		daire.push(elemanlar[i]);
	}
	while(daire.size()!=1){
	    say++;
		if(say==n){
		cout<<daire.front()<<":** Kisisi oldu :=("<<endl;;
		daire.pop();
		say=0;
		continue;
		}
		temp=daire.front();
		daire.pop();
		daire.push(temp);
	}
	cout<<"Kurtulan kisi:"<<daire.back()<<endl;
	
	



	
}

