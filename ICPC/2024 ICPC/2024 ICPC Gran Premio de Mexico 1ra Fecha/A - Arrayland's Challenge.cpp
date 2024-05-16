#include <bits/stdc++.h>
#define INF 2000000
#define MAX 10005

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int mat[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;
	
	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			mat[i][j] = abs(a[i] - a[j]);
 		}
		mat[i][i] = INF;
	}

	for(int i = 1; i < n; i++){
		for(int j = 0; (j + i) < n; j++){
			int a = j, b = j + i;
			mat[a][b] = min({mat[a][b], mat[a + 1][b], mat[a][b - 1]});
		}
	}


	int q;
	cin >> q;

	while(q--){
		int l, r;
		cin >> l >> r; l--; r--;

		cout << mat[l][r] << ENDL;
	}

 	return 0;
}
