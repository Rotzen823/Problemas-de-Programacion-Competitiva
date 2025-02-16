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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vi> mat(n, vi(n));
    vector<ii> way;

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    for(int j = n - 1; j >= 1; j--){
        int id = 0;
        for(int i = 0; i < j; i++){
            if(mat[id][j] < mat[i][j]){
                id = i;
            }
        }

        ans += mat[id][j];
        way.pb(ii(id + 1, j + 1));

        for(int i = 0; i < n; i++){
            mat[i][id] = max(mat[i][id], mat[i][j]);
            mat[id][i] = mat[i][id];
        }
    }

    cout << ans << ENDL;
    for(ii ax : way){
        cout << ax.fi << ' ' << ax.se << ENDL;
    }

    return 0;
}
