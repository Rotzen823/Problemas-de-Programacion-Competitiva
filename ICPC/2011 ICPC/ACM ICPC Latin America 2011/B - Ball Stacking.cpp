#include <bits/stdc++.h>
#define MAX 1005
 
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<int> vi;

ll mat[MAX][MAX];
ll memo[MAX][MAX];
ll col[MAX][MAX];

ll dp(int n){
    memset(memo, 0, sizeof(memo));
    ll res = 0;

    for(int k = n; k >= 1; k--){
        int lim = (n - k) + 1;
        for(int j = 1; j <= lim; j++){
            if(j == lim){
                memo[k][j] = memo[k][j - 1] + col[k][j];
            }
            else{
                memo[k][j] = max(memo[k][j - 1] + col[k][j], memo[k + 1][j]);
            }
            res = max(memo[k][j], res);
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        for(int k = 1; k <= n; k++){
            for(int j = 1; j <= k; j++){
                int x = k - (j - 1);
                cin >> mat[x][j];
                col[x][j] = mat[x][j] + col[x - 1][j];
            }
        }

        cout << dp(n) << "\n";
    }
    
    return 0;
}