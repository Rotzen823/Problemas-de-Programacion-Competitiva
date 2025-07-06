#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 1000000000
#define MOD 998244353
#define MAX 1000005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll mcdExt(ll a, ll b){
    ll r, y = 0, x1 = 0, y1 = 1, tx, ty;
    ll x = 1;
    while(b > 0){
        r= a % b;
        tx = x1, ty = y1;
        x1 = x - (a / b) * x1;
        x = tx;
        y1 = y - (a / b) * y1;
        y = ty;
        a = b;
        b = r;
    }

    return x;
}

ll inv_mod(ll a, ll b){
    ll x = mcdExt(b, MOD);
    x = (x + MOD) % MOD;
    return (a * x) % MOD;
}

ll fact[MAX];

ll comb(int n, int k){
    ll num = fact[n];
    ll den = (fact[k] * fact[n - k]) % MOD;

    return inv_mod(num, den);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAX; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int q;
    cin >> q;

    while(q--){
        int n, k;
        cin >> n >> k;

        cout << comb(n + 1, k + 1) << ENDL;
    }

    return 0;
}
