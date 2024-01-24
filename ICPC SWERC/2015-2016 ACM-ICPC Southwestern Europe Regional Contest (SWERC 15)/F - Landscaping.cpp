#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

struct Dinic {
    using F = ll; // flow type
    struct Edge { int to; F flo, cap; };
    int N;
    vector<Edge> eds;
    vector<vi> adj;
    void init(int _N) { N = _N; adj.resize(N), cur.resize(N); }
    void ae(int u, int v, F cap, F rcap = 0) { assert(min(cap,rcap) >= 0);
        adj[u].push_back(eds.size()); eds.push_back({v, 0, cap});
        adj[v].push_back(eds.size()); eds.push_back({u, 0, rcap});
    }
    vi lev;
    vector<vi::iterator> cur;
    bool bfs(int s, int t) {
        lev = vi(N,-1); for (int i = 0; i < N; i++) cur[i] = begin(adj[i]);
        queue<int> q({s}); lev[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int e : adj[u]) {
                const Edge& E = eds[e];
                int v = E.to; if (lev[v] < 0 && E.flo < E.cap)
                    q.push(v), lev[v] = lev[u]+1;
            }
        }
        return lev[t] >= 0;
    }
    F dfs(int v, int t, F flo) {
        if (v == t) return flo;
        for (; cur[v] != end(adj[v]); cur[v]++) {
            Edge& E = eds[*cur[v]];
            if (lev[E.to]!=lev[v]+1||E.flo==E.cap) continue;
            F df = dfs(E.to,t,min(flo,E.cap-E.flo));
            if (df) { E.flo += df; eds[*cur[v]^1].flo -= df;
                return df; } // saturated >=1 one edge
        }
        return 0;
    }
    void reset(){//Agregar metodo reset para hacer mas de un MaxFlow
        for(int i = 0; i < (int)eds.size(); i++){
            eds[i].flo = 0;
        }
    }
    F maxFlow(int s, int t) {
        //reset();
        F tot = 0; while (bfs(s,t)) while (F df =
            dfs(s,t,numeric_limits<F>::max())) tot += df;
        return tot;
    }
};

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool validar(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> n >> m >> a >> b;

    Dinic dinic;
    dinic.init(n * m + 2);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k], y = j + dy[k];
                if(validar(x, y)){
                    //cout << (i * m + j) << " " << (x * m + y) << " " << a << "\n";
                    dinic.ae((i * m + j), (x * m + y), a);
                }   
            }

            if(c == '.'){
                dinic.ae(n * m, (i * m + j), b);
                //cout << (i * m + j) << " " << n * m << " " << b << "\n";
            }
            else{
                dinic.ae((i * m + j), n * m + 1, b);
                //cout << (i * m + j) << " " << n * m + 1 << " " << b << "\n";
            }
        }
    }

    ll res = dinic.maxFlow(n * m, n * m + 1);
    cout << res << "\n";

    return 0;
}
