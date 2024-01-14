#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//Puntos
struct point {
    ll x, y;                                   // if need more precision
    point() { x = y = 0.0; }                       // default constructor
    point(ll _x, ll _y) : x(_x), y(_y) {}  // constructor

    bool operator < (point other) const {          // override < operator
        if (x != other.x)                   // useful for sorting
            return x < other.x;                        // by x-coordinate
        return y < other.y;                          // if tie, by y-coordinate
    }
    
    bool operator == (point other) const {
      return (x == other.x && y == other.y);
    }
};

//Vector
struct vec { ll x, y; // name: `vec' is different from STL vector
    vec(ll _x, ll _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {      // convert 2 points
    return vec(b.x-a.x, b.y-a.y);                  // to vector a->b
}

// returns the cross product of two vectors a and b
ll cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool cw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) < 0;
}

vector<point> CH_Andrew(vector<point> &pts) {    // overall O(n log n)
    int n = pts.size(), k = 0;
    vector<point> H(2*n);
    sort(pts.begin(), pts.end());                  // sort the points by x/y

    for (int i = 0; i < n; ++i) {                  // build lower hull
        while ((k >= 2) && !ccw(H[k-2], H[k-1], pts[i])) --k;
        H[k++] = pts[i];
    }
    
    for (int i = n-2, t = k+1; i >= 0; --i) {       // build upper hull
        while ((k >= t) && !ccw(H[k-2], H[k-1], pts[i])) --k;
        H[k++] = pts[i];
    }

    H.resize(k);
    return H;
}

bool insidePolygon(point pt, const vector<point> &P) {
    int n = (int)P.size();
    if (n <= 3) return false;

    for(int i = 0; i < n - 1; i++){
        if(cw(P[i], P[i + 1], pt)){
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, s;
    vector<point> pts;

    cin >> l;

    for(int i = 0; i < l; i++){
        ll x, y;
        cin >> x >> y;
        pts.push_back(point(x, y));
    }

    vector<point> larges = CH_Andrew(pts);
    l = larges.size();
    
    cin >> s;
    int res = 0;
    while(s--){
        ll x, y;
        cin >> x >> y;
        point p(x, y);

        int in = 1, fin = l - 2;
        while(in < fin){
            int mid = (in + fin) / 2;

            if(ccw(larges[0], larges[mid], p)){
                in = mid + 1;
            }
            else{
                fin = mid;
            }
        }
        
        if(in == 1){
            in++;
        }
        if(insidePolygon(p, {larges[0], larges[in - 1], larges[in], larges[0]})){
            res++;
        }
    }   

    cout << res << "\n";

    return 0;
}
