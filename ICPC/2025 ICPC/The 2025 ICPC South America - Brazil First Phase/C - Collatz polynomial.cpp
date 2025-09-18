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
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    int mask = 0;
    for(int i = n; i >= 0; i--){
        int x;
        cin >> x;
        if(x == 1){
            mask |= (1 << i);
        }
    }

    int ans = 0;
    while(mask > 1){
        if(mask & 1){
            int ax = mask;
            mask <<= 1;
            mask ^= ax;
            mask--;
        }
        else{
            mask >>= 1;
        }
        ans++;
    }

    cout << ans << ENDL;
 
    return 0;
}
