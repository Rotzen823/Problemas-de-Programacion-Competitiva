#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 305
#define INF 1000000000000

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<pi>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll x[MAX], h;
ll memo[MAX][MAX];

ll dp(int l, int r){
    if(l == r){
        return h;
    }

    if(memo[l][r] != -1){
        return memo[l][r];
    }

    ll ans = INF;
    ll d = x[r] - x[l] + 1;

    ll hlr = max(0LL, h + 1 - (d / 2));
    //cout << l << ' ' << r << ' ' << hlr << ENDL;
    for(int m = l; m < r; m++){
        ll op = dp(l, m) + dp(m + 1, r) - hlr;
        //cout << dp(l, m) << ' ' << dp(m + 1, r) << ENDL;
        ans = min(op, ans);
    }
    //cout << "----------\n";

    return memo[l][r] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    int n;
    cin >> n >> h;

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    ll ans = dp(0, n - 1);

    cout << ans << ENDL;

  return 0;
}
