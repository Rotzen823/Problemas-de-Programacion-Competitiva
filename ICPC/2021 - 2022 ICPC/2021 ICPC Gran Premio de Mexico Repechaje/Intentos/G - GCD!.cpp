#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	ll x,y,r=1,limy,j;
	cin>>n;
	
	while(n--){
		cin>>x>>y;
		if(x >= y){
			cout<<y<<"\n";
			continue;
		}
		r = 1;
		limy = (ll) sqrt(y);
		for(ll k=limy; k>=2; k--){
			if(y % k == 0){
				j = y / k;
				if(k <= x && y % (r*k) == 0){
					r *= k;
				}
				if(j <= x && j != k && y % (r*j) == 0){
					r *= j;
				}
			}
		}
		cout<<r<<"\n";
	}
	
	return 0;
}
