#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 100000000000000
#define MOD 1000000007
#define MAX 1005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll comb[MAX][MAX];

ll nCk(ll n, ll k){
    if(k < 0 || k > n){
        return 0;
    }

    if(n == k || k == 0){
        return 1;
    }

    if(comb[n][k] != -1){
        return comb[n][k];
    }

    return comb[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k)) % MOD;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(comb, -1, sizeof(comb));
    
    int n;
    cin >> n;

    vii points(n);
    map<ii, int> mapPoints;

    for(int i = 0; i < n; i++){
        cin >> points[i].fi >> points[i].se;
    }

    for(int i = 0; i < n; i++){
        mapPoints[ii(2 * points[i].fi, 2 * points[i].se)]++;
        for(int j = i + 1; j < n; j++){
            ii middlePoint = ii(points[i].fi + points[j].fi, points[i].se + points[j].se);
            mapPoints[middlePoint] += 2;
        }
    }

    vll ans(n);
    ans[0] = n;

    for(auto mapPoint : mapPoints){
        //cout << "P: " << mapPoint.fi.fi << ' ' << mapPoint.fi.se << " - " << mapPoint.se << ENDL;
        int edgePoints = mapPoint.se;
        for(int i = 1; i < edgePoints; i += 2){
            ll ax = nCk(edgePoints / 2, (i + 1) / 2);
            ans[i] += ax; ans[i] %= MOD;

            if((i + 1) < edgePoints && edgePoints & 1){
                ans[i + 1] += ax; ans[i + 1] %= MOD;
            }
        }
    }

    cout << ans[0];
    for(int i = 1; i < n; i++){
        cout << ' ' << ans[i];
    }
    cout << ENDL;

    return 0;
}
