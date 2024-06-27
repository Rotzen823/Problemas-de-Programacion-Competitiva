#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll n;
vector<vi> tree;

ll ans = 0;
int c = 0;

ll dfs(int u, int p){
    ll sons = 1;
    for(int v : tree[u]){
        if(v == p){
            continue;
        }

        sons += dfs(v, u);
    }

    ll edge = sons * (n - sons);
    if(edge > ans){
        ans = edge;
        c = 1;
    }
    else if(edge == ans){
        c++;
    }

    return sons;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    tree.assign(n, vi());

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(0, -1);

    cout << ans << ' ' << c << ENDL;

 	return 0;
}
