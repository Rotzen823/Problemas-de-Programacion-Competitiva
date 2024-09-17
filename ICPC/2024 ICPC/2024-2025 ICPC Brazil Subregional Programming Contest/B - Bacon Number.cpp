#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);;
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

vector<vii> grafo;
vi path;

int dfs(int u, int p, int t){
    if(u == t){
        return 0;
    }

    for(ii x : grafo[u]){
        int v = x.fi, a = x.se;
        if(v == p){
            continue;
        }
        
        int ans = dfs(v, u, t);
        if(ans != -1){
            path.pb(v + 1);
            path.pb(a + 1);
            return ans + 1;
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    int n, m;
    cin >> n >> m;

    DSU dsu;
    dsu.init(n);

    vi actors(m, -1);
    grafo.assign(n, vii());
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x--){
            int a;
            cin >> a; a--;
            if(actors[a] != -1){
                if(dsu.join(actors[a], i)){
                    grafo[i].pb(ii(actors[a], a));
                    grafo[actors[a]].pb(ii(i, a));
                }
            }
            actors[a] = i;
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b; a--; b--;

        int s = actors[b], t = actors[a];

        if(s == -1 || t == -1){
            cout << "-1\n";
            continue;
        }

        if(dsu.get(s) != dsu.get(t)){
            cout << "-1\n";
            continue;
        }

        path.clear();
        path.pb(a + 1);
        int ans = dfs(s, -1, t);
        path.pb(s + 1);
        path.pb(b + 1);

        cout << ans + 2 << ENDL;

        cout << path[0];
        for(int i = 1; i < SZ(path); i++){
            cout << ' ' << path[i];
        }
        cout << ENDL;
    }

    return 0;
}
