#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
struct Segment{
    int a, b, c;
    bool vert;
 
    Segment(int _a = 1, int _b = 0, int _c = 0, bool _vert = false) :
        a(_a), b(_b), c(_c), vert(_vert) {}
 
    bool isEmpty(){
        return a > b;
    }
 
    Segment intersect(Segment &s){
        if(isEmpty() || s.isEmpty()){
            return Segment();
        }
 
        if(s.vert == vert){
            if(c != s.c){
                return Segment();
            }
            return Segment(max(a, s.a), min(b, s.b), c, vert);
        }
        if(c >= s.a && c <= s.b && s.c >= a && s.c <= b){
            return Segment(s.c, s.c, c, vert);
        }
        return Segment();
    }
 
    vii convertToPoints(){
        vii res;
        for(int k = a; k <= b; k++){
            int x = k - c;
            int y = k + c;
 
            if(vert){
                x = -x;
            }
 
            if(!(x & 1) && !(y & 1)){
                res.push_back(ii(x / 2, y / 2));
            }
        }
 
        return res;
    }   
};
 
typedef vector<Segment> vs;
 
vs intersecarSegmentos(vs& a, vs& b){
    vs res;
    for(auto s1 : a){
        for(auto s2 : b){
            Segment s = s1.intersect(s2);
            if(!s.isEmpty()){
                res.push_back(s);
            }
        }
    }
 
    return res;
}
 
vs convertirSegements(int x, int y, int d){
    vs res;
    int cx = x + y;
    int cy = y - x;
    if(d == 0){
        res.push_back(Segment(cx, cx, cy, false));
    }
    else{
        res.push_back(Segment(cx - d, cx + d, cy + d, false));
        res.push_back(Segment(cx - d, cx + d, cy - d, false));
        res.push_back(Segment(cy - d + 1, cy + d - 1, cx + d, true));
        res.push_back(Segment(cy - d + 1, cy + d - 1, cx - d, true));
    }
    
    return res;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
 
    int x, y, d;
    cin >> x >> y >> d;
 
    vs segs = convertirSegements(x, y, d);
 
    while(--n){
        cin >> x >> y >> d;
        vs ax = convertirSegements(x, y, d);
        segs = intersecarSegmentos(segs, ax);
    }
 
    set<ii> res;
    for(auto s : segs){
        vii ax = s.convertToPoints();
        for(ii x : ax){
            res.insert(x);
        }
    }
 
    for(ii x : res){
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
