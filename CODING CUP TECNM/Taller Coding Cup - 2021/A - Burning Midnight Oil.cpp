#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll k,n;

bool bus(ll v){
	ll sum=v;
	while(v>0){
		v/=k;
		sum+=v;
		if(sum>=n) break;
	}
	return sum >= n;
}

int main(){
	cin>>n>>k;
	ll i=1,f=n,med;
	while(i<f){
		med=(i+f)/2;
		if(bus(med)){
			f=med;
		}
		else{
			i=med+1;
		}
	}
	cout<<i<<"\n";
	return 0;
}
