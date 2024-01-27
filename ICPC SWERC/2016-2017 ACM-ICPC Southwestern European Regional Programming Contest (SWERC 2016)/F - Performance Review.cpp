#include <bits/stdc++.h>
 
using namespace std;
 
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
        void build(int id, ll value, int v, int l, int r){
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

        ll query(int sl, int sr, int v, int l, int r){
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
 
        ll query(int l, int r){
            return query(l, r, 1, 0, n - 1);
        }
 
        void update(int id, int value){
            build(id, value, 1, 0, n - 1);
        }
};

struct Grafo{
    int V;
    vector<vi> adj;
    vi in, out;
    int tiempo;

    void init(int _V){
        V = _V;
        adj.assign(V, vi());
        in.assign(V, -1);
        out.assign(V, -1);
        tiempo = 0;
    }

    void ae(int a, int b){ adj[a].push_back(b); }

    void dfs(int u){
        in[u] = tiempo++;
        
        for(int v : adj[u]){
            dfs(v);
        }
    
        out[u] = tiempo++;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int n;
    cin >> n;

    Grafo g;

    g.init(n);

	int root = -1;

	vi t(n);
	vii emp;
    for(int k = 0; k < n; k++){
        int p, r;
		cin >> p >> r >> t[k];

		emp.push_back(ii(r, k));
		if(p == -1){
			root = k;
			continue;
		}

		p--;
		g.ae(p, k);
    }

    g.dfs(root);
	sort(emp.begin(), emp.end());

	SegmentTree st(n * 2);

	vi res(n);

	for(int i = 0, j = 0; i < n; i++){
		while(j < n && emp[j].first < emp[i].first){
			int id = emp[j].second;
			st.update(g.in[id], t[id]);
			st.update(g.out[id], t[id]);
			j++;
		}

		int id = emp[i].second;
		res[id] = st.query(g.in[id], g.out[id]) / 2;
	}

	for(int i = 0; i < n; i++){
		cout << res[i] << "\n";
	}
 
	return 0;
}
