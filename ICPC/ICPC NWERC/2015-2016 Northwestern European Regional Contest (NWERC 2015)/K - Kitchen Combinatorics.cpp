#include <bits/stdc++.h>
#define MAX 100
#define MAXR 1005

using namespace std;

using ll = long long;
using pa = pair <int, int>;
using vi = vector <ll>;
using vii = vector <pa>;

ll ing[MAXR];
vi plat[MAX];
bool relat[MAX][MAX];

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOr(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int r, s, m, d, n;

    ll INF = 1e18;

    cin >> r >> s >> m >> d >> n;

    for(int i = 1; i <= r; i++){
        cin >> ing[i];
    }

    for(int i = 1; i <= (s + m + d); i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            plat[i].pb(x);
        }
    }

    while(n--){
        int a, b;
        cin >> a >> b;
        relat[a][b] = relat[b][a] = true;
    }

    ll ans = 0;
    bool tooMany = false;
    for(int i = 1; i <= s; i++){
        for(int j = s + 1; j <= (s + m); j++){
            if(relat[i][j]){
                continue;
            }
            for(int k = s + m + 1; k <= (s + m + d); k++){
                if(relat[i][k] || relat[j][k]){
                    continue;
                }

                set<int> ingsT;
                for(int x : plat[i]){
                    ingsT.insert(x);
                }
                for(int x : plat[j]){
                    ingsT.insert(x);
                }
                for(int x : plat[k]){
                    ingsT.insert(x);
                }

                ll sum = 1;

                for(int x : ingsT){
                    ll br = ing[x];

                    if(sum <= (INF / br)){
                        sum *= br;
                    }
                    else{
                        tooMany = true;
                        break;
                    }
                    if(sum > INF){
                        tooMany = true;
                        break;
                    }
                }

                if(tooMany){
                    break;
                }

                ans += sum;
                if(ans > INF){
                    tooMany = true;
                    break;
                }
            }
            if(tooMany){
                break;
            }
        }
        if(tooMany){
            break;
        }
    }

    if(tooMany){
        cout << "too many\n";
    }
    else{
        cout << ans << ENDL;
    }

    return 0;
}
