#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    ll n ,z;

    while(scanf("%lld %lld", &n, &z), !(n == 0 && z == 0)){
        ll r = (ll) sqrt(z);
        ll x = (n / 2) + 1;
        ll y = x;

        if(z == 1){
             printf("Line = %lld, column = %lld.\n", x, y);
             continue;
        }

        if(r % 2 == 0){
            r++;
        }
        else if((r * r) < z){
            r += 2;
        }

        ll c = r / 2;
        ll izq = ((r - 2) * (r - 2)) + 1;
        
        x += c;
        y += c;
        z -= izq;
        r--;
        if(z / r == 0){
            y -= ((z % r) + 1);
        }
        else if(z / r == 1){
            y -= r;
            x -= ((z % r) + 1);
        }
        else if(z / r == 2){
            x -= r;
            y -= ((r - (z % r)) - 1);
        }
        else{
            x -= ((r - (z % r)) - 1);
        }

        printf("Line = %lld, column = %lld.\n", x, y);
    }
    
    return 0;
}