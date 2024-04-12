#include <bits/stdc++.h>
#define MAXR 25
#define MAX 3605

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<set<int> > grafo;
vector<bool> ready;

void dfs(int u){
    if(ready[u]){
        return;
    }
    //cout << u / 360 << ' ' <<u % 360 << ENDL;
    ready[u] = true;

    for(int v : grafo[u]){
        dfs(v);
    }
}

void borrar(int a, int b){
    if(grafo[b].count(a)){
        grafo[b].erase(a);
    }
    if(grafo[a].count(b)){
        grafo[a].erase(b);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    while(t--){
        int m;
        cin >> m;

        grafo.assign(8000, set<int>());
        ready.assign(8000, false);

        for(int i = 0; i <= 20; i++){
            for(int j = 0; j < 360; j++){
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = (j + dy[k] + 360) % 360;
                    if(x < 0 || x > 20){
                        continue;
                    }
                    grafo[i * 360 + j].insert(x * 360 + y);
                }
            }
        }

        while(m--){
            char op;
            int a, b, c;
            cin >> op >> a >> b >> c;

            if(op == 'S'){
                int d = (c - 1 + 360) % 360;
                //cout << a << ' ' << b << ' ' << c << ' ' << d << ENDL;
                for(int i = a; i < b; i++){
                    borrar(i * 360 + c, i * 360 + d);
                    //cout << i << ' ' << c << " - " << i << ' ' << d << ENDL;
                }
            }
            else{
                int d = a - 1;
                //cout << a << ' ' << d << ' ' << b << ' ' << c << ENDL;
                if(b > c){
                    c += 360;
                }
    
                for(int i = b; i < c; i++){
                    int teta = i % 360;
                    borrar(a * 360 + teta, d * 360 + teta);
                    //cout << a << ' ' << teta << " - " << d << ' ' << teta << ENDL;
                }
            }
        }

        dfs(0);

        /*for(int i = 0; i < 360; i++){
            if(!ready[360 + i]){
                cout << i << ENDL;
            }
        }*/
        for(int i = 0; i <= 20; i++){
            for(int j = 0; j < 360; j++){
                if(!ready[i * 360 + j]){
                    //cout << i << ' ' << j << ENDL;
                }
            }
        }

        bool flag = true;
        for(int i = 0; i < 360; i++){
            if(ready[20 * 360 + i]){
                flag = false;
                cout << "YES\n";
                break;
            }
        }

        if(flag){
            cout << "NO\n";
        }
        
    }

  return 0;
}
