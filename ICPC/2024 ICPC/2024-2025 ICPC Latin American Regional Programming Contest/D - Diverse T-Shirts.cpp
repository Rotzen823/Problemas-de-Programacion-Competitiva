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

pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
  int res = 0;
  vi btoa(m, -1), A(sz(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
    }
    return 0;
  };
  while (1) {
    fill(all(A), 0);
    fill(all(B), 0);
    /// Encuentra los nodos restantes para BFS (i.e. con layer 0)
    cur.clear();
    for (int a : btoa) if(a != -1) A[a] = -1;
    forns (a, 0, sz(g)) if(A[a] == 0) cur.pb(a);
    /// Encunetra todas las layers usando BFS
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur) for (int b : g[a]) {
        if (btoa[b] == -1) {
          B[b] = lay;
          islast = 1;
        }
        else if (btoa[b] != a && !B[b]) {
          B[b] = lay;
          next.pb(btoa[b]);
        }
      }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    /// Usa DFS para escanear caminos aumentantes
    forns (a, 0, sz(g)) res += dfs(dfs, a, 0);
  }
}

vector<vi> g, graph;
vi ready;

int c1 = 0, c2 = 0;
void dfs(int u, bool c){
    if(ready[u] != -1){
        return;
    }

    ready[u] = c ? c1++ : c2++;
    for(int v : graph[u]){
        dfs(v, !c);
    }

    if(c){
        g.pb(vi());
        for(int v : graph[u]){
            g.back().pb(ready[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<char> > models(n, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> models[i][j];
        }
    }

    vii cliques(n, ii(-1, -1));
    int m = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(models[i][j] == '0'){
                continue;
            }
            vi ar;
            ar.pb(i); ar.pb(j);
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                if(models[k][i] == '1' && models[k][j] == '1'){
                    ar.pb(k);
                }
            }

            for(int a : ar){
                cliques[a] = ii(m, cliques[a].fi);
                for(int b : ar){
                    models[a][b] = '0';
                }
            }
            m++;
        }
    }

    graph.assign(m, vi());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cliques[i].fi == -1){
            ans++;
            continue;
        }
        if(cliques[i].se == -1){
            cliques[i].se = m++;
            graph.pb(vi());
        }

        graph[cliques[i].fi].pb(cliques[i].se);
        graph[cliques[i].se].pb(cliques[i].fi);
    }

    if(m == 0){
        cout << ans << ENDL;
        return 0;
    }

    ready.assign(m, -1);
    for(int i = 0; i < m; i++){
        dfs(i, true);
    }
    ans += hopcroftKarp(g, c2).fi;
    cout << ans << ENDL;

    return 0;
}
