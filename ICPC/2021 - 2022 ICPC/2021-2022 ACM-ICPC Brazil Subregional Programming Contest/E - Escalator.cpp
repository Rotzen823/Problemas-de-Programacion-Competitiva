#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,t,d,act=0;
	bool dir,fila=false;
	cin>>n;
	cin>>t>>d;
	act=t+10;
	dir=d;
	while(--n){
		cin>>t>>d;
		if(d==dir){
			if(t<act){
				act=t+10;
			}
			else if(fila){
				act+=10;
				dir=!dir;
			}
			else{
				act=t+10;
				fila=false;
			}
		}
		else{
			if(t<act){
				fila=true;
			}
			else{
				act=t+10;
				dir=!dir;
				fila=false;
			}
		}
	}
	if(fila){
		act+=10;
	}
	cout<<act<<"\n";
	return 0;
}
