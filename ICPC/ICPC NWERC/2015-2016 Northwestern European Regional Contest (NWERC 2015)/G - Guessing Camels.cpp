#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 10000000000000
#define MAX 1000005

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

#define NEUT 0
#define oper(a, b) (a + b)
template <class T>
struct SegTree {
	int n;
	vector<T> A, st;

	inline int lc(int p) { return (p << 1) + 1; }
	inline int rc(int p) { return (p << 1) + 2; }

	void init(int N) {
		n = N;
		st.resize(n * 4);
	}

	T query(int l, int r, int p, int L, int R) {
		if (l <= L && r >= R) return st[p];
		if (l > R || r < L) return NEUT;
		int m = (L + R) >> 1;
		return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
	}
	T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

	void update(int i, T val, int p, int L, int R) {
		if (L > i || R < i) return;
		if (L == R) {
		st[p] = val;
		return;
		}
		int m = (L + R) >> 1;
		update(i, val, lc(p), L, m);
		update(i, val, rc(p), m + 1, R);
		st[p] = oper(st[lc(p)], st[rc(p)]);
	}
	void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

ll intersects(vi &a, vi &b){
	vi ax(SZ(a));
	for(int i = 0; i < SZ(a); i++){
		ax[a[i]] = i;
	}

	SegTree<ll> st;
	st.init(SZ(a));

	ll ans = 0;

	for(int x : b){
		ans += st.query(ax[x], SZ(a) - 1);
		st.update(ax[x], 1);
	}

	return ans;
}

void read(vi &a){
	for(int i = 0; i < SZ(a); i++){
		cin >> a[i]; a[i]--;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

	int n;
	cin >> n;

	vi a(n), b(n), c(n);
	read(a); read(b); read(c);

	ll inters = (intersects(a, b) + intersects(a, c) + intersects(b, c)) / 2;

	ll ans = ((ll) n * (ll) (n - 1)) / 2 - inters;

	cout << ans << ENDL;

  return 0;
}
