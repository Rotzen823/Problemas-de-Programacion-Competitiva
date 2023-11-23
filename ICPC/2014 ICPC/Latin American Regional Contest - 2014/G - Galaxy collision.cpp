#include <bits/stdc++.h>
#define MAX 50005
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi grafo[MAX];
bool ready[MAX];

int c1, c2;
void dfs(int u, bool c){
    if(ready[u]){
        return;
    }
    ready[u] = true;
    c ? c1++ : c2++;
    for(int v : grafo[u]){
        dfs(v, !c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ii puntos[n];
    map<ii, int> puntosM;
    
    for(int k = 0; k < n; k++){
        cin >> puntos[k].fi >> puntos[k].se;
        puntosM[puntos[k]] = k;
    }

    for(int k = 0; k < n; k++){
        for(int dx = -5; dx <= 5; dx++){
            for(int dy = -5; dy <= 5; dy++){
                if((dx == 0 && dy == 0) || dx * dx + dy * dy > 25){
                    continue;
                }
                if(puntosM.count(ii(puntos[k].fi + dx, puntos[k].se + dy))){
                    int id = puntosM[ii(puntos[k].fi + dx, puntos[k].se + dy)];
                    grafo[k].push_back(id);
                }
            }
        }
    }

    int res = 0;
    for(int k = 0; k < n; k++){
        c1 = c2 = 0;
        dfs(k, true);
        res += min(c1, c2);
    }
    cout << res << "\n";

    return 0;
}
