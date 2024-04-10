#include <bits/stdc++.h>
#define MAX 2025

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll mod;
ll memoT[MAX], memo[MAX], comb[MAX][MAX];

ll nCk(int n, int k) {
  if (k > n || k < 0)
    return 0;
  if (n == k || k == 0)
    return 1;
  if (comb[n][k] != -1)
    return comb[n][k];
  return comb[n][k] = (nCk(n - 1, k) + nCk(n - 1, k - 1)) % mod;
}

ll dp(int n){
    if(n <= 1){
        return 1;
    }

    if(memoT[n] != -1){
        return memoT[n];
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        ll sum = dp(i + 1) * dp(n - 2 - i); sum %= mod;
        sum *= nCk(n - 2, i); sum %= mod;
        ans += sum; ans %= mod;
    }

    return memoT[n] = ans;
}

ll dp(int n, int a){
    if(memo[n] != -1){
        return memo[n];
    }

    ll ans = dp(n);
    //cout << n << ' ' << a << ' ' << ans << ENDL;
    for(int i = a; i < n; i++){
        ll sum = dp(i, a) * dp(n - i + 1); sum %= mod;
        sum *= nCk(n - a, n - i); sum %= mod;
        ans = (ans - sum + mod) % mod;
    }

    return memo[n] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, r;
    cin >> r >> n >> mod;

    memset(memo, -1, sizeof(memo));
    memset(comb, -1, sizeof(comb));
    memset(memoT, -1, sizeof(memoT));

    ll ans = dp(n, n - r + 1);

    cout << ans << ENDL;

  return 0;
}
