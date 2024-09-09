#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi  = pair<int, int>;
using vi = vector<int>;


#define fi first
#define se second
#define pb push_back

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  k -= (n - 1);

  int res = k / n;
  cout << res << '\n';

  return 0;
}
