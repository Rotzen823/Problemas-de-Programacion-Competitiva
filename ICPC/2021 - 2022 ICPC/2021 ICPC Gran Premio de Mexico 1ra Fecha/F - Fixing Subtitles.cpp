#include<iostream>
#define MAX 205
 
using namespace std;
 
int sx,msx;
string txt;
 
void mostrar(int h, int m, int s, int ms){
	ms+=msx;
	s+=sx;
	if(ms>=1000){
		s+=(ms/1000);
		ms=ms%1000;
	}
	if(s>=60){
		m+=(s/60);
		s=s%60;
	}
	if(m>=60){
		h+=(m/60);
		m=m%60;
	}
	
	if(h<10) cout<<"0";
	cout<<h<<":";
	if(m<10) cout<<"0";
	cout<<m<<":";
	if(s<10) cout<<"0";
	cout<<s<<",";
	if(ms<100){
		cout<<"0";
		if(ms<10) cout<<"0";
	}
	cout<<ms;
		
}
 
int main(){
	int n;
	int h,m,s,ms,c,j,lim=2;
	char ax;
	scanf("%d %d%c%d%c",&n,&sx,&ax,&msx,&ax);
	
	while(n--){
		getline(cin,txt);
		cout<<txt<<"\n";
		getline(cin,txt);
		h=(txt[0]-48)*10+(txt[1]-48);
		m=(txt[3]-48)*10+(txt[4]-48);
		s=(txt[6]-48)*10+(txt[7]-48);
		ms=(txt[9]-48)*100+(txt[10]-48)*10+(txt[11]-48);
		mostrar(h,m,s,ms);
		h=(txt[17]-48)*10+(txt[18]-48);
		m=(txt[20]-48)*10+(txt[21]-48);
		s=(txt[23]-48)*10+(txt[24]-48);
		ms=(txt[26]-48)*100+(txt[27]-48)*10+(txt[28]-48);
		cout<<" --> ";
		mostrar(h,m,s,ms);
		cout<<"\n";
		getline(cin,txt);
		while(txt!=""){
			cout<<txt<<"\n";
			getline(cin,txt);
		}
		cout<<"\n";
	}
}


