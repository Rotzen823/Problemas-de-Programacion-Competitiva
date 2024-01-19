#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Grafo{
    int V;
    vector<vi> adj;
    vector<bool> ready;
    vi tin, low, color;
    int numC, timer;
    stack<int> pila;

    void init(int _V){
        V = _V;
        adj.assign(V, vi());
        ready.assign(V, false);
        tin.assign(V, 0); low.assign(V, 0); color.assign(V, 0);
        numC = 0; timer = 1;
    }

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
            numC++;
            while (true) {
                int v = pila.top();
                pila.pop();
                ready[v] = false;
                color[v] = numC;
                if (u == v) {
                    break;
                }
            }
        }
    }

    bool solve2Sat() {
        for (int k = 0; k < V; k++) {
            if (!tin[k]) {
                tarjan(k);
            }
        }
        
        for (int k = 0; k < V; k += 2) {
            if (color[k] == color[k + 1]) {
                return false;
            }
        }
        return true;
    }

    void add_edge(int a, bool na, int b, bool nb) {
        a <<= 1;
        b <<= 1;
        
        int notA = a + 1, notB = b + 1;
        if (na) {
            swap(a, notA);
        }
        if (nb) {
            swap(b, notB);
        }
        
        adj[notA].push_back(b);
        adj[notB].push_back(a);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Grafo g;
    g.init(26 * 4);

    for(int i = 0; i < 26; i++){
        g.add_edge(i * 2, true, i * 2 + 1, true);
    }

    while(n--){
        char a, b;
        int p, r;
        cin >> a >> b >> p >> r;
        p--;

        int v1 = (a - 'A') * 2 + p, v2 =( b - 'A') * 2 + p;
        switch(r){
            case 0:
            g.add_edge(v1, false, v2, true);
            g.add_edge(v1, true, v2, false);
            g.add_edge(v1, true, v2, true);
            break;
            case 1:
            g.add_edge(v1, false, v2, false);
            g.add_edge(v1, true, v2, true);
            break;
            case 2:
            g.add_edge(v1, false, v2, false);
            g.add_edge(v1, false, v2, true);
            g.add_edge(v1, true, v2, false);
            break;
        }
    }

    if(!g.solve2Sat()){
        cout << "0\n";
        return 0;
    }

    int res = 0;
    for(int i = 0; i < 26; i++){
        for(int j = i + 1; j < 26; j++){
            for(int k = j + 1; k < 26; k++){
                Grafo ax; ax.init(26 * 4);
                ax.adj = g.adj;
                for(int v = 0; v < 26; v++){
                    int v1 = v * 2, v2 = v * 2 + 1;
                    if(v == i || v == j || v == k){
                        ax.add_edge(v1, false, v2, true);
                        ax.add_edge(v1, true, v2, false);
                    }
                    else{
                        ax.add_edge(v1, false, v2, false);
                    }
                }

                if(ax.solve2Sat()){
                    res++;
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}
