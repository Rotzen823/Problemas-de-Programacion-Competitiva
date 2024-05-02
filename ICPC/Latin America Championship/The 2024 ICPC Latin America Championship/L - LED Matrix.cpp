#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 10000000000000
#define MAX 55

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

	int r, c, k;
	cin >> r >> c >> k;

	bool res = true;
	while(r--){
		string m, p;
		cin >> m >> p;
		if(!res){
			continue;
		}

		bool todosOn = true, hayOn = false;

		for(char x : m){
			if(x == '-'){
				todosOn = false;
				break;
			}
		}

		for(char x : p){
			if(x == '*'){
				hayOn = true;
				break;
			}
		}

		if(!todosOn && hayOn){
			res = false;
		}
	}

	if(res){
		cout << "Y\n";
	}
	else{
		cout << "N\n";
	}

 	return 0;
}
