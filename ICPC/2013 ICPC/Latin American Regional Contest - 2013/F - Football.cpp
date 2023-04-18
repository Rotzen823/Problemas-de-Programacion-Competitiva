#include <bits/stdc++.h>
#define MAX 100005

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef struct Partido{
    int goles;
    int puntos;
}Partido;

class Comparacion{
    public:
        bool operator() (Partido a, Partido b){
            double dA, dB;
            dA = (double) a.puntos / a.goles;
            dB = (double) b.puntos / b.goles;
            return dA < dB;
        }
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, g;
    cin >> n >> g;

    priority_queue<Partido, vector<Partido>, Comparacion> q;

    int res = 0;
    for(int k = 0; k < n; k++){
        int s, r;
        cin >> s >> r;
        if(s > r){
            res += 3;
        }
        else if(s == r){
            res++;
            q.push({1, 2});
        }
        else{
            q.push({r - s, 1});
        }
    }

    while(!q.empty() && g > 0){
        Partido p = q.top(); q.pop();
        if(p.goles <= g){
            g -= p.goles;
            res += p.puntos;
            if(p.puntos == 1){
                q.push({1, 2});
            }
        }
    }

cout << res << "\n";

    return 0;
}
