#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 2000000
#define MAX 1000
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef vector <pi> vii;

const double PI=acos(-1.0);
const double EPS = 1e-8;

double DEG_to_RAD(double d) { return d*PI / 180.0; }

typedef double T;

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const { return {x / d, y / d}; }  // Solo para punto flotante

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Point unit() { return *this / norm(); }

  // Operaciones generales:
  Point translate(Point v) { return *this + v; }
  Point scale(Point c, double factor) { return c + (*this - c) * factor; }
  Point rotate(double ang) { return {x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)}; }
  Point rot_around(double ang, Point c) { return c + (*this - c).rotate(ang); }
  Point perp() { return {-y, x}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  double angle() const { return atan2(y, x); }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

// Retorna si el Punto P se encuentra dentro del circulo entre A y B
bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

// Retorna si el punto P se encuentra en el segmento de puntos S a E
bool onSegment(Point a, Point b, Point p) {
  return a.cross(b, p) == 0 && inDisk(a, b, p);
}

T orient(Point a, Point b, Point c) { return a.cross(b, c); }

double areaPol(vector<Point> p) {
  double area = 0.0;
  int n = SZ(p);
  for(int i = 0; i < n; i++) {
    area += p[i].cross(p[(i + 1) % n]);
  }
  return fabs(area) / 2.0;
}

bool inPolygon(vector<Point>& l, Point p, bool strict = true) {
  int a = 1, b = SZ(l) - 1, r = !strict;
  if (SZ(l) < 3) return r && onSegment(l[0], l.back(), p);
  if (orient(l[0], l[a], l[b]) > 0) swap(a, b);
  if (orient(l[0], l[a], p) >= r || orient(l[0], l[b], p) <= -r)
    return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (orient(l[0], l[c], p) > 0 ? b : a) = c;
  }
  return sgn(l[a].cross(l[b], p)) < r;
}

vector<Point> pts;
int n;

bool allIn(vector<Point>& pol){
    for(int i = 0; i < n; i++){
        if(!inPolygon(pol, pts[i], true)){
            return false;
        }
    }

    //out << "Fin ALL\n";
    return true;
}

bool allOut(vector<Point>& pol){
    for(int i = 0; i < n; i++){
        if(inPolygon(pol, pts[i], false)){
            return false;
        }
    }

    return true;
}

vector<Point> createPol(int k, double d){
    vector<Point> pol;
    Point p = {d, 0};

    pol.pb(p);
    double ang = 360.0 / (double)k;
    for(int i = 1; i < k; i++){
        Point px = p.rotate(DEG_to_RAD(ang * (double) i));
        pol.pb(px);
    }

    return pol;
}   

double outer(int k){
    double in = 0, fin = 1e9;
    while((fin - in) >= EPS){
        double mid = (fin + in) / 2;

        vector<Point> pol = createPol(k, mid);
        //cout << "FIN\n";

        bool ax = allIn(pol);
        if(ax){
            fin = mid;
        }
        else{
            in = mid;
        }
    }
    //cout << "FIN OUT\n";

    return areaPol(createPol(k, in));
}

double inner(int k){
    double in = 0, fin = 1e9;
    ll sol = (ll) fin;
    while((fin - in) >= EPS){
        double mid = (fin + in) / 2;

        vector<Point> pol = createPol(k, mid);

        if(allOut(pol)){
            in = mid;
        }
        else{
            fin = mid;
        }
    }

    return areaPol(createPol(k, in));
}

double solve(int k){
    double out = outer(k);
    double in = inner(k);

    return in / out;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pts.pb({a, b});
    }

    int k = 0;
    double best = 0;
    for(int i = 3; i <= 8; i++){
        double ax = solve(i);
        //cout << ax << ENDL;
        if(ax > best){
            best = ax;
            k = i;
        }
    }   

    cout << k << ' ';
    cout << fixed << setprecision(10);
    cout << best << ENDL;

    return 0;
}
