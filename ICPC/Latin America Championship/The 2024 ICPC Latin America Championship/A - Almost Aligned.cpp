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

double inter(ii a, ii b){
    return (double) (a.second - b.second) / (double) (b.first - a.first);
}
 
vii convex(vii& a){
    sort(a.begin(),a.end());
    vii res;
    FOR(i, 0, a.size()){
        if(i+1 < a.size() and a[i].first == a[i+1].first) continue;
        while(res.size() >= 2 and inter(res[res.size()-2],res.back()) >= inter(res.back(),a[i])) res.pop_back();
        res.pb(a[i]);
    }
    return res;
}
 
double query(vii& a, double x){
    int lo = 0, hi = a.size();
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(x <= inter(a[m-1],a[m])) hi = m;
        else lo = m;
    }
    return a[lo].first * x + a[lo].second;
}

vii cht[4];

double f(double t){
	double xM = query(cht[0], t);
	double xm = -query(cht[1], t);
	double yM = query(cht[2], t);
	double ym = -query(cht[3], t);

	return fabs(xM - xm) * fabs(yM - ym);
}

bool toContinue(vi &idx){
	for(int i = 0; i < 4; i++){
		if(idx[i] < SZ(cht[i]) - 1){
			return true;
		}
	}
	return false;
}

double calcArea(vi &idx, double t){
	vector<double> dims(4);
	for(int i = 0; i < 4; i++){
		dims[i] = cht[i][idx[i]].fi * t + cht[i][idx[i]].se;
	}

	return (dims[0] + dims[1]) * (dims[2] + dims[3]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	vii linX, linY;
	for(int i = 0; i < n; i++){
		int x, y, vx, vy;
		cin >> x >> y >> vx >> vy;

		linX.pb({vx, x});
		//cht[0].add(-vx, -x);
		linY.pb({vy, y});
		//cht[2].add(-vy, -y);
	}

	cht[0] = convex(linX);
	FOR(i, 0, n){
		linX[i].fi = -linX[i].fi;
		linX[i].se = -linX[i].se;
	}
	cht[1] = convex(linX);

	cht[2] = convex(linY);
	FOR(i, 0, n){
		linY[i].fi = -linY[i].fi;
		linY[i].se = -linY[i].se;
	}
	cht[3] = convex(linY);

	double ans = f(0);

	vi idx(4);
	while(toContinue(idx)){
		pair<double, int> avs = {1/.0, -1};
		for(int i = 0; i < 4; i++){
			if(idx[i] < SZ(cht[i]) - 1){
				avs = min(avs, {inter(cht[i][idx[i]], cht[i][idx[i] + 1]), i});
			}
		}

		auto [t, i] = avs;

		if(t >= 0.0){
			ans = min(ans, calcArea(idx, t));
		}
		idx[i]++;
	}

	cout << (fixed) << setprecision(12);
	cout << ans << ENDL;

 	return 0;
}
