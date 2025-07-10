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
#define MAX 1005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

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
 
    vii minimumCut(int s, int t){
        maxFlow(s, t);
        vii minCut;
        ready.assign(N, false);
        dfs2(s);
        
        for(int i = 0; i < N; i++){
            if(ready[i]){
                //cout << i << ENDL;
                for(int v : adj[i]){
                    //cout << " - " << eds[v].to << ' ' << ready[eds[v].to] << ' ' << v << ENDL;
                    if(!ready[eds[v].to]){
                        minCut.pb({i + 1, eds[v].to + 1});
                    }
                }
            }
        }
 
        return minCut;
    }
 
    void dfs2(int u){
        if(ready[u]){
            return;
        }
 
        ready[u] = true;
        for(int v : adj[u]){
            if(eds[v].flo < eds[v].cap){
                dfs2(eds[v].to);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vi value(n);

    Ford_Fulkerson graph;
    graph.init(n + 2);

    for(int i = 0; i < n; i++){
        cin >> value[i];
        if(value[i] >= 0){
            graph.ae(0, i + 1, value[i]);
        }
        else{
            graph.ae(i + 1, n + 1, -value[i]);
        }
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        graph.ae(b, a, INF);
    }

    graph.minimumCut(0, n + 1);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(graph.ready[i]){
            ans += value[i - 1];
        }
    }

    cout << ans << ENDL;

    return 0;
}
