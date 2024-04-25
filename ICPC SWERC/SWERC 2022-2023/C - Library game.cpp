#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 105
#define INF 1000000000

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

int winBern(vi &x, int m){
	int n = SZ(x);
	for(int i = n - 1, k = 1; i >= 0; i--, k++){
		if(x[i] > (m / k)){
			return (m / k) + 1;
		}
	}
	return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
	cin >> n >> m;

	vi x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}

	sort(ALL(x));
	vector<bool> shels(m + 1, false);

	int div = winBern(x, m);

	if(div){
		cout << "Bernardo\n";
		cout.flush();
		while(n--){
			int y, a;
			cin >> y >> a;

			int b = -1;
			for(int i = a; i < a + y; i++){
				if(shels[i]){
					b = i;
					break;
				}
			}
			if(b == -1){
				b = (a / div);
				if(a % div > 0){
					b++;
				}
				b *= div;
				if(b >= a + y){
					b = a;
				}
			}
			cout << b << ENDL;
			shels[b] = true;
			cout.flush();
		}
	}
	else{
		cout << "Alessia\n";
		cout.flush();
		int y, a = 1;
		while(n--){
			y = x[n];
			cout << y << ' ' << a << ENDL;
			cout.flush();

			int b;
			cin >> b;
			shels[b] = true;
			int st = 1, tam = 0;
			for(int i = 1; i <= m; i++){
				if(shels[i]){
					if(i - st > tam){
						a = st;
						tam = i - st;
					}
					st = i + 1;
				}
			}

			if(m - st + 1 > tam){
				a = st;
			}
		}
	}

  return 0;
}
