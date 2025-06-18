#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

typedef pair<int, ii> iii;
typedef vector<iii> viii;

typedef struct Edge{
    int a;
    int b;
    ll d;
    ll c;

    friend bool operator<(const Edge& a, const Edge& b) {
        if(a.d != b.d){
            return a.d > b.d;
        }
        return a.c > b.c;
    }
}Edge;

struct Grafo{
    int V;
    vector<viii> adj;
    vector<bool> ready;

    void init(int _V){
        V = _V;
        adj.assign(V, viii());
        ready.assign(V, false);
    }

    void ae(int a, int b, ll d, ll c){ adj[a].push_back({b, {d, c}}); }

    ll prim(){
        priority_queue<Edge> q;
        q.push({-1, 0, 0});
        ll costo = 0;
        Edge edge;
        for(int k = 0; k < V; k++){
            do{
                edge = q.top();
                q.pop();   
            }while(ready[edge.b]);
            costo += edge.c;
            ready[edge.b] = true;
            for(auto e : adj[edge.b]){
                int v = e.first;
                if(!ready[v]){
                    q.push({edge.b, v, edge.d + e.se.fi, e.se.se});
                }
            }
        }
        return costo;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    int n, m;
    cin >> n >> m;

    Grafo g;
    g.init(n);

    while(m--){
        int a, b;
        ll d, c;
        cin >> a >> b >> d >> c; a--; b--;
        g.ae(a, b, d, c);
        g.ae(b, a, d, c);
    }

    cout << g.prim() << ENDL;

    return 0;
}
