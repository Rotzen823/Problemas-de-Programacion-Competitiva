#include <bits/stdc++.h>
 
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000009
#define MAX 10000
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int b, c;
        cin >> b >> c;
 
        int tin = 0, bla = 0;
        while(c--){
            int x, y;
            cin >> x >> y;
            tin = max(tin, x);
            bla = max(y, bla);
        }
 
        if(tin + bla > b){
            cout << "IMPOSSIBLE\n";
        }
        else{
            for(int k = 0; k < tin; k++){
                cout << "R";
            }
            for(int k = tin; k < b; k++){
                cout << "W";
            }
            cout << "\n";
        }
    }
 
    return 0;
}
