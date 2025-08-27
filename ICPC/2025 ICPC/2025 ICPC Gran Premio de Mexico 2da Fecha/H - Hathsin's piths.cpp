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
#define MOD 998244353
#define MAX 100005

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll h, k;
vector<pair<ii, int> > ledges;
int n;

ll distP(ii a, ii b){
    ll distA = a.fi - b.fi;
    ll distB = a.se - b.se;
    return distA * distA + distB * distB;
}

bool isConnected(int i, int j){
    ll distPoints = distP(ledges[i].fi, ledges[j].fi);
    return (ledges[j].se && distPoints <= k) || 
    (ledges[i].se && distPoints <= h);
}

int bfs(int x){
    vi dist(n, -1);
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    if(ledges[x].fi.se == 0){
        return 0;
    }

    while(!q.empty()){
        int u = q.front(); q.pop();

        if(ledges[u].se && distP(ledges[u].fi, ii(ledges[u].fi.fi, 0)) <= h){
            return dist[u] + 1;
        }

        for(int v = 0; v < n; v++){
            if(dist[v] == -1 && isConnected(u, v)){
                dist[v] = dist[u] + 1;
                q.push(v);
                if(ledges[v].fi.se == 0){
                    return dist[v];
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> h >> k;
    h *= h;
    k *= k;

    ledges.resize(n);
    for(int i = 0; i < n; i++){
        cin >> ledges[i].fi.fi >> ledges[i].fi.se >> ledges[i].se;
    }
    ii cord;
    cin >> cord.fi >> cord.se;

    int st = 0;

    for(int i = 0; i < n; i++){
        if(ledges[i].fi == cord){
            st = i;
        }
    }

    int ans = bfs(st);
    cout << ans << ENDL;

    return 0;
}
