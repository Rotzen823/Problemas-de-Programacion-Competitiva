#include <bits/stdc++.h>
#define MOD 1000000000
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;

typedef struct Matrix{
    vector<vi> mat;
    int n, m;

    Matrix(int N, int M, ll a){
        n = N; m = M;
        mat.assign(n, vi(m, 0));

        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                mat[k][j] = (k == j) * a;
            }
        }
    }

    Matrix operator *(const Matrix& a) const
    {
        Matrix ans(n, a.m, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < a.m; j++)
            {
                for(int k = 0; k < m; k++){
                    ll res = (mat[i][k] * a.mat[k][j]) % MOD;
                    ans.mat[i][j] = (ans.mat[i][j] + res) % MOD;
                }
            }
        }
        return ans;
    }    
}Matrix;

Matrix qpow(Matrix x, ll n)
{
    Matrix ans(x.n, x.m, 1);
    while(n)
    {
        if(n & 1) ans = ans * x;
        n >>= 1;
        x = x * x;
    }
    return ans;
}

void nextMask(int mask, int i, int nMask, Matrix& m){
    if(i < 0){
        m.mat[mask][nMask]++;
        return;
    }

    if(i > 0){
        if((mask & (1 << i)) == 0 && (mask & (1 << (i - 1))) == 0){
            nextMask(mask, i - 2, nMask, m);
        }
    }

    nextMask(mask, i - 1, nMask, m);

    if((mask & (1 << i)) == 0){
        nextMask(mask, i - 1, nMask | (1 << i), m);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll m;
    cin >> n >> m;

    Matrix mat(1 << n, 1 << n, 0);

    for(int i = 0; i < (1 << n); i++){
        nextMask(i, n - 1, 0, mat);
    }

    Matrix r = qpow(mat, m);

    ll res = r.mat[0][0];

    cout << res << "\n";

	return 0;
}
