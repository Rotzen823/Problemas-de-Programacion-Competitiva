#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

set<int> res;
set<ii> ready;
vi grafo[MAX];

int C[MAX];

void dfs(int u, int c){
    if(ready.count(ii(u, c))){
        return;
    }

    res.insert(c);
    ready.insert(ii(u, c));

    for(int v : grafo[u]){
        dfs(v, __gcd(c, C[v]));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int i, s;
    cin >> i >> s;

    for(int k = 0; k < i; k++){
        cin >> C[k];
    }

    while(s--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for(int k = 0; k < i; k++){
        dfs(k, C[k]);
    }

    cout << res.size() << "\n";

    return 0;
}
