#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 10000000000000
#define MAX 1000005

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<int, int>;
using vi = vector<ll>;
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
	ll m;
	cin >> n >> m;

	vii resears;
	for(int i = 0; i < n; i++){
		ll a, s;
		cin >> a >> s;
		resears.pb(ii(a, s));
	}

	sort(ALL(resears));

	priority_queue<ll, vi, greater<ll> > doors;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ll a = resears[i].fi, s = resears[i].se;
		
		while(!doors.empty()){
			ll ax = doors.top();
			if(a >= ax){
				if(a <= ax + m){
					doors.pop();
					doors.push(a + s);
					break;
				}
				else{
					doors.pop();
				}
			}
			else{
				doors.push(a + s);
				ans++;
				break;
			}
		}

		if(doors.empty()){
			ans++;
			doors.push(a + s);
		}
	}

	cout << n - ans << ENDL;

  return 0;
}
