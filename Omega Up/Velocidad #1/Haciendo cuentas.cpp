#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, man = 0, nar = 0;

    cin >> n;

    while(n--){
        ll a, b, c, d;
        ll x, y;
        cin >> a >> b >> c >> d;

        y = (d - b * a) / (c - b);
        x = a - y;
        man += x;
        nar += y;
    }

    cout << man << " " << nar << "\n";
    return 0;
}