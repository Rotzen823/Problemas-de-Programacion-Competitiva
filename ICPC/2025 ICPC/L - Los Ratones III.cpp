// Pura Gente del Coach Moy
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
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT 0

  int n;
  vector<ll> st, lazy;

  STree(int n) : n(n), st(4 * n, 1), lazy(4 * n, 1) {}

  void apply(int v, int tl, int tr, ll val) {
    st[v] *= val; st[v] %= MOD;
    lazy[v] *= val; lazy[v] %= MOD;
  }

  void push(int v, int tl, int tr) {
    if (lazy[v] != 1) {
      int tm = (tl + tr) / 2;
      apply(lp, lazy[v]), apply(rp, lazy[v]);
      lazy[v] = 1;
    }
  }

  ll query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return (query(lp, l, r) + query(rp, l, r)) % MOD;
  }
  
  void upd(int v, int tl, int tr, int l, int r, ll val) {
    if (tr <= l || r <= tl) return;
    if (l <= tl && tr <= r) { apply(v, tl, tr, val); return; }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(lp, l, r, val), upd(rp, l, r, val);
    st[v] = (st[ls] + st[rs]) % MOD;
  }
 
  ll query(int l, int r) {
    return query(0, 0, n, l, r);
  }
  void upd(int l, int r, ll val) {
    upd(0, 0, n, l, r, val);
  }
};

template <bool VALS_EDGES>
struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, head, pos;
  STree tree;
  HLD(vector<vi> adj_)
      : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), head(N), pos(N), tree(N) {
    dfsSz(0);
    head[0] = 0;
    dfsHld(0);
  }
  void dfsSz(int v) {
    if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
    for (int& u : adj[v]) {
      par[u] = v;
      dfsSz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
  void dfsHld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      head[u] = (u == adj[v][0] ? head[v] : u);
      dfsHld(u);
    }
  }
  template <class B>
  void process(int u, int v, B op) {
    for (; head[u] != head[v]; v = par[head[v]]) {
      if (pos[head[u]] > pos[head[v]]) swap(u, v);
      op(pos[head[v]], pos[v] + 1);
    }
    if (pos[u] > pos[v]) swap(u, v);
    op(pos[u] + VALS_EDGES, pos[v] + 1);
  }
  void modifyPath(int u, int v, ll val) {
    process(u, v, [&](int l, int r) { tree.upd(l, r, val); });
  }
  ll queryPath(int u, int v) {
    ll res = 0;
    process(u, v, [&](int l, int r) { res += tree.query(l, r); res %= MOD; });
    return res;
  }
  ll querySubtree(int v) {  // modifySubtree es similar
    return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vi> adj(n, vi());
    vector<tuple<int, int, ll>> edges;
    for(int i = 1; i < n; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        edges.pb({a, b, c});
    }

    HLD<true> hld(adj);

    for(auto &e : edges){
        int a, b; ll c;
        tie(a, b, c) = e;
        int pos = hld.pos[b];
        if(hld.par[a] == b){
            pos = hld.pos[a];
        }
        hld.tree.upd(pos, pos + 1, c);
    }

    while(q--){
        int a, b;
        ll c;
        cin >> a >> b >> c; a--; b--;
        hld.modifyPath(a, b, c);
        cout << hld.queryPath(a, b) << ENDL;
    }

    return 0;
}
