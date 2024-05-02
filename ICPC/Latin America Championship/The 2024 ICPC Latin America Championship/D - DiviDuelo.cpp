#include <bits/stdc++.h>

#define fi first
#define se second
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;

    cin >> n;

    ll div = 0;

    for(ll i = 1; (i * i) <= n; i++){
        if(n % i == 0){
            div++;
            if(n / i != i){
                div++;
            }
        }
    }

    if(div & 1){
        cout << "N\n";
        return 0;
    }

    if(div <= 4){
        cout << "Y\n";
        return 0;
    }

    ll p = 2;

    while(n % p != 0){
        p++;
    }

    while(n % p == 0){
        n /= p;
    }

    if(n == 1){
        cout << "Y\n"; 
    }
    else{
        cout << "N\n";
    }


    return 0;
}
