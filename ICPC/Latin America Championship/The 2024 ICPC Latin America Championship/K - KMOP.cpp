#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
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

bool isVocal(char x){
	return x == 'A' || x == 'E' || x == 'I' || x == 'O' ||
		x == 'U' || x == 'Y';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> words(n);

	for(int i = 0; i < n; i++){
		cin >> words[i];
		words[i] += "BB";
	}

	int ans = n, c = 0;
	bool flag = true;
	for(int i = n - 1; i >= 0; i--){
		c++;
		if(isVocal(words[i][0])){
			c = 0;
		}
		
		if(c > 2){
			if(isVocal(words[i][1])){
				c = 1; ans++;
			}
			else if(flag && isVocal(words[i + 1][1])){
				c = 2; ans++;
			}
			else if(isVocal(words[i][2])){
				c = 2; ans += 2;
				flag = false;
				continue;
			}
		}
		flag = true;

		if(c > 2){
			cout << "*\n";
			return 0;
		}
	}

	cout << ans << ENDL;

 	return 0;
}
