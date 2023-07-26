#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll modpow(ll x, ll n, ll m) {
    if (n == 0)
        return 1;

    ll u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n % 2 == 1){
        u = (u * x) % m;
    }

    return u;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll k, res;
	cin >> k;
	ll pot = (1LL << k) - 2;

    res = modpow(4, pot, MOD);
    res = (res * 6) % MOD;

    cout << res << "\n";

    return 0;
}
