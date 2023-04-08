#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    int n;
	
	while(scanf("%d", &n), !(n == 0)){
		multiset<ll> recibos;
		ll res = 0;
		while(n--){
			int m;
			scanf("%d", &m);

			while(m--){
				int x;
				scanf("%lld", &x);

				recibos.insert(x);
			}
			
			ll rmen = *recibos.begin();
			ll rmax = *recibos.rbegin();
			recibos.erase(recibos.find(rmen));
			recibos.erase(recibos.find(rmax));
			res += (rmax - rmen);
		}

		printf("%lld\n", res);
	}

    return 0;
}