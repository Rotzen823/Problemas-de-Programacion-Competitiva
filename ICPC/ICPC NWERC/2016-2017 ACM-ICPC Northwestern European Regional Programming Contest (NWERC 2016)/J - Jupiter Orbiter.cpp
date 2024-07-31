#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
//#define INF 1000000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

template<typename T>
struct Dinic {
  #define INF numeric_limits<T>::max()
  struct Edge {
    int to, rev;
    T c, oc;
    T flow() { return max(oc - c, T(0)); }  // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, T c, T rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }
  T dfs(int v, int t, T f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1) if (T p = dfs(e.to, t, min(f, e.c))) {
        e.c -= p, adj[e.to][e.rev].c += p;
        return p;
      }
    }
    return 0;
  }
  T calc(int s, int t) {
    T flow = 0;
    q[0] = s;
    FOR(L, 0, 31) do {  // 'int L=30' maybe faster for random data
      lvl = ptr = vi(SZ(q));
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v]) if (!lvl[e.to] && e.c >> (30 - L)) q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (T p = dfs(s, t, INF)) flow += p;
    }
    while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main(){
    
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    int n, q, s;
    cin >> n >> q >> s;

    vi sensQ(s), quesC(q);

    Dinic<ll> dinic(n * (q * 2 + 1) + 2);

    for(int i = 0; i < s; i++){
        cin >> sensQ[i];
		sensQ[i]--;
    }

    for(int i = 0; i < q; i++){
        cin >> quesC[i];
    }

	ll maxFlow = 0;
    for(int i = 0; i < n; i++){
		int d;
        cin >> d;
		vector<ll> quesI(q, 0);
        for(int j = 0; j < s; j++){
			int a;
            cin >> a;
			quesI[sensQ[j]] += (ll) a;
			maxFlow += (ll) a;
        }

		int ids = i * (q * 2 + 1) + 1;
		for(int j = 0; j < q; j++){
			dinic.addEdge(0, ids + j, quesI[j]);
			dinic.addEdge(ids + j, ids + j + q, quesC[j]);
			dinic.addEdge(ids + j + q, ids + q * 2, quesC[j]);
			if(i != n - 1){
				dinic.addEdge(ids + j + q, ids + j + (q * 2 + 1), quesC[j]);
			}
		}

		dinic.addEdge(ids + q * 2, n * (q * 2 + 1) + 1, d);
    }

	if(dinic.calc(0, n * (q * 2 + 1) + 1) == maxFlow){
		cout << "possible\n";
	}
	else{
		cout << "impossible\n";
	}
    
    return 0;
}
