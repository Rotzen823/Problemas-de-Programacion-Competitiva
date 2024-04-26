#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 10000000000000
#define MAX 1000005

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll r, p;

ll memo[MAX];

ll dp(ll n){
	if(n == 1){
		return 0;
	}

	if(memo[n] != -1){
		return memo[n];
	}

	ll ans = (n - 1) * p + r;
	for(ll d = 1; d < n; d++){
		ll ax = n / (d + 1);
		if(n % (d + 1) > 0){
			ax++;
		}
		ll op = dp(ax) + (p * d) + r;
		ans = min(op, ans);
	}

	return memo[n] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	memset(memo, -1, sizeof(memo));

	ll n;
	cin >> n >> r >> p;
	
	ll ans = dp(n);

	cout << ans << ENDL;

  return 0;
}
