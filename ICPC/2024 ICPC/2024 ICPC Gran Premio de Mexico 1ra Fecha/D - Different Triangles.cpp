#include <bits/stdc++.h>
#define MOD 1000000007
#define ENDL '\n'

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;

int solve(int n){
	int ans = 0;
	for(int i = 1; i < (n - i); i++){
		//cout << i << ": ";
		int a = i + 1, b = min(n - i, i * 2);

		int len = (b - a + 1);
		ll sum = (len) * (a + b) / 4;
		//cout << "sum : " << sum;

		int rest = (len * (len - 1)) / 2;
		sum -= rest;

		//cout << " rest: " << rest;

		if(a % 2 == 0) a++;
		if(b % 2 == 0) b--;
		int imp = (b - a) / 2 + 1;

		if(a > b){
			imp = 0;
		}
		//cout << " imp: " << imp << ENDL; 

		sum -= (imp / 2);
		ans += sum;
	}
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;

	vi sumDiv(n + 1), sumR(n + 1);

	for(int i = 1; i <= n; i++){
		sumDiv[i] = ((i / 2 ) + sumDiv[i - 1]) % MOD;
		sumR[i] = (i + sumR[i - 1]) % MOD;
	}

	int ans = 0;
	for(int i = 1; i < (n - i); i++){
		int a = i + 1, b = min(n - i, i * 2);

		ll sum = (sumDiv[b] - sumDiv[a - 1] + MOD) % MOD;

		ll rest = sumR[b - a];

		sum = (sum - rest + MOD) % MOD;
		ans += sum; ans %= MOD;
	}

	cout << ans << ENDL;

 	return 0;
}
