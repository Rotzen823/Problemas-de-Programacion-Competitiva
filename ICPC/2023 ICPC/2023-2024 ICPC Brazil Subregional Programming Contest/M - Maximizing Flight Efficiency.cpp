#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Grafo{
    int V;
    vector<vi> adj;
    vector<vi> dist, dist2;

    void init(int _V){
        V = _V;
        adj.assign(V, vi(V, 0));
    }

    void ae(int a, int b, int c){ adj[a][b] = c; }

    void floyd_warshall(){
        dist.assign(V, vi(V, 0));
        dist2.assign(V, vi(V, 0));
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j){
                    dist[i][j] = 0;
                    dist2[i][j] = 0;
                }
                else if (adj[i][j]){
                    dist[i][j] = adj[i][j];
                    dist2[i][j] = INF;
                }
                else{
                    dist[i][j] = INF;
                    dist2[i][j] = INF;
                }
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    if(k != i && k != j){
                        dist2[i][j] = min(dist2[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    Grafo g;
    g.init(n);

    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            g.ae(k, j, x);
        }
    }

    g.floyd_warshall();

    int res = 0;
    for(int k = 0; k < n; k++){
        for(int j = k + 1; j < n; j++){
            if(g.adj[k][j] > g.dist2[k][j]){
                cout << "-1\n";
                return 0;
            }
            else if(g.adj[k][j] == g.dist2[k][j]){
                res++;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
