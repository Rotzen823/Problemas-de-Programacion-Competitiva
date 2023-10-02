#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll sacarArea(vii &puntos){
    int n = puntos.size();
    ll area = 0;
    for(int k = 0; k < n; k++){
        int j = (k + 1) % n;
        area += puntos[k].first * puntos[j].second - puntos[j].first * puntos[k].second;
    }

    return abs(area);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int p;
    cin >> p;
    ll res = 0;
    while(p--){
        int n;
        cin >> n;
        vii puntos;

        for(int k = 0; k < n; k++){
            ll x, y;
            cin >> x >> y;
            puntos.push_back(ii(x, y));
        }

        res += sacarArea(puntos);
    }

    res /= 2;
    cout << res << "\n";

  return 0;
}
