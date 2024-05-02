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

pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
	int res = 0;
	vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
	auto dfs = [&](auto self, int a, int L) -> bool {
		if (A[a] != L) return 0;
		A[a] = -1;
		for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
		}
		return 0;
	};
	while (1) {
		fill(ALL(A), 0);
		fill(ALL(B), 0);
		/// Encuentra los nodos restantes para BFS (i.e. con layer 0)
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		FOR (a, 0, SZ(g)) if(A[a] == 0) cur.pb(a);
		/// Encunetra todas las layers usando BFS
		for (int lay = 1;; lay++) {
		bool islast = 0;
		next.clear();
		for (int a : cur) for (int b : g[a]) {
			if (btoa[b] == -1) {
			B[b] = lay;
			islast = 1;
			}
			else if (btoa[b] != a && !B[b]) {
			B[b] = lay;
			next.pb(btoa[b]);
			}
		}
		if (islast) break;
		if (next.empty()) return {res, btoa};
		for (int a : next) A[a] = lay;
		cur.swap(next);
		}
		/// Usa DFS para escanear caminos aumentantes
		FOR (a, 0, SZ(g)) res += dfs(dfs, a, 0);
	}
}

char mat[MAX][MAX];
int color[MAX][MAX];
int id[MAX][MAX];
int n, m, c0, c1;

bool validar(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y, int c){
	if(!validar(x, y) || mat[x][y] == '#' || color[x][y] != -1){
		return;
	}

	color[x][y] = c;
	if(c){
		id[x][y] = c1++;
	}
	else{
		id[x][y] = c0++;
	}

	for(int i = 0; i < 4; i++){
		dfs(x + dx[i], y + dy[i], (c + 1) % 2);
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	memset(color, -1, sizeof(color));

	vector<vi> grafo[2];

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dfs(i, j, 0);
		}
	}

	grafo[0].assign(c0, vi());
	grafo[1].assign(c1, vi());

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == '#'){
				continue;
			}
			int c = color[i][j];
			int ix = id[i][j];
			for(int k = 0; k < 4; k++){
				int x = i + dx[k], y = j + dy[k];
				if(validar(x, y) && mat[x][y] != '#'){
					grafo[c][ix].pb(id[x][y]);
				}
			}
		}
	}

	int maxMatch = hopcroftKarp(grafo[0], c1).fi;

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == '#'){
				continue;
			}
			int c = color[i][j];
			int ix = id[i][j];
			
			vi temp = grafo[c][ix];
			grafo[c][ix].clear();

			int ax;
			if(c){
				ax = hopcroftKarp(grafo[1], c0).fi;
			}
			else{
				ax = hopcroftKarp(grafo[0], c1).fi;
			}

			if(ax == maxMatch){
				ans++;
			}

			grafo[c][ix] = temp;
		}
	}

	cout << ans << ENDL;

 	return 0;
}
