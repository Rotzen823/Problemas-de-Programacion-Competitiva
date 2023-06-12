#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
    int n, k;
    cin >> n >> k;
    k--;

    int mat[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        int x = i + k;
        if(x >= n){
            break;
        }
        for(int j = 0; j < n; j++){
            int y = j + k;
            if(y >= n){
                break;
            }
            if(mat[i][j] == mat[i][y] && mat[i][j] == mat[x][j] && mat[i][j] == mat[x][y]){
                res++;
            }
        }
    }

    cout << res << "\n";
	return 0;
}
