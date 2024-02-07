#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll w;
    int n;
    cin >> w >> n;

    ll area = 0;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        area += (a * b);
    }

    ll l = area / w;

    cout << l << "\n";

    return 0;
}
