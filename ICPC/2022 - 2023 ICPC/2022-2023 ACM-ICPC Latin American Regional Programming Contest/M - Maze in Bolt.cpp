#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

string llave;
string mat[MAX];
bool memo[MAX][MAX];

int n, m;

int D[] = {1, 0, -1, 0};
int d[] = {0, -1, 0, 1};

bool dfs(int r, int p){
    if(r == n){
        return true;
    }

    if(memo[r][p]){
        return false;
    }

    memo[r][p] = true;

    for(int k = 0; k < 4; k++){
        int x, y;
        x = r + D[k], y = p + d[k];
        y = (y + m) % m;

        if(x < 0){
            continue;
        }
        bool ban = true;
        for(int i = 0, j = y; i < m; i++, j++){
            j %= m;
            if(llave[j] == '1' && mat[x][i] == '1'){
                ban = false;
                break;
            }
        }

        if(ban){
            if(dfs(x, y)){
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cin >> llave;

    mat[0] = llave;
    for(int k = 0; k < m; k++){
        mat[0][k] = '0';
    }

    for(int k = 1; k <= n; k++){
        cin >> mat[k];
    }

    if(dfs(0, 0)){
        cout << "Y\n";
        return 0;
    }
    
    reverse(llave.begin(), llave.end());
    memset(memo, false, sizeof(memo));

    if(dfs(0, 0)){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}