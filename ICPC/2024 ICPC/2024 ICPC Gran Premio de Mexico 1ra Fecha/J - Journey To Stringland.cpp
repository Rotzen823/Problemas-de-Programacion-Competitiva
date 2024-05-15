#include <bits/stdc++.h>
#define MAX 505
#define INF 1000000

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

string s;
int memo[MAX][MAX][MAX];
bool ready[MAX][MAX][MAX];

int dp(int i, int j, int k){
	if(k == 0){
		return 0;
	}

	if(k == 1 && i <= j){
		return 0;
	}

	if(i >= j){
		return INF;
	}

	if(ready[i][j][k]){
		return memo[i][j][k];
	}

	ready[i][j][k] = true;

	int ans = dp(i + 1, j - 1, k - 2);
	if(s[i] != s[j]){
		ans++;
		ans = min({ans, dp(i + 1, j, k), dp(i, j - 1, k)});
	}

	return memo[i][j][k] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	cin >> s;

	int ans = dp(0, n - 1, k);

	cout << ans << ENDL;

 	return 0;
}
