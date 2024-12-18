#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define maxlog 20
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <ll, ll> ii;
typedef pair <int, ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

double inter(ii a, ii b){
    return (double) (a.second - b.second) / (double) (b.first - a.first);
}
 
vii convex(vii& a){
    sort(a.begin(),a.end());
    vii res;
    for(int i = 0; i < a.size(); i++){
        if(i+1 < a.size() and a[i].first == a[i+1].first) continue;
        while(res.size() >= 2 and inter(res[res.size()-2],res.back()) >= inter(res.back(),a[i])) res.pop_back();
        res.pb(a[i]);
    }
    return res;
}
 
ll query(vii& a, ll x){
    int lo = 0, hi = a.size();
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(x <= inter(a[m-1],a[m])) hi = m;
        else lo = m;
    }
    return a[lo].first * x + a[lo].second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    while(cin >> n >> k){
        vi x(n + 1), w(n + 1), W(n + 1), G(n + 1);
        vector<vi> dp(k, vi(n + 1, 0));

        W[0] = G[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> w[i];
            W[i] = W[i - 1] + w[i];
            G[i] = G[i - 1] + (w[i] * x[i]);
        }

        for(int i = 1; i <= n; i++){
            dp[0][i] = W[i] * x[i] - G[i];
        }

        for(int i = 1; i < k; i++){
            vii cht;
            for(int j = i; j <= n; j++){
                //Pendiente negativa por que buscaremos los minimos
                //Formula Real(a, b) = dp[i - 1][a] + x[b] * (W[b] - W[a]) - (G[b] - G[a])
                cht.push_back(ii(-(W[n] - W[j]), -(dp[i - 1][j] - (G[n] - G[j]))));
            }

            cht = convex(cht);

            for(int j = i + 1; j <= n; j++){
                ll ans = -query(cht, x[j]);
                dp[i][j] = ans + (G[n] - G[j]) - (x[j] * (W[n] - W[j]));
            }
        }
        
        cout << dp[k - 1][n] << ENDL;
    }

    return 0;
}
