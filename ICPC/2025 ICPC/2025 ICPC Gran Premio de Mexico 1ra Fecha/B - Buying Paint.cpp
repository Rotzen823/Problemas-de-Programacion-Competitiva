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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;
vector<vi> a;
vector<vector<bool> > ready;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

ll ans = 0, sum = 0;
void solve(int i, int j, int d){
    if(i < 0 || j < 0 || i >= n || j >= n){
        return;
    }
    if(ready[i][j]){
        return;
    }
    ready[i][j] = true;

    sum += a[i][j];
    if(sum < 0){
        sum = 0;
    }
    ans = max(sum, ans);

    solve(i + dx[d], j + dy[d], d);
    for(d = 0; d < 4; d++){
        solve(i + dx[d], j + dy[d], d);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.assign(n, vi(n));
    ready.assign(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(0, 0, 0);
    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(0, 0, 1);

    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(0, n - 1, 1);
    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(0, n - 1, 2);

    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(n - 1, 0, 3);
    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(n - 1, 0, 0);

    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(n - 1, n - 1, 3);
    sum = 0; ready.assign(n, vector<bool>(n, false));
    solve(n - 1, n - 1, 2);

    cout << ans << ENDL;

    return 0;
}
