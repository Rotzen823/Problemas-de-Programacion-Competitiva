#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;

using ll = long long;
using pa = pair <ll, ll>;
using vi = vector <int>;
using vii = vector <pa>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct HopcroftKrap {
    using F = ll; // flow type
    int N, n1, n2;
    vi pairU, pairV, dist;
    vector <vi> adj;

    void init(int _N, int M){
        N = _N + M;
        n1 = _N; n2 = M;
        adj.assign(N, vi());
        pairU.resize(_N + 1);
        dist.resize(_N + 1);
        pairV.resize(M + 1);
    }

    void ae(int a, int b){ adj[a].push_back(b); }

    bool bfs(){
        queue<int> q;

        for(int u = 1; u <= n1; u++){
            if(!pairU[u]){
                dist[u] = 0;
                q.push(u);
            }
            else{
                dist[u] = INF;
            }
        }

        dist[0] = INF;

        while(!q.empty()){
            int u = q.front(); q.pop();

            if(dist[u] < dist[0]){
                for(int v : adj[u]){
                    if(dist[pairV[v]] == INF){
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(pairV[v]); 
                    }
                }
            }
        }
        return dist[0] != INF;
    }

    bool dfs(int u){
        if(u){
            for(int v : adj[u]){
                if(dist[pairV[v]] == dist[u] + 1){
                    if(dfs(pairV[v])){
                        pairU[u] = v;
                        pairV[v] = u;
                        return true;
                    }
                }
            }

            dist[u] = INF;
            return false;
        }
        return true;
    }

    int maxMachine(){
        int result = 0;

        for(int u = 0; u <= n1; u++){
            pairU[u] = 0;
        }
        for(int u = 0; u <= n2; u++){
            pairV[u] = 0;
        }

        while(bfs()){
            for(int u = 1; u <= n1; u++){
                if(!pairU[u] && dfs(u)){
                    result++;
                }
            }
        }
        return result;
    }

    void printMachine(){ //Solo necesario si se necesita usar
        for(int u = 1; u <= n1; u++){
            if(pairU[u]){
                cout << "Machine " << u << " -> Worker " << pairU[u] << ENDL;
            }
        }
    }

};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vii nums;
    map<ll, int> ids;
    vector<ll> idR;
    vector<vi> adj(n, vi());
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        nums.pb(pa(a, b));

        ll ops[] = {a + b, a - b, a * b};
        for(ll op : ops){
            //cout << i << ' ' << op << ' ';
            int id;
            if(ids.count(op)){
                id = ids[op];
            }
            else{
                id = ids[op] = ids.size();
                idR.pb(op);
            }
            //cout << id << ENDL;
            adj[i].pb(id);
        }
    }

    HopcroftKrap hk;
    hk.init(n, ids.size());

    for(int i = 0; i < n; i++){
        //cout << i << ": \n";
        for(int v : adj[i]){
            //cout << v << '-' << ids[v] << ENDL;
            hk.ae(i + 1, v + 1);
        }
    }

    int maxM = hk.maxMachine();
    vi match = hk.pairU;

    //cout << maxM << ENDL;

    if(maxM < n){
        cout << "impossible\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        //cout << match[i] << ENDL;
        ll r = idR[match[i] - 1], a = nums[i - 1].fi, b = nums[i - 1].se;

        //cout << a << ' ' << b << ' ' << r << ENDL;

        if(a + b == r){
            cout << a << " + " << b << " = " << r << ENDL;
        }
        else if(a - b == r){
            cout << a << " - " << b << " = " << r << ENDL;
        }
        else if(a * b == r){
            cout << a << " * " << b << " = " << r << ENDL;
        }
    }



    return 0;
}
