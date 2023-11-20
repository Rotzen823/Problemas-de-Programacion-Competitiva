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

// returns the cross product of two vectors a and b
double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

// returns the squared value of the normalized vector
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

//Devuelve el angulo de a respecto a la linea horizontal que pasa por o
//Usado para Sweep Radain
double polarAngle(point p1, point p2){
	double x = p1.x - p2.x, y = p1.y - p2.y;
    double a = atan2(y, x);
    return a < 0 ? a + 2 * PI : a;
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

bool segIntersects(point a, point b, point p, point q)
{   
	vec ab = toVec(a, b), pq = toVec(p, q);
	vec A = toVec(point(0, 0), a), P = toVec(point(0, 0), p);

    double k1 = (cross(A, pq) - cross(P, pq)) * 1.0 / cross(pq, ab);
    double k2 = (cross(A, ab) - cross(P, ab)) * 1.0 / cross(pq, ab);
    return k1 >= 0 && k1 <= 1 && k2 >= 0 && k2 <= 1;
}

point puntos[MAX];
pair<point, point> lineas[MAX];
point pivot;

struct comp{
    bool operator() (const int& a, const int& b){
        point u = lineas[a].first, v = lineas[a].second; //seg uv
        point p = lineas[b].first, q = lineas[b].second; //seg pq

        if (cross(toVec(pivot, u), toVec(pivot, p)) > 0)
            return segIntersects(u, v, pivot, p);
        return !segIntersects(u, pivot, p, q);
    } 
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
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
        pivot = puntos[i];
        vector<pair<double, ii> > events;

        set<int, comp> segments;

        for(int j = 0; j < w; j++){
            if(cross(toVec(pivot, lineas[j].first), toVec(pivot, lineas[j].second)) < 0){
                swap(lineas[j].first, lineas[j].second);
            }
            double angP1 = polarAngle(pivot, lineas[j].first);
            double angP2 = polarAngle(pivot, lineas[j].second);

            if(angP1 > angP2){
                segments.insert(j);
            }

            events.push_back({angP1, ii(0, j)});
            events.push_back({angP2, ii(2, j)});
        }

        for(int j = 0; j < k; j++){
            if(j == i){
                continue;
            }
            double ang = polarAngle(pivot, puntos[j]);
            events.push_back({ang, ii(1, j)});
        }

        sort(events.begin(), events.end());
        
        int res = 0;
        for(int j = 0; j < (int) events.size(); j++){
            int id = events[j].second.second;
            int l;
            switch (events[j].second.first){
                case 0:
                segments.insert(id);
                break;
                case 1:
                if(segments.empty()){
                    res++;
                    continue;
                }
                l = *segments.begin();
                if(!segIntersects(lineas[l].first, lineas[l].second, pivot, puntos[id])){
                    res++;
                }
                break;
                case 2:
                segments.erase(id);
                break;
            }
        }

        cout << res << "\n";
    }
    
    return 0;
}
