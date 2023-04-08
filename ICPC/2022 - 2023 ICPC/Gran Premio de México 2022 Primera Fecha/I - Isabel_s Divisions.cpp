#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll num, c = 0, r;

    scanf("%lld", &num);

    ll div = num;
    while(div > 0){
        r = div % 10;
        if(r != 0){
            if(num % r == 0 && r != 0){
                c++;
            }
        }

        div /= 10;
    }

    printf("%lld\n", c);
	

	return 0;
}