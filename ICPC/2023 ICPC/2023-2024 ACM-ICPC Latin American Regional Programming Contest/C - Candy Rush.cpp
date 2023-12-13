#include <bits/stdc++.h>
#define MAX 400005
#define MOD1 1000000007
#define MOD2 1000000009
#define P1 400009
#define P2 400031

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll memo1[MAX], memo2[MAX];

ll dp1(int n){
    if(n == 0){
        return 1;
    }

    if(memo1[n]){
        return memo1[n];
    }

    return memo1[n] = (P1 * dp1(n - 1)) % MOD1;
}

ll dp2(int n){
    if(n == 0){
        return 1;
    }

    if(memo2[n]){
        return memo2[n];
    }

    return memo2[n] = (P2 * dp2(n - 1)) % MOD2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    //int c[n]
    map<ii, int> hash;
    hash[ii(0, 0)] = -1;
    
    ll h1 = 0, h2 = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x != 1){
            h1 += dp1(x);
            h1 %= MOD1;
            h2 += dp2(x);
            h2 %= MOD2;
        }
        if(x != k){
            h1 -= dp1(x + 1);
            h1 += MOD1; h1 %= MOD1;
            h2 -= dp2(x + 1);
            h2 += MOD2; h2 %= MOD2;
        }

        ii h(h1, h2);
        //cout << h1 << " " << h2 << "\n";

        if(hash.count(h)){
            res = max(res, i - hash[h]);
        }
        else{
            hash[h] = i;
        }
    }

    cout << res << "\n";
    return 0;
}
