#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 300
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

typedef struct Tree{
    ll x, y; 
    int v, t;
}Tree;

ll cross(Tree &a, Tree &b){
    return a.x * b.y - b.x * a.y;
}

bool above(Tree &a){
    return a.y > 0 || (a.y == 0 && a.x > 0);
}

bool comparar(Tree &a, Tree &b){
    ll cros = cross(a, b);
    if(!above(a)) cros = -cros;
    if(!above(b)) cros = -cros;
    return cros > 0;
}

bool equal(Tree &a, Tree &b){
    return cross(a, b) == 0;
}

vector<Tree> axTr;

int solve(int type){
    int n = SZ(axTr);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(above(axTr[i]) && axTr[i].t != type) ans += axTr[i].v;
        if(!above(axTr[i]) && axTr[i].t == type) ans += axTr[i].v;
    }

    int act = ans;
    for(int i = 0, j = 0; i < n; i = j){
        j = i;
        while(j < n && equal(axTr[i], axTr[j])){
            if(above(axTr[j])){
                if(axTr[j].t == type){
                    act += axTr[j].v;
                }
                else{
                    act -= axTr[j].v;
                }
            }
            else{
                if(axTr[j].t != type){
                    act += axTr[j].v;
                }
                else{
                    act -= axTr[j].v;
                }
            }
            j++;
        }
        ans = min(ans, act);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int l, p;
    while(cin >> l >> p){
        if(l == 0 && p == 0){
            break;
        }

        vector<Tree> trees;
        int ans = 0;
        for(int i = 0; i < l; i++){
            int x, y, v;
            cin >> x >> y >> v;
            trees.pb({x, y, v, 0});
            ans += v;
        }
        for(int i = 0; i < p; i++){
            int x, y, v;
            cin >> x >> y >> v;
            trees.pb({x, y, v, 1});
            ans += v;
        }

        int n = l + p;
        for(int i = 0; i < n; i++){
            axTr.clear();
            for(int j = 0; j < n; j++) if(i != j){
                Tree ax = trees[j];
                ax.x -= trees[i].x;
                ax.y -= trees[i].y;
                axTr.pb(ax);
            }
            sort(ALL(axTr), comparar);
            ans = min({ans, solve(0), solve(1)});
        }

        cout << ans << ENDL;
    }

    return 0;
}
