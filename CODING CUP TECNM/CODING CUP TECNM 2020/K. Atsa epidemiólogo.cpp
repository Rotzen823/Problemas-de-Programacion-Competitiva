#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

struct Grafo{
    int V;
    vector<vi> adj;
    vector<bool> ready;

    void init(int _V){
        V = _V;
        adj.assign(V, vi());
        ready.assign(V, false);
    }

    void ae(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int dfs(int u){
        if(ready[u]){
            return 0;
        }
        ready[u] = true;

        int r = 1;
        for(int v : adj[u]){
            r += dfs(v);
        }   

        return r;
    }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    Grafo g;
    g.init(n);

    for(int k = 0; k < m; k++){
        int a, b;
        cin >> a >> b;
        g.ae(a, b);
        g.ae(b, a);
    }

    int h;
    cin >> h;

    int st = 0, fin = n - h;
    while(st < fin){
        int mid = (st + fin) / 2;
        g.ready[0] = false;
        for(int k = 1; k <= mid; k++){
            g.ready[k] = true;
        }
        for(int k = mid + 1; k < n; k++){
            g.ready[k] = false;
        }
        int r = g.dfs(0);
        if(r <= h){
            fin = mid;
        }
        else{
            st = mid + 1;
        }
    }

    cout << st << "\n";
    return 0;
}
