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
//#define MOD 1000000007
#define MAX 1005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

template<int MOD> struct mi {
  int v; 
  mi():v(0) {}
  mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
  mi& operator+=(mi o) { 
    if ((v += o.v) >= MOD) v -= MOD; 
    return *this; }
  mi& operator-=(mi o) { 
    if ((v -= o.v) < 0) v += MOD; 
    return *this; }
  mi& operator*=(mi o) { 
    v = int((ll)v*o.v%MOD); return *this; }
  friend mi be(mi a, ll p) { assert(p >= 0);
    return p==0?1:be(a*a,p/2)*(p&1?a:1); }
  friend mi inv(mi a) { assert(a.v != 0); return be(a,MOD-2); }
  friend mi operator+(mi a, mi b) { return a += b; }
  friend mi operator-(mi a, mi b) { return a -= b; }
  friend mi operator*(mi a, mi b) { return a *= b; }
};
using modint = mi<1000000007>;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    vll x(q);
    for(int i = 0; i < q; i++){
        cin >> x[i];
    }

    vector<modint> pot2(q + 1), sufixSum(q + 1), ans(n);
    pot2[0] = 1;
    for(int i = 1; i <= q; i++){
        pot2[i] = pot2[i - 1] * 2;
    }

    sufixSum[q] = 0;
    for(int i = q - 1; i >= 0; i--){
        sufixSum[i] = sufixSum[i + 1] + (x[i] * (inv(pot2[i + 1])));
    }

    ll inv2 = inv(pot2[1]).v;
    for(int i = 0, table = 0; i < q; i++){
        modint ax = sufixSum[i] * pot2[i];
        
        if(i > 0){
            ax *= inv2;
        }
        ans[table] += ax;
        table = x[i] - 1;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i].v << ENDL;
    }

    return 0;
}
