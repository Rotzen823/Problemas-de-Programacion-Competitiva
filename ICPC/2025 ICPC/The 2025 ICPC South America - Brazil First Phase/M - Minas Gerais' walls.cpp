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

typedef pair<ll, int> ll2;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vll x(n), prefix(n), sufix(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    prefix[0] = x[0];
    for(int i = 1; i < n; i++){
        prefix[i] = min(prefix[i - 1], x[i]);
    }

    sufix[n - 1] = x[n - 1];
    for(int i = n - 2; i >= 0; i--){
        sufix[i] = min(sufix[i + 1], x[i]);
    }

    set<ll2> menores;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        menores.insert({x[i] + i, -i});
        if(menores.sz() > k){
            int id = i - k;
            menores.erase({x[id] + id, -id});
        }

        int id = -menores.begin()->second;
        ll ax = x[id] + (k - (i - id));
        if(i - k >= 0){
            ax = min(ax, prefix[i - k]);
        }
        if(i < n - 1){
            ax = min(ax, sufix[i + 1]);
        }
        ans = max(ans, ax);
    }

    cout << ans << ENDL;
 
    return 0;
}
