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
#define INF 100000000000000
#define MOD 1000000007
#define MAX 200005

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> ii;
typedef vector<ii> vii;

int n;
vii c;

ll memo[MAX][8];

ll dp(int i, int mask){
    if(i >= 2 * n){
        if(mask == 0){
            return 0;
        }
        return INF;
    }

    if(mask >= 8){
        return INF;
    }

    if(memo[i][mask] != -1){
        return memo[i][mask];
    }

    ll ans = dp(i + 1, (mask * 2) + 1);
    for(int pot = 1, j = 1; pot < 8; pot *= 2, j++){
        if((mask & pot) && c[i].se != c[i - j].se){
            ans = min(ans, dp(i + 1, (mask - pot) * 2) + (c[i].fi - c[i - j].fi));
        }
    }

    return memo[i][mask] = ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i = 0; i < n; i++){
        ll ax, ax2;
        cin >> ax >> ax2;
        c.push_back(ii(ax, i));
        c.push_back(ii(ax2, i));
    }

    sort(all(c));

    ll ans = dp(0, 0);

    cout << ans << ENDL;

    return 0;
}
