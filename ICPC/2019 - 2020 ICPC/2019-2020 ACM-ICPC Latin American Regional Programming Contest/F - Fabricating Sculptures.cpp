#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000
#define MAX 5005
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

ll memo[MAX][MAX];

ll dp(int s, int b){
    if(b == 0){
        return 1;
    }
    if(s <= 0 || b < 0){
        return 0;
    }

    if(memo[s][b]){
        return memo[s][b];
    }

    ll ans = (dp(s - 1, b) * 2) % MOD;
    ans += dp(s, b - s); ans %= MOD;
    ans = (ans - dp(s - 2, b) + MOD) % MOD;

    return memo[s][b] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    
    int s, b;
    cin >> s >> b;

    ll ans = dp(s, b - s);

    cout << ans << ENDL;

    return 0;
}
