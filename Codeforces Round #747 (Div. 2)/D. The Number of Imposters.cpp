#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct Grafo{
    int V, c1, c2;
    vector<vi> adj;
    vector<int> color;

    void init(int _N, int _M){
        V = _N;
        adj.assign((_N + _M), vi());
        color.assign((_N + _M), -1);
    }

    void ae(int a, int b){ adj[a].push_back(b); }

    bool dfs(int u, int c){
        if(color[u] != -1){
            return color[u] == c;
        }

        color[u] = c;
        if(u < V){
            if(c){
                c1++;
            }
            else{
                c2++;
            }
        }

        for(int v : adj[u]){
            if(!dfs(v, (c + 1) % 2)){
                return false;
            }
        }

        return true;
    }
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        Grafo g;
        g.init(n, m);

        int ax = n;
        while(m--){
            int a, b;
            string s;
            cin >> a >> b >> s;
            a--; b--;
            if(s == "imposter"){
                g.ae(a, b);
                g.ae(b, a);
            }
            else if(s == "crewmate"){
                g.ae(a, ax); g.ae(ax, a);
                g.ae(b, ax); g.ae(ax, b);
                ax++;
            }
        }

        bool cont = false;
        int res = 0;
        for(int k = 0; k < n; k++){
            if(g.color[k] == -1){
                g.c1 = g.c2 = 0;
                if(!g.dfs(k, 0)){
                    cont = true;
                    break;
                }
                res += max(g.c1, g.c2);
            }
        }

        if(cont){
            cout << "-1\n";
        }
        else{
            cout << res << "\n";
        }
    }

    return 0;
}
