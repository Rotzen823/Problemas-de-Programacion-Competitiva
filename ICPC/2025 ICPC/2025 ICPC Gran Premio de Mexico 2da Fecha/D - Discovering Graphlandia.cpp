#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 10000000000000
#define MOD 998244353
#define MAX 100005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vii e(n);
    vi orE(n);
    vector<vi> adj(n, vi());

    for(int i = 0; i < n; i++){
        cin >> orE[i];
        e[i] = ii(orE[i], i);
    }
    sort(all(e));

    while(m--){
        int a, b;
        cin >> a >> b; a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    DSU dsu;
    dsu.init(n);

    vi ans(n);
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && e[j].fi <= e[i].fi){
            for(int v : adj[e[j].se]){
                if(orE[v] <= e[j].fi){
                    dsu.join(v, e[j].se);
                }
            }
            j++;
        }

        ans[e[i].se] = dsu.size(e[i].se);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ENDL;
    }

    return 0;
}
