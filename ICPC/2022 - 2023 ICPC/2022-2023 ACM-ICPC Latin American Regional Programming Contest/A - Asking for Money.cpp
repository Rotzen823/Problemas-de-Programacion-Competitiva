#include <bits/stdc++.h>
#define MAX 1005
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
 
vi grafo[MAX];
ii relat[MAX];
int contador[MAX];
bool ready[MAX];
 
void dfs(int v){
    if(ready[v]){
        return;
    }
 
    ready[v] = true;
    contador[v]++;
 
    for(int u : grafo[v]){
        dfs(u);
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int k = 1; k <= n; k++){
        int a, b;
        cin >> a >> b;
        relat[k] = ii(a, b);
        grafo[a].push_back(k);
        grafo[b].push_back(k);
    }
    
    for(int k = 1; k <= n; k++){
        bool bandera = true;
        int a = relat[k].first;
        int b = relat[k].second;
        memset(contador, 0, sizeof(contador));
        memset(ready, false, sizeof(ready));
        dfs(k);

        memset(ready, false, sizeof(ready));
        ready[k] = true;
        dfs(a);

        memset(ready, false, sizeof(ready));
        ready[k] = true;
        dfs(b);

        for(int j = 1; j <= n; j++){
            if(contador[j] == 3){
                printf("Y");
                bandera = false;
                break;
            }
        }

        if(bandera){
            printf("N");
        }
    }

    printf("\n");
    return 0;
}