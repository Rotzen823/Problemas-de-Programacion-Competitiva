#include <bits/stdc++.h>

#define ENDL '\n'
#define MOD 1000000007
#define INF 1000000000
#define MAX 10005
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

double const EPS = 1e-5;

struct point{
    double x, y;
    point() {x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p){
    return hypot(p.x, p.y);
}

bool intersect(point p1, point p2, double r){
    double d = (r * r * 4.0);
    double dist = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    return dist <= d;
}

double X, Y;
int n;
vector<point> pts;

vector<vi> grafo;
vector<bool> ready;

void dfs(int u){
    if(ready[u]){
        return;
    }

    ready[u] = true;

    for(int v : grafo[u]){
        dfs(v);
    }
}

bool check(double d){
    grafo.assign(n + 4, vi());

    for(int i = 0; i < n; i++){
        if(pts[i].x - d <= 0.0){
            grafo[0].push_back(i + 4);
            grafo[i + 4].push_back(0);
        }
        if(pts[i].x + d >= X){
            grafo[1].push_back(i + 4);
            grafo[i + 4].push_back(1);
        }
        if(pts[i].y - d <= 0.0){
            grafo[2].push_back(i + 4);
            grafo[i + 4].push_back(2);
        }
        if(pts[i].y + d >= Y){
            grafo[3].push_back(i + 4);
            grafo[i + 4].push_back(3);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(intersect(pts[i], pts[j], d)){
                grafo[i + 4].push_back(j + 4);
                grafo[j + 4].push_back(i + 4);
            }
        }
    }

    ready.assign(n + 4, false);
    dfs(0);

    if(ready[1] || ready[2]){
        return false;
    }

    ready.assign(n + 4, false);
    dfs(3);
    if(ready[1] || ready[2]){
        return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> X >> Y >> n;

    pts.resize(n);
    double minD = 10000000;
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
        minD = min(minD, dist(pts[i]));
    }

    double in = 0, fin = minD;
    while((fin - in) >= EPS){
        double mid = (in + fin) / 2;
        
        if(check(mid)){
            in = mid;
        }
        else{
            fin = mid;
        }
    }   

    cout << in << "\n";

    return 0;
}
