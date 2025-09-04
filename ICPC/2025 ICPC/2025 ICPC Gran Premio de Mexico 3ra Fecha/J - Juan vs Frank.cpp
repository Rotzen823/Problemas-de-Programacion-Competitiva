// Pura Gente del Coach Moy
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 1005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif, ll cur) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1){
        s[pos] ^= cur;
        s[pos] ^= (cur + dif);
    }
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res ^= s[pos-1];
    return res;
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    FT ft(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        ft.update(i, b[i], 0);
    }

    while(q--){
        char op;
        cin >> op;

        if(op == 'P'){
            int l, r;
            cin >> l >> r; l--;
            
            ll ans = ft.query(r) ^ ft.query(l);
            if(ans){
                cout << "FRANK\n";
            }
            else{
                cout << "JUAN\n";
            }
        }
        else{
            int k;
            ll x;
            cin >> k >> x; k--;
            ft.update(k, x, b[k]);
            b[k] += x;
        }
    }

    return 0;
}
