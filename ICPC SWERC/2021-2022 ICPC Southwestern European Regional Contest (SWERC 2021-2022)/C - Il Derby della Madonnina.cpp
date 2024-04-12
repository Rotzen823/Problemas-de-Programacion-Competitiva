#include <bits/stdc++.h>

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<pi>;

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
    ll v;
    cin >> n >> v;

    ll t[n];
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    vii kicks;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;

        if(abs(a) > (v * t[i])){
            continue;
        }
        kicks.pb(pi(v * t[i] - a, v * t[i] + a));
    }

    if(kicks.empty()){
        cout << "0\n";
        return 0;
    }

    sort(kicks.begin(), kicks.end());

    vi lis;

    for(int i = 0; i < (int) kicks.size(); i++){
        ll y = kicks[i].se;
        if(lis.empty() || lis.back() <= y){
            lis.pb(y);
        }
        else{
            int id = upper_bound(lis.begin(), lis.end(), y) - lis.begin();
            lis[id] = y;
        }
    }

    cout << lis.size() << ENDL;

  return 0;
}
