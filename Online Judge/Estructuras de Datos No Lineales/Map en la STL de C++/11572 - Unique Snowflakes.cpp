#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    int n;
	cin >> n;

	while(n--){
		int m, res = 0, sum = 0;
		cin >> m;

		map<ll, int> snow;
		ll x;
		int ax = 0;
		for(int k = 0; k < m; k++){
			cin >> x;

			ax = max(snow[x], ax);

			sum = k - ax + 1;
			snow[x] = k + 1;

			res = max(res, sum);
		}

		cout << res << "\n";
	}

    return 0;
}