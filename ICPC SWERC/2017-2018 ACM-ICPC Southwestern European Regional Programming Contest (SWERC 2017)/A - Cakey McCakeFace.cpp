#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    ll best = 0;

    vi a(n);
    map<ll, int> cont;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        ll x;
        cin >> x;

        for(int i = 0; i < n; i++){
            ll dif = x - a[i];
            if(dif >= 0){
                cont[dif]++;
                if(cont[dif] > cont[best] || (cont[dif] == cont[best] && dif < best)){
                    best = dif;
                }
            }
        }
    }

    cout << best << "\n";

    return 0;
}
