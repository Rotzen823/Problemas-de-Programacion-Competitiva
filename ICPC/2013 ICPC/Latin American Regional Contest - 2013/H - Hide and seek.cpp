#include <bits/stdc++.h>
#define MAX 10005
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const double PI = acos(-1.0);
double const EPS = 1e-9;

//Puntos
struct point {
    double x, y;                                   // if need more precision
    point() { x = y = 0.0; }                       // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}  // constructor

    bool operator < (point other) const {          // override < operator
        if (fabs(x-other.x) > EPS)                   // useful for sorting
          return x < other.x;                        // by x-coordinate
        return y < other.y;                          // if tie, by y-coordinate
    }
    
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
      return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));
    }
};

double dist(point p1, point p2) {                // Euclidean distance
  // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
  return hypot(p1.x-p2.x, p1.y-p2.y);            // return double
}

//Vector
struct vec { double x, y; // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {      // convert 2 points
    return vec(b.x-a.x, b.y-a.y);                  // to vector a->b
}

vec scale(const vec &v, double s) {              // s = [<1..1..>1]
  return vec(v.x*s, v.y*s);                      // shorter/eq/longer
} 

point translate(const point &p, const vec &v) {  // translate p
  return point(p.x+v.x, p.y+v.y);                // according to v
}  


//Producto punto
int dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

// returns the squared value of the normalized vector
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

//Linea
struct line { double a, b, c; };  // most versatile

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x-p2.x) < EPS)                     // vertical line is fine
      l = {1.0, 0.0, -p1.x};                       // default values
    else {
      double a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
      l = {a, 1.0, -(double)(a*p1.x) - p1.y};      // NOTE: b always 1.0
    }
}

bool areParallel(line l1, line l2) {             // check a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {                 // also check  c
  return areParallel(l1 ,l2) && (fabs(l1.c-l2.c) < EPS);
}

// returns true (+ intersection point p) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;         // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
  else                  p.y = -(l2.a*p.x + l2.c);
  return true;
}

// angle aob in rad
double angle(const point &a, const point &o, const point &b) {
    vec oa = toVec(o, a), ob = toVec(o, b);        // a != o != b
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double angleComp(const point &o, const point &a){
	point ref = o;
	ref.x++;
	double ang = angle(ref, o, a);
	if(a.y < o.y){
		ang = (2.0 * PI) - ang;
	}

	return ang;
}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  // formula: c = a + u*ab
  c = translate(a, scale(ab, u));                // translate a to c
  return dist(p, c);                             // Euclidean distance
}

// returns the distance from p to the line segment ab defined by
// two points a and b (technically, a has to be different than b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {                                 // closer to a
    c = point(a.x, a.y);
    return dist(p, a);                           // dist p to a
  }
  if (u > 1.0) {                                 // closer to b
    c = point(b.x, b.y);
    return dist(p, b);                           // dist p to b
  }
  return distToLine(p, a, b, c);                 // use distToLine
}

point puntos[MAX];
pair<point, point> lineas[MAX];

bool intersectSegment(point a, point b, point c, point d){
    double x1 = a.x, x2 = b.x, x3 = c.x, x4 = d.x;
    double y1 = a.y, y2 = b.y, y3 = c.y, y4 = d.y;
    line l1, l2;

    pointsToLine(a, b, l1);
    pointsToLine(c, d, l2);

    if(x1 > x2){
        swap(x1, x2);
    }
    if(y1 > y2){
        swap(y1, y2);
    }
    if(x3 > x4){
        swap(x3, x4);
    }
    if(y3 > y4){
        swap(y3, y4);
    }

    point p;
    if(areSame(l1, l2)){
        return !(x1 > x4 || x2 < x3 || y1 > y4 || y2 < y3);
    }
    else if(areIntersect(l1, l2, p)){
        return p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2 &&
        p.x >= x3 && p.x <= x4 && p.y >= y3 && p.y <= y4;
    }
    return false;
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    int s, k, w;
    cin >> s >> k >> w;

    for(int i = 0; i < k; i++){
        cin >> puntos[i].x >> puntos[i].y;
    }

    for(int i = 0; i < w; i++){
        cin >> lineas[i].first.x >> lineas[i].first.y;
        cin >> lineas[i].second.x >> lineas[i].second.y;
    }

    for(int i = 0; i < s; i++){
        vector<pair<double, ii> > events;

        vector<double> distW(w);
        set<pair<double, int> > segments;

        for(int j = 0; j < w; j++){
            double angP1 = angleComp(puntos[i], lineas[j].first);
            double angP2 = angleComp(puntos[i], lineas[j].second);
            point ax;
            distW[j] = distToLineSegment(puntos[i], lineas[j].first, lineas[j].second, ax);

            if(angP1 > angP2){
                swap(angP1, angP2);
            }

            if(angP1 <= (PI / 2.0) && angP2 >= (3 * (PI / 2.0))){
                segments.insert({distW[j], j});
            }

            if((angP2 - angP1) < PI){
                events.push_back({angP1, ii(0, j)});
                events.push_back({angP2, ii(2, j)});
            }
            else{
                events.push_back({angP2, ii(0, j)});
                events.push_back({angP1, ii(2, j)});
            }
        }

        for(int j = 0; j < k; j++){
            if(j == i){
                continue;
            }
            double ang = angleComp(puntos[i], puntos[j]);
            events.push_back({ang, ii(1, j)});
        }

        sort(events.begin(), events.end());
        
        int res = 0;
        //cout << i << " " << segments.size() << "\n";
        for(int j = 0; j < (int) events.size(); j++){
            //cout << j << " " << events[j].second.first << " " << events[j].second.second << "\n";
            int id = events[j].second.second;
            int l;
            switch (events[j].second.first){
                case 0:
                segments.insert({distW[id], id});
                break;
                case 1:
                if(segments.empty()){
                    res++;
                    continue;
                }
                l = segments.begin() -> second;
                if(!intersectSegment(lineas[l].first, lineas[l].second, puntos[i], puntos[id])){
                    res++;
                }
                break;
                case 2:
                segments.erase({distW[id], id});
                break;
            }
        }

        cout << res << "\n";
    }
    
    return 0;
}
