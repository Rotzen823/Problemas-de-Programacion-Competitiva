#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

vector <vi> AdjList;
vector <vi> bridges;
int V, E;

int dfsNumberCounter = 0;

vi dfs_num, dfs_low, dfs_parent;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == -1) {                          // a tree edge
      dfs_parent[v] = u;

      articulationPointAndBridge(v);
      if (dfs_low[v] > dfs_num[u]){
        bridges[u].push_back(v);
        bridges[v].push_back(u);
      }                           
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);       // update dfs_low[u]
    }
    else if (v != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);       // update dfs_low[u]
} 
}

void dfsColor(int u, int c){
    if(dfs_parent[u] != -1){
        return;
    }
    dfs_parent[u] = c;

    for(int v : bridges[u]){
        dfsColor(v, c);
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;

    while(cin >> V >> E >> q){
        if(V == 0 && E == 0 && q == 0){
            break;
        }
        AdjList.assign(V, {}); bridges.assign(V, {});
        dfs_num.assign(V, -1);  dfs_low.assign(V, 0); dfs_parent.assign(V, 0);
        dfsNumberCounter = 0;

        for(int k = 0; k < E; k++){
            int a, b;
            cin >> a >> b; a--; b--;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        for(int k = 1; k <= V; k++){
            if(dfs_num[k] == -1){
                articulationPointAndBridge(k);
            }
        }

        dfs_parent.assign(V, -1);
        for(int k = 1; k <= V; k++){
            dfsColor(k, k);
        }

        while(q--){
            int a, b;
            cin >> a >> b; a--; b--;
            //cout << dfs_parent[a] << " " << dfs_parent[b] << "\n";
            if(dfs_parent[a] == dfs_parent[b]){
                cout << "Y\n";
            }
            else{
                cout << "N\n";
            }
        }
        cout << "-\n";
    }

    return 0;
}
