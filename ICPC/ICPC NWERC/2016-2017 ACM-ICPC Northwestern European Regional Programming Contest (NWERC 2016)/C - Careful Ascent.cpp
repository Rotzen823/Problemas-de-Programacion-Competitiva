#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF 1000000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ii, double> iid;
typedef vector<int> vi;
typedef vector <ii> vii;

vector<iid> shields;

double EPS = 10e-12;

double f(double vH, double yf){
    double x = 0, y = 0;

    for(auto s : shields){
        double l = s.fi.fi, u = s.fi.se, v = s.se;

        x += (l - y) * vH;
        y = l;

        double vR = vH * v;
        x += (u - y) * vR;
        y = u;
    }

    x += (yf - y) * vH;
    y = yf;

    return x;
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    int x, y, n;
    cin >> x >> y >> n;

    bool flag = x < 0;
    x = abs(x);

    for(int i = 0; i < n; i++){
        int l, u;
        double v;
        cin >> l >> u >> v;

        shields.pb(iid(ii(l, u), v));
    }

    sort(ALL(shields));

    double l = 0, r = x;
    while((r - l) >= EPS){
        //cout << l << ' ' << r << ' '; 
        double mid = (r + l) / 2.0;

        double xm = f(mid, y);
        //cout << mid << ' ' << xm << ENDL;
        if(fabs(xm - x) <= EPS){
            l = r = mid;
        }
        else if(x < xm - EPS){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << (fixed) << setprecision(11);

    if(flag){
        l = -l;
    }
    cout << l << ENDL;
    
    return 0;
}
