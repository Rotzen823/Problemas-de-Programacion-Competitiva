#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, m;

	cin >> n >> m;

	ll ax = 0;

	for(ll k = 3; k < n; k++){
		if(__builtin_popcount(k) & 1){
			continue;
		}

		if((k - ax) > m){
			ax = k;
			k += m;
		}
	}

	if((n - ax) <= m){
		cout << "Pay the bill\n";
	}
	else{
		cout << "Free snacks!\n";
	}

	return 0;
}