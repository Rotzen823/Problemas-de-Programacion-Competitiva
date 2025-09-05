// Pura Gente del Coach Moy
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
#define MAX 100005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

string s, t;
ll memo[MAX][65][2];

ll dp(int i, int j, bool change){
    if(j < 0){
        if(change){
            return 25 * (i + 1) + 1;
        }
        return 1;
    }

    if(i < 0){
        return 0;
    }

    if(memo[i][j][change] != -1){
        return memo[i][j][change];
    }

    //No changes
    ll ans = dp(i - 1, j, change);
    if(s[i] == t[j]){
        ans += dp(i - 1, j - 1, change); ans %= MOD;
    }
    //Changes
    if(change){
        if(s[i] != t[j]){
            ans += dp(i - 1, j - 1, false); ans %= MOD;
        }
        ans += (25 * dp(i - 1, j, false)) % MOD; ans %= MOD;
    }
    
    return memo[i][j][change] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m >> s >> t;

    memset(memo, -1, sizeof(memo));

    cout << dp(n - 1, m - 1, true) << ENDL;

    return 0;
}
