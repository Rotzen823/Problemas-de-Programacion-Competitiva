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

	int n;
	cin >> n;

	vi torres(n);
	for(int i = 0; i < n; i++){
		cin >> torres[i];
	}

	sort(ALL(torres));

	vi difs;
	difs.pb(torres[0]);
	for(int i = 1; i < n; i++){
		int dif = torres[i] - torres[i - 1];
		if(dif == 0){
			continue;
		}
		difs.pb(dif);
	}

	bool alice = true;
	for(int i = 0; i < SZ(difs) - 1; i++){
		if(difs[i] == 1){
			alice = !alice;
		}
		else{
			break;
		}
	}

	if(alice){
		cout << "Alicius\n";
	}
	else{
		cout << "Bobius\n";
	}

 	return 0;
}
