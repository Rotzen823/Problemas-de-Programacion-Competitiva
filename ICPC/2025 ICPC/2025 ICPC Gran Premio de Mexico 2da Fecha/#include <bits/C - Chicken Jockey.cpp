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
#define INF 10000000000000
#define MOD 998244353
#define MAX 100005

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n), dp(n + 1);
    vi heights(MAX, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = (heights[a[i]] + dp[i + 1]) % MOD;
        heights[a[i]] = dp[i];
    }

    cout << dp[0] << ENDL;


    return 0;
}
