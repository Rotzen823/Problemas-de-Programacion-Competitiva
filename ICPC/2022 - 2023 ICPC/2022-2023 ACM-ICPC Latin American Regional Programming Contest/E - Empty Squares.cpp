#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int memo[MAX][MAX];
bool ready[MAX];

int dp(int b, int p){
    if(b == 0 || p == 0){
        return p;
    }

    if(memo[b][p] != -1){
        return memo[b][p];
    }

    int res = dp(b - 1, p);
    if(!ready[b]){
        res = min(dp(min(p - b, b - 1), p - b), res);
    }

    //cout << b << " " << p << " " << res << "\n";
    return memo[b][p] = res;
}

void recor(int b, int p, int r){
    if(b == 0 || p == 0){
        return;
    }
    //cout << b << " " << p << "\n";

    if(!ready[b] && dp(min(p - b, b - 1), p - b) == r){
        ready[b] = true;
        recor(min(p - b, b - 1), p - b, r);
        return;
    }
 
    recor(b - 1, p, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, e;
    cin >> n >> k >> e;
    ready[k] = true;
    memset(memo, -1, sizeof(memo));

    int res = dp(e, e);
    recor(e, e, res);
    memset(memo, -1, sizeof(memo));
    res += dp(n - k - e, n - k - e);
    //Opcion 2
    memset(memo, -1, sizeof(memo));
    memset(ready, false, sizeof(ready));
    ready[k] = true;
    int ax = dp(n - k - e, n - k - e);
    recor(n - k - e, n - k - e, ax);
    memset(memo, -1, sizeof(memo));
    ax += dp(e, e);
    res = min(res, ax);

    cout << res << "\n";
    return 0;
}
