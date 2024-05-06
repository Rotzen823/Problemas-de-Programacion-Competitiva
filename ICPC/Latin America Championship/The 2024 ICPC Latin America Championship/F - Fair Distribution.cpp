#include <bits/stdc++.h>
#define MAX 200005

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

bool dp[MAX];
int cont[MAX];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;
	int sumG = 0, gcdR = 0;
	map<int, int> gs;
	for(int i = 0; i < n; i++){
		int g, r;
		cin >> g >> r;
		sumG += g;
		gcdR = __gcd(r, gcdR);
		gs[g]++;
	}

	dp[0] = true;
	for(auto g : gs){

		memset(cont, 0, sizeof(cont));
		int x = g.fi, c = g.se;
		
		for(int i = 0; i <= sumG - x; i++){
			if(!dp[i]){
				continue;
			}

			if(!dp[i + x] && cont[i] < c){
				dp[i + x] = true;
				cont[i + x] = cont[i] + 1;
			}
		}
	}

	if(gs.count(0) && sumG % gcdR == 0){
		cout << "Y\n";
		return 0;
	}

	for(int i = 1; i < sumG; i++){
		if(dp[i]){
			int ax = abs(sumG - 2 * i);
			if(ax % gcdR == 0){
				cout << "Y\n";
				return 0;
			}
		}
	}

	cout << "N\n";

 	return 0;
}
