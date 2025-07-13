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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const double PI=acos(-1.0);
double DEG_to_RAD(double d) { return d*PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/PI; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ang, n;
    cin >> ang >> n;

    double tanAng = tan(DEG_to_RAD(ang));

    vii flats(n);
    for(int i = 0; i< n; i++){
        cin >> flats[i].fi >> flats[i].se;
    }

    sort(all(flats));

    double st = 0, ans = 0;

    for(int i = 0; i < n; i++){
        st = max(st, (double)flats[i].fi);

        double dist = ((double) flats[i].se / tanAng) + flats[i].fi;
        ans += max(0.0, dist - st);
        st = max(st, dist);
    }

    cout.setf(ios::fixed); cout << setprecision(6);
    cout << ans << ENDL;

    return 0;
}
