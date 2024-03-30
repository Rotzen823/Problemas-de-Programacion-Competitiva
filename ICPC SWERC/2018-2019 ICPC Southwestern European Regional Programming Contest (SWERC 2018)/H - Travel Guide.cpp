//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX 1005
#define ENDL '\n'
#define INF 1000000000
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<ii> vii;

struct Grafo{
    int V;
    vector<vii> adj;
    vector<bool> ready;

    void init(int _V){
        V = _V;
        adj.assign(V, vii());
    }

    void ae(int a, int b, int c){ adj[a].push_back(ii(b, c)); }

    vi dijkstra(int x){
        vi dist(V, INF);
        dist[x] = 0;
        ready.assign(V, false);
        priority_queue<ii> q;
        q.push({0, x});

        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (ready[u])
                continue;
            ready[u] = true;
            for (auto e : adj[u]) {
                int v = e.first, w = e.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push({-dist[v], v});
                }
            }
        }

        return dist;
    }
};

template <class T>
struct SegTree {
    #define NIL INF
    
    int n;
    vector<T> A, st;
    
    inline int lc(int p) { return (p << 1) + 1; }
    inline int rc(int p) { return (p << 1) + 2; }

    T merge(T a, T b){
        return min(a, b);
    }

    void init(vector<T> v) {
        A = v;
        n = A.size();
        st.resize(n * 4);
        build(0, 0, n - 1);
    }

    void build(int p, int L, int R) {
        if (L == R) {
        st[p] = A[L];
        return;
        }
        int m = (L + R) >> 1;
        build(lc(p), L, m);
        build(rc(p), m + 1, R);
        st[p] = merge(st[lc(p)], st[rc(p)]);
    }

    T query(int l, int r, int p, int L, int R) {
        if (l <= L && r >= R) return st[p];
        if (l > R || r < L) return NIL;
        int m = (L + R) >> 1;
        return merge(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
    }
    T query (int l, int r) { return query(l, r, 0, 0, n - 1); }

    void update(int i, T val, int p, int L, int R) {
        if (L > i || R < i) return;
        if (L == R) {
        st[p] = val;
        return;
        }
        int m = (L + R) >> 1;
        update(i, val, lc(p), L, m);
        update(i, val, rc(p), m + 1, R);
        st[p] = merge(st[lc(p)], st[rc(p)]);
    }
    void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, e;
    cin >> n >> e;

    Grafo g;
    g.init(n);

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;

        g.ae(a, b, c);
        g.ae(b, a, c);
    }

    vector<vi> stations(n, vi());

    for(int p = 0; p < 3; p++){
        vi dist = g.dijkstra(p);
        for(int i = 0; i < n; i++){
            stations[i].push_back(dist[i]);
        }
    }

    vi ys;
    for(int i = 0; i < n; i++){
        ys.push_back(stations[i][1]);
    }

    sort(ys.begin(), ys.end());
    auto it = unique(ys.begin(), ys.end());
    ys.erase(it, ys.end());

    for(int i = 0; i < n; i++){
        stations[i][1] = lower_bound(ys.begin(), ys.end(), stations[i][1]) - ys.begin(); 
    }

    sort(stations.begin(), stations.end());

    SegTree<int> st;
    st.init(vi(ys.size(), INF));

    int ans = 0;
    bool flag = true;

    for(int i = 0; i < n; i++){
        if(i > 0 && stations[i - 1] == stations[i]){
            ans += flag;
            continue;
        }

        flag = false;
        if(stations[i][2] < st.query(0, stations[i][1])){
            st.update(stations[i][1], stations[i][2]);
            flag = true;
            ans++;
        }
    }

    cout << ans << ENDL;

    return 0;
}
