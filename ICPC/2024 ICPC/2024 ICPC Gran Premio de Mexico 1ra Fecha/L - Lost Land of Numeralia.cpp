#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
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

ll calcX(double s, double p, double n){
	return ceil((s / (n * p)) - ((n + 1.0) / 2.0));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n;
	int q;
	cin >> n >> q;

	while(q--){
		ll s, p;
		cin >> s >> p;

		ll lim = n / p;
		ll ans = 0;
		for(int i = 2; i <= 1001; i++){
			ll x = max(calcX(s, p, i), 0LL);
			//cout << i << ": " << x;
			ll ax = (lim - x + 1) - i;
			//cout << ' ' << ax << ENDL;
			ans += max(ax, 0LL);
		}
		cout << ans << ENDL;
	}

 	return 0;
}
