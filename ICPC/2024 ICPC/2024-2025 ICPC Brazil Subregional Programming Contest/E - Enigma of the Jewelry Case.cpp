#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi  = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define ENDL '\n'

bool validate(vvi &mat){
    int n = SZ(mat);
    for(int j = 0; j < n; j++){
        int ax = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][j] <= ax){
                return false;
            }
            ax = mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        int ax = -1;
        for(int j = 0; j < n; j++){
            if(mat[i][j] <= ax){
                return false;
            }
            ax = mat[i][j];
        }
    }

    return true;
}

vvi rotar90(vvi &mat){
    int n = SZ(mat);
    vvi newMat(n, vi(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            newMat[n - j - 1][i] = mat[i][j]; 
        }
    }

    return newMat;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vvi mat(n, vi(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        /*for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cout << mat[j][k] << ' ';
            }
            cout << ENDL;
        }*/
        if(validate(mat)){
            cout << i << ENDL;
            return 0;
        }
        
        mat = rotar90(mat);
    }

    cout << "-1\n";



    return 0;
}
