#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

bool esPrimo(int n){
    for(int k = 2; (k * k) <= n; k++){
        if(n % k == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while(!esPrimo(n)){
        n--;
    }

    cout << n << "\n";

	return 0;
}
