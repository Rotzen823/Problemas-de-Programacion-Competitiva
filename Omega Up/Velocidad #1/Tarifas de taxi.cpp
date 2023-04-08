#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll b, m, s, t, res = 0;

    cin >> b >> m >> s >> t;
    res = b;

    ll seg = 0, x, ant = 0;
    while(t--){
        cin >> x;
        seg++;

        ll met = x - ant;

        if(met >= m){
            ll c = (met / m);
            res += c;
            ant = x - (met % m);
            seg = 0;
        }
        else if(seg >= s){
            res++;
            seg = 0;
            ant = x;
        }
    }

    cout << res << "\n";
    return 0;
}