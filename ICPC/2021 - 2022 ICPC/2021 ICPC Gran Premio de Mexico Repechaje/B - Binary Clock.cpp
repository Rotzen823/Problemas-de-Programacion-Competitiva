#include<bits/stdc++.h>

using namespace std;

int leer(int lim){
	int t = 0;
	char a,c;
	for(int k=lim-1; k>=0; k--){
		cin>>a>>c;
		if(c == '*'){
			cin>>c;
			t+= pow(2,k);
		}
	}
	t*=10;
	for(int k=3; k>=0; k--){
		cin>>a>>c;
		if(c == '*'){
			cin>>c;
			t+= pow(2,k);
		}
	}
	return t;
}

int main(){
	int n, h, m, s;
	cin>>n;
	for(int k=1; k<=n; k++){
		h = leer(2);
		m = leer(3);
		s = leer(3);
		cout<<"Case "<<k<<": ";
		if(h<10) cout<<"0";
		cout<<h<<":";
		if(m<10) cout<<"0";
		cout<<m<<":";
		if(s<10) cout<<"0";
		cout<<s<<"\n";
	}
	return 0;
}
