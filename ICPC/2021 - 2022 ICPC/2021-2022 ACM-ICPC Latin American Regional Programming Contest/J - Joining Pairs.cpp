#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;

int w, h;
bool borde(int x, int y){
    return x == 0 || x == w || y == 0 || y == h;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;

    cin >> w >> h >> n;

    vector<iii> puntos;
    for(int k = 0; k < n; k++){
        int x[2], y[2];
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        if(borde(x[0], y[0]) && borde(x[1], y[1])){
            for(int j = 0; j < 2; j++){
                if(y[j] == 0){
                    puntos.push_back(iii(ii(0, x[j]), k));
                }
                else if(x[j] == w){
                    puntos.push_back(iii(ii(1, y[j]), k));
                }
                else if(y[j] == h){
                    puntos.push_back(iii(ii(2, -x[j]), k));
                }
                else{
                    puntos.push_back(iii(ii(3, -y[j]), k));
                }
            }
        }
    }

    sort(puntos.begin(), puntos.end());

    stack<int> pila;
    vector<bool> abr(n, true);

    for(int k = 0; k < (int) puntos.size(); k++){
        int i = puntos[k].second;
        if(abr[i]){
            abr[i] = false;
            pila.push(i);
        }
        else if(pila.top() != i){
            cout << "N\n";
            return 0;
        }
        else{
            pila.pop();
        }
    }

    cout << "Y\n";
 
    return 0;
}
