#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define maxlog 20
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> ii2;
typedef vector <int> vi;
typedef vector <ii> vii;

vector<vii> tree, queries;
vi ans, conq;

vector<ii2> shtLeaf;

ii firstDFS(int u, int p){

    shtLeaf[u].fi = shtLeaf[u].se = ii(INF, u);
    if(SZ(tree[u]) == 1){
        shtLeaf[u].fi = ii(0, u);
    }

    for(auto e : tree[u]){
        int v = e.fi, w = e.se;
        if(v == p){
            continue;
        }

        ii ax = firstDFS(v, u);
        ax.fi += w;

        if(ax < shtLeaf[u].fi){
            shtLeaf[u].se = shtLeaf[u].fi;
            shtLeaf[u].fi = ax;
        }
        else{
            shtLeaf[u].se = min(ax, shtLeaf[u].se);
        }
    }
    
    conq[shtLeaf[u].fi.se]++;
    return shtLeaf[u].fi;
}

void secondDFS(int u, int p, ii up){
    bool changeUp = false;
    if(up < shtLeaf[u].fi){
        changeUp = true;
        conq[up.se]++;
        conq[shtLeaf[u].fi.se]--;

        shtLeaf[u].se = shtLeaf[u].fi;
        shtLeaf[u].fi = up;
    }
    else{
        shtLeaf[u].se = min(up, shtLeaf[u].se);
    }

    for(ii query : queries[u]){
        ans[query.se] = conq[query.fi];
    }

    for(auto e : tree[u]){
        int v = e.fi, w = e.se;
        if(v == p){
            continue;
        }
        
        if(shtLeaf[u].fi.se == shtLeaf[v].fi.se){
            conq[shtLeaf[u].fi.se]--;
            conq[shtLeaf[u].se.se]++;

            ii ax = shtLeaf[u].se;
            ax.fi += w;

            secondDFS(v, u, ax);

            conq[shtLeaf[u].fi.se]++;
            conq[shtLeaf[u].se.se]--;
        }
        else{
            ii ax = shtLeaf[u].fi;
            ax.fi += w;
            secondDFS(v, u, ax);
        }
    }

    if(changeUp){
        conq[up.se]--;
        conq[shtLeaf[u].se.se]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    conq.assign(n, 0);
    tree.assign(n, vii());
    shtLeaf.assign(n, ii2());

    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        tree[a].pb(ii(b, c));
        tree[b].pb(ii(a, c));
    }

    int q;
    cin >> q;
    queries.assign(n, vii());
    ans.assign(q, 0);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        queries[b].pb(ii(a, i));
    }

    firstDFS(0, -1);
    secondDFS(0, -1, ii(INF, 0));

    for(int a : ans){
        cout << a << ENDL;
    }

    return 0;
}
