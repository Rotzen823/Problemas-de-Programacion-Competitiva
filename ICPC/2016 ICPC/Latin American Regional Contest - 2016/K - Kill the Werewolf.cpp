#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 100000000000000
#define MOD 1000000007
#define MAX 1005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vii players(n);

    for(int i = 0; i < n; i++){
        cin >> players[i].fi >> players[i].se;
        players[i].fi--;
        players[i].se--;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int wolveVotes = 0;
        for(int j = 0; j < n; j++){
            if(players[j].fi == i || players[j].se == i){
                wolveVotes++;
            }
        }

        if(wolveVotes <= 1){
            ans++;
            continue;
        }
        
        Ford_Fulkerson graph;
        int s = n * 2, t = n * 2 + 1;
        graph.init(t + 1);

        for(int j = 0; j < n; j++){
            if(i == j) continue;

            graph.ae(s, j, 1);
            
            int capacity = wolveVotes - 1;
            if(players[i].fi == j || players[i].se == j){
                capacity--;
            }
            graph.ae(j + n, t, capacity);
            
            if(players[j].fi != i && players[j].se != i){
                graph.ae(j, players[j].fi + n, 1);
                graph.ae(j, players[j].se + n, 1);
            }
        }

        if(graph.maxFlow(s, t) < (n - (wolveVotes + 1))){
            ans++;
        }
    }

    cout << ans << ENDL;

    return 0;
}
