#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 10005
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair <int, ll> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

int n;
vii travels;
ll memo[MAX][121][7];

ll dp(int i, int t, int o){
    if(i == n){
        return 0;
    }

    if(memo[i][t][o]){
        return memo[i][t][o];
    }

    ll cost = travels[i].se;
    switch(o){
        case 1:
            cost /= 2;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            cost /= 4;
            break;
    }

    ll ans = dp(i + 1, 0, 0) + cost; //Wait to restart discounts
    if(t + travels[i].fi < 120){
        ans = min(ans, dp(i + 1, t + travels[i].fi, o == 6 ? 6 : o + 1) + cost);
    }

    return memo[i][t][o] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    cin >> n;
    travels.resize(n);

    for(int i = 0; i < n; i++){
        cin >> travels[i].fi >> travels[i].se;
        travels[i].se *= 100;
    }

    ll ans = dp(0, 0, 0);

    cout << ans / 100 << '.';
    ans %= 100;
    if(ans < 10){
        cout << '0';
    }
    cout << ans << ENDL;

    return 0;
}
