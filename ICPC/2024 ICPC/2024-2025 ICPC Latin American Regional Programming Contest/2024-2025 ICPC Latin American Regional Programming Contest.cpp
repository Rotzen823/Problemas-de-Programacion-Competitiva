#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define maxlog 20
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> ii2;
typedef vector <int> vi;
typedef vector <ii> vii;

vi columns, rows;

int dfs(vi &graph, vi &ans, int u, int c){
    if(ans[u] != -1){
        return 0;
    }

    ans[u] = c;
    return dfs(graph, ans, graph[u], c) + 1;
}

void solve(vector<vi> &ans, int a, int b, int x){
    if(ans[a][b] != 0){
        return;
    }

    ans[a][b] = x;

    solve(ans, rows[a], columns[b], x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n >> t;

    columns.assign(n, 0);
    rows.assign(n, 0);

    for(int i = 0; i < n; i++){
        columns[i] = rows[i] = i;
    }

    while(t--){
        char op;
        int a, b;
        cin >> op >> a >> b; a--; b--;

        if(op == 'R'){
            swap(rows[a], rows[b]);
        }
        else{
            swap(columns[a], columns[b]);
        }
    }

    vi cycleC(n, -1), cycleR(n, -1);

    int tamCycle = 0;
    for(int i = 0, j = 0, k = 0; i < n; i++){
        if(cycleC[i] == -1){
            int ax = dfs(columns, cycleC, i, j);
            j++;
            if(tamCycle == 0){
                tamCycle = ax;
            }
            else if(tamCycle != ax){
                cout << "*\n";
                return 0;
            }
        }

        if(cycleR[i] == -1){
            int ax = dfs(rows, cycleR, i, k);
            k++;
            if(tamCycle != ax){
                cout << "*\n";
                return 0;
            }
        }
    }

    int ciclos = (n / tamCycle);

    vector<vi> ans(n, vi(n)), tab(ciclos, vi(ciclos)), ids(ciclos, vi(ciclos, 1));

    for(int i = 0; i < ciclos; i++){
        tab[0][i] = i;
    }
    for(int i = 1; i < ciclos; i++){
        for(int j = 0; j < ciclos; j++){
            tab[i][j] = (tab[i - 1][j] + 1) % ciclos;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!ans[i][j]){
                int r = cycleR[i], c = cycleC[j];
                int x = tab[r][c] * tamCycle + ids[r][c];
                solve(ans, i, j, x);
                ids[r][c]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i][0];
        for(int j = 1; j < n; j++){
            cout << ' ' << ans[i][j];
        }
        cout << ENDL;
    }



    return 0;
}
