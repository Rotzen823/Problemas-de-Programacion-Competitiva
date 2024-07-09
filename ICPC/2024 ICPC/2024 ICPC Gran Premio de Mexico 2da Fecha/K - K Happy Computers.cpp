#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}

ll modInverse(ll a) {
    ll x, y, d = euclid(a, MOD, x, y);
    assert(d == 1);
    return (x + MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, divN;
    int k;
    cin >> n >> k;

    divN = modInverse(n);
    //cout << divN << ENDL;

    ll ans = ((n % MOD) * modInverse(k - 1)) % MOD;
    for(int i = k - 2; i >= 0; i--){
        ans++; ans %= MOD;
        ans *= (n - i) % MOD; ans %= MOD;
        //cout << ans << ' ';
        ans += i; ans %= MOD;
        //cout << ans << ' ';
        ans *= divN; ans %= MOD;
    }

    cout << ans << ENDL;


 	return 0;
}
