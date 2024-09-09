#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
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
    cin >> n;

    vi bitCont(30, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        for(int k = 29; k >= 0; k--){
            if(x & (1 << k)){
                bitCont[k]++;
            }
        }
    }

    vi ans(n);
    for(int i = 0; i < n; i++){
        for(int k = 29; k >= 0; k--){
            if(bitCont[k]){
                ans[i] |= (1 << k);
                bitCont[k]--;
            }
        }
    }

    cout << ans[0];
    for(int i = 1; i < n; i++){
        cout << ' ' << ans[i];
    }

    cout << ENDL;

 	return 0;
}
