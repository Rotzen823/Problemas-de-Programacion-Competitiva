#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){	
	int c;
	cin >> c;

	while(c--){
		int n, m, cargo = 0;
		ll t, mint = 0;

		cin >> n >> t >> m;
		int lad = 0;

		ll minutos[m];
		queue<pair<ll, int> > colas[2];

		for(int k = 0; k < m; k++){
			ll x;
			string lado;

			cin >> x >> lado;

			if(k == 0){
				mint = x;
			}

			if(lado == "left"){
				colas[0].push({x, k});
			}
			else{
				colas[1].push({x, k});
			}
		}

		while(!colas[0].empty() || !colas[1].empty()){
			if(colas[lad].empty()){
				if(cargo > 0){
					cargo = 0;
					mint += t;
					lad = (lad + 1) % 2;
					continue;
				}
				lad = (lad + 1) % 2;
				cargo = 0;
				if(colas[lad].front().first <= mint){
					mint += t;
				}
				else{
					mint = colas[lad].front().first + t;
					//cout << mint << "\n";
				}
				continue;
			}

			if(colas[lad].front().first <= mint){
				minutos[colas[lad].front().second] = mint + t;
				colas[lad].pop();
				cargo++;
				if(cargo == n){
					cargo = 0;
					mint += t;
					lad = (lad + 1) % 2;
				}
			}
			else if(cargo > 0){
				cargo = 0;
				mint += t;
				lad = (lad + 1) % 2;
			}
			else if(!colas[(lad + 1) % 2].empty()){
				if(colas[(lad + 1) % 2].front().first < colas[lad].front().first){
					lad = (lad + 1) % 2;
					cargo = 0;

					if(colas[lad].front().first <= mint){
						mint += t;
					}
					else{
						mint = colas[lad].front().first + t;
					}
				}
				else{
					mint = colas[lad].front().first;
				}
			}
			else{
				mint = colas[lad].front().first;
			}
		}

		for(int k = 0; k < m; k++){
			cout << minutos[k] << "\n";
		}

		if(c){
			cout << "\n";
		}
	}
	
	return 0;
}