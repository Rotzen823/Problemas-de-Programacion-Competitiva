#include <bits/stdc++.h>
#define MAX 105
#define MAXN 10005
#define INF 100000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int U = 0, V = 0;
vi graph[MAXN];
int pairU[MAXN];
int pairV[MAXN];
int dist[MAXN];

bool bfs(){
    queue<int> q;

    for(int u = 1; u <= U; u++){
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
            for(int v : graph[u]){
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
        for(int v : graph[u]){
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

int hopcroftKarp(){
    int result = 0;

    for(int u = 0; u <= U; u++){
        pairU[u] = 0;
    }

    for(int v = 0; v <= V; v++){
        pairV[v] = 0; 
    }

    while(bfs()){
        for(int u = 1; u <= U; u++){
            if(!pairU[u] && dfs(u)){
                result++;
            }
        }
    }

    return result;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    char mat[n][n];
    int idFilas[n][n];

    bool used;
    for(int k = 0; k < n; k++){
        used = true;
        for(int j = 0; j < n; j++){
            cin >> mat[k][j];
            if(mat[k][j] == '.'){
                if(used){
                    used = false;
                    ++U;
                }
                idFilas[k][j] = U;
            }
            else{
                used = true;
            }
        }
    }

    for(int j = 0; j < n; j++){
        used = true;
        for(int k = 0; k < n; k++){
            if(mat[k][j] == '.'){
                if(used){
                    used = false;
                    ++V;
                }
                graph[idFilas[k][j]].push_back(V);
            }
            else{
                used = true;
            }
        }
    }

    cout << hopcroftKarp() << "\n";

    return 0;
}
