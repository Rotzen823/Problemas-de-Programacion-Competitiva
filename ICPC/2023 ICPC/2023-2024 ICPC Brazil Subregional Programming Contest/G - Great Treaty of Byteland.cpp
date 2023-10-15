#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
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
    return cross(toVec(p, q), toVec(p, r)) >= 0;
}

vector<pair<point, int> > CH_Andrew(vector<pair<point, int> > &pts) {    // overall O(n log n)
    int n = pts.size(), k = 0;
    vector<pair<point, int> > H(2 * n);
    sort(pts.begin(), pts.end());                  // sort the points by x/y

    for (int i = 0; i < n; ++i) {                  // build lower hull
        while ((k >= 2) && !ccw(H[k-2].first, H[k-1].first, pts[i].first)) --k;
        H[k].second = pts[i].second;
        H[k++].first = pts[i].first;
    }
    
    for (int i = n-2, t = k+1; i >= 0; --i) {       // build upper hull
        while ((k >= t) && !ccw(H[k-2].first, H[k-1].first, pts[i].first)) --k;
        H[k].second = pts[i].second;
        H[k++].first = pts[i].first;
    }

    H.resize(k);
    return H;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<point, int> > pts;

    int n;
    cin >> n;

    for(int k = 0; k < n; k++){
        ll x, y;
        cin >> x >> y;
        pts.push_back({point(x, y), k + 1});
    }

    vector<pair<point, int> > hull = CH_Andrew(pts);

    set<int> res;
    for(int k = 0; k < (int) hull.size() - 1; k++){
        res.insert(hull[k].second);
    }

    bool espacio = false;
    for(int x : res){
        if(!espacio){
            espacio = true;
        }
        else{
            cout << " ";
        }
        cout << x;
    }
    cout << "\n";

    return 0;
}
