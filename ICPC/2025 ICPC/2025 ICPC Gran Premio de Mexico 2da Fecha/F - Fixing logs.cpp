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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vii arms(n);

    ll sumA = 0, sumB = 0;
    for(int i = 0; i < n; i++){
        cin >> arms[i].fi >> arms[i].se;
        sumA += arms[i].fi; sumB += arms[i].se;
    }

    if(n == 2){
        cout << abs(arms[0].fi - arms[1].se) + abs(arms[1].fi - arms[0].se) << ENDL;
        return 0;
    }

    if(sumA > sumB){
        for(int i = 0; i < n; i++){
            swap(arms[i].fi, arms[i].se);
        }
        swap(sumA, sumB);
    }

    ll ans = sumB - sumA;
    for(int i = 0; i < n; i++){
        if(arms[i].fi > (sumB - arms[i].se)){
            ans += (arms[i].fi - (sumB - arms[i].se)) * 2;
            break;
        }
    }

    cout << ans << ENDL;

    return 0;
}
