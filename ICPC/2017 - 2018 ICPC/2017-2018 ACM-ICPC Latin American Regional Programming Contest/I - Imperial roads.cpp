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
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct GrafoPrim{
    typedef struct Edge{
        int a;
        int b;
        int costo;
    }Edge;
     
    class ComparisonClass{
        public:
            bool operator() (Edge a, Edge b){
                return a.costo > b.costo;
            }
    };

    int V;
    vector<vii> adj, tree;
    vector<bool> ready;

    void init(int _V){
        V = _V;
        adj.assign(V, vii());
        tree.assign(V, vii());
        ready.assign(V, false);
    }

    void ae(int a, int b, int cost){ adj[a].push_back(ii(b, cost)); }
    
    int prim(){
        priority_queue<Edge, vector<Edge>, ComparisonClass> q;
        q.push({-1, 1, 0});
        int costo = 0;
        Edge edge;
        for(int k = 0; k < V; k++){
            do{
                edge = q.top();
                q.pop();   
            }while(ready[edge.b]);
            costo += edge.costo;
    
            if(edge.a != -1){
                tree[edge.a].push_back({edge.b, edge.costo});
                tree[edge.b].push_back({edge.a, edge.costo});
            }
    
            ready[edge.b] = true;
            for(auto cord : adj[edge.b]){
                int h = cord.first;
                if(!ready[h]){
                    q.push({edge.b, h, cord.second});
                }
            }
        }
        
        return costo;
    }
};
 
struct GrafoAncest{
    int V;
    vector<vii> adj, ancestros;
    vector<bool> ready;
    vi depth;
 
    void init(int _V){
        V = _V;
        adj.assign(V, vii());
        ancestros.assign(V, vii(LOG, ii(-1, 0)));
        depth.assign(V, 0);
        ready.assign(V, false);
    }
 
    void ae(int a, int b, int cost){ adj[a].push_back(ii(b, cost)); }
 
    void ancest(int v, int costEdge, int anc, int p){
        if(ancestros[anc][p - 1].fi == -1){
            return;
        }
        ancestros[v][p] = ancestros[anc][p - 1];
        ancestros[v][p].se = max(ancestros[v][p].se, costEdge);
        ancest(v, ancestros[v][p].se, ancestros[v][p].fi, p + 1);
    }
 
    void buildAncest(int x){
        queue<int> q;
        q.push(x);
        ready[x] = true;
        ancestros[x][0].fi = x;
        depth[x] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            
            for(auto edge : adj[v]){
                int u = edge.fi, cost = edge.se;
                if(ready[u]){
                    continue;
                }
                ancestros[u][0].fi = u;
                depth[u] = depth[v] + 1;
                ancest(u, cost, v, 1);
                q.push(u);
                ready[u] = true;
            }
        }
    }
 
    int lowbit(int x){
        return (-x) & x;
    }
 
    ii ancestK(int v, int k, int e = 0){
        if(k == 0){
            return ii(v, e);
        }
 
        int x = lowbit(k);
        int p = 32 - __builtin_clz(x);

        e = max(e, ancestros[v][p].se);
 
        return ancestK(ancestros[v][p].fi, k - x, e);
    }
 
    int lca(int a, int b){
        if(depth[a] > depth[b]){
            swap(a, b);
        }
        
        ii resAnc = ancestK(b, depth[b] - depth[a]);
        b = resAnc.fi;
        int res = resAnc.se;
 
        if(a == b){
            return res;
        }
        
        for(int k = LOG - 1; k >= 0; k--){
            if(ancestros[a][k].fi != ancestros[b][k].fi){
                res = max({res, ancestros[a][k].se, ancestros[b][k].se});
                a = ancestros[a][k].fi;
                b = ancestros[b][k].fi;
            }
        }

        res = max({res, ancestros[a][1].se, ancestros[b][1].se});
        return res;
    }
    
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, m;
    map<ii, int> edges;

    cin >> n >> m;

    GrafoPrim prim;
    GrafoAncest ancests;
    prim.init(n);
    ancests.init(n);

	for(int k = 0; k < m; k++){
		int a, b, c;

		cin >> a >> b >> c; a--; b--;

        prim.ae(a, b, c);
        prim.ae(b, a, c);

		edges[ii(a, b)] = c;
		edges[ii(b, a)] = c;
	}

	int bestCost = prim.prim();
    ancests.adj = prim.tree;
    ancests.buildAncest(0);

	int q;
	cin >> q;

	while(q--){
		int a, b, c;
		cin >> a >> b;
        a--; b--;

		c = edges[{a, b}];
        
		int w = ancests.lca(a, b);
		cout << bestCost - w + c << "\n";
	}
 
    return 0;
}
