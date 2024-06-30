#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<int, int>;
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

    int n, m;
	cin >> n >> m;

	set<ii> edges;
	while(m--){
		int a, b;
		cin >> a >> b;
		if(a > b){
			swap(a, b);
		}
		edges.insert(ii(a, b));
	}

	if(n == 1){
		cout << "NO\n";
		return 0;
	}

	vii ans;
	int lim = n / 2;

	for(int i = 1; i <= lim; i++){
		for(int j = i + 1; j <= lim; j++){
			if(!edges.count(ii(i, j))){
				ans.pb(ii(i, j));
			}
		}
	}

	for(int i = lim + 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(!edges.count(ii(i, j))){
				ans.pb(ii(i, j));
			}
		}
	}

	cout << "YES\n";
	cout << SZ(ans) << ENDL;
	for(auto e : ans){
		cout << e.fi << ' ' << e.se << ENDL;
	}

 	return 0;
}
