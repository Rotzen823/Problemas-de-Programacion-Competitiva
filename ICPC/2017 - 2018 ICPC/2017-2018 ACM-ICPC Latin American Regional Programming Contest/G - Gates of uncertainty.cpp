#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

typedef pair<ii, int> iii;
typedef vector<iii> viii;

viii tree;
vector<vector<vll> > memo;

ll dp(int u, int x, int y){
    if(u == -1){
        return x == y ? 1 : 0;
    }

    if(memo[u][x][y] != -1){
        return memo[u][x][y];
    }

    if(tree[u].se != -1 && tree[u].se != y){
        return memo[u][x][y] = 0;
    }

    ll ans = 0;
    for(int a1 = 0; a1 < 2; a1++){
        for(int a2 = 0; a2 < 2; a2++){
            for(int b1 = 0; b1 < 2; b1++){
                for(int b2 = 0; b2 < 2; b2++){
                    if(x == (!(a1 & b1)) && (tree[u].se == y || y == (!(a2 & b2)))){
                        ans += (dp(tree[u].fi.fi, a1, a2) * dp(tree[u].fi.se, b1, b2)) % MOD;
                        ans %= MOD;
                    }
                }
            }
        }
    }

    return memo[u][x][y] = ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    int n;
    cin >> n;

    tree.resize(n);
    memo.assign(n, vector<vll>(2, vll(2, -1)));

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        tree[i] = iii(ii(a, b), c);
    }

    ll ans = (dp(0, 0, 1) + dp(0, 1, 0)) % MOD;

    cout << ans << ENDL;

    return 0;
}
