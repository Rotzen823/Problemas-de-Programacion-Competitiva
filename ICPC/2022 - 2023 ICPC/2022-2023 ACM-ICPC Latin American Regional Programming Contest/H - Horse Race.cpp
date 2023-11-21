#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 305
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int freq[MAX][MAX];
int places[MAX];
bool ready[MAX];

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
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    string pal[n + 1];
    map<string, int> ids;
    for(int k = 1; k <= n; k++){
        cin >> pal[k];
        ids[pal[k]] = k;
    }

    int r;
    cin >> r;
    while(r--){
        int m, p;
        cin >> m >> p;
        places[p]++;
        while(m--){
            string ax;
            cin >> ax;
            int id = ids[ax];
            freq[p][id]++;
        }
    }

    HopcroftKrap hk;
    hk.init(n, n);

    for(int k = n; k >= 1; k--){
        for(int j = 1; j <= n; j++){
            if(freq[k][j] == places[k] && !ready[j]){
                hk.ae(k, j);
            }
            if(!ready[j] && freq[k][j] > 0){
                ready[j] = true;
            }
        }
    }

    hk.maxMachine();

    cout << pal[hk.pairU[1]];
    for(int k = 2; k <= n; k++){
        cout << " " << pal[hk.pairU[k]];
    }
    cout << "\n";
    
    return 0;
}
