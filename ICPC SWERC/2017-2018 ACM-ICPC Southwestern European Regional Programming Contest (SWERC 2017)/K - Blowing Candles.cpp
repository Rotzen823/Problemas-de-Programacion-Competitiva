#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;

struct P {
  double x, y;
  P(double x=0.0, double y=0.0) : x(x), y(y) {}
  double length() {return hypot(x, y);} 
  double norm_sq() { return x*x + y*y; }
  P operator*(double a)const{return P(x*a,y*a);}
  P operator+(const P &p)const{return P(x+p.x,y+p.y);}
  P operator-(const P &p)const{return P(x-p.x,y-p.y);}
  bool operator < (const P &P) const{
        return x<P.x || (x==P.x && y<P.y);
    }
};
 
P toVec(P a, P b){
    return P(b.x-a.x, b.y-a.y);
}
 
double dot(P a, P b){ return a.x*b.x + a.y*b.y; }
double cross(P a, P b){ return a.x*b.y - a.y * b.x; }
 
bool ccw(P p, P q, P r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
 
vector<P> CH_Andrew(vector<P> &pts){
    int n=pts.size(), k=0;
    vector<P> H(2*n);
    sort(pts.begin(), pts.end());
    for(int i=0;i<n;++i){
        while((k>=2) && !ccw(H[k-2], H[k-1], pts[i])) --k;
        H[k++] = pts[i];
    }
    for(int i=n-2, t=k+1; i>=0;--i){
        while((k>=t) && !ccw(H[k-2],H[k-1], pts[i])) --k;
        H[k++]= pts[i];
    }
    H.resize(k);
    return H;
}
 
double distToLine(P p, P a, P b){
    P ab=b-a, ap=p-a;
    double r = dot(ap, ab) / ab.norm_sq();
    P c = a+ (ab*r);
    return (c-p).length();
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout << setprecision(6);

	int n;
    double r;
    cin >> n >> r;

    vector<P> p;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        p.push_back(P(x, y));
    }

    vector<P> pol = CH_Andrew(p);
    int m = pol.size();
    if(m <= 3){
        cout << "0\n";
        return 0;
    }

    double res = 2.0 * r;
    int id = 0;
    for(int i = 0; i < m - 1; i++){
        double maxD = distToLine(pol[id], pol[i], pol[i + 1]);
        while(distToLine(pol[(id + 1) % m], pol[i], pol[i + 1]) >= maxD){
            maxD = distToLine(pol[(id + 1) % m], pol[i], pol[i + 1]);
            id++; id %= m;
        }
        res = min(res, maxD);
    }

    cout << res << "\n";
	
    return 0;
}
