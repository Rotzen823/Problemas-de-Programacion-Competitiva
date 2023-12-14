#include <bits/stdc++.h>
#define INF 200005
#define LOG 20

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct CentroidDecomposition {
    vector <vi> adj;
    vi centroidTree, subtreeSize;
    vector <bool> is_removed;
    vii querys;
    int V;

    //LCA
    vector<vi> ancestros;
    vector<bool> ready;
    vi depth;

    void init(int n) {
        V = n;
        adj.assign(n, vi());
        centroidTree.assign(V, -1);
        subtreeSize.assign(V, 0);
        is_removed.assign(V, false);
        //build(0); //Si los index de los nodos empiezan en 1, cambiar a build(1)
        ancestros.assign(V, vi(LOG, 0));
        depth.assign(V, 0);
        ready.assign(V, false);
        //dfsLCA(0, -1);
        querys.assign(V, ii(INF, INF));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs para encontrar el tamaño de los subarboles
    int dfs(int u, int p) {
        subtreeSize[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !is_removed[v]) {
                subtreeSize[u] += dfs(v, u);
            }
        }
        return subtreeSize[u];
    }
    // dfs para encontrar el centroide
    int getCentroid(int u, int p, int tam) {
        for (int v : adj[u]) {
            if (v != p && !is_removed[v]) {
                if (subtreeSize[v] > tam / 2) {
                    return getCentroid(v, u, tam);
                }
            }
        }
        return u;
    }
    // construir el arbol de centroides
    void build(int u, int p = -1) {
        int tam = dfs(u, u);
        int centroid = getCentroid(u, -1, tam);

        centroidTree[centroid] = p; // padre del centroide

        is_removed[centroid] = true;
        for (int v : adj[centroid]) {
            if (!is_removed[v]) {
                build(v, centroid);
            }
        }
    }

    //Con eso ya tenemos el arbol de centroides

    //Para problemas que requieran LCA

    void ancest(int v, int anc, int p){
        if(!ancestros[anc][p - 1]){
            return;
        }
        ancestros[v][p] = ancestros[anc][p - 1];
        ancest(v, ancestros[anc][p - 1], p + 1);
    }

    void buildAncest(int x){
        queue<int> q;
        q.push(x);
        ready[x] = true;
        ancestros[x][0] = x;
        depth[x] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();

            for(int u : adj[v]){
                if(ready[u]){
                    continue;
                }
                ancestros[u][0] = u;
                depth[u] = depth[v] + 1;
                ancest(u, v, 1);
                q.push(u);
                ready[u] = true;
            }
        }
    }

    int lowbit(int x){
        return (-x) & x;
    }

    int ancestK(int v, int k){
        if(k == 0){
            return v;
        }

        int x = lowbit(k);
        int p = 32 - __builtin_clz(x);

        return ancestK(ancestros[v][p], k - x);
    }

    int lca(int a, int b){
        if(depth[a] > depth[b]){
            swap(a, b);
        }

        b = ancestK(b, depth[b] - depth[a]);

        if(a == b){
            return a;
        }

        for(int k = LOG - 1; k >= 0; k--){
            if(ancestros[a][k] != ancestros[b][k]){
                a = ancestros[a][k];
                b = ancestros[b][k];
            }
        }

        return ancestros[a][1];
    }

    //Para este problema en especifico

    int dist(int a, int b){
        return (depth[a] + depth[b]) - (2 * depth[lca(a, b)]);
    }

    void block(int a){
        int b = centroidTree[a];
        querys[a] = ii(0, a);
        while(b != -1){
            querys[b] = min(querys[b], ii(dist(a, b), a));
            b = centroidTree[b];
        }
    }

    int query(int a){
        int b = centroidTree[a];
        ii ans = querys[a];
        while(b != -1){
            ans = min(ans, ii(dist(a, b) + querys[b].first, querys[b].second));
            b = centroidTree[b];
        }
        return ans.second;
    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    CentroidDecomposition tree;
    tree.init(n);

    for(int k = 1; k < n; k++){
        int a, b;
        cin >> a >> b; a--; b--;
        tree.addEdge(a, b);
    }

    tree.build(0);
    tree.buildAncest(0);

    int res[n];
    res[n - 1] = n;
    tree.block(n - 1);
    
    for(int k = n - 2; k >= 0; k--){
        res[k] = tree.query(k) + 1;
        tree.block(k);
    }

    cout << res[0];
    for(int k = 1; k < n; k++){
        cout << " " << res[k];
    }
    cout << "\n";
    return 0;
}
