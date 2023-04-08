#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,res;
	bool primo;
	cin>>n;
	if(n==2){
		cout<<"2\n";
	}
	for(ll k=n; k>=2; k--){
		primo=true;
		if(k%2==0) continue;
		for(int j=3; (j*j)<=n; j+=2){
			if(k%j==0){
				primo=false;
				break;
			}
		}
		if(primo){
			cout<<k<<"\n";
			break;
		}
	}
	
	return 0;
}
