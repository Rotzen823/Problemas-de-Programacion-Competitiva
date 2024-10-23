#include <bits/stdc++.h>

using namespace std;

#define INF 1000000009
#define MOD 1000000000
#define MAX 1005
#define fi first
#define se second
#define pb push_back
#define ENDL '\n'
#define ALL(x) (begin(x), end(x))

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector<double> vd;

vd rounds;
vector<vd> memo;

double dp(int i, int k){
    if(k == -1){
        return 1;
    }

    if(rounds[i] == 0){
        return 0;
    }

    if(memo[i][k] != -1){
        return memo[i][k];
    }

    double ans = 0;
    int st = i ^ (1 << k);
    for(int j = 0; j < k; j++){
        if(i & (1 << j)){
            st -= (1 << j);
        }
    }

    vi save;
    for(int mask = st, j = 0; j < (1 << k); mask++, j++){
        save.pb(rounds[mask]);
        ans += (dp(mask, k - 1) * rounds[i] / (rounds[i] + rounds[mask])); 
        
    }
    ans *= dp(i, k - 1);

    /*cout << rounds[i] << ' ' << i << ' ' << k << ' ' << ans << ":\n";

    for(int s : save){
        cout << s << ' ';
    }
    cout << ENDL;*/
    return memo[i][k] = ans;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int nx, dale;
    cin >> nx >> dale;
    vi r(nx - 1);

    for(int i = 0; i < nx - 1; i++){
        cin >> r[i];
    }

    sort(r.begin(), r.end());

    int lim = 0;
    while((1 << lim) < nx) lim++;

    int n = 1 << lim, ceros = n - nx;

    rounds.assign(n, 0);

    rounds[0] = dale;
    for(int i = 1, j = 0; i < n; i++){
        if(ceros && (i & 1)){
            ceros--;
            continue;
        }

        rounds[i] = r[j];
        j++;
    }

    memo.assign(n, vd(lim, -1));

    double ans = dp(0, lim - 1);

    cout << fixed << setprecision(10);
    cout << ans << ENDL;

    return 0;
}
