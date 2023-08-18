#include <bits/stdc++.h>
#define MAX 505

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool intersectCircles(int x1, int y1, int r1, int x2, int y2, int r2){
    double d = dist(x1, y1, x2, y2);

    return d <= r1 + r2;
}

struct Grafo{
    int V;
    vector<vi> adj;
    vector<bool> ready;

    void init(int _V){
        V = _V;
        adj.assign(V, vi());
        ready.assign(V, false);
    }

    void ae(int a, int b){ adj[a].push_back(b); }

    void dfs(int u){
        if(ready[u]){
            return;
        }
        ready[u] = true;

        for(int v : adj[u]){
            dfs(v);
        }
    }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while(n--){
        int c, w, h;
        cin >> c >> w >> h;

        ii circ[c];
        Grafo g;
        g.init(c + 2);
        for(int k = 0; k < c; k++){
            cin >> circ[k].first >> circ[k].second;
            if(circ[k].first <= 2){
                g.ae(0, k + 1);
                g.ae(k + 1, 0);
            }

            if(circ[k].first >= w - 2){
                g.ae(c + 1, k + 1);
                g.ae(k + 1, c + 1);
            }
        }

        for(int k = 0; k < c; k++){
            for(int j = k + 1; j < c; j++){
                if(intersectCircles(circ[k].first, circ[k].second, 2, circ[j].first, circ[j].second, 2)){
                    g.ae(k + 1, j + 1);
                    g.ae(j + 1, k + 1);
                }
            }
        }

        g.dfs(0);

        if(g.ready[c + 1]){
            cout << "RISKY\n";
        }
        else{
            cout << "SAFE\n";
        }
    }

    return 0;
}
