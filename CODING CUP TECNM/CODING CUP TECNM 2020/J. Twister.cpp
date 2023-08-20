#include <bits/stdc++.h>
#define MAX 505
#define INF 1000000

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair<int, ii> iii;
typedef vector <ii> vii;
typedef vector <int> vi;

int n, m;
vector<vi> mat, salto[4];

void bfs(int x, int y, vector<vi> &res){
    res[x][y] = 0;
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(iii(0, ii(x, y)));

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    while(!q.empty()){
        int u = q.top().second.first, v = q.top().second.second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int t = 2;
            int d = 1;
            while(salto[k][u][v] >= (t - 1)){
                int a = u + dx[k] * (t - 1);
                int b = v + dy[k] * (t - 1);
                if(res[u][v] + d < res[a][b]){
                    res[a][b] = res[u][v] + d;
                    q.push({res[a][b], {a, b}});
                }
                t *= 2;
                d++;
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    mat.assign(n, vi(m, 0));
    for(int k = 0; k < 4; k++){
        salto[k].assign(n, vi(m, 0));
    }
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--; y1--; y2--; x2--;
    int b;
    cin >> b;
    while(b--){
        int a, b;
        cin >> b >> a; b--; a--;
        mat[a][b] = 1;
    }

    //0 - Izquierda
    for(int k = 0; k < n; k++){
        if(mat[k][0]){
            salto[0][k][0] = -1;
        }
        for(int j = 1; j < m; j++){
            if(mat[k][j]){
                salto[0][k][j] = -1;
            }
            else{
                salto[0][k][j] = salto[0][k][j - 1] + 1;
            }
        }
    }

    //1 - Derecha
    for(int k = 0; k < n; k++){
        if(mat[k][m - 1]){
            salto[1][k][m - 1] = -1;
        }
        for(int j = m - 2; j >= 0; j--){
            if(mat[k][j]){
                salto[1][k][j] = -1;
            }
            else{
                salto[1][k][j] = salto[1][k][j + 1] + 1;
            }
        }
    }

    //2 - Arriba
    for(int j = 0; j < m; j++){
        if(mat[0][j]){
            salto[2][0][j] = -1;
        }
        for(int k = 1; k < n; k++){
            if(mat[k][j]){
                salto[2][k][j] = -1;
            }
            else{
                salto[2][k][j] = salto[2][k - 1][j] + 1;
            }
        }
    }

    //3 - Abajo
    for(int j = 0; j < m; j++){
        if(mat[n - 1][j]){
            salto[3][n - 1][j] = -1;
        }
        for(int k = n - 2; k >= 0; k--){
            if(mat[k][j]){
                salto[3][k][j] = -1;
            }
            else{
                salto[3][k][j] = salto[3][k + 1][j] + 1;
            }
        }
    }

    vector<vi> resA, resB;
    resA.assign(n, vi(m, INF));
    resB.assign(n, vi(m, INF));

    bfs(x1, y1, resA);
    bfs(x2, y2, resB);

    int res = INF;
    for(int k = 0; k < n; k++){
        for(int j = 0; j < m; j++){
            res = min(res, max(resA[k][j], resB[k][j]));
        }
    }

    if(res == INF){
        cout << "-1\n";
    }
    else{
        cout << res << "\n";
    }

    return 0;
}
