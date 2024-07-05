#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

double PI = acos(-1.0);
double EPS = 10e-9;

double calcHeight(double l, double tet){
    return sin(tet) * l;
}

double calcR(double l, double h, double r){
    return r + sqrt((l * l) - (h * h));
}

double f(double l, double r, double tet){
    double h = calcHeight(l, tet);
    double R = calcR(l, h, r);
    //cout << h << ' ' << R;

    return (h * PI * (r * r + R * R + r * R)) / 3.0;
}

double solve(double l, double r){
    double in = PI / 2.0, fin = PI;
    
    while(fin - in > EPS){
        //cout << in << ' ' << fin << ENDL;
        double m1 = in + (fin - in) / 3;
        double m2 = fin - (fin - in) / 3;
        double f1 = f(l, r, m1);
        double f2 = f(l, r, m2);
        if (f1 < f2){
            in = m1;
        }
        else if(f1 > f2){
            fin = m2;
        }
        else{
            in = m1;
            fin = m2;
        }
    }

    return in;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //cout.setf(ios::fixed);
    cout << (fixed) << setprecision(8);

    while(n--){
        int l, r;
        cin >> l >> r;
        
        cout << solve(l, r) << ENDL;
    }

 	return 0;
}
