#include<bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;

typedef long long ll;

bool primo[MAX];
ll pot[MAX];
vector <ll> fact;

void criba(){
	primo[0]=primo[1]=true;
	for(int k=2; (k*k)<=MAX; k++){
		if(!primo[k]){
			for(int j=k*k; j<=MAX; j+=k){
				primo[j]=true;
			}
		}
	}
}

ll pot2(ll k){
	if(pot[k]) return pot[k];
	pot[k] = (2 * pot2(k-1))%MOD;
	return pot[k];
}

ll sum(int p, int lim, ll f, ll sig, ll x){
	ll s=0, comb, r,exp;
	for(int k=p; k<lim; k++){
		comb=f*fact[k];
		exp = x/comb;
		r= sig * pot2(exp);
		//cout<<k<<" "<<comb<<" "<<exp<<" "<<r<<"\n";
		s= (s+r)%MOD;
		s= (s + sum(k+1, lim, comb, -sig, x))%MOD;
	}
	return s;
}

int main(){
	int n,c;
	ll x,lim,f;
	pot[0]=1;
	cin>>n;
	criba();
	while(n--){
		cin>>x;
		c=0;
		for(ll k=2; k<=x; k++){
			if(x%k==0 && !primo[k]){
				fact.push_back(k);
				c++;
			}
		}
		cout<<sum(0,c,1,1,x)<<"\n";
		while(!fact.empty()){
			fact.pop_back();
		}
	}
	cout<<(pot2(96)+pot2(64)-pot2(32))%MOD;
	return 0;
}
