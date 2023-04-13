#include <bits/stdc++.h>
#define MAX 55
#define MAXN 2505
#define INF 10000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;

int pairU[MAXN];
int pairV[MAXN];
int dist[MAXN];
vi graph[MAXN];

bool mat[MAX][MAX];
int bipart[MAX][MAX];
int c1 = 0, c2 = 0;

int D[] = {1, 0, -1, 0};
int d[] = {0, -1, 0, 1};

bool bfs(){
    queue<int> q;

    for(int u = 1; u <= c1; u++){
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

    for(int u = 0; u <= c1; u++){
        pairV[u] = pairU[u] = 0;
    }

    while(bfs()){
        for(int u = 1; u <= c1; u++){
            if(!pairU[u] && dfs(u)){
                result++;
            }
        }
    }

    return result;
}

bool dfs(int x, int y, int c){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }

    if(!mat[x][y]){
        return false;
    }

    if(bipart[x][y]){
        return true;
    } 

    if(c & 1){
        bipart[x][y] = ++c1;
    }
    else{
        bipart[x][y] = ++c2;
    }

    for(int k = 0; k < 4; k++){
        int x1 = x + D[k], y1 = y + d[k];
        bool res = dfs(x1, y1, c + 1);
        if(res && (c & 1)){
            graph[bipart[x][y]].push_back(bipart[x1][y1]);
        }
    }

    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(cin >> n >> m){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                char op;
                cin >> op;
                mat[k][j] = (op == '.');
                bipart[k][j] = 0;
            }
        }

        bool bandera = false;
        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                c1 = c2 = 0;
                dfs(k, j, 1);
                if(!c1){
                    continue;
                }

                if(c1 != c2 || c1 != hopcroftKarp()){
                    bandera = true;
                }

                for(int i = 0; i <= c1; i++){
                    graph[i].clear();
                }

                if(bandera){
                    break;
                }
            }   
            if(bandera){
                break;
            }
        }

        if(bandera){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }

    return 0;
}
