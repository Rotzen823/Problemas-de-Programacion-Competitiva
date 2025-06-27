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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<int, ii> iii;

double const EPS = 1e-9;
const double PI=acos(-1.0);
double DEG_to_RAD(double d) { return d*PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/PI; }

//Devuelve el angulo de a respecto a la linea horizontal que pasa por o
//Usado para Sweep Radain
double polarAngle(ii p1, ii p2){
	int x = p1.fi - p2.fi, y = p1.se - p2.se;
    double a = atan2(y, x);
    return a < 0 ? a + 2 * PI : a;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<iii> stars(n);
    for(int i = 0; i < n; i++){
        cin >> stars[i].se.fi >> stars[i].se.se >> stars[i].fi;
    }

    sort(all(stars));

    vector<double> directions;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            if(stars[i].fi == stars[j].fi){
                break;
            }
            directions.pb(polarAngle(stars[i].se, stars[j].se));
        }
    }

    sort(all(directions));

    bool flag = false;
    for(int i = 0; i < directions.sz(); i++){
        int j = (i + 1) % directions.sz();

        double ang = directions[j] - directions[i];
        if(ang < 0){
            ang += (2 * PI);
        }
        if(ang >= PI){
            flag = true;
            break;
        }
    }

    if(flag || directions.sz() == 0){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}
