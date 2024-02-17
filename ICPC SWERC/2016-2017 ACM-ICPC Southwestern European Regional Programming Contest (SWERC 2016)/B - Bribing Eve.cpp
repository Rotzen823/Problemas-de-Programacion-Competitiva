#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const double EPS = 1e-9;

typedef double T;
struct Point {
  T x, y;
  Point(T x=0, T y=0) : x(x), y(y) {}// Point p(x,y)
  
  Point operator+(const Point &p)const{return Point(x+p.x,y+p.y);}
  Point operator-(const Point &p)const{return Point(x-p.x,y-p.y);}
  Point operator*(double a) const {return Point(x*a,y*a);}
  Point operator/(T d) const { return {x / d, y / d}; } //Usar con double
  
  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  
  T norm_sq() { return x * x + y * y; }
  double norm() { // hypot(x, y) mas lento pero mas precision 
    return sqrt( norm_sq() ); 
  } 

  bool operator<(Point p) const { 
    return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS); 
  }

  bool operator == (Point p) const { // Numeros Flotantes
    return (fabs(x - p.x) < EPS && (fabs(y - p.y) < EPS));
  }

  void out(){ cout << x << " " << y << '\n'; }
};

// Ecuacion ax + by = c
struct Line { double a, b, c; };

//Checa si la linea L2 y L2 son paralelas
bool areParallel(Line l1, Line l2) {             
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

//Checa si son la misma linea
bool areSame(Line l1, Line l2) {                 // also check  c
  return areParallel(l1 ,l2) && (fabs(l1.c-l2.c) < EPS);
}

// Devuelve si intersecta la linea L1 y L2 + Punto  p de interseccion
bool areIntersect(Line l1, Line l2, Point &p) {
  if (areParallel(l1, l2)) return false;         // No intersectan
  // Resolver sistema de ecuaciones 2x2 con 2 variables desconocidas
  p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
  // Caso especial: Probar Linea vertical para evitar division por cero
  if (fabs(l1.b) > EPS) 
    p.y = -(l1.a*p.x + l1.c);
  else                 
    p.y = -(l2.a*p.x + l2.c);
  return true;
}

double f(Line l, double w){
    return -(l.c + l.a * w);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    double x1, x2;
    cin >> x1 >> x2;

    Line lm = {x2 - x1, 1, -x2};

    vector<Line> lines;

    for(int i = 1; i < n; i++){
        cin >> x1 >> x2;
        lines.push_back({x2 - x1, 1, -x2});
    }

    vector<pair<Point, ii> > events;

    int same = 0, up = 0;

    for(int i = 0; i < n - 1; i++){
        if(areSame(lm, lines[i])){
            same++;
            continue;
        }

        Point c;
        double ax;
        if(areIntersect(lm, lines[i], c)){
            if((c.x >= 0.0 && c.x <= 1.0)){
                events.push_back({c, ii(0, i)});
                events.push_back({c, ii(1, i)});
            }
            ax = c.x == 0.0 ? -1.0 : 0.0;
        }
        else{
            ax = 0.0;
        }

        if(f(lm, ax) < f(lines[i], ax)){
            up++;
        }
    }

    if(events.size() == 0){
        cout << up + 1 << " " << up + same + 1 << "\n";
        return 0;
    }

    sort(events.begin(), events.end());

    bool flag = false;
    int best = n, worst = 0;
    for(auto e : events){
        Point p = e.first;
        int i = e.second.second;

        if(e.second.first){
            if(flag){   
                best = min(best, up + 1);
                worst = max(worst, up + same + 1);
                flag = false;
            }
            same--;
            if(f(lines[i], -1.0) < f(lm, -1.0)){
                up++;
            }
        }
        else{
            flag = true;
            same++;
            if(f(lines[i], -1.0) > f(lm, -1.0)){
                up--;
            }
        }
    }

    cout << best << " " << worst << "\n";

    return 0;
}
