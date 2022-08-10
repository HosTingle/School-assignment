#include <iostream>
#include <sstream>
#include <cstring> 
#include <stack>
#include <limits>
#include <string>
#include <math.h>
using namespace std;
int main(){
	string posfix;
	int hold,a,t,l;
	cout << "Posfix ifadeyi giriniz: " << endl;
    
	getline(cin, posfix);
    
	stack<char> kor;
	string output = "";
    for (int i = 0; i < posfix.length(); i++){
    	if(isdigit(posfix[i])){
    	l=posfix[i]-'0';
    	kor.push(l);
		}
    	else if( posfix[i] == '-'){
    	a=kor.top();
    	kor.pop();
		t=kor.top();
		kor.pop();
		hold=t-a;
		kor.push(hold);
		}
		else if(posfix[i] == '/'){
			a=kor.top();
    	kor.pop();
		t=kor.top();
		kor.pop();
		hold=a/t;
		kor.push(hold);
		}
		else if(posfix[i] == '^'){
		a=kor.top();
    	kor.pop();
		t=kor.top();
		kor.pop();
		hold=pow(t,a);
		kor.push(hold);
		}
		else if(posfix[i] == '*' ){
			a=kor.top();
    	kor.pop();
		t=kor.top();
		kor.pop();
		hold=a*t;
		kor.push(hold);
		}
		else if(posfix[i] == '+'){
    	a=kor.top();
    	kor.pop();
		t=kor.top();
		kor.pop();
		hold=a+t;
		kor.push(hold);
        }
	}
	hold=kor.top();
	cout<<"Sonuc:"<<(int)hold<<endl;

}
