#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  int n, m;

  Matrix(VVT aux) : M(aux), n(M.size()), m(M[0].size()) {}

  Matrix operator*(Matrix& other) const {
    int k = other.M[0].size();
    VVT C(n, vector<T>(k, 0));
    FOR(i, 0, n)
    FOR(j, 0, k)
    FOR(l, 0, m)
    C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
    return Matrix(C);
  }

  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<T>(n))), B(*this);
    FOR(i, 0, n)
    ret.M[i][i] = 1;

    while (p) {
      if (p & 1)
        ret = ret * B;
      p >>= 1;
      B = B * B;
    }
    return ret;
  }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	vector<vi> ide(20, vi(20, 0));

	ide[0][5] = ide[0][9] = ide[0][13] = ide[0][17] = 3;
	for(int i = 1; i < 20; i++){
		ide[i][i - 1] = 1;
	}

	Matrix<ll> ax(ide);

	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll ans = 0;
		Matrix<ll> res = ax ^ n;
		for(int i = 0; i < 20; i++){
			ans += res.M[i][0];
			ans %= MOD;
		}
		cout << ans << ENDL;
	}

 	return 0;
}
