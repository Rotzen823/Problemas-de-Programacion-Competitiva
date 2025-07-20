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
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;
    vi a(k);

    for(int i = 0; i < k; i++){
        cin >> a[i];
    }

    int n;
    cin >> n;
    vector<vi> b(n, vi(k));
    vi sumB(k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> b[i][j];
            sumB[j] += b[i][j];
        }
    }

    ll ans = INF;
    for(int i = 0; i < k; i++){
        if(sumB[i] == 0){
            continue;
        }
        ans = min(ans, a[i] / sumB[i]);
    }

    for(int i = 0; i < k; i++){
        a[i] -= (sumB[i] * ans);
    }

    int idx = 0;
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < k; j++){
            if(a[j] < b[i][j]){
                flag = false;
                break;
            }
            a[j] -= b[i][j];
        }
        if(!flag){
            idx = i + 1;
            break;
        }
    }

    cout << ans + 1 << ' ' << idx << ENDL;

    return 0;
}
