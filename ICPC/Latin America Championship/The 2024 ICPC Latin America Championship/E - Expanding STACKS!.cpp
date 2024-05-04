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

vector<vi> grafo;
vi color;

bool dfs(int u, int c){
	if(color[u] != -1){
		return color[u] == c;
	}

	color[u] = c;
	for(int v : grafo[u]){
		if(!dfs(v, (c + 1) % 2)){
			return false;
		}
	}

	return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;

	grafo.assign(n, vi());
	color.assign(n, -1);

	vi pila;
	for(int i = 0; i < 2 * n; i++){
		int x;
		cin >> x;
		if(x > 0){
			pila.pb(x - 1);
		}
		else{
			x = -x; x--;
			int j;
			for(j = SZ(pila) - 1; j >= 0; j--){
				if(pila[j] != x){
					grafo[x].pb(pila[j]);
					grafo[pila[j]].pb(x);
				}
				else{
					break;
				}
			}

			pila.erase(pila.begin() + j);
		}
	}	

	for(int i = 0; i < n; i++){
		if(color[i] == -1){
			if(!dfs(i, 0)){
				cout << "*\n";
				return 0;
			}
		}
	}

	string res(n, 'G');
	for(int i = 0; i < n; i++){
		if(color[i]){
			res[i] = 'G';
		}
		else{
			res[i] = 'S';
		}
	}

	cout << res << ENDL;

 	return 0;
}
