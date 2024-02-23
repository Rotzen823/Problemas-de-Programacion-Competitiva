#include <bits/stdc++.h>

#define ENDL '\n'
#define INF 100000000
#define MOD 1000000007
#define MAX_N 10000005
#define se second
#define fi first

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int n;
vii c;

ll f(int y){
    ll res = 0;

    int actX = -1, minY = INF, maxY = -1;
    for(int i = 0; i < n; i++){
        if(c[i].fi != actX){
            //cout << y << " " << actX << " " << minY << " " << maxY << "\n";
            if(minY < y){
                res += (y - minY);
            }
            if(maxY > y){
                res += (maxY - y);
            }
            actX = c[i].fi;
            minY = c[i].se;
            maxY = c[i].se;
        }
        else{
            minY = min(minY, c[i].se);
            maxY = max(minY, c[i].se);
        }
    }

    if(minY < y){
        res += (y - minY);
    }
    if(maxY > y){
        res += (maxY - y);
    }

    return res;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int X, Y;
    cin >> X >> Y >> n;

    c.assign(n, ii(0, 0));

    for(int i = 0; i < n; i++){
        cin >> c[i].fi >> c[i].se;
    }

    sort(c.begin(), c.end());

    /*for(int i = 0; i < Y; i++){
        cout << f(i) << " ";
    }
    cout << "\n";*/

    int l = 0, r = Y - 1;
    while((r - l) >= 3){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        ll f1 = f(m1);
        ll f2 = f(m2);

        if(f1 > f2){
            l = m1;
        }
        else if(f1 < f2){
            r = m2;
        }
        else{
            l = m1;
            r = m2;
        }
    }

    ll ax = min({f(l), f(l + 1), f(r)});

    ll ans = (X - 1) + ax * 2;

    cout << ans << "\n";

    return 0;
}
