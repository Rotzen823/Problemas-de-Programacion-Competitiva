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

typedef pair<ll, ll> ll2;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    ll2 star;
    cin >> star.fi >> star.se;
    vll dist(n - 1);

    for(int i = 1; i < n; i++){
        ll2 starAux;
        cin >> starAux.fi >> starAux.se;

        if(star.fi == starAux.fi){
            dist[i - 1] = abs(star.se - starAux.se);
        }
        else{
            dist[i - 1] = abs(star.fi - starAux.fi);
        }

        star = starAux;
    }

    ll2 ans(1, dist[0] - 1);
    ll sum = 0;

    for(int i = 0; i < n - 1; i++){
        sum *= -1;
        sum += dist[i];

        if(i & 1){ // + r0
            ans.fi = max(ans.fi, -sum + 1);
            ans.se = min(ans.se, dist[i] - sum - 1);
        }
        else{ // - r0
            ans.fi = max(ans.fi, sum - dist[i] + 1);
            ans.se = min(ans.se, sum - 1);
        }
    }

    if(ans.se > 0 && ans.se >= ans.fi){
        cout << ans.se << ENDL;
    }
    else{
        cout << "-1\n";
    }


    return 0;
}
