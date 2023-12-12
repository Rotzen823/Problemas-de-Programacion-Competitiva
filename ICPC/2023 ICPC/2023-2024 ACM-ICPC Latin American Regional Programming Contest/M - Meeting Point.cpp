#include <bits/stdc++.h>
#define INF 200000000000000

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

struct Grafo{
    int V;
    vector<vii> adj;
    vector<bool> ready;

    void init(int _V){
        V = _V;
        adj.assign(V, vii());
        ready.assign(V, false);
    }

    void ae(int a, int b, int c){ adj[a].push_back(ii(b, c)); }

    vi dijkstra(int x){
        vi dist(V, INF);
        dist[x] = 0;
        priority_queue<ii> q;
        q.push({0, x});

        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (ready[u])
                continue;
            ready[u] = true;
            for (auto e : adj[u]) {
                int v = e.first, w = e.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push({-dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, p, g;

    cin >> n >> m >> p >> g; p--; g--;

    Grafo grafo;
    grafo.init(n);
    while(m--){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        grafo.ae(a, b, c);
        grafo.ae(b, a, c);
    }

    vi dist = grafo.dijkstra(p);
    grafo.ready.assign(n, false);

    grafo.ready[g] = true;
    vi distG = grafo.dijkstra(p);

    vi res;
    for(int k = 0; k < n; k++){
        if(dist[k] < distG[k] && dist[g] * 2 == dist[k]){
            res.push_back(k + 1);
        }
    }

    if(res.size() == 0){
        cout << "*\n";
    }
    else{
        cout << res[0];
        for(int k = 1; k < (int) res.size(); k++){
            cout << " " << res[k];
        }
        cout << "\n";
    }
    return 0;
}
