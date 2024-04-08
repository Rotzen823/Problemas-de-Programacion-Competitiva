#include <bits/stdc++.h>
#define INF 1000000
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<vi> grafo;

int maxDis(int n, int x){
    vi dist(n, INF);
    dist[x] = 0;

    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : grafo[u]){
            if(dist[v] != INF){
                continue;
            }

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, dist[i]);
    }

    return res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, m;
    cin >> n >> m;

    grafo.assign(n, vi());

    while(m--){
        int a, b;
        cin >> a >> b; a--; b--;

        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    int dis = maxDis(n, 0);

    if(dis == INF){
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    while((1 << ans) < dis){
        ans++;
    }

    cout << ans + 1 << ENDL;



  return 0;
}
