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
#define INF 10000000000000
#define MOD 998244353
#define MAX 100005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef double T;
constexpr double EPS = 1e-8;

int sgn(T x) { return (T(0) < x) - (x < T(0)); }
struct Point {
  T x, y;

  Point operator-(Point p) const { return {x - p.x, y - p.y}; }

  bool operator<(Point p) const { return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS); }
  bool operator==(Point p) const { return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

T orient(Point a, Point b, Point c) { return a.cross(b, c); }

// Retorna si el Punto P se encuentra dentro del circulo entre A y B
bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

// Retorna si el punto P se encuentra en el segmento de puntos S a E
bool onSegment(Point a, Point b, Point p) {
  return a.cross(b, p) == 0 && inDisk(a, b, p);
}

vector<Point> convexHull(vector<Point> pts) {
  if (sz(pts) <= 1) return pts;
  //sort(all(pts));
  vector<Point> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (Point p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;  // quitar = si se incluye colineares
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

// Determina si un punto P se encuentra dentro de un poligono
// convexo ordenado en ccw y sin puntos colineares (Convex hull)
// Tiempo O(log n)
bool inPolygonCH(vector<Point>& l, Point p, bool strict = true) {
  int a = 1, b = sz(l) - 1, r = !strict;
  if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
  if (orient(l[0], l[a], l[b]) > 0) swap(a, b);
  if (orient(l[0], l[a], p) >= r || orient(l[0], l[b], p) <= -r)
    return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (orient(l[0], l[c], p) > 0 ? b : a) = c;
  }
  return sgn(l[a].cross(l[b], p)) < r;
}

int n;
Point gldCookie;
map<Point, double> cookies;

bool solve(double h){
    vector<Point> islands;
    for(auto ck : cookies){
        if(ck.se >= h){
            islands.pb(ck.fi);
        }
    }

    vector<Point> cHull = convexHull(islands);

     bool flag = false;
    if(cHull.sz() == 4 && onSegment(cHull[0], cHull[2], gldCookie) && onSegment(cHull[1], cHull[3], gldCookie)){
        for(Point isl : islands){
            if(!onSegment(cHull[0], cHull[2], isl) && !onSegment(cHull[1], cHull[3], isl)){
                flag = true;
                break;
            }
        }
    }
    else{
        flag = true;
    }
 
    return flag && inPolygonCH(cHull, gldCookie);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double h;
    cin >> n >> h;

    double minH = h;
    for(int i = 0; i < n; i++){
        Point ck;
        double h;
        cin >> ck.x >> ck.y >> h;

        minH = min(minH, h);
        if(cookies.count(ck)){
            cookies[ck] = max(cookies[ck], h);
        }
        else{
            cookies[ck] = h;
        }
    }

    cin >> gldCookie.x >> gldCookie.y;

    if(!solve(minH)){
        cout << "-1\n";
        return 0;
    }

    double l = minH, r = h;
    while((r - l) > EPS){
        double mid = (r + l) / 2;

        if(solve(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout.setf(ios::fixed);
    cout << setprecision(10);
    cout << (h - l) << ENDL;

    return 0;
}
