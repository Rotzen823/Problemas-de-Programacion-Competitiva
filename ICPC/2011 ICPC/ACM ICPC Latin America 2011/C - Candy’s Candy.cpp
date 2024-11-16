#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 300
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

ll solve(vi &candies, ll s, ll sum){
    if(sum % s > 0){
        return 0;
    }

    int menor = 1e9, mod = candies[0] % s;
    for(int c : candies){
        if(c % s != mod){
            return 0;
        }
        menor = min(c, menor);
    }

    if(menor <= s){
        return 0;
    }

    ll ans = (menor / s);
    if(mod == 0){
        ans--;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int f;
    while(cin >> f){
        if(f == 0){
            break;
        }

        vi candies(f);
        ll sum = 0;
        int gcd = 0;
        for(int i = 0; i < f; i++){
            cin >> candies[i];
            sum += candies[i];
            gcd = __gcd(gcd, candies[i]);
        }

        if(sum % f > 0){
            cout << "0\n";
            continue;
        }

        ll ans = 0;
        for(ll d = 1; (d * d) <= gcd; d++){
            if(gcd % d > 0){
                continue;
            }

            ans += solve(candies, f * d, sum);

            if(gcd / d != d){
                ans += solve(candies, (gcd / d) * f, sum);
            }
        }

        cout << ans << ENDL;
    }

    return 0;
}
