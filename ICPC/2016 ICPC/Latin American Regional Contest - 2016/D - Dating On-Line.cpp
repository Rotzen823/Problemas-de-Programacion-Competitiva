#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
    int n;
    cin >> n;

    int rad[n];

    for(int k = 0; k < n; k++){
        cin >> rad[k];
    }

    sort(rad, rad + n);
    deque<int> orden;

    orden.push_back(rad[n - 1]);
    for(int k = n - 2; k >= 0; k--){
        if(orden.back() > orden.front()){
            orden.push_back(rad[k]);
        }
        else{
            orden.push_front(rad[k]);
        }
    }

    double PI = acos(-1);
    double teta = (2 * PI) / n;
    vector<pair<double, double> > puntos;
    puntos.assign(n + 1, {0.0, 0.0});
    for(int k = 0; k < n; k++){
        double t = teta * k;
        puntos[k].first = (double) orden[k] * cos(t);
        puntos[k].second = (double) orden[k] * sin(t);
    }
    puntos[n] = puntos[0];

    double ans = 0;
    for(int k = 0; k < n; k++){
        ans += (puntos[k].first * puntos[k + 1].second) - (puntos[k + 1].first * puntos[k].second);
    }
    ans = fabs(ans) / 2.0;

    printf("%.3lf\n", ans);

	return 0;
}
