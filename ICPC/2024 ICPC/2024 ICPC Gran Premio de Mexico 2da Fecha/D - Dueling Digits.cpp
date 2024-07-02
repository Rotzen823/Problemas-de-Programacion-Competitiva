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

ll memo[805][14405];

ll dp(int i, int dif = 7200){
    if(i == 0){
        return dif == 7200;
    }

    if(memo[i][dif] != -1){
        return memo[i][dif];
    }

    ll ans = 0;
    for(int d = 1; d <= 9; d++){
        ans += (dp(i - 1, dif + d) * (10LL - d)) % MOD;
        ans %= MOD;
        ans += (dp(i - 1, dif - d) * (10LL - d)) % MOD;
        ans %= MOD;
    }

    return memo[i][dif] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int q;
    cin >> q;
    memset(memo, -1, sizeof(memo));

    while(q--){
        int n;
        cin >> n;

        ll ans = dp(n);
        for(int i = 1; i <= 9; i++){
            ans -= (dp(n - 1, 7200 + i) + dp(n - 1, 7200 - i)) % MOD;
            ans = (ans + MOD) % MOD; 
        }

        cout << ans << ENDL;
    }

 	return 0;
}
