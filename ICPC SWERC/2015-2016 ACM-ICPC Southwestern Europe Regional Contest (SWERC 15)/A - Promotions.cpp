#include <bits/stdc++.h>
#define MAX 5005
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;

vi grafo[MAX];
vi grafo2[MAX];
bool ready[MAX];

int dfs(int u){
    if(ready[u]){
        return 0;
    }
    ready[u] = true;

    int res = 1;
    for(int v : grafo[u]){
        res += dfs(v);
    }

    return res;
}

int dfs2(int u){
    if(ready[u]){
        return 0;
    }
    ready[u] = true;

    int res = 1;
    for(int v : grafo2[u]){
        res += dfs2(v);
    }

    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int a, b, e, p;
    cin >> a >> b >> e >> p;

    while(p--){
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo2[b].push_back(a);
    }

    int A = 0, B = 0, C = 0;
    for(int i = 0; i < e; i++){
        memset(ready, false, sizeof(ready));
        int subs = dfs(i);
        memset(ready, false, sizeof(ready));
        int jefs = dfs2(i) - 1;

        int noSubs = e - subs;
        if(noSubs < a){
            A++;
        }
        if(noSubs < b){
            B++;
        }

        if(jefs >= b){
            C++;
        }
    }

    cout << A << '\n' << B << '\n' << C << '\n';
    
    return 0;
}
