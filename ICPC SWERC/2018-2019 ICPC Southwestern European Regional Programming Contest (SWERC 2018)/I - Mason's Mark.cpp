//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX 1005
#define ENDL '\n'
#define INF 1000000
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector <int> vi;

char mat[MAX][MAX];
int color[MAX][MAX];
int n, m;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, 1, -1, 1, -1};

int dfs(int x, int y, int c){
    if(x < 0 || x >= n || y < 0 || y >=m){
        return 0;
    }

    if(mat[x][y] == '.'){
        return 0;
    }

    if(color[x][y]){
        return 0;
    }

    color[x][y] = c;

    int tam = 1;

    for(int i = 0; i < 8; i++){
        tam += dfs(x + dx[i], y + dy[i], c);
    }

    return tam;
}

int solve(int x, int y, int c){
    int x2 = x, y2 = y;

    while(color[x2][y] == c){
        x2++;
    }
    x2--;

    while(color[x][y2] == c){
        y2++;
    }
    y2--;

    while(color[x2][y] == c){
        y++;
    }
    y--;

    //Es A
    if(y != y2){
        return 0;
    }

    while(color[x][y2] == c){
        x++;
    }
    x--;

    //Es C
    if(x != x2){
        return 2;
    }

    //Es B
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    dfs(0, 0, 1);
    
    int c = 2;

    int ans[] = {0, 0, 0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '.' || color[i][j]){
                continue;
            }

            if(dfs(i, j, c) > 1){
                ans[solve(i, j, c)]++;
            }
            c++;
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ENDL;
    
    return 0;
}
