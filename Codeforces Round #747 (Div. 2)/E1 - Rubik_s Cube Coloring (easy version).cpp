#include<bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;

typedef long long ll;

ll bin(ll a, ll n){
	ll res=1;
	while(n>0){
		if(n%2) res=(res%MOD) * (a%MOD);
		a=(a%MOD) * (a%MOD);
		n/=2;
	}
	return res;
}
 
int main(){
	ll k,pot=2,res;
	cin>>k;
	while(--k){
		pot*=2;
	}
	pot-=2;
	res=bin(4,pot);
	res = ((res%MOD) * 6)%MOD;
	cout<<res<<"\n";
}
