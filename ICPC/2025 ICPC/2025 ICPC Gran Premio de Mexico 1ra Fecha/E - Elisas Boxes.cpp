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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        if(a[i] >= m){
            ans = i + 1;
            break;
        }
    }

    cout << ans << ENDL;

    return 0;
}
