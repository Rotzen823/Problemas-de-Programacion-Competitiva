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

struct SuffixArray {
  vi SA, LCP;
  string S;
  int n;
  SuffixArray(string &s, int lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
    int k = 0, a, b;
    vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
    SA = LCP = y, iota(ALL(SA), 0);

    // Calcular SA
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j, iota(ALL(y), n - j);
      FOR(i, 0, n) {
        if (SA[i] >= j) y[p++] = SA[i] - j;
      }
      fill(ALL(ws), 0);
      FOR(i, 0, n) {
        ws[x[i]]++;
      }
      FOR(i, 1, lim) {
        ws[i] += ws[i - 1];
      }
      for (int i = n; i--;) SA[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[SA[0]] = 0;
      FOR(i, 1, n) {
        a = SA[i - 1];
        b = SA[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
      }
    }

    // Calcular LCP (longest common prefix)
    FOR(i, 1, n) {
      rank[SA[i]] = i;
    }
    for (int i = 0, j; i < n - 1; LCP[rank[i++]] = k)
      for (k &&k--, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k++)
        ;
  }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    string S = s + s + "$" + t + t + "{";

    SuffixArray sa(S);

    ll ans = 0;
    int c = n;

    for(int i : sa.SA){
        if(i < n){
            ans += c;
        }
        else if(i > n * 2 && i <= n * 3){
            c--;
        }
    }

    cout << ans << ENDL;

 	return 0;
}
