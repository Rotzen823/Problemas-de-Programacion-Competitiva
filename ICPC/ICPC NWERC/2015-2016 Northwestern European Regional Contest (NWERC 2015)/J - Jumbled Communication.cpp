#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 10000000000000
#define MAX 1000005

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<int, int>;
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;

	vi res(n);

	for(int i = 0; i < n; i++){
		int b;
		cin >> b;

		int x = 0, car = 0;
		for(int bit = 0; bit < 8; bit++){
			//cout << bit << ' ' << car << ' ' << (b & (1 << bit)) << ENDL;
			if((car ^ ((b & (1 << bit)) > 0))){
				car = 1;
				x |= (1 << bit);
			}
			else{
				car = 0;
			}
		}

		res[i] = x;
	}

	cout << res[0];
	for(int i = 1; i < n; i++){
		cout << ' ' << res[i];
	}
	cout << ENDL;

  return 0;
}
