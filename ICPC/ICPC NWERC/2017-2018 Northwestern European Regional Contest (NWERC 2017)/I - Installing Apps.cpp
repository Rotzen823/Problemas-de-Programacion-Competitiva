#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef pair<ii, int> iii;

vector<ii> apps;
vector<iii> sortApps;
int memo[505][10005], best[505][10005];
int n;

int dp(int i, int mem){
    if(i == n || mem == 0){
        return 0;
    }

    if(memo[i][mem] != -1){
        return memo[i][mem];
    }
    //cout << i << ' ' << mem << ENDL;

    int ans = dp(i + 1, mem);

    int id = sortApps[i].se;
    if(max(apps[id].fi, apps[id].se) <= mem){
        int ax = dp(i + 1, mem - apps[id].se) + 1;
        if(ax > ans){
            //cout << i << ' ' << mem << ' ' << ax << ENDL;
            ans = ax;
            best[i][mem] = 1;
        }
    }

    return memo[i][mem] = ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int mem;
    cin >> n >> mem;

    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        apps.pb(ii(a, b));
        sortApps.pb(iii(ii(b - a, b), i));
    }

    sort(ALL(sortApps));

    int ans = dp(0, mem);

    vi camino;
    for(int i = 0; i < n; i++){
        if(best[i][mem]){
            int id = sortApps[i].se;
            camino.pb(id + 1);
            mem -= apps[id].se;
        }
    }

    cout << ans << ENDL;

    if(ans > 0){
        cout << camino[0];
        for(int i = 1; i < SZ(camino); i++){
            cout << ' ' << camino[i];
        }
        cout << ENDL;
    }

    return 0;
}
