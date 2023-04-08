#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool bus(ll n){
	bool res = false;
	ll p,lim,c,l;
	c = 8*(n-2)+1;
	p = (ll) sqrt(c);
	if(p*p==c){
		lim = (p-1)/2;
		for(ll k=0; k<=lim; k++){
			cout<<"A";
		}
		cout<<"B";
		return true;
	}
	l = (ll) sqrt(n);
	for(ll k=l; k>=2; k--){
		if(n%k==0){
			c = 8*(k-2)+1;
			p = (ll) sqrt(c);
			if(p*p==c){
				res = bus(n/k);
				if(res){
					break;
				}
			}
		}
	}
	if(res){
		lim = (p-1)/2;
		for(ll k=0; k<=lim; k++){
			cout<<"A";
		}
		cout<<"B";
	}
	return res;
}

int main(){
	ll n;
	bool res;
	cin>>n;
	res = bus(n);
	if(!res){
		cout<<"IMPOSSIBLE";
	}
	cout<<"\n";
	return 0;
}
