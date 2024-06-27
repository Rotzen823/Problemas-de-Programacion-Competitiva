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

    int q;
    cin >> q;

    while(q--){
        int n, t;
        cin >> n >> t;

        if(t == 1){
            cout << n << ENDL;
            continue; 0;
        }

        t--;
        int ans = 0;
        for(int d = 1; d * d <= t; d++){
            if(t % d > 0){
                continue;
            }

            if(d <= n){
                ans++;
                int d2 = t / d;
                if(d2 != d && d2 <= n){
                    ans++;
                }
            }
        }

        cout << ans << ENDL;
        
    }

 	return 0;
}
