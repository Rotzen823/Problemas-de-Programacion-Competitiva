#include <bits/stdc++.h>

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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int l, w, h;
	cin >> l >> w >> h;

	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);

	int res = 0;
	do{
		int area = (l / a[0]) * (w / a[1]) * (h / a[2]); 
		res = max(res, area);
	}while(next_permutation(a, a + 3));

	cout << res << ENDL;

 	return 0;
}
