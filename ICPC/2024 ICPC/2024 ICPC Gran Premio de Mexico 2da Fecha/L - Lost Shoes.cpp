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

    int ans = 0, t = 2;
    while(t--){
        vi a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }

        for(int i = 0; i < n; i++){
            while(a[i] != i){
                swap(a[i], a[a[i]]);
                ans++;
            }
        }
    }

    cout << ans << ENDL;

 	return 0;
}
