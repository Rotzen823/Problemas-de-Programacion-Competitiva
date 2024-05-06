#include <bits/stdc++.h>
#define MAX 200005

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

vector<vi> divs;
vector<double> probs, memo;

int n;

double dp(int i){
	if(memo[i] != -1){
		return memo[i];
	}

	vector<bool> ready(n + 1, true);

	double ans = 0, p0;
	for(int j = 1; (j * i) <= n; j ++){
		double pi = 0;
		for(int d : divs[i]){
			if(ready[j * d]){
				pi += probs[j * d];
				ready[j * d] = false;
			}
		}

		if(j == 1){
			p0 = pi;
			ans += pi;
		}
		else{
			ans += pi * (dp(j * i) + 1.0);
		}
	}

	ans /= (1.0 - p0);
	return memo[i] = ans;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	cin >> n;

	probs.resize(n + 1);
	divs.assign(n + 1, vi());
	memo.assign(n + 1, -1);

	double sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> probs[i];
		sum += probs[i];
	}

	for(int i = 1; i <= n; i++){
		probs[i] /= sum;
	}

	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			divs[j].pb(i);
		}
	}

	double ans = dp(1);

	cout << (fixed) << setprecision(12);

	cout << ans << ENDL;

 	return 0;
}
