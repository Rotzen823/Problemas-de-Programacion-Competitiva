#include <bits/stdc++.h>
#define MAX 100005
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii tree[MAX];
ii padre[MAX];
int dist[MAX];
bool ready[MAX];

void dfs(int u){
    
    for(ii e : tree[u]){
        int v = e.fi, w = e.se;
        padre[v].fi = u;
        padre[v].se = w;
        dist[v] = dist[u] + w;
        dfs(v);
    }
}

int subir(int u){
    if(u == 1 || ready[u]){
        return 0;
    }

    ready[u] = true;
    return subir(padre[u].fi) + padre[u].se;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, f;
    cin >> n >> f;

    for(int k = 1; k < n; k++){
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back(ii(b, c));
    }
    dfs(1);

    vii friends(f);
    for(int k = 0; k < f; k++){
        cin >> friends[k].se;
        friends[k].fi = dist[friends[k].se];
    }

    sort(friends.begin(), friends.end());

    int res = 0;
    subir(friends[f - 1].se);
    for(int k = f - 2; k >= 0; k--){
        int u = friends[k].se;
        int x = subir(u);
        res += x;
    }   

    cout << res << "\n";

    return 0;
}
