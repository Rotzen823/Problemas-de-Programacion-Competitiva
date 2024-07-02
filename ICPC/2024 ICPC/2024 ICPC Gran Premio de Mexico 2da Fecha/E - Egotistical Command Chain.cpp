#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vii progs;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a; a--;
        progs.pb(ii(a, i + 1));
    }

    sort(ALL(progs));

    vi sons;
    vii ans;
    bool flag = false;
    for(int i = 0; i < n; i++){
        int a = progs[i].fi, id = progs[i].se;

        if(a > SZ(sons)){
            flag = true;
            break;
        }

        for(int i = 0; i < a; i++){
            ans.pb(ii(id, sons[i]));
        }

        sons.pb(id);
    }

    if(flag){
        cout << "-1\n";
        return 0;
    }
    
    cout << ans.size() << ENDL;
    for(auto e : ans){
        cout << e.fi << ' ' << e.se << ENDL;
    }

 	return 0;
}
