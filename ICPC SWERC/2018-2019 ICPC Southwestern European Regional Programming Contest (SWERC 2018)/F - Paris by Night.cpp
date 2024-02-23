#include <bits/stdc++.h>

#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX_N 10000005
#define se second
#define fi fisrt

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

const double PI = acos(-1.0);

//Orientacion del punto P en la linea ab
//Positivo = izquierda, Negativo = derecha , 0 = colineal
struct P{
    ll x,y,c;
    P(ll x=0, ll y=0) : x(x), y(y){}
    P operator-(const P &p)const{
        return P(x-p.x, y-p.y);
    }
};

ll cross(P a,P b){ return a.x * b.y-a.y * b.x; }
ll orient(P a, P b, P p) {return cross(b-a,p-a);}

double polarAngle(P p1, P p2){
    double x = p1.x - p2.x, y = p1.y - p2.y;
    double a = atan2(y, x);
    return a < 0 ? a + 2 * PI : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<P>a(n);
    ll sumT = 0;
    for(int i=0;i<n;i++){
       cin>>a[i].x>>a[i].y>>a[i].c; 
       sumT += a[i].c;
    }

    ll ans=INF;

    for(int k = 0; k < n; k++){
        P o = a[k];
        vector<pair<double, int> > events;

        for(int j = 0; j < n; j++){
            if(j == k){
                continue;
            }
            events.push_back({polarAngle(o, a[j]), j});
        }

        sort(events.begin(), events.end());

        int m = events.size();
        int i = 0, j = 0;
        ll ax = a[k].c;
        //cout << k << ":\n";
        while(i < m){
            //cout << i << " " << j << "\n";
            if(ax < sumT && orient(o, a[events[i].se], a[events[j].se]) >= 0){
                ax += a[events[j].se].c;
                j++;
                j %= m;
            }
            else{
                //Calcular
                ll ax2 = (sumT - ax) + a[k].c + a[events[i].se].c;
                ans = min(ans, abs(ax2 - ax));

                //Next
                ax -= a[events[i].se].c;
                i++;
            }
        }
    }
    cout<<ans<<ENDL;

    return 0;
}
