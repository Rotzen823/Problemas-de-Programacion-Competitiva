#include<bits/stdc++.h>

using namespace std;

map<string, int> mapa;

int main() {
    int n, c;
    int res = 0;
    string pal = "", ax = "";

    cin >> n >> c;

    for(int k = 0; k < c; k++){
        pal += "z";
    }

    while(n--){
        cin >> ax;
        int p = -1;
        for(int k = 0; k < c; k++){
            if(ax[k] == '*'){
                p = k;
                break;
            }
        }
        for(char k = 'a'; k <= 'z'; k++){
            ax[p] = k;
            mapa[ax]++;
            int x = mapa[ax];
            if(x > res || (x == res && ax < pal)){
                pal = ax;
                res = x;
            }
        }
    }

    cout << pal << " " << res << "\n";
    
    return 0;
}