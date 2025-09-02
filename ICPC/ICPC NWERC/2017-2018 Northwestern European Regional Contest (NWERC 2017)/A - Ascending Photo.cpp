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
#define MOD 998244353
#define MAX 100005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vi h(n);
    map<int, int> idsH;
    for(int i = 0, j = 0; i < n; i++){
        cin >> h[i];
        idsH[h[i]] = 0;
    }

    int id = 0;
    for(auto x : idsH){
        idsH[x.fi] = id++;
    }

    int uniques = idsH.sz();
    vi newH;
    for(int i = 0; i < n; i++){
        if(i == 0 || h[i] != h[i - 1]){
            newH.pb(idsH[h[i]]);
        }
    }

    n = sz(newH);
    vector<vi> pos(uniques, vi());

    for(int i = 0; i < n; i++){
        pos[newH[i]].pb(i);
    }

    vi dp(n, 0);
    for(int i = uniques - 2; i >= 0; i--){
        if(pos[i].sz() == 1){
            int p = pos[i].front();
            for(int q : pos[i + 1]){
                if(p + 1 == q){
                    dp[p] = max(dp[p], dp[q] + 1);
                }
                else{
                    dp[p] = max(dp[p], dp[q]);
                }
            }
            continue;
        }
        
        ii ans1(0, -1), ans2(0, -1);
        for(int q : pos[i + 1]){
            int p = q - 1;
            ii ax(dp[q], q);
            if(p >= 0 && newH[p] == i){
                ax.fi++;
            }
            
            if(ax > ans2){
                ans2 = ax;
                if(ans2 > ans1){
                    swap(ans1, ans2);
                }
            }
        }

        for(int p : pos[i]){
            int q = p + 1;
            if(ans1.se == q){
                dp[p] = max(ans1.fi - 1, ans2.fi);
            }
            else{
                dp[p] = ans1.fi;
            }
        }
    }

    int bestP = 0;
    for(int p : pos[0]){
        bestP = max(bestP, dp[p]);
    }

    int ans = (n - 1) - bestP;
    
    cout << ans << ENDL;


    return 0;
}
