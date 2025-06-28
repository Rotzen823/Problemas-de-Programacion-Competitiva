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
#define MOD 1000000007
#define MAX 10005

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    ll l;
    cin >> k >> l;
    vector<vi> keyb(k, vi(k));

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cin >> keyb[i][j];
        }
    }

    int n;
    cin >> n;
    vi p(n - 1);

    for(int i = 0; i < n - 1; i++){
        cin >> p[i];
    }

    vector<vi> dp(n, vi(k));
    for(int i = 0; i < k; i++){
        dp[n - 1][i] = i + 1;
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < k; j++){
            dp[i][j] = j ? dp[i][j - 1] : 0;
            int id = upper_bound(all(keyb[j]), p[i] + l) - keyb[j].begin();
            ll sumUp = id ? dp[i + 1][id - 1] : 0;
            id = lower_bound(all(keyb[j]), p[i]- l) - keyb[j].begin();
            ll sumDw = id ? dp[i + 1][id - 1] : 0;

            dp[i][j] += (sumUp - sumDw + MOD) % MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[0][k - 1] << ENDL;

    return 0;
}
