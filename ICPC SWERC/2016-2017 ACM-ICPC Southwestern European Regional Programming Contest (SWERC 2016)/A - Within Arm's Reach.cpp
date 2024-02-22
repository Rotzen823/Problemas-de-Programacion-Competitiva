#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct Point {
    T x, y;
    Point(T x=0, T y=0) : x(x), y(y) {}// Point p(x,y)
    
    Point operator+(const Point &p)const{return Point(x+p.x,y+p.y);}
    Point operator-(const Point &p)const{return Point(x-p.x,y-p.y);}
    Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

    Point operator*(double a) const {return Point(x*a,y*a);}
    Point operator/(T d) const { return {x / d, y / d}; } //Usar con double
    
    T norm_sq() { return x * x + y * y; }
    double norm() { // hypot(x, y) mas lento pero mas precision 
        return sqrt( norm_sq() ); 
    }
    
    void read() { cin >> x >> y; } 
    void out(){ cout << x << " " << y << '\n'; }
};

double angle(Point p) { 
  return atan2(p.y, p.x); 
}

// -1 Negativo | 0 Cero | 1 Positivo 
int sgn(T x) { 
    return (T(0) < x) - (x < T(0)); 
}

Point rotateCCW90(Point p) { // p = rotateCCW90();
  return { -p.y, p.x }; 
} 

// Retorna el punto que se encuentra en el circulo dado el angulo en radianes
Point circlePoint(Point c, double r, double ang) { // Usar double
  return Point{c.x + cos(ang) * r, c.y + sin(ang) * r};
}

// Retorna las intersecciones entre dos circulos. 
int circleCircle(Point o1, double r1, Point o2, double r2, pair<Point, Point> &out) {
    Point d = o2 - o1;
    double d2 = d.norm_sq();
    if (d2 == 0) {
        //assert(r1 != r2);  // Los circulos son iguales
        return 0;
    }
    double pd = (d2 + r1 * r1 - r2 * r2) / 2;
    double h2 = r1 * r1 - pd * pd / d2;
    if (h2 >= 0) {
        Point p = o1 + d * pd / d2, h = rotateCCW90(d) * sqrt(h2 / d2);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << (fixed) << setprecision(5);

    int n;
    cin >> n;

    double L[n];

    for(int i = 0; i < n; i++){
        cin >> L[i];
    }

    Point p;
    cin >> p.x >> p.y;

    double in[n], out[n];
    in[0] = out[0] = L[0];
    for(int i = 1; i < n; i++){
        out[i] = L[i] + out[i - 1];
        in[i] = min(abs(out[i - 1] - L[i]), abs(in[i - 1] - L[i]));
        if(L[i] >= in[i - 1] && L[i] <= out[i - 1]){
            in[i] = 0;
        }
    }

    if(p.norm() > out[n - 1]){
        p = circlePoint({0.0, 0.0}, out[n - 1], angle(p));
    }
    else if(p.norm() < in[n - 1]){
        p = circlePoint({0.0, 0.0}, in[n - 1], angle(p));
    }

    vector<Point> ans;
    ans.push_back(p);

    for(int i = n - 2; i >= 0; i--){
        double rMax = L[i + 1] + p.norm();
        double r = min(rMax, out[i]);

        pair<Point, Point> out;

        if(circleCircle({0.0, 0.0}, r, p, L[i + 1], out) != 0){
            p = out.first;
            ans.push_back(p);
        }
        else{
            p = circlePoint({0.0, 0.0}, r, angle(p));
            ans.push_back(p);
        }
    } 

    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i].x << " " << ans[i].y << "\n";
    }  

    return 0;
}
