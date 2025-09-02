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
    string s;
    cin >> n >> s;
    vi firstAppear(1 << 26, -1);

    int mask = 0, ans = 1;

    for(int i = 0; i < n; i++){
        int idx = s[i] - 'a';
        mask ^= (1 << idx);

        if(mask == 0 || __builtin_popcount(mask) == 1){
            ans = i + 1;
            if(firstAppear[mask] == -1){
                firstAppear[mask] = i;
            }
            continue;
        }
        
        if(firstAppear[mask] != -1){
            ans = max(ans, i - firstAppear[mask]);
        }

        for(int j = 0; j < 26; j++){
            int maskAux = mask ^ (1 << j);
            if(firstAppear[maskAux] != -1){
                ans = max(ans, i - firstAppear[maskAux]);
            }
        }

        if(firstAppear[mask] == -1){
            firstAppear[mask] = i;
        }
    }

    cout << ans << ENDL;

    return 0;
}
