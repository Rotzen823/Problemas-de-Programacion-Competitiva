#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 10000000000000
#define MOD 1000000007
#define MAX 1005

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;

    vi fibo(55);
    fibo[0] = fibo[1] = 1;

    for(int i = 2; i < fibo.sz(); i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2]; 
    }
    fibo[0] = 0;
    //cout << fibo[fibo.sz() - 1] << ENDL;

    while(q--){
        ll x, k;
        cin >> x >> k;
        
        ll num = k / x;
        if(k % x != 0){
            num++;
        }

        int ans = lower_bound(all(fibo), num) - fibo.begin();
        cout << ans << ENDL;
    }

    return 0;
}
