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
#define MOD 1000000007
#define MAX 1005

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class SegmentTree{
    private:
        int n;
        vi st;
        int left(int v){
            return (v << 1);
        }
        int right(int v){
            return (v << 1) + 1;
        }
        void build(int id, int value, int v, int l, int r){
            if(l == r){
                st[v] = value;
                return;
            }
            int m = (l + r) / 2;
            if(id <= m){
                build(id, value, left(v), l, m);
            }
            else{
                build(id, value, right(v), m + 1, r);
            }
            st[v] = st[left(v)] + st[right(v)];
        }

        int query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return 0;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;
 
            return query(sl, sr, left(v), l, m) + query(sl, sr, right(v), m + 1, r);
        }
 
    public:
        SegmentTree(int N){
            n = N;
            st.assign(4 * n, 0);
        }
 
        int query(int l, int r){
            return query(l, r, 1, 0, n - 1);
        }
 
        void update(int id, int value){
            return build(id, value, 1, 0, n - 1);
        }
};

int t = 0;
vi in, out;
vector<vi> tree;
void dfs(int u){
    if(in[u] != -1){
        return;
    }

    in[u] = t++;
    for(int v : tree[u]){
        dfs(v);
    }
    out[u] = t++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vii employ;
    in.assign(n, -1); out.assign(n, -1);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        employ.pb({x, i});
    }
    sort(all(employ));

    tree.assign(n, vi());
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(0);

    SegmentTree st(n * 2);

    vector<pair<ii, ii> > querys;
    vi ans(q);
    for(int i = 0; i < q; i++){
        int x, k;
        cin >> x >> k; x--;
        querys.pb({ii(k, x), ii(i, 1)});
        querys.pb({ii(k - 1, x), ii(i, -1)});
    }

    sort(all(querys));

    for(int i = 0, j = 0; i < (2 * q); i++){
        while(j < n && employ[j].fi <= querys[i].fi.fi){
            int idx = employ[j].se;
            int inE = in[idx], outE = out[idx];
            st.update(inE, 1);
            st.update(outE, 1);
            j++;
        }

        int idQ = querys[i].se.fi, idX = querys[i].fi.se;
        int inX = in[idX], outX = out[idX];
        ans[idQ] += (st.query(inX, outX) * querys[i].se.se);
    }

    for(int i = 0; i < q; i++){
        ans[i] /= 2;
        cout << ans[i] << ENDL;
    }

    return 0;
}
