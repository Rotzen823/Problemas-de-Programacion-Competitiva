#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
struct Grafo{
    int V;
    vector<vi> adj;
    vector<vi> adj2;
    vector<bool> ready, nodes, ready2;
    vi tin, low;
    int numC, timer;
    stack<int> pila;
    vi color, tamC;
 
    void init(int _V){
        V = _V;
        adj.assign(V, vi());
        ready.assign(V, false); ready2.assign(V, false);
        nodes.assign(V, false);
        tin.assign(V, 0); low.assign(V, 0);
        color.assign(V, 0);
        timer = 1;
    }
 
    void ae(int a, int b){ adj[a].push_back(b); }
    void ae2(int a, int b){ adj2[a].push_back(b); }
 
    void tarjan(int u) {
        tin[u] = low[u] = timer++;
        ready[u] = true;
        pila.push(u);
 
        for (int v : adj[u]) {
            if (!tin[v]) {
                tarjan(v);
            }
 
            if (ready[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
 
        if (low[u] == tin[u]) {
            int c = 0;
            while (true) {
                int v = pila.top();
                pila.pop();
                ready[v] = false;
                color[v] = tamC.size();
                if(nodes[v]){
                    c++;
                }
                if (u == v) {
                    break;
                }
            }
            tamC.push_back(c);
        }
    }
 
    int dfs(int u){
        if(ready2[u]){
            return tamC[u];
        }
 
        ready2[u] = true;
 
        for(int v : adj2[u]){
            tamC[u] += dfs(v);
        }
 
        return tamC[u];
    }
};
 
int main() { 
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
 
    int n, m, t;
    cin >> n >> m >> t;
    
    Grafo g;
    g.init(n);
 
    while(m--){
        int a, b;
        cin >> a >> b;
        if(b == t){
            g.nodes[a] = true;
            continue;
        }
        g.ae(a, b);
    }
 
    for(int k = 0; k < n; k++){
        if(!g.tin[k]){
            g.tarjan(k);
        }
    }
 
    g.adj2.assign(g.tamC.size(), vi());
    for(int k = 0; k < n; k++){
        for(int j : g.adj[k]){
            if(g.color[k] != g.color[j]){
                g.ae2(g.color[k], g.color[j]);
            }
        }
    }
 
    vi res;
    for(int k = 0; k < n; k++){
        if(g.nodes[k] && g.dfs(g.color[k]) == 1){
            res.push_back(k);
        }
    }
 
    cout << res.size() << "\n";
    for(int x : res){
        cout << x << "\n";
    }    
 
 
 
    return 0;
}
