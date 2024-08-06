#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define INF 1000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

vi scc(vector<vi>& g) {
  int n = SZ(g), t = 0, ncomps = 0;
  vi tin(n), scc(n, -1), z;
  auto dfs = [&](auto&& self, int u) -> int {
    int low = tin[u] = ++t, x; z.push_back(u);
    for (auto v : g[u]) if (scc[v] < 0)
      low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      do {
        x = z.back(); z.pop_back();
        scc[x] = ncomps;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  FOR (i, 0, n) if (scc[i] == -1) dfs(dfs, i);
  return scc;
}

int memo[MAX];
bool ready[MAX];
vi color;
vector<vi> graph, graph2;
vector<map<int, int> > largeWay;

void dfs(int p, int u, int sum){
    if(ready[u]){
        return;
    }   

    largeWay[p][u] = max(largeWay[p][u], sum);

    ready[u] = true;
    for(int v : graph[u]){
        if(color[v] == color[u]){
            dfs(p, v, sum + 1);
        }
    }
    ready[u] = false;    
}

int dp(int u){
    if(memo[u]){
        return memo[u];
    }

    int ans = 0;
    for(auto p : largeWay[u]){
        int v = p.fi, w = p.se;
        ans = max(ans, w);
        for(int a : graph[v]){
            if(color[u] != color[a]){
                ans = max(ans, dp(a) + w);
            }
        }
    }  

    return memo[u] = ans;
}

int main(){
    
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);

	int n, m;
    cin >> n >> m;
    
    graph.assign(n, vi());
    largeWay.assign(n, map<int, int>());

    while(m--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
    }

    color = scc(graph);

    for(int i = 0; i < n; i++){
        dfs(i, i, 1);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp(i));
    }

    cout << ans << ENDL;

    return 0;
}
