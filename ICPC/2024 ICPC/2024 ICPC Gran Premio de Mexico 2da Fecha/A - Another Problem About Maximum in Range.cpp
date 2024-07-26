#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, int>;
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

template<class T>
struct SparseTable {
  vector<vector<T>> jmp;
  void init(const vector<T>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      FOR (j, 0, SZ(jmp[k]))
        jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int l, int r) { // [a, b)
    int dep = 31 - __builtin_clz(r - l);
    return max(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

pair<vi, vi> montonicStack(vii a){
    int n = SZ(a);
    vi leftSmaller(n), rightSmaller(n);
    stack<int> st;
    FOR(i, 0, n) {
        while (!st.empty() && a[st.top()] < a[i])
        st.pop();
        if (st.empty())
        leftSmaller[i] = -1;
        else
        leftSmaller[i] = st.top();
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    ROF(i, n, 0) {
        while (!st.empty() && a[st.top()] < a[i])
        st.pop();
        if (st.empty())
        rightSmaller[i] = n;
        else
        rightSmaller[i] = st.top();
        st.push(i);
    }

    return {leftSmaller, rightSmaller};
}

ll solveBruta(vii a){
    ll res = 0;
    int n = SZ(a);

    for(int i = 0; i < n; i++){
        ll maxA = a[i].first;
        for(int j = i; j < n; j++){
            maxA = max(maxA, a[j].first);
            ll ax = __gcd(i + 1, j + 1);
            ax = (ax * ax) % MOD;
            ax *= maxA; ax %= MOD;
            res += ax; res %= MOD;
        }
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vii a(n); 
    vi h(n + 1), f(n + 1);
    SparseTable<ii> st;

    for(int i = 0; i < n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    vi left, right;
    auto ax = montonicStack(a);
    left = ax.fi, right = ax.se;

    st.init(a);

    /*for(ll x : left){
        cout << x << ' ';
    }
    cout << ENDL;
    for(ll x : right){
        cout << x << ' ';
    }
    cout << ENDL;*/

    for(int g = 1; g <= n; g++){
        for(int i = 1; g * i <= n; i++){
            if((i + 1) * g <= n){
                auto q = st.query(i * g - 1, (i + 1) * g);
                int idx = q.se;
                ll x = q.fi;

                if((idx + 1) % g > 0){
                    ll ax = (i - (left[idx] + 1) / g) % MOD;
                    ax *= ((ll) (right[idx]) / g - (i)) % MOD;
                    ax %= MOD;
                    ax *= x; ax %= MOD;
                    //cout << ax << ENDL;

                    h[g] += ax; h[g] %= MOD;
                }
            }

            //cout << (left[i * g - 1] + 1) / g << " - " << (right[i * g - 1] + 1) / g << ' ';
            ll ax = (i - (left[i * g - 1] + 1) / g) % MOD;
            ax *= ((ll) (right[i * g - 1]) / g - (i - 1)) % MOD;
            ax %= MOD;
            ax *= a[i * g - 1].fi; ax %= MOD;
            //cout << i << ": " << ax << ENDL;

            h[g] += ax; h[g] %= MOD;
        }
        //cout << h[g] << ENDL << ENDL;
    }

    ll ans = 0;
    for(ll g = n; g >= 1; g--){
        f[g] = h[g];

        for(ll i = g * 2; i <= n; i += g){
            //cout << f[i] << ' ';
            f[g] = (f[g] - f[i] + MOD) % MOD;
        }
        //cout << ENDL;

        //cout << g << ": " << f[g] << ENDL;
        ans += (((g * g) % MOD) * f[g]) % MOD;
        ans %= MOD;
    }

    cout << ans << ENDL;
    //cout << solveBruta(a) << ENDL;

 	return 0;
}
