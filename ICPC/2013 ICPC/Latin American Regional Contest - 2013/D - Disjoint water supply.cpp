#include <bits/stdc++.h>
#define MAX 1005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi graph[MAX];
bool memo[MAX][MAX];
bool ready[MAX][MAX];

bool dp(int u, int v){
    if(u > v){
        swap(u, v);
    }

    if(u == 1 || v == 1){
        return true;
    }

    if(u == v){
        return false;
    }

    if(ready[u][v]){
        return memo[u][v];
    }

    ready[u][v] = true;

    for(int x : graph[v]){
        if(dp(u, x)){
            return memo[u][v] = true;
        }
    }

    return memo[u][v] = false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int k = 0; k < m; k++){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int res = 0;
    for(int k = 1; k <= n; k++){
        for(int j = k + 1; j <= n; j++){
            if(dp(k, j)){
                res++;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
