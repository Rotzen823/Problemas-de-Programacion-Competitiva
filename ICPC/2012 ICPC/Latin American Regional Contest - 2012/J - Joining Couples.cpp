#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define maxlog 20
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

vector<vi> tree;
vi colors, fathers, ready, ciclos, padreCiclo;

//Colorea los distintos arboles
void colorear(int u, int c){
    if(colors[u] != -1){
        return;
    }
    colors[u] = c;

    colorear(fathers[u], c);
    for(int v : tree[u]){
        colorear(v, c);
    }
}

//DFS para encontrar los ciclos,
//Hay un ciclo por cada color (arbol)
int encontrarCiclos(int u, int c, int id = 0){
    if(ready[u] == 2){
        return id;
    }

    if(ready[u] == 1){
        ciclos[u] = id++;
    }
    ready[u]++;

    return encontrarCiclos(fathers[u], c, id);
}

//DFS para ver cada nodo cual es su raiz ciclo
int raizCiclo(int u){
    if(ciclos[u] != -1){
        return u;
    }

    if(padreCiclo[u] != -1){
        return padreCiclo[u];
    }

    return padreCiclo[u] = raizCiclo(fathers[u]);
}

void pasarAristas(vi &edges, int u){
    if(u == -1){
        return;
    }

    int next = -1;
    while(!tree[u].empty()){
        int v = tree[u].back();
        tree[u].pop_back();
        if(ciclos[v] == -1){
            edges.pb(v);
        }
        else{
            next = v;
        }
    }

    pasarAristas(edges, next);
}


int jmp[MAX][maxlog], d[MAX];
void dfs(int u, int p = -1) {
    jmp[u][0]=p;
    for (auto &v:tree[u])if(v!=p)d[v]=d[u]+1,dfs(v,u);
}
void build(vi &roots) {
    int n = SZ(tree);

    for(int u : roots){
        dfs(u);
    }
    for(int i=1;i<maxlog;i++)for(int u=0;u<n;u++)if(jmp[u][i-1]!=-1)
        jmp[u][i]=jmp[jmp[u][i-1]][i-1];
}
int LCA(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int dist = d[u] - d[v];
    for(int i=maxlog-1;i>=0;i--)if((dist>>i)&1)u=jmp[u][i];
    if(u==v)return u;
    for(int i=maxlog-1;i>=0;i--)if(jmp[u][i]!=jmp[v][i])u=jmp[u][i],v=jmp[v][i];
    return jmp[u][0];
}
int dist(int u, int v) { return d[u] + d[v] - 2 * d[LCA(u, v)]; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    while(cin >> n){
        tree.assign(n, vi());
        fathers.resize(n); colors.assign(n, -1);
        ready.assign(n, 0); ciclos.assign(n, - 1);
        padreCiclo.assign(n, -1);
        memset(jmp, -1, sizeof(jmp));
        memset(d, -1, sizeof(d));

        for(int i = 0; i < n; i++){
            cin >> fathers[i]; fathers[i]--;
            tree[fathers[i]].pb(i);
        }

        int color = 0;
        vi tamCiclos;
        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
                colorear(i, color);
                tamCiclos.pb(encontrarCiclos(i, color));
                color++;
            }
        }

        vi raices(color);
        for(int i = 0; i < n; i++){
            padreCiclo[i] = raizCiclo(i);
            if(ciclos[i] != -1 && SZ(tree[i]) > 0){
                vi axNew;
                pasarAristas(axNew, i);
                tree[i] = axNew;
                raices[colors[i]] = i;
            }
        }

        build(raices);

        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b; a--; b--;

            if(colors[a] != colors[b]){
                cout << "-1\n";
                continue;
            }

            int ax = a, bx = b;
            if(ciclos[a] != -1){
                ax = raices[colors[a]];
            }
            if(ciclos[b] != -1){
                bx = raices[colors[b]];
            }

            int lca = LCA(ax, bx);
            int ans = dist(ax, bx);

            if(ciclos[lca] != -1){
                int tam = tamCiclos[colors[a]];
                int x = ciclos[padreCiclo[a]], y = ciclos[padreCiclo[b]];
                ans += min((x - y + tam) % tam, (y - x + tam) % tam);
            }

            cout << ans << ENDL;
        }
    }

    return 0;
}
