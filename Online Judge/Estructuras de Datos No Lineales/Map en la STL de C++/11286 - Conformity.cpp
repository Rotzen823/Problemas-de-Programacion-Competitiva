#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    int n;

	while(scanf("%d", &n), !(n == 0)){
		ll num[5];
		map<ll, int> comb;
		int mayor = 0;

		while(n--){
			for(int k = 0; k < 5; k++){
				cin >> num[k];
			}
			sort(num, num + 5);

			ll id = 0;
			for(int k = 0; k < 5; k++){
				id *= 1000;
				id += num[k];
			}

			comb[id]++;
			mayor = max(mayor, comb[id]);
		}

		int res = 0;
		for(auto x : comb){
			if(x.second == mayor){
				res += mayor;
			}
		}

		printf("%d\n", res);

	}

    return 0;
}