#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 10000000000000
#define MAX 1000005

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

const double EPS = 1e-9;  // 1e-9 es suficiente para problemas de precision doble
const double PI = acos(-1.0);

typedef double T;
struct Point {
	T x, y;
 
	// Operaciones Punto - Punto
	Point operator+(Point p) const { return {x + p.x, y + p.y}; }
	Point operator-(Point p) const { return {x - p.x, y - p.y}; }
	Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }
 
	// Operaciones Punto - Numero
	Point operator*(T d) const { return {x * d, y * d}; }
	Point operator/(T d) const { return {x / d, y / d}; }  // Solo para punto flotante
 
	bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
 
	T cross(Point p) const { return x * p.y - y * p.x; }
	T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};
T orient(Point a, Point b, Point c) { return a.cross(b, c); }
 
bool properInter(Point a, Point b, Point c, Point d) {
	if(a == c || a == d ||b == c || b == d){
		return true;
	}
	double oa = orient(c, d, a),
			ob = orient(c, d, b),
			oc = orient(a, b, c),
			od = orient(a, b, d);
	if (oa * ob < 0 && oc * od < 0) {
		return true;
	}
	return false;
}

vector<vi> grafo;
vector<int> color;

bool dfs(int u, int c){
	if(color[u] != -1){
		return color[u] != c;
	}
	color[u] = c;

	for(int v : grafo[u]){
		if(dfs(v, (c + 1) % 2)){
			return true;
		}
	}

	return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<Point> w;
	for(int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;
		w.pb({x, y});
	}

	vector<pair<int, Point> > p;
	for(int i = 0; i < m; i++){
		int s;
		double x, y;
		cin >> s >> x >> y; s--;
		p.pb({s, {x, y}});
	}

	grafo.assign(m, vi());
	color.assign(m, -1);
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			if(p[i].fi == p[j].fi){
				continue;
			}

			if(properInter(w[p[i].fi], p[i].se, w[p[j].fi], p[j].se)){
				grafo[i].pb(j);
				grafo[j].pb(i);
			}
		}
	}

	for(int i = 0; i < m; i++){
		if(color[i] != -1){
			continue;
		}
		if(dfs(i, 0)){
			cout << "impossible\n";
			return 0;
		}	
	}

	cout << "possible\n";


 	return 0;
}
