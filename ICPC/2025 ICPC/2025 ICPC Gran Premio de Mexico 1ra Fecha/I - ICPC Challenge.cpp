// Pura Gente del Coach Moy
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
#define INF 1000000000
#define MOD 1000000007
#define MAX 1005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> g;
vi in, out;
int t = 0;
void dfs(int u, int p) {
    in[u] = ++t;
    for (auto& v:g[u])if(v!=p)dfs(v,u);
    out[u] = t;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vii employees(n);
    for(int i = 0; i < n; i++){
        cin >> employees[i].fi;
    }

    g.assign(n, vi());
    in.resize(n); out.resize(n);
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].pb(b);
    }

    dfs(0, -1);

    for(int i = 0; i < n; i++){
        employees[i].se = in[i];
    }

    sort(all(employees));
    while(q--){
        int x, k;
        cin >> x >> k; x--;

        int a = lower_bound(all(employees), ii(k, in[x])) - employees.begin();
        int b = upper_bound(all(employees), ii(k, out[x])) - employees.begin();

        cout << (b - a) << ENDL;
    }

    return 0;
}
