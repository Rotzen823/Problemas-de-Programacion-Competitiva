#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef vector <pi> vii;

ll solve(ll a, ll b, ll c){
    return a * a + b * b + c * c + 7LL * min({a, b, c});
}

void ordenar(ll &a, ll &b, ll &c){
    if(a < b){
        swap(a, b);
    }
    if(a < c){
        swap(a, c);
    }
    if(b < c){
        swap(b, c);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;

    cin >> n;

    while(n--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ordenar(a, b, c);

        while(d){
            int ax = min(4LL, d);

            int x, y, z;
            ll res = 0;
            for(int i = ax; i >= 0; i--){
                for(int j = ax - i; j >= 0; j--){
                    int k = ax - i - j;
                    ll axS = solve(a + i, b + j, c + k);

                    if(axS > res){
                        //cout << axS << ENDL;
                        //cout << i << ' ' << j << ' ' << k << ENDL;
                        res = axS;
                        x = i, y = j, z = k;
                    }
                }
            }

            if(x == ax){
                a += d;
                break;
            }
            else{
                a += x; b += y; c += z;
            }

            ordenar(a, b, c);
            d -= ax;
        }

        cout << solve(a, b, c) << ENDL;
    }

    return 0;
}
