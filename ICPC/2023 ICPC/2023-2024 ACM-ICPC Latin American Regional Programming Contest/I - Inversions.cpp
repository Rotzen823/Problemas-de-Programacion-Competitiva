#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 1000005

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll x[MAX], t[MAX];
int cont[30];

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
    if(a == 0){
        return 0;
    }
    ll x = mcdExt(b, MOD);
    x = (x + MOD) % MOD;
    return (a * x) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string pal;
    ll n;
    cin >> pal >> n;

    int lim = pal.length();

    for(int k = lim - 1; k >= 0; k--){
        cont[pal[k] - 'a']++;
        for(int j = 0; j < (pal[k] - 'a'); j++){
            x[k] += cont[j];
        }
    }

    ll res = 0;
    for(int k = 0; k < lim; k++){
        for(int j = 0; j < (pal[k] - 'a'); j++){
            t[k] += cont[j];
        }
        ll ax = n * x[k];
        ax %= MOD;
        ll ax2 = (n % MOD) * ((n - 1) % MOD) % MOD;
        ax2 = inv_mod(ax2, 2);
        ax2 *= t[k]; ax2 %= MOD;
        ax += ax2; ax %= MOD;
        res += ax; res %= MOD;
    }

    cout << res << "\n";

    return 0;
}
