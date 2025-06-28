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
#define MAX 10005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
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

int stringToInt(string &s){
    int ans = 0;
    for(int i = 0; i < s.sz(); i++){
        ans *= 10;
        ans += (s[i] - '0');
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    Dinic d;
    d.init(n + 1);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if(s == "*"){
            int l;
            cin >> l; l--;
            if(i != l){
                d.ae(i, l, INF);
            }
            if(l == 0){
                d.ae(i, n, INF);
            }
            continue;
        }

        int m = stringToInt(s);
        vi cont(n + 1, 0);
        while(m--){
            int x;
            cin >> x; x--;
            cont[x]++;
            if(x == 0){
                cont[n]++;
            }
        }

        for(int j = 0; j <= n; j++){
            if(cont[j] > 0 && i != j){
                d.ae(i, j, cont[j]);
            }
        }
    }

    ll ans = d.maxFlow(0, n);

    if(ans == INF){
        cout << "*\n";
    }
    else{
        cout << ans + 1 << ENDL;
    }

    return 0;
}
