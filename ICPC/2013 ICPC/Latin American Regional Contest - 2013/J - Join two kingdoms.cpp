#include <bits/stdc++.h>
#define MAX 400005
 
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<vi> tree[2];

void dfs(int u, int p, int t, vi &dist){
    dist[u] = dist[p] + 1;

    for(int v : tree[t][u]){
        if(v != p){
            dfs(v, u, t, dist);
        }
    }
}

iii diametro(int t){
    vi dist(tree[t].size());
    int a = 1, b = 0;
    dist[0] = -1;
    dfs(1, 0, t, dist);

    for(int k = 2; k < (int) dist.size(); k++){
        if(dist[k] > dist[a]){
            a = k;
        }
    }

    dfs(a, 0, t, dist);

    for(int k = 1; k < (int) dist.size(); k++){
        if(dist[k] > dist[b]){
            b = k;
        }
    }

    return iii(dist[b], ii(a, b));
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout << setprecision(3);
    
    int n, q;
    cin >> n >> q;
    tree[0].resize(n + 1); tree[1].resize(q + 1);

    for(int k = 1; k < n; k++){
        int a, b;
        cin >> a >> b;
        tree[0][a].push_back(b);
        tree[0][b].push_back(a);
    }

    for(int k = 1; k < q; k++){
        int a, b;
        cin >> a >> b;
        tree[1][a].push_back(b);
        tree[1][b].push_back(a);
    }

    auto ax = diametro(0);
    int dN = ax.first, aN = ax.second.first, bN = ax.second.second;
    
    ax = diametro(1);
    int dQ = ax.first, aQ = ax.second.first, bQ = ax.second.second;

    vi distA[2], distB[2], distN, distQ;
    distA[0].resize(n + 1); distB[0].resize(n + 1); distN.resize(n + 1);
    distA[1].resize(q + 1); distB[1].resize(q + 1); distQ.resize(q + 1);

    distA[0][0] = distB[0][0] = distA[1][0] = distB[1][0] = -1;
    dfs(aN, 0, 0, distA[0]); dfs(bN, 0, 0, distB[0]);
    dfs(aQ, 0, 1, distA[1]); dfs(bQ, 0, 1, distB[1]);

    for(int k = 1; k <= n; k++){
        distN[k] = max(distA[0][k], distB[0][k]);
    }

    for(int k = 1; k <= q; k++){
        distQ[k] = max(distA[1][k], distB[1][k]);
    }

    sort(distQ.begin(), distQ.end());

    vi suma(q + 1, 0);
    for(int k = 1; k <= q; k++){
        suma[k] = suma[k - 1] + distQ[k];
    }
    
    int d = max(dN, dQ);
    double res = 0;
    for(int k = 1; k <= n; k++){
        int i = lower_bound(distQ.begin() + 1, distQ.end(), d - distN[k]) - distQ.begin();
        if(i <= q){
            res += (q - (i - 1));
            res += (suma[q] - suma[i - 1]);
            res += (distN[k] * (q - (i - 1)));
        }
        res += (d * (i - 1));
    }

    res /= (double (n * q));
    cout << res;
    
    return 0;
}
