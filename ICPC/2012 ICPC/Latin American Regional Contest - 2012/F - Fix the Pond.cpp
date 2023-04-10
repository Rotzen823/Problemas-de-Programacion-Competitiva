#include <bits/stdc++.h>
#define MAX 605

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool ready[MAX][MAX];
bool mat[MAX][MAX][4];

// izq ab der arr
int D[] = {0, 1, 0, -1};
int d[] = {-1, 0, 1, 0};
int N, M;

void dfs(int x, int y){
    if(ready[x][y]){
        return;
    }

    ready[x][y] = true;
    
    for(int k = 0; k < 4; k++){
        int a = x + D[k], b = y + d[k];
        if(a < 0 || a >= N || b < 0 || b >= M || !mat[x][y][k]){
            continue;
        }

        dfs(a, b);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;

    while(cin >> n){
        N = (n << 1);
        M = N + 1;
        memset(mat, true, sizeof(mat));
        memset(ready, false, sizeof(ready));
        char op;
        for(int k = 0; k < N - 1; k++){
            int r = k % 2;
            for(int j = 0; j < n; j++){
                int y = (j * 2) + r;
                cin >> op;
                // izq ab der arr
                switch(op){
                    case 'H':
                    mat[k][y][1] = false;
                    mat[k + 1][y][3] = false;
                    mat[k][y + 1][1] = false;
                    mat[k + 1][y + 1][3] = false;
                    break;
                    case 'V':
                    mat[k][y][2] = false;
                    mat[k][y + 1][0] = false;
                    mat[k + 1][y][2] = false;
                    mat[k + 1][y + 1][0] = false;
                    break;
                }
            }
        }

        int res = 0;
        for(int k = 0; k < N; k++){
            for(int j = 0; j < M; j++){
                if(!ready[k][j]){
                    dfs(k, j);
                    res++;
                }
            }
        }

        cout << res - 1 << "\n";
    }

    return 0;
}
