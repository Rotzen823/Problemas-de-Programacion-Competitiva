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
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map<ll, int> r;
    vi x(n), a(n, 0);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n; i++){
        int rx;
        cin >> rx;
        r[rx]++;
    }

    int idOdd = 0, idEven = 0;
    for(int i = 1; i < n; i++){
        a[i] = (x[i] - x[i - 1]) - a[i - 1];
        if(idOdd == 0 || ((i & 1) && a[i] < a[idOdd])){
            idOdd = i;
        }
        else if((!(i & 1) && a[i] < a[idEven])){
            idEven = i;
        }
    }

    ll minR = r.begin()->fi;
    ll X = minR - a[idEven];

    bool flag = true;
    for(int i = 0; i < n; i++){
        ll rx = a[i] + X;
        if(i & 1){
            rx = a[i] - X;
        }
        if(r[rx] > 0){
            r[rx]--;
        }
        else{
            flag = false;
            break;
        }
    }

    if(!flag){
        X = a[idOdd] - minR;
    }

    cout << X;
    for(int i = 1; i < n; i++){
        ll rx = a[i] + X;
        if(i & 1){
            rx = a[i] - X;
        }
        cout << ' ' << rx;
    }
    cout << ENDL;

    return 0;
}
