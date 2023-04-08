#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,d,m,a=0,x;
	bool y=false;
	cin>>t>>d>>m;
	while(m--){
		cin>>x;
		if(x-a>=t){
			y=true;
		}
		a=x;
	}
	if(d-a>=t){
		y=true;
	}
	if(y){
		cout<<"Y\n";
	}
	else{
		cout<<"N\n";
	}
	return 0;
}
