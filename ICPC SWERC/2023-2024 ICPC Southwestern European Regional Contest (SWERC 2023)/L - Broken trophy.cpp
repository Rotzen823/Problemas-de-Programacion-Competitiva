#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 100005

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

vi ids[5][5];
int res[3][MAX];

void fillC(int x, int w, int id){
	for(int i = 0; i < 3; i++){
		for(int j = x; j < x + w; j++){
			res[i][j] = id; 
		}
	}
}

void fillR(int x, int w, int id){
	for(int j = x; j < x + w; j++){
		res[0][j] = id; 
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n, k;
	cin >> k >> n;

	vi a(k);
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}

	for(int i = 0; i < k; i++){
		int b;
		cin >> b;
		ids[a[i]][b].pb(i + 1);
	}

	int x = 0;
	//Colocar 3x3 y 2x3
	for(int i = 3; i >= 2; i--){
		for(int id : ids[i][3]){
			fillC(x, i, id);
			x += i;
		}
	}

	int st = x;
	//Colocar 2x2
	for(int id : ids[2][2]){
		for(int i = 1; i < 3; i++){
			for(int j = x; j < x + 2; j++){
				res[i][j] = id; 
			}
		}
		x += 2;
	}	

	//Rellenar lo de arriba de 2x2
	int d[] = {2, 3, 1};
	for(int i = 0; i < 3; i++){
		int w = d[i];
		while(!ids[1][w].empty()){
			if(st + w > x){
				break;
			}
			fillR(st, w, ids[1][w].back());
			ids[1][w].pop_back();
			st += w;
		}
	}

	//Colocar 1x3
	for(int id : ids[1][3]){
		fillC(x, 1, id);
		x++;
	}

	while(!ids[1][1].empty() && !ids[1][2].empty()){
		res[0][x] = ids[1][1].back(); ids[1][1].pop_back();
		res[2][x] = res[1][x] = ids[1][2].back(); ids[1][2].pop_back();
		x++;
	}

	while(SZ(ids[1][2]) >= 3){
		for(int i = 0; i < 3; i++){
			res[i][x] = res[i][x + 1] = ids[1][2].back();
			ids[1][2].pop_back();
		}
		x += 2;
	}

	while(SZ(ids[1][1]) >= 3){
		for(int i = 0; i < 3; i++){
			res[i][x] = ids[1][1].back();
			ids[1][1].pop_back();
		}
		x++;
	}

	for(int i = 0; i < 3; i++){
		cout << res[i][0];
		for(int j = 1; j < n; j++){
			cout << ' ' << res[i][j];
		}
		cout << ENDL;
	}
	

  return 0;
}
