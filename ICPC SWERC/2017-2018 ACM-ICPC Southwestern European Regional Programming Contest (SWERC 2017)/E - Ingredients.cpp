#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 10005
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

struct Grafo{
    int V;
    vector<viii> adj;
    vector<bool> base;
    vii dist;

    void init(int _V){
        V = _V;
        adj.assign(V, viii());
        base.assign(V, true);
    }

    void ae(int a, int b, ii c){ adj[a].push_back(iii(b, c)); }

    void dijkstra(){
        dist.assign(V, ii(INF, INF));

        priority_queue<iii, viii, greater<iii> > q;

        for(int i = 0; i < V; i++){
            if(base[i]){
                dist[i] = ii(0, 0);
                q.push(iii(0, ii(0, i)));
            }
        }

        while (!q.empty()) {
            int u = q.top().second.second; 
            int c = q.top().first, p = q.top().second.first; q.pop();
            
            if(dist[u] < ii(c, p)){
                continue;
            }
            dist[u] = ii(c, p);

            for (auto e : adj[u]) {
                int v = e.first;
                ii w = e.second;
                ii s = ii(w.first + dist[u].first, w.second + dist[u].second);
                if (s < dist[v]) {
                    dist[v] = s;
                    q.push(iii(dist[v].first, ii(dist[v].second, v)));
                }
            }
        }
    }
};

Grafo g;

int memo[MAX][MAX];

int dp(int i, int b){
    if(i < 0 || b < 0){
        return 0;
    }

    if(memo[i][b] != -1){
        return memo[i][b];
    }

    int res = dp(i - 1, b);
    if(b >= g.dist[i].first){
        res = max(res, dp(i - 1, b - g.dist[i].first) + g.dist[i].second);
    }

    return memo[i][b] = res;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int b, n;
    cin >> b >> n;
    
    memset(memo, -1, sizeof(memo));

    map<string, int> ids;

    vector<pair<ii, ii> > edges;
    for(int i = 0; i < n; i++){
        string dn, bd, ing;
        int c, p;
        cin >> dn >> bd >> ing >> c >> p;

        if(!ids.count(dn)){
            ids[dn] = ids.size();
        }
        if(!ids.count(bd)){
            ids[bd] = ids.size();
        }

        int a = ids[dn], b = ids[bd];
        edges.push_back({ii(ids[dn], ids[bd]), ii(c, -p)});
    }   

    g.init(ids.size());

    for(auto e : edges){
        g.ae(e.first.second, e.first.first, e.second);
        g.base[e.first.first] = false;
    }

    g.dijkstra();

    for(int i = 0; i < g.V; i++){
        g.dist[i].second = -g.dist[i].second;
    }

    int res = dp(g.V - 1, b);

    if(res == 0){
        cout << "0\n0\n";
        return 0;
    }

    int prec = b;
    while(dp(g.V - 1, prec - 1) == res){
        prec--;
    }

    cout << res << "\n" << prec << "\n";
 
	return 0;
}
