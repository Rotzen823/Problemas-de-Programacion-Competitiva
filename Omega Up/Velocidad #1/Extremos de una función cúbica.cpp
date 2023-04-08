#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll a, b, c, d, m, n, p , q, r, s;

    cin >> a >> b >> c >> d >> m >> n;

    q = p = (a * m * m * m) + (b * m * m) + (c * m) + d;
    r = s = m;

    for(ll k = m + 1; k <= n; k++){
        ll x = (a * k * k * k) + (b * k * k) + (c * k) + d;
        if(x < q){
            q = x;
            s = k;
        }

        if(x > p){
            p = x;
            r = k;
        }
    } 

    printf("%lld %lld %lld %lld\n", p, q, r, s);
 
    return 0;
}