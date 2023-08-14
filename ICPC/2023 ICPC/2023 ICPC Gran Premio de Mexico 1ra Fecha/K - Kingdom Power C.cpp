#include<bits/stdc++.h>
#define MAX 35

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct Ford_Fulkerson{
    using F = ll;
    struct Edge { int to; F flo, cap; };
    int N;
    vector<Edge> eds;
    vector<vi> adj;
    vector<bool> ready;
    void init(int _N) { N = _N; adj.resize(N);}
    void ae(int u, int v, F cap, F rcap = 0) { assert(min(cap,rcap) >= 0);
        adj[u].push_back(eds.size()); eds.push_back({v, 0, cap});
        adj[v].push_back(eds.size()); eds.push_back({u, 0, rcap});
    }

    F dfs(int v, int t, F flo) {
        if (v == t) return flo;
        ready[v] = true;
        for (int x : adj[v]) {
            Edge& E = eds[x];
            if (E.flo == E.cap || ready[E.to]) continue;
            F df = dfs(E.to,t,min(flo,E.cap-E.flo));
            if (df) { E.flo += df; eds[x^1].flo -= df;
                return df; } // saturated >=1 one edge
        }
        return 0;
    }

    F maxFlow(int s, int t) {
        F tot = 0;
        while (true){
            ready.assign(N, false);
            F df = dfs(s,t,numeric_limits<F>::max());
            if(!df){
                break;
            }
            tot += df;
        } 
        return tot;
    }
};

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int n, s, e;
    cin >> n >> s >> e;

    Ford_Fulkerson ff;
    int ax = n * 2 + 1;
    ff.init(ax + 1);

    for(int k = 1; k <= n; k++){
        ff.ae(k * 2 - 1, k * 2, 1);
    }

    for(int k = 0; k < s; k++){
        int x;
        cin >> x;
        ff.ae(0, x * 2 - 1, 1);
    }

    for(int k = 0; k < e; k++){
        int x;
        cin >> x;
        ff.ae(x * 2, ax, 1);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ff.ae(a * 2, b * 2 - 1, 1);
    }   

    cout << ff.maxFlow(0, ax) << "\n";

    return 0;
}K - Kingdom Power C.
