#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 100005
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> il;
 
vi grafo[MAX];
int entry[MAX], exits[MAX], sons[MAX], tiempo = 1;
ll INF = 1e15;
 
class Lazy{
    private:
        int n;
        vector<il> st;
        vector<ll> lazy;
        int left(int v){
            return (v << 1);
        }
        int right(int v){
            return (v << 1) + 1;
        }
 
        void build(int id, il value, int v, int l, int r){
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
            } // Continaución en la siguiente página 
            st[v] = max(st[left(v)], st[right(v)]);
        }
 
        il query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return il(-INF, 0);
            }
 
            if(lazy[v] != 0){
                st[v].first += lazy[v];
                if(r != l){
                    lazy[left(v)] += lazy[v];
                    lazy[right(v)] += lazy[v];
                }
                lazy[v] = 0;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;
 
            return max(query(sl, sr, left(v), l, m), query(sl, sr, right(v), m + 1, r));
        }
 
        void update(int sl, int sr, ll value, int v, int l, int r){
            if(lazy[v] != 0){
                st[v].first += lazy[v];
                if(r != l){
                    lazy[left(v)] += lazy[v];
                    lazy[right(v)] += lazy[v];
                }
                lazy[v] = 0;
            }
 
            if(sl > r || sr < l){
                return;
            }
 
            if(l >= sl && r <= sr){
                st[v].first += value;
                if(r != l){
                    lazy[left(v)] += value;
                    lazy[right(v)] += value;
                }
                return;
            }
 
            int m = (l + r) / 2;
 
            update(sl, sr, value, left(v), l, m);
            update(sl, sr, value, right(v), m + 1, r);
 
            st[v] = max(st[left(v)], st[right(v)]);
        }
 
    public:
        Lazy(int N){
            n = N;
            st.assign(4 * n, il(-INF, 0));
            lazy.assign(4 * n, 0);
        }
 
        il query(int l, int r){
            return query(l, r, 1, 0, n - 1);
        }
 
        void update(int l, int r, ll value){
            update(l, r, value, 1, 0, n - 1);
        }
 
        void build(int id, il value){
            build(id, value, 1, 0, n - 1);
        }
};
 
int dfs(int u, int p){
    entry[u] = tiempo++;
    
    sons[u] = 1;
    for(int v : grafo[u]){
        if(v == p){
            continue;
        }
        sons[u] += dfs(v, u);
    }
 
    exits[u] = tiempo++;
    return sons[u];
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, q;
    cin >> n >> q;
 
    ll bonos[n + 1];
    int res[n + 1];
 
    for(int k = 1; k <= n; k++){
        cin >> bonos[k];
        res[k] = -1;
    }
 
    for(int k = 1; k < n; k++){
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
 
    dfs(1, 0);
 
    Lazy st(tiempo);
 
    st.build(0, il(-INF, 0));
    for(int k = 1; k <= n; k++){
        st.build(entry[k], il(-bonos[k], k));
        st.build(exits[k], il(-bonos[k], k));
    }
 
    for(int k = 1; k <= q; k++){
        int x;
        ll b;
        cin >> x >> b;
        //cout << "r " << entry[x] << " " << exits[x] << "\n";
        st.update(entry[x], exits[x], b / sons[x]);
        st.update(entry[x], entry[x], b % sons[x]);
        st.update(exits[x], exits[x], b % sons[x]);
 
        /*for(int j = 1; j <= n; j++){
            il ax = st.query(entry[j], entry[j]);
            cout << j << " " << ax.first << " " << ax.second << "\n";
        }*/
 
        while(true){
            il ax = st.query(entry[x], exits[x]);
            //cout << ax.first << " " << ax.second << "\n";
            if(ax.first < 0){
                break;
            }
            int u = ax.second;
            res[u] = k;
            st.update(entry[u], entry[u], -INF);
            st.update(exits[u], exits[u], -INF);
        }
    }
 
    for(int k = 1; k <= n; k++){
        cout << res[k] << "\n";
    }
 
	return 0;
}
