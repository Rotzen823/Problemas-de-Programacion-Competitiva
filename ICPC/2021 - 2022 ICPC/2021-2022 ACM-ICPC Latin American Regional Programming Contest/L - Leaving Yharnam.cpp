#include <bits/stdc++.h>
#define MAX 2000005
#define MOD 1000000007
 
using namespace std;

typedef long long ll;

ll memo[MAX], memo2[MAX];

ll mcdExt(int a, int b){
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

ll factorial(ll n){
    if(n == 0 || n == 1){
        return 1;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = n * factorial(n - 1);
    memo[n] %= MOD;
    return memo[n];
}

ll pot2(ll n){
    if(n == 0){
        return 1;
    }

    if(memo2[n] != -1){
        return memo2[n];
    }

    return memo2[n] = ((pot2(n - 1) * 2) % MOD);
}

ll comb(ll a, ll b){
    ll den = (factorial(b) * factorial(a - b)) % MOD;
    return inv_mod(factorial(a), den);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(memo, -1, sizeof(memo));
    memset(memo2, -1, sizeof(memo2));
    ll n, g, i, e;
    cin >> n >> g >> i >> e;
    g = min(g, (n * 2));
    e = min(e, (n * 2) - g);
    i = min(i, (n * 2) - (g + e));

    if(e == 0 && i == 0){
        cout << g << "\n";
        return 0;
    }

    ll res = 0;
    ll tot = comb(2 * n, g);
    for(ll k = max(0LL, g - n); (k * 2) <= g; k++){
        //Easy-going
        ll px = g;
        //Easy going en parejas
        ll qx = comb(n, k);
        //Easy going solos
        ll gSolos = g - (k * 2);
        qx *= comb(n - k, gSolos); qx %= MOD;
        qx *= pot2(gSolos); qx %= MOD;
        qx = inv_mod(qx, tot);

        //Extroverts with Easy Going
        px += min(e, gSolos);
        ll newE = e - min(e, gSolos);
        ll newN = n - (k + gSolos);
        gSolos -= min(e, gSolos);

        //Extroverts en parejas
        bool soloE = newE & 1;
        px += (newE - soloE);

        newN -= (newE / 2);
        if(soloE){
            newN--;
        }

        //Introvert With Extrovert
        ll newI = i;
        if(newI > newN && soloE){
            newI--;
            px++;
        }
        else if(newI > newN && gSolos > 0){ //Introvert With Easy Going
            ll iPar = min(gSolos, newI - newN);
            newI -= iPar;
        }

        //Introverts with Introverts
        ll iSolos = newI - (max(0LL, newI - newN) * 2);
        newN -= max(0LL, newI - newN);

        //Introverts Alone
        px += (iSolos);

        //Juntar resultados
        qx *= px; qx %= MOD;
        res += qx; res %= MOD;
    }

    cout << res << "\n";
    return 0;
}
