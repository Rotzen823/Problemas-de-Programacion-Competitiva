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

vi color;
vector<vi> grafo;

vector<vi> bfs(int n, int x){
	vector<vi> dist(n, vi(2, INF));

	queue<ii> q;
	q.push(ii(x, 0));
	dist[x][0] = 0;

	while(!q.empty()){
		int u = q.front().fi;
		int p = q.front().se;
		q.pop();

		for(int v : grafo[u]){
			int nP = (p + (color[u] != color[v])) % 2;
			if(dist[v][nP] >= INF){
				dist[v][nP] = dist[u][p] + 1;
				q.push(ii(v, nP));
			}
		}
	}

	return dist;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

	color.assign(n, 0);
	grafo.assign(n, vi());

    for(int i = 0; i < n; i++){
		cin >> color[i];
    }

	while(m--){
		int a, b;
		cin >> a >> b; a--; b--;

		grafo[a].pb(b);
		grafo[b].pb(a);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		vector<vi> dist = bfs(n, i);
		int maxN = 0;
		for(int j = 0; j < n; j++){
			if(i == j){
				continue;
			}
			for(int x = 0; x <= k; x++){
				maxN = max(maxN, min(dist[j][0] + x, dist[j][1] + k - x));
			}
		}
		ans = max(ans, maxN);
	}

	cout << ans << ENDL;

  return 0;
}
