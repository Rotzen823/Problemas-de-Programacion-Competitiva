#include <bits/stdc++.h>
#define MAX 105
#define MOD 1000000007
 
using namespace std;

typedef long long ll;

int freq[15];
ll comb[MAX][MAX];
ll memo[15][11][55][55];

ll nCk(int n, int k){
    if(k > n || k < 0){
        return 0;
    }

    if(k == n || k == 0){
        return 1;
    }

    if(comb[n][k]){
        return comb[n][k];
    }

    return comb[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k)) % MOD;
}

ll dp(int dig, int mod, int par, int imp){
    if(par < 0 || imp < 0){
        return 0;
    }

    if(dig == 10){
        return mod == 0 ? 1 : 0;
    }

    if(memo[dig][mod][par][imp] != -1){
        return memo[dig][mod][par][imp];
    }

    ll tot = 0;
    for(int k = 0; k <= freq[dig]; k++){
        int px = k;
        int ix = freq[dig] - px;

        ll ax = dig == 0 ? 1 : 0;
        ll res = nCk(par - ax, px);
        res *= nCk(imp, ix); res %= MOD;
        res *= dp(dig + 1, (mod + dig * (px - ix)) % 11, par - px, imp - ix);
        res %= MOD;
        tot += res; tot %= MOD;
    }

    return memo[dig][mod][par][imp] = tot;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(memo, -1, sizeof(memo));
    string num;
    cin >> num;

    int len = num.length();
    for(char x : num){
        freq[x - '0']++;
    }

    cout << dp(0, 0, (len / 2) + (len % 2), len / 2) << "\n";
    
    return 0;
}
