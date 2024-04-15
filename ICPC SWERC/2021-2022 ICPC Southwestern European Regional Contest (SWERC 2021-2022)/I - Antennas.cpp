#include <bits/stdc++.h>
#define MAX 2
#define INF 1000000

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<pi>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

template <class T>
struct SegTree {
    int n;
    const T NEUT = pi(0, 0);
    vector<T> A, st;

    T oper(T a, T b){
        return max(a, b);
    }

    inline int lc(int p) { return (p << 1) + 1; }
    inline int rc(int p) { return (p << 1) + 2; }

    void init(int N) {
        n = N;
        st.resize(n * 4);
    }

    T query(int l, int r, int p, int L, int R) {
        if (l <= L && r >= R) return st[p];
        if (l > R || r < L) return NEUT;
        int m = (L + R) >> 1;
        return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
    }
    T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

    void update(int i, T val, int p, int L, int R) {
        if (L > i || R < i) return;
        if (L == R) {
        st[p] = val;
        return;
        }
        int m = (L + R) >> 1;
        update(i, val, lc(p), L, m);
        update(i, val, rc(p), m + 1, R);
        st[p] = oper(st[lc(p)], st[rc(p)]);
    }
    void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

template <class T>
struct SegTreeMin {
    int n;
    const T NEUT = pi(INF, 0);
    vector<T> A, st;

    T oper(T a, T b){
        return min(a, b);
    }

    inline int lc(int p) { return (p << 1) + 1; }
    inline int rc(int p) { return (p << 1) + 2; }

    void init(int N) {
        n = N;
        st.resize(n * 4);
    }

    T query(int l, int r, int p, int L, int R) {
        if (l <= L && r >= R) return st[p];
        if (l > R || r < L) return NEUT;
        int m = (L + R) >> 1;
        return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
    }
    T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

    void update(int i, T val, int p, int L, int R) {
        if (L > i || R < i) return;
        if (L == R) {
        st[p] = val;
        return;
        }
        int m = (L + R) >> 1;
        update(i, val, lc(p), L, m);
        update(i, val, rc(p), m + 1, R);
        st[p] = oper(st[lc(p)], st[rc(p)]);
    }
    void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, a, b;
        cin >> n >> a >> b;

        SegTree<pi> st;
        st.init(n);
        SegTreeMin<pi> stMin;
        stMin.init(n);

        vi ar(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
            stMin.update(i, pi(i - ar[i], i));
            st.update(i, pi(i + ar[i], i));
        }
        a--; b--;

        vi dist(n, INF);

        dist[a] = 0;
        st.update(a, pi(0, a));
        stMin.update(a, pi(INF, a));
        queue<int> q;
        q.push(a);

        while(!q.empty()){
            int u = q.front(); q.pop();
            //cout << u << ':' << ENDL;

            while(u > 0 && st.query(max(0, u - ar[u]), u - 1).fi >= u){
                int v = st.query(max(0, u - ar[u]), u - 1).se;
                //cout << v << ' ';
                dist[v] = dist[u] + 1;
                q.push(v);
                st.update(v, pi(0, v));
                stMin.update(v, pi(INF, v));        
            }

            while(u < n - 1 && stMin.query(u - 1, min(n - 1, u + ar[u])).fi <= u){
                int v = stMin.query(u - 1, min(n - 1, u + ar[u])).se;
                //cout << v << ' ';
                dist[v] = dist[u] + 1;
                q.push(v);
                st.update(v, pi(0, v));
                stMin.update(v, pi(INF, v));        
            }
            //cout << ENDL;
        }

        cout << dist[b] << ENDL;
    }

  return 0;
}
